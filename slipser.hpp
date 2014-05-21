//////////////////////////////////////////////////////////////////////
// slipser.hpp -- SLIP Serial Class for Teensy-3.x
// Date: Mon May 19 16:37:28 2014   (C) Warren Gay ve3wwg
///////////////////////////////////////////////////////////////////////

#ifndef SLIPSER_HPP
#define SLIPSER_HPP

#include "HardwareSerial.h"
#include "slip.hpp"

class SlipSer {
	HardwareSerial&		serial;		// Serial device
	SLIP			slip;
	uint8_t			*buffer;	// Receive buffer
	unsigned		rxlength;	// Received message length
	
public:	SlipSer(HardwareSerial& ser_dev);

	inline int rx_available()	{ return serial.available(); }
	inline uint8_t rx_byte()	{ return uint8_t(serial.read()); }
	inline void tx_byte(uint8_t b)	{ serial.write(int(b)); }		
	inline void tx_flush()		{ serial.flush(); }

	void open(uint32_t baud,void *rxbuffer,unsigned maxbuflen,uint32_t format = SERIAL_8N1);
	void close();

	void write(const void *buffer,unsigned length);
	void *read(unsigned& length);
};


#endif // SLIPSER_HPP

// End slipser.hpp
