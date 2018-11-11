#include <Firmata.h>
//Servo allows us to control RC servo motors
#include <Servo.h>

Servo servos[MAX_SERVOS];
byte servoPin[TOTAL_PINS];
byte count = 0;


//write callback
void writeCallback(byte pin, int val){
  if(IS_PIN_DIGITAL(pin)){
    servos[servoPin[pin]].write(val);
  }
}

//rest count to 0
void reset(){
  count = 0;
}

void setup(){
  byte pin;
  Firmata.begin(57000);
  reset();

  //here we will attach the servos from the first digital pin to the max # of servos
  for(pin = 0; pin < TOTAL_PINS; pin++){
    if(IS_PIN_DIGITAL(pin)){
      if(count < MAX_SERVOS){
        servoPin[pin] = count;
        servos[servoPin[pin]].attach(PIN_TO_DIGITAL(pin));
        count++;
      }
    }
  }
}

//loop until max # is reached
void loop(){
  while(Firmata.available())
  Firmata.processInput();
}
