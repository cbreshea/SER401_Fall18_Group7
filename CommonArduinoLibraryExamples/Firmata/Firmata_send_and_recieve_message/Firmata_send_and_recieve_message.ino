//Example shows how to send and recieve an analog message using Firmata
//https://www.arduino.cc/en/Reference/Firmata
//include Firmata library
#include <Firmata.h>

byte anaPin;

//write to analog pin
void writeAnalog(byte pin, int x){
  pinMode(pin, OUTPUT);
  analogWrite(pin, x);
}

//run
void setup(){
  //set firmware version
  Firmata.setFirmwareVersion(FIRMATA_MAJOR_VERSION, FIRMATA_MINOR_VERSION);
  //attach message
  Firmata.attach(ANALOG_MESSAGE, writeAnalog);
  //start
  Firmata.begin();
  
}

//run continously while there is still more to read
void loop(){
  while(Firmata.available()){
    Firmata.processInput();
  }
  for(anaPin = 0; anaPin < TOTAL_ANALOG_PINS; anaPin++){
    Firmata.sendAnalog(anaPin, analogRead(anaPin));
  }
}
