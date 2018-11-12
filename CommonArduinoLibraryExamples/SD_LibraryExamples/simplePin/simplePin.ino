#include <SD.h>

// basic functions using the SD Library to work with SD cards

int pin = 13; // choose SPI pin 10-13

void setup() {
  // put your setup code here, to run once:
  initialize();
  // create a directory
  SD.mkdir("testDirectory/hello.text");
  // open file
  SD.open("testDirectory/hello.text");
  // write to file
  SD.open("testDirectory/hello.text").write("Hello World");
  // read the file 
  SD.open("testDirectory/hello.text").read();
  // open file directly without directory
  openSingle();

}

void loop() {
  // put your main code here, to run repeatedly:
  

}

void initialize(){
  pinMode(pin, OUTPUT);
}

void openSingle(){
  File myFile = SD.open("testFile.txt", FILE_WRITE);
  myFile.close();

  // Check if file exist 
  if (SD.exists("testFile.txt")) {
    Serial.println("File found.");
  } else {
    Serial.println("Error. File not found.");
  }
}
