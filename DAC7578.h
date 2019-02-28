/*
  DAC7578.cpp - Library for ___.
  Created by Justin HB, February 28, 2019.
*/

#ifndef DAC7578_h
#define DAC7578_h

#include "Arduino.h"
#include <Wire.h>

class DAC7578
{
    public:
        //include Chart here
        //mine is 0x4A
        DAC7578(uint32_t newDeviceAddress);
        
        //value = 0-4095
        void writeDAC(uint16_t value, uint8_t DAC);
    private:
        uint32_t _deviceAddress;
        byte CA = 0x30;
};

#endif