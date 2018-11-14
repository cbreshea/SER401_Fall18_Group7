//Flash memory is where the arduino is sketch is stored
//SRAM (static random access memory) is where the sketch creates and manipulates variables
//EEPROM is memory space that programmers use for long term information
#include <StackArray.h>
const String msg = "Arduino is cool!";

StackArray<char> stack;



//Depending on what chip/board you are using you can use up a lot of space very quickly

//This puts 33 bytes into SRAM
char message[] = "I support the Cape Wind project.";

void setup() {
  //start communication
  Serial.begin(9999);

  Serial.println("Here is a string: " + msg);

  //push the message onto the stack
  for(int i = 0; i < msg.length(); i++){
    stack.push(msg.charAt(i));
  }

}
void loop(){ }
