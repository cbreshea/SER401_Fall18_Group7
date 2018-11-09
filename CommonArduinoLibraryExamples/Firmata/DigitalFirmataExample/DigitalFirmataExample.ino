// https://github.com/firmata/arduino/blob/master/examples/SimpleDigitalFirmata/SimpleDigitalFirmata.ino
// Simple digital Firmata
// Arduino/Genuino Uno board
#include <Firmata.h>

byte prevPin[TOTAL_PORTS];
byte prevPort[TOTAL_PORTS];

//This function will only send data when something changes this will prevent being sent too many messages
void output(byte portNum, byte portVal){
  if(prevPin[portNum] != portVal){
    Firmata.sendDigitalPort(portNum, portVal);
    prevPin[portNum] = portVal;
  }
}


//write callback function
void writeCallback(byte port, int val){
  //like int i
  byte i;
  byte currentVal;
  byte previousVal;

  if(port < TOTAL_PORTS && val != prevPort[port]){
    for(i = 0; i < 8; i++){
      currentVal = (byte) val & (1 << i);
      if(currentVal != previousVal){
        digitalWrite(i + (port * 8), currentVal);
      }
    }
    prevPort[port] = val;
  }
}

//loop 
void loop(){
byte i;
for(i = 0; i < TOTAL_PORTS; i++){
  output(i, readPort(i, 0xff));
}
  while(Firmata.available()){
    Firmata.processInput();
  }
}
