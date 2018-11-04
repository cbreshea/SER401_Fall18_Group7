#include <EEPROM.h>
#include <Arduino.h>

/*
 * This example shows how to retrieve values from EEPROM using get and read
 * while also showing how to iterate through EEPROM and to easily write 
 * objects to EEPROM. read can only retrieve a byte and cannot be easily used to retrieve objects, 
 * but get can retrieve multiple bytes so it can be used to easily retrieve
 * objects from EEPROM. the EEPROM length method allows for iteration over
 * EEPROM. put can write multiple bytes and so should be used to write
 * objects to EEPROM. put also uses the update method and so a byte will
 * only be written if the data to be written is different from the data
 * contained in EEPROM.
 */

byte = value;

struct testObject{//struct for illustrating how to retrieve objects from EEPROM
  char str[10];
  float f;  
};

void setup() {
  Serial.begin(9600);//start serial communication with baud rate of 9600
  while(!Serial){;}//wait for serial port to connect
  testObject var;//variable for struct
  var.str = "testString";
  var.f = 1.0;
  int i = 0;
  //fill EEPROM with testObjects
  for(i < EEPROM.length()){//iterate through EEPROM
    EEPROM.put(i, var);//put object in EEPROM
    i += sizeof(var);//move address to next byte after struct
  }
  Serial.println("EEPROM filled");

  //print out EEPROM contents using read
  Serial.println("EEPROM contents using read:");
  for(int j = 0; j < EEPROM.length(); ++j){
      Serial.println(EEPROM.read(j));
  }

  //print out EEPROM contents using get
  Serial.println("EEPROM contents using get:");
  i = 0;
  while(i < EEPROM.length()){
    EEPROM.get(i, var);
    Serial.println("Object " + std::tostring(i) + ":");
    //print expected fields of object
    Serial.println(var.str);
    Serial.println(var.f);
    i += sizeof(var);//move address to next byte after struct
  }
}

void loop() {
}
