// simple example blink sketch to demonstrate how to compile using the cli
// 
void setup() {
   // built in led more to be output
   pinMode(LED_BUILTIN, OUTPUT);

}

void loop() {

   digitalWrite(LED_BUILTIN, LOW);
   delay(3000);
   digitalWrite(LED_BUILTIN, HIGH);
   delay(3000);


}
