//Jared LeBlanc
//11/16/18
//Uses the installed package ESP8266 Community version 1.6

//This program connects an arduino board to the internet using an attached ESP8266 wifi module
//once connected to the wifi the board is setup nicely for any IoT project

#include "ESP8266WiFi.h"

void setup() {
  Serial.begin(9600); //begins serial connectiona the ATMEGA168 default buad rate of 9600

}

void loop() {
  if (Wifi.scanNetworks() == 1){
    Serial.println("Scan found networks!")
  }
  else{
    Serial.println("No networks are currently available")
  }
}
