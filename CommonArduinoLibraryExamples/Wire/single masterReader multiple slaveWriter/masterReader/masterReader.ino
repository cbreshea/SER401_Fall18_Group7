#include <Wire.h>
/*
 * This project requires 2 arduino boards, and an analog sensor
 * this is meant to be used with slaveWriter. This code shows how
 * to communicate between 2 arduino boards using the wire library.
 * In this the master is requesting the slave send a 1 byte message
 * that will repesent the value read from a sensor on the slave board.
 * The master will take the received sensor value and print it out
 * using serial communicaiton to a connected computer or serial display.
 */
void setup() {
  Wire.begin();//join i2c bus, no address given to function to designate as master
  Serial.begin(9600);//start serial with specified baud rate.
}

void loop() {
  //reading 8-bit int from slaveWriter
  Wire.requestFrom(8, 1);// request 1 byte from device at address 8
  Serial.print("sensor 1 reads: ");
  uint8_t i = Wire.read(); // receive a byte as usnigned 8-bit int
  Serial.print(i);         // print the value
  Serial.print("\n");

  //reading two character message from slaveWriter
  Wire.requestFrom(9, 2);// request 2 bytes from device at address 9
  Serial.print("message received: ");
  while(Wire.available()){// while there are bytes to read
    char  c = Wire.read();// read in byte
    Serial.print(c);
  }
  Serial.print("\n");

  //reading 10-bit int from slaveWriter
  Wire.requetFrom(10, 2);//request 2 bytes from device at address 10
  Serial.print("sensor 2 reads: ");
  uint16_t i = Wire.read();// first byte
  i = (i << 8) | Wire.read();// read second byte, shift first byte and OR to make 10 bit value
  Serial.print(i);
  Serial.print("\n");

  delay(500);
}
