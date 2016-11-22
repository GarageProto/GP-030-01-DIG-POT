/*************************************************** 
  This is a library example for the MAX5481 1024 Step digital Pot

  Designed specifically to work with the GP-030-01 Dev board
  ----> http://GarageProto.com/Product/GP-030-XX

  Written by RF Chapaman and MS Blankenship for GarageProto 
  
  GP_MAX5841.h is based upon a sketch by Gabriel Staples
  http://forum.arduino.cc/index.php?topic=242376.0
  http://www.electricrcaircraftguy.com/2016/11/MAX5481-DigitalPotentiometer.html 
 ****************************************************/

/*
===================================================================================================
  LICENSE & DISCLAIMER
  Copyright (C) 2014 Gabriel Staples.  All right reserved.
   
  ------------------------------------------------------------------------------------------------
  License: GNU Lesser General Public License Version 3 (LGPLv3) - https://www.gnu.org/licenses/lgpl.html
  ------------------------------------------------------------------------------------------------
   
  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU Lesser General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
 
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU Lesser General Public License for more details.
 
  You should have received a copy of the GNU Lesser General Public License
  along with this program.  If not, see http://www.gnu.org/licenses/
===================================================================================================
*/


#include <GP_MAX5841.h>
#include <SPI.h>



GP_MAX5841::GP_MAX5841(uint8_t ss)
{
     pinMode(ss, OUTPUT);
     //SPI.begin();
     _SS = ss;  //Set Slave Select Pin
}

void GP_MAX5841::setWiper(unsigned int value)
{
 //local constants
 const byte WRITE_WIPER = 0x00; //command to write to the wiper register only

//  const byte COPY_EEPROM_TO_WIPER = 0x30; //command to copy the EEPROM value to the wiper register
 
 //command the new wiper setting (requires sending 3 bytes)
 digitalWrite(_SS,LOW); //set the SS pin low to select the chip
 SPI.transfer(WRITE_WIPER); //Byte 1: the command byte
 SPI.transfer(highByte(value<<6)); //Byte 2: the upper 8 bits of the 10-bit command: (D9.D8.D7.D6.D5.D4.D3.D2)
 SPI.transfer(lowByte(value<<6)); //Byte 3: the lower 2 bits of the 10-bit command, with 6 zeros to the right of them: (D1.D0.x.x.x.x.x.x)
 digitalWrite(_SS,HIGH); //set the SS pin high to "latch the data into the appropriate control register" (see datasheet pg. 14)
 delay(10); //wait a short time for the previous command to get properly set
}

void GP_MAX5841::writeWiper()
{
 const byte WRITE_EEPROM = 0x20; //command to copy the wiper register into the non-volatile memory (EEPROM) of the digital pot
   
   digitalWrite(_SS,LOW); //set the SS pin low to select the chip
   SPI.transfer(WRITE_EEPROM); //Byte 1: the command byte
   digitalWrite(_SS,HIGH); //set the SS pin high to "latch the data into the appropriate control register" (see datasheet pg. 14 & 16)
   delay(13); //wait 13ms (see datasheet pg. 16 under the paragraph titled "Copy Wiper Register to NV Register"--they require a 12ms wait time, so I'll wait 13ms to be sure)
}
   
//copy the value stored in the EEPROM to the wiper register, to command the wiper to go there
void GP_MAX5841::readWiper()
{
 const byte COPY_EEPROM_TO_WIPER = 0x30; //command to copy the EEPROM value to the wiper register
 digitalWrite(_SS,LOW); //set the SS pin low to select the chip
 SPI.transfer(COPY_EEPROM_TO_WIPER); //Byte 1: the command byte
 digitalWrite(_SS,HIGH); //set the SS pin high to "latch the data into the appropriate control register" (see datasheet pg. 14 & 16)
}

