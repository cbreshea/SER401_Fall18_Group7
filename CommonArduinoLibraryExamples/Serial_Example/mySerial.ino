#include <SoftwareSerial.h>

//Please note some of this code came from the Arduino website https://www.arduino.cc/en/Tutorial/SoftwareSerialExample
// All copyright to the appropiate parties

SoftwareSerial mySerial(10, 11); // RX, TX

void setup() {
  // Open serial communications and wait for port to open:
  Serial.begin(57600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Hello!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(4800);
  mySerial.println("Begin reading 4800");
  mySerial.println("Now leaving setup");
}

void loop() { 
  if (mySerial.available()) {
    mySerial.println("Now in loop");
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}