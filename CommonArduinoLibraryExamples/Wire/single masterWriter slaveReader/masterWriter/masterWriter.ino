#include <Wire.h>

/*
 * This is an example of how to create a masterWriter to be used 
 * along with a slaveReader. This would be used in situations
 * such as having one board calculate a value and send it to 
 * another board to control something.
 */
 
int sensorPin = A0;//some sensor is connecting to this pin
uint8_t sensorValue = 0;//variable to store sensor value read

void setup() {
  Wire.begin();//init Wire, indicate this device is a master by giving no parameter to function
}

void loop() {
    sensorValue = (analogRead(sensorPin) >> 2);//analog is 10-bit in length, shift right to reduce to 8-bit
    Wire.beginTransmission(10);//transmit to device 10
    Wire.write(sensorValue);//send one byte
    Wire.endTransmission();//stop transmitting
}
