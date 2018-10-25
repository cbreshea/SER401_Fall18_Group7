/*
 * The Servo library gives the arduino to the rotate servos between 0 and 180 degrees.
 * Supports up to 12 motors
 * Disables Pulse Width Modulation
 */

#include <Servo.h>

Servo servo; //Instanciates new servo object

void setup() {
  servo.attach(10); //links servo on pin 3 and the servo object
}

void loop() {
  servo.write(analogRead(0));  //Moves the servo to the location denoted by the analog sensor
}
