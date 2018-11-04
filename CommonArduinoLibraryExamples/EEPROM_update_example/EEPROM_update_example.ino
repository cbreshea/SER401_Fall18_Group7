#include <EEPROM.h>

/*
 * This example shows how to store values using EEPROM.
 * In this example an analog sensor, LED and button are used.
 * When the button is pressed, the LED will turn on and
 * the value stored in EEPROM will be updated if the value from the sensor
 * is different than what is stored.
 */

int address = 0;//current address for EEPROM
const int buttonin = 2;//pin for button
const int ledPin = 10;//pin for LED

int buttonState = 0;//variable for tracking if button is pressed

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  int value = analogRead(0) >> 2;//read value from analog sensor
  //value from sensor is 10 bits but EEPROM only allows 8 bits, shift to minimize precision lost
  buttonState = digitalRead(buttonPin);//read if button is pressed

  if(buttonState == HIGH){
    EEPROM.update(address,value);//store value from sensor in EEPROM if read value
                                  //is different from stored value
    digitalWrite(ledPin, HIGH);//turn on LED
  }
  else{
    digitalWrite(ledPin, LOW);//turn off LED
  }
}
