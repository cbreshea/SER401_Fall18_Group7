/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>

/*End of auto generated code by Atmel studio */

#include <StackArray.h>
//Beginning of Auto generated function prototypes by Atmel Studio
//End of Auto generated function prototypes by Atmel Studio


//global variables use up to 27 bytes and sketch uses 1666 bytes before setup()
StackArray <byte> stack;

byte a = 1;
byte b = 12;
byte c = 13;
byte d = 19;
byte e = 23;
byte f = 56;
byte g = 99;
byte h = 66;

void setup() {
  // put your setup code here, to run once:
stack.push(a);
  stack.push(b);
  stack.push(c);
  stack.push(d);
  stack.push(e);
  stack.push(f);
  stack.push(g);
  stack.push(h);
    Serial.print("hi");
    //sketch uses 3442 bytes and global variables used 306 bytes
}

void loop() {
  // put your main code here, to run repeatedly:

}
