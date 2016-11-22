
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

