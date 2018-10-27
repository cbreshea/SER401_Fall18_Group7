#include <Wire.h>

void setup() {
  Wire.begin(10)//register as device 10 on i2c bus
  Wire.onReceive(receiveEvent)//register event handler
  Serial.begin(9600);//start serial for output
}

void loop() {
  int i = Wire.read();//receive byte as integer

  if(i > 64){
    Serial.println("Sensor value is high");//print string to terminal  
  }
  else{
    Serial.println("Sensor value is low");//print string to terminal
  }
}
