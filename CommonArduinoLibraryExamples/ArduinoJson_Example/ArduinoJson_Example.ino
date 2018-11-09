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

  //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  //This is all that is required to decode a json object

  StaticJsonDocument<200> Document2;

  //Creates Json string
  char jsonString[] = "{\"Animal\":\"Deer\",\"Health\":\"Fair\",\"Weight\":1351824120,\"Health\":\"Old\"}"; 

  //Decodes the Jsonstring
  JsonObject& jsonObject2 = jsonBuffer.parseObject(jsonString);
  checkDecode(jsonObject2);

}

//checks to see if the decoding was successful
bool checkDecode(JsonObject x){
  if(!x.success()) {
    return false;
  }
  return true;
}
