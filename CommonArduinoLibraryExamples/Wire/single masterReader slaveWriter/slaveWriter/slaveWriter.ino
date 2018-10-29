/*
 * this is meant to be used with masterReader. This code shows how 
 * to communicate between 2 arduino boards using the wire Library.
 * In this the slave is constantly reading from sensor and converting
 * what is read to an 8-bit int. The program will also send this value
 * using wire when it is requested.
 */
int sensorPin = A0; //some sensor is outputing to this pin
uint8_t sensorValue = 0;//variable to store sensor value read

void setup() {
  Wire.begin(8);//join i2c bus with address #8
  Wire.onRequest(requestEvent);//register handler for event

}

void loop() {
  sensorValue = (analogRead(sensorPin) >> 2);//analog is 10-bit in length, shift right to reduce to 8-bit
}

/*this function will execute whenever wire.requestfrom is used
* by the master
 */
void requestEvent() {
  Wire.write(sensorValue); // respond with message of 1 byte
  // as expected by master
}
