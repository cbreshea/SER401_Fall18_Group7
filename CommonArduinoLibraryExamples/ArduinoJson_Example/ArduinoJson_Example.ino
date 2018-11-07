//Encoding JSON
//Using ArduinoJson version 6.5
  //in version 5 and prior DynamicJsonDocument is instead DynamicJsonBuffer

/*
 * What is being encoded:
 * 
 * "Animal": "Deer",
 * "Health": "Fair",
 * "Weight": 230,
 * "Age": "Old"
 */

#include <ArduinoJson.h>

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  //This is all that is required to encode a json object
  //This does nothing with the object but this could be transmitted to computer over serial and used for something like logs or saves
  DynamicJsonDocument buffer;
  JsonObject& jsonObject = buffer.createObject();

  jsonObject["Animal"] = "Deer";
  jsonObject["Health"] = "Fair";
  jsonObject["Weight"] = 230;
  jsonObject["Age"] = "Old";

}
