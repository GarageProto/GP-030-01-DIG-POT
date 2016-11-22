/*************************************************** 
  This is a library example for the MAX5481 Dev board

  Designed specifically to work with the GP-030-01 Dev board
  ----> http://GarageProto.com/Product/GP-030-XX

  Written by RF Chapaman and MS Blankenship for GarageProto 
  GP_MAX5841.h is based upon a sketch by Gabriel Staples
  http://forum.arduino.cc/index.php?topic=242376.0
  
 ****************************************************/
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


