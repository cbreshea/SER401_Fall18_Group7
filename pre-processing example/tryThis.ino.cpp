#include <Arduino.h> // Arduino Header File
#line 1 "C:\\Users\\FFJFMQ\\Documents\\Arduino\\tryThis\\tryThis.ino" //line directive
#line 1 "C:\\Users\\FFJFMQ\\Documents\\Arduino\\tryThis\\tryThis.ino" //line directive
// -*- c++ -*-
// Simple sketch to read out one register of an I2C device
// This program uses the softi2c library which is an alternative to the wire library
// an alternative library in cases the wire library cannot be used such as when the i2c pins are already in use

#define SDA_PORT PORTC
#define SDA_PIN 4 // = A4
#define SCL_PORT PORTC
#define SCL_PIN 5 // = A5
#include <SoftWire.h> // library

#define address 0x68 // 7 bit address
#define location 0x0A //memory location
#define address_length 1

SoftWire Wire = SoftWire();

#line 18 "C:\\Users\\FFJFMQ\\Documents\\Arduino\\tryThis\\tryThis.ino" //line directive
void setup(void); // function prototype
#line 23 "C:\\Users\\FFJFMQ\\Documents\\Arduino\\tryThis\\tryThis.ino" //line directive
void loop(void); // function prototype
#line 18 "C:\\Users\\FFJFMQ\\Documents\\Arduino\\tryThis\\tryThis.ino" //line directive
void setup(void) {
  Serial.begin(57600);
  Wire.begin();
}

void loop(void){
  Wire.beginTransmission(address);
  for (byte i=1; i<address_length; i++) Wire.write(0x00); // starting register
  Wire.write(location);
  Wire.endTransmission(false); // end write operation
  Wire.requestFrom(address,1); // number of bytes
  byte value = Wire.read(); // read from starting register
  Serial.println(value);
  delay(1000);
}

