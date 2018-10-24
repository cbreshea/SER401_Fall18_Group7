int sensorPin = A0; //some sensor is outputing to this pin
uint16_t sensorValue = 0;//variable to store sensor value read

void setup() {
  Wire.begin(10);//join i2c bus with address #10
  Wire.onRequest(requestEvent);//register handler for event

}

void loop() {
  sensorValue = analogRead(sensorPin);//read analog signal from sensor
}

/*this function will execute whenever wire.requestfrom is used
* by the master
 */
void requestEvent() {
  Wire.write(sensorValue); // respond with message of 2 bytes as expected by master
}
