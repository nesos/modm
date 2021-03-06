#!/usr/bin/env python3
# -*- coding: utf-8 -*-
#
# Copyright (c) 2010-2012, Fabian Greif
# Copyright (c) 2010, 2013, Georgi Grinshpun
# Copyright (c) 2012, 2014, 2016, Sascha Schade
# Copyright (c) 2014, Kevin Läufer
# Copyright (c) 2016, Daniel Krebs
# Copyright (c) 2017, Michael Thies
#
# This file is part of the modm project.
#
# This Source Code Form is subject to the terms of the Mozilla Public
# License, v. 2.0. If a copy of the MPL was not distributed with this
# file, You can obtain one at http://mozilla.org/MPL/2.0/.
# -----------------------------------------------------------------------------

import time
import codecs		# utf-8 file support
import sys
import traceback
import os
import jinja2		# template engine
import textwrap
from optparse import OptionParser

sys.path.append(os.path.join(os.path.dirname(__file__), '..'))
from xmlparser.parser import Parser
from xmlparser.parser_exception import ParserException


class BuilderException(Exception):
	pass


class Builder(object):
	"""
	Base class for any builder-class

	Attributes:
	self.xmlpath		--	path to the xml-file
	self.xmlfile		--	xml-filename
	self.tree			--	evaluated xml tree, instance of Parser
	self.time			--	string containing the current date and time
	self.options		--	evaluated commandline arguments (see OptionParser)
	self.include_paths	--	paths that will be searched for include files

	To access the elements from the xml tree use for example:
	self.tree.components
	self.tree.components.actions			--	all actions
	self.tree.components.subscriptions		--	all events
	self.tree.components["driver"].actions	--	only actions form the
												component 'driver'
	self.tree.components["driver"].events.publish
	self.tree.components["driver"].events.subscribe
	self.tree.containers
	self.tree.containers["PC"].components	--	only components form the
												container 'PC'
	self.tree.types
	self.tree.events

	You have to specify a VERSION attribute.

	"""
	def __init__(self):
		optparser = OptionParser(
				usage   = "%prog [options] XML_FILE",
				version = "%prog version: " + self.VERSION )

		optparser.add_option(
				"-o", "--outpath",
				dest = "outpath",
				default = None,
				help = "Output path [optional]")

		optparser.add_option(
				"-t", "--template_path",
				dest = "templatePath",
				default = None,
				help = "Template path [optional]")

		optparser.add_option(
				"-d", "--dtdpath",
				dest = "dtdPath",
				default = None,
				help = "DTD path [optional]")

		optparser.add_option(
				"-I", "--include_path",
				dest = "includePath",
				default = None,
				action = "append",
				help = "Include Search Path [optional]")

		self.setup(optparser)

		(self.options, args) = optparser.parse_args()

		if len(args) != 1:
			raise BuilderException("XML_FILE: You have to specify a valid xml-file")
			exit(1)

		self.xmlfile = args[0]
		self.xmlpath = os.path.dirname(os.path.abspath(self.xmlfile))

		# convert include paths to absolute paths
		self.include_paths = []
		include_paths = self.options.includePath
		if not isinstance(include_paths, list):
			include_paths = [include_paths]
		for path in include_paths:
			if isinstance(path, str):
				self.include_paths.append(os.path.abspath(path))

		try:
			parser = Parser()
			parser.parse(self.xmlfile, dtdPath=self.options.dtdPath, include_paths=self.include_paths)
		except ParserException as e:
			sys.stderr.write("Parsing Error: %s\n" % str(e))
			print(traceback.format_exc())
			sys.exit(1)

		self.tree = parser.tree
		self.globals = {
			'time': time.strftime("%d %b %Y, %H:%M:%S", time.localtime()),
		}

		if self.options.templatePath == None:
			self.templatePath = "templates/"
		else:
			self.templatePath = self.options.templatePath

	def generate(self):
		""" Generate the requested files """
		raise BuilderException("You can not use this class directly!")

	def setup(self, optparser):
		"""
		Setup the builder. Can be overwritten to customise the behavior.

		Keywords arguments:
		optparser		--	OptionParser instance. Use add_option for
							additional commandline arguments.
		"""
		pass

	def write(self, filename, data):
		"""
		Write data utf-8 decoded to a file.

		Contents of the file will be overwritten.
		"""
		# create the path if it doesn't exists
		dir = os.path.dirname(filename)
		if not os.path.isdir(dir):
			os.mkdir(dir)

		# write data
		file = codecs.open(filename, 'w', 'utf8')
		file.write(data)
		file.close()

	def read(self, filename):
		"""
		Read a utf-8 decoded file.

		Provided for convenience.
		"""
		return codecs.open(filename, 'r', 'utf8').read()

	def template(self, filename, filter=None):
		""" Open a template file

		Uses the jinja2 template engine. The following additional filters
		are included:
		modm.wordwrap(with)		--	like the original filter, but with correct
									handling of newlines
		modm.indent(level)		--	indent every line with \a level tabs

		Keyword arguments:
		filename	--	Template file
		filter		--	dict with additional filters (see the section
						'Custom Filters' in the Jinja2 documentation for details)

		Example:
		template = builder.template(file)

		output = template.render(dict)
		builder.write(outputfile, output)

		"""
		def filter_wordwrap(value, width=79):
			return '\n\n'.join([textwrap.fill(str, width) for str in value.split('\n\n')])

		def filter_indent(value, level=0, prefix=""):
			return ('\n' + '\t' * level + prefix).join(value.split('\n'))

		path = os.path.dirname(filename)
		name = os.path.basename(filename)

		if not os.path.isabs(filename):
			relpath = os.path.dirname(os.path.abspath(__file__))
			path = os.path.join(relpath, path)

		environment = jinja2.Environment(
				loader=jinja2.FileSystemLoader(path),
				extensions=["jinja2.ext.loopcontrols"])
		environment.line_comment_prefix = '%#'
		environment.filters['modm.wordwrap'] = filter_wordwrap
		environment.filters['modm.indent'] = filter_indent
		if filter:
			environment.filters.update(filter)
		template = environment.get_template(name, globals=self.globals)

		return template

	def run(self):
		try:
			self.generate()
		except BuilderException as e:
			sys.stderr.write("Builder Error: %s\n" % str(e))
			sys.exit(1)
		except jinja2.exceptions.TemplateSyntaxError as e:
			sys.stderr.write("Error in Template: %s\n" % str(e))
			sys.exit(1)
		#except Exception as e:
		#	sys.stderr.write("Internal Error: %s\n" % str(e))
		#	sys.exit(1)
