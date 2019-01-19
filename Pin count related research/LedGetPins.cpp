
/*
  Blink

  Turns an LED on for one second, then off for one second, repeatedly.

  **PLEASE READ**
  
  THIS IS EXAMPLE CODE, I AM NOT TAKING CREDIT FOR THIS. 
  THIS EXAMPLE IS MERELY TO BE USED TO PUSH THE GROUP'S
  KNOWLEDGE OF THE PROJECT FORWARD. I HAVE ADDED MY OWN SNIPPET OF 
  CODE TO SHOW A TEST WHICH WILL BE COMMENTED BELOW. 

  ALL COPYRIGHT TO THE RESPECTED PARTIES

  Most Arduinos have an on-board LED you can control. On the UNO, MEGA and ZERO
  it is attached to digital pin 13, on MKR1000 on pin 6. LED_BUILTIN is set to
  the correct LED pin independent of which board is used.
  If you want to know what pin the on-board LED is connected to on your Arduino
  model, check the Technical Specs of your board at:
  https://www.arduino.cc/en/Main/Products

  modified 8 May 2014
  by Scott Fitzgerald
  modified 2 Sep 2016
  by Arturo Guadalupi
  modified 8 Sep 2016
  by Colby Newman

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Blink
*/

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second

// THE FOLLOWING I ADDED TO SHOW THE NUMBER OF PINS NEEDED
Serial.print("number of digital pins: ");
Serial.print(NUM_DIGITAL_PINS);
Serial.print("number of analog inputs: ");
Serial.print(NUM_ANALOG_INPUTS);
}