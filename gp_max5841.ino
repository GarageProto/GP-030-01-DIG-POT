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
Functions :
GPOT.setWiper(int) Writes to the Wiper register ONLY does NOT store in EEPROM
GPOT.writeWiper()  Copies wiper register to the EEPROM
GPOT.readWiper()   Copies whats in the EEPROM to the wiper register     
*/

#include<GP_MAX5841.h>
#include <SPI.h>

GP_MAX5841 GPOT(5);
int myCounter = 0;

void setup()
{
 //initialize SPI
 SPI.begin();

}

void loop()
{
  GPOT.setWiper(myCounter);
   myCounter++;
  delay(25);
}


