#include <StackArray.h>
//global variables use up 27 bytes before setup()
//sketch uses 1666 bytes before setup()
StackArray <double> stack;

double a = 2.0;
double b = 3.0;
double c = 4.0;
double d = 5.0;
double e = 2.0;
double f = 3.0;
double g = 4.0;
double h = 5.0;

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
  //3526 bytes used with the setup() included
  //global variables use 306 bytes with the setup() included
}

void loop() {
  

}
