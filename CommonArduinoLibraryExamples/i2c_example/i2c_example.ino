// -*- c++ -*-
// Simple sketch to read out one register of an I2C device
// This program uses the softi2c library which is an alternative to the wire library
// an alternative library in cases the wire library cannot be used such as when the i2c pins are already in use

#define SDA_PORT PORTC
#define SDA_PIN 4 // = A4
#define SCL_PORT PORTC
#define SCL_PIN 5 // = A5
#include <SoftWire.h>

#define I2C_7BITADDR 0x68 // DS1307
#define MEMLOC 0x0A
#define ADDRLEN 1

SoftWire Wire = SoftWire();

void setup(void) {
  Serial.begin(57600);
  Wire.begin();
}

void loop(void){
  Wire.beginTransmission(I2C_7BITADDR);
  for (byte i=1; i<ADDRLEN; i++) Wire.write(0x00); // starting register
  Wire.write(MEMLOC);
  Wire.endTransmission(false); // end write operation
  Wire.requestFrom(I2C_7BITADDR,1); // number of bytes
  byte val = Wire.read(); // read from starting register
  Serial.println(val);
  delay(1000);
}
