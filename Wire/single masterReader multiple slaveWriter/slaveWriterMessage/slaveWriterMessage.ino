int sensorPin = A0; //some sensor is outputing to this pin
uint8_t sensorValue = 0;//variable to store sensor value read

void setup() {
  Wire.begin(9);//join i2c bus with address #9
  Wire.onRequest(requestEvent);//register handler for event

}

void loop() {
  sensorValue = (analogRead(sensorPin) >> 2);//analog is 10-bit in length, shift right to reduce to 8-bit
}

/*this function will execute whenever wire.requestfrom is used
* by the master
 */
void requestEvent() {
  if(sensorValue < 128){
    Wire.write("ok"); // respond with message of 2 bytes as expected by master
  }
  else{
    Wire.write("na"); // respond with message of 2 bytes as expected by master
  }
}
