// coding: utf-8
// ----------------------------------------------------------------------------
/* Copyright (c) 2009, Roboterclub Aachen e.V.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Roboterclub Aachen e.V. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY ROBOTERCLUB AACHEN E.V. ''AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOTERCLUB AACHEN E.V. BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id$
 */
// ----------------------------------------------------------------------------
#ifndef XPCC_TIPC_RECEIVER_H_
#define XPCC_TIPC_RECEIVER_H_
 

#include "../backend_interface.hpp"
#include "tipc_receiver_socket.hpp"

#include <queue>

#include <boost/thread/mutex.hpp>
#include <boost/shared_array.hpp>
#include <boost/thread/thread.hpp>
#include <boost/scoped_ptr.hpp>

namespace xpcc {
	namespace tipc {

		/**
		 * @brief		Receive Packets over the TIPC and store them.
		 * 
		 * In a seperate thread the packets are taken from the TIPC and saved local.
		 *  
		 * @ingroup		tipc
		 * @version		$Id$
		 * @author		Carsten Schmitt < >
		 */
		class Receiver {
			public:
				Receiver();

			 	~Receiver();

				void
				addEventId(uint8_t id);

				void
				addReceiverId(uint8_t id);

				bool
				hasPacket() const;
		
				const ::xpcc::Header&
			 	frontHeader() const;

				unsigned int
				frontPayloadSize() const;
			 	
				const uint8_t*
				frontPayload() const;
				
				void 
				popFront();
				
			private:
				typedef boost::shared_array<uint8_t>	SharedArr;
				typedef boost::mutex					Mutex;
				typedef boost::mutex::scoped_lock		MutexGuard;
				typedef	boost::thread::thread			Thread;
				
				struct PacketQueueSummary {
					//! @param	xpcc::Header&	header of the packet
					//! @param	SharedArr&		char array of the payload
					PacketQueueSummary(
							const xpcc::Header&,
							const uint8_t* payload,
							unsigned int size);

					xpcc::Header	header;
					unsigned int	size;
					SharedArr		payload;
				};
				
				bool 
				isAlive();
		
				void* 
				runReceiver();
				
				void 
				update();
				
				ReceiverSocket						tipcReceiverSocket_;
				std::queue<PacketQueueSummary>		packetQueue_;
				
				boost::scoped_ptr<Thread>			receiverThread_;
				mutable Mutex						receiverSocketLock_;
				mutable Mutex						packetQueueLock_;
				
				bool								isAlive_;
		};
	};
};

#endif // XPCC_TIPC_RECEIVER_H_
