/*
  DAC7578.cpp - Library for ___.
  Created by Justin HB, February 28, 2019.
*/
#include "DAC7578.h"


unsigned createMask(unsigned a, unsigned b)
{
   unsigned r = 0;
   for (unsigned i=a; i<=b; i++)
       r |= 1 << i;

   return r;
}


DAC7578::DAC7578(uint32_t newDeviceAddress)
{
  _deviceAddress = newDeviceAddress;
}


void DAC7578::writeDAC(uint16_t value, uint8_t DAC){
  uint16_t MSDB2, LSDB2;
  
  unsigned r = createMask(0, 3);
  LSDB2 = value & r;
  LSDB2 = LSDB2 << 4;
  
  unsigned x = createMask(3, 11);
  MSDB2 = value & x;
  MSDB2 = MSDB2 >> 4;
  
  Wire.begin();
  Wire.beginTransmission(0x4A); // hex 48, B1001000
  Wire.write(CA + DAC);    //CA byte
  Wire.write(MSDB2);  //MSDB
  Wire.write(LSDB2);  //LSDB
  Wire.endTransmission();
}
