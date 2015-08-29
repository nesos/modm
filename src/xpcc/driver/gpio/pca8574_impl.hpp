// coding: utf-8
/* Copyright (c) 2015, Roboterclub Aachen e. V.
 * All Rights Reserved.
 *
 * The file is part of the xpcc library and is released under the 3-clause BSD
 * license. See the file `LICENSE` for the full license governing this code.
 */
// ----------------------------------------------------------------------------

#ifndef XPCC_PCA8574_HPP
#	error "Don't include this file directly, use 'pca8574.hpp' instead!"
#endif

template < class I2cMaster >
xpcc::Pca8574<I2cMaster>::Pca8574(uint8_t address)
: I2cDevice<I2cMaster, 1>(address), pins(0)
{
}

template < class I2cMaster >
xpcc::ResumableResult<bool>
xpcc::Pca8574<I2cMaster>::write(uint8_t value)
{
	RF_BEGIN();

	i2cBuffer = value;
	this->transaction.configureWrite(&i2cBuffer, 1);

	RF_END_RETURN_CALL( this->runTransaction() );
};

template < class I2cMaster >
xpcc::ResumableResult<bool>
xpcc::Pca8574<I2cMaster>::read(uint8_t &value)
{
	RF_BEGIN();

	this->transaction.configureRead(&i2cBuffer, 1);
	if (RF_CALL(this->runTransaction()))
	{
		value = i2cBuffer;
		RF_RETURN( true );
	}

	RF_END_RETURN( false );
};
