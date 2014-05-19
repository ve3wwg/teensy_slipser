teensy_slipser
==============

Teensy-3.x Slip Serial Class


    class SlipSer {
        HardwareSerial&         serial;         // Serial device
        SLIP                    slip;
        char                    *buffer;        // Receive buffer
        unsigned                rxlength;       // Received message length
        
    public:
        SlipSer(HardwareSerial& ser_dev);

        inline uint8_t rx_byte()        { return uint8_t(serial.read()); }
        inline void tx_byte(uint8_t b)  { serial.write(int(b)); }               
        inline void tx_flush()          { serial.flush(); }

        void open(uint32_t baud,char *rxbuffer,unsigned maxbuflen,uint32_t format = SERIAL_8N1);
        void close();

        void write(const void *buffer,unsigned length);     // Read packet
        void *read(unsigned& length);                       // Write packet
    };


This project depends upon the SLIP class here:

    https://github.com/ve3wwg/slip
