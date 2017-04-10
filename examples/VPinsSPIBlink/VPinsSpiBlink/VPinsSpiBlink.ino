#include <Arduino.h>

/*
Virtual pins library
blinking a led wired over an SPI shift register
*/

#include <SPI.h>// <---<< we will use this media
#include <VPinsSPI.h>//<-- with this driver
#include <debug.h>

#define STCP 9//stcp or latch pin
//use virtual pins over SPI shift registers as VPA (Virtual Port A)
SPIBranch spi(SPI,STCP,VPA,2);//<-- map 2 virtual ports starting at A (VPA+VPB)

//now we have an extra 16 output pins
//ranging from 20 to 35 (virtual pins)
#define LEDPIN 27

void setup() {
  SPI.begin();//<-- initialize the media
  pinMode(LEDPIN,OUTPUT);//<-- using a virtual pins the same way as an internal
  //we can pass it around to libraries, no need to recode your library.
}

void loop() {
  digitalWrite(LEDPIN,0);
  delay(500);
  digitalWrite(LEDPIN,1);
  delay(500);
}
