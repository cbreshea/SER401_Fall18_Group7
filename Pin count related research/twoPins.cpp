 // PLEASE NOTE, THIS CODE WAS GOT FROM https://playground.arduino.cc/Main/LEDHeartbeat?action=sourceblock&num=1

 // THIS WAS USED TO GET AN EXAMPLE AND PUSH THE GROUPS UNDERSTANDING OF PIN COUNTS FORWARD

 // I DO NOT OWN THIS, I ADDED SOME COMMENTS IN TO GIVE INSIGHT

 // ALL COPYRIGHT TO THE APPRORIATE PARTIES

 // Define these at the top of your sketch.

 // Here we are defining that we are using two pins. Since the user defines two pins we are recommending the lowest board. 
#define LEDBLINK_PIN    13    // I/O pin connected to the LED.
#define LEDBLINK_MS     1000  // Blink rate (in milliseconds).

void setup()
{
  // For ledBlink(), set LEDBLINK_PIN to output.
  pinMode(LEDBLINK_PIN, OUTPUT);
}

void loop()
{
  // Blink the LED to let the user know we are still alive.
  ledBlink();

  // Do something. 
}

//
// LED Heartbeat routine by Allen C. Huffman (www.appleause.com)
//
void ledBlink()
{
  static unsigned int  ledStatus = LOW;  // Last set LED mode.
  static unsigned long ledBlinkTime = 0; // LED blink time.

  // LED blinking heartbeat. Yes, we are alive.
  // For explanation, see:
  // http://playground.arduino.cc/Code/TimingRollover
  if ( (long)(millis()-ledBlinkTime) >= 0 )
  {
    // Toggle LED.
    ledStatus = (ledStatus==HIGH ? LOW : HIGH);

    // Set LED pin status.
    digitalWrite(LEDBLINK_PIN, ledStatus);

    // Reset "next time to toggle" time.
    ledBlinkTime = millis()+LEDBLINK_MS;
  }
} // End of ledBlink()