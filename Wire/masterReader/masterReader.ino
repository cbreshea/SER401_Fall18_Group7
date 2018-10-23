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
  Wire.requestFrom(8, 1);
  Serial.print("sensor reads: ");
  uint8_t i = Wire.read(); // receive a byte as usnigned 8-bit int
  Serial.print(i);         // print the value

  delay(500);
}
