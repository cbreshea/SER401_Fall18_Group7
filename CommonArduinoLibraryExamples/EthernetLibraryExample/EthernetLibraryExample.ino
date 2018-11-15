#include <Ethernet.h>
#include <SPI.h>

// display Link status 

void setup() {
  // put your setup code here, to run once:
  Ethernet.init(10); // configure CS pin for Arduino shield
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
   auto linkStat = Ethernet.linkStatus(); // get status of ethernet 
   Serial.print("Link Status: ");
   if(linkStat == LinkON){
      Serial.print("Link is on");
   }else if(linkStat == LinkOFF){
    Serial.print("Link if off");
   }else{
    Serial.print("Link status unknown");
   }
}
