#include <Stepper.h>

#define STEPS 100
#define PIN1 6
#define PIN2 7
#define RPMS 30

/*
 * This program shows how to use serial communication to move
 * a stepper motor. communication is expected to be of the form
 * s(number of steps) eg: s100
 * 
 * constructor for creating an instance of stepper class.
 * can alternatively add two more params for stepper motors
 * that require four pins. Stepper(steps,pin1,pin2,pin3,pin4)
 */
Stepper stepper(STEPS, PIN1, PIN2);
char c;
int s = 0;

void setup() {
  stepper.setSpeed(RPMS);//function for setting the speed the motor will turn at when stepping
  Serial.begin(9600);start serial
}

void loop() {
  if(Serial.available()){//if serial data is received
    c = Serial.read();//read next byte received
    if(c == 115 | c == 83){//character received is 's'
      s = Serial.parseInt();//read number of steps to take
      stepper.step(s);//turn motor 's' steps
    }
  }
}
