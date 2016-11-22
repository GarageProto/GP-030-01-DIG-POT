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


