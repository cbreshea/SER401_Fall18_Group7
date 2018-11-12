#include <TFT.h>
#include <SPI.h>

//defines for pin usage
#define cs 10
#define dc 9
#define rst 8

/*
 * This example is a combination of the arduino examples:
 * TFTDisplayText: https://www.arduino.cc/en/Tutorial/TFTDisplayText
 * TFTGraph: https://www.arduino.cc/en/Tutorial/TFTGraph
 * this example show how to make use of an arudino tft screen
 * with an arduino uno and the SPI library to display the value
 * read from an analog sensor and graph it.
 * this example is meant for use with an arduino uno and
 * arduino tft display.
 * size is 160 pixels wide, 128 pixels tall
 * default orientation is wider than taller, top being on the
 * same side as the SD card
 * pins to connect to on arduino uno
 * +5V: +5V
 * MISO: pin 12
 * SCK: pin 13
 * MOSI: pin 11
 * LCD CS: pin 10
 * SD CS: pin 4
 * D/C: pin 9
 * RESET: pin 8
 * BL: +5V
 * GND: GND
 */

char printoutArr[4];
int xPos = 0;//var for tracking position of newest bar in graph

TFT screen = TFT(cs, dc, rst);//create instance of TFT
 
void setup() {
  screen.begin();//initialize screen
  screen.background(255,255,255);//set background to white
  screen.stroke(0,0,0);//set color of lines to black
  screen.setTextSize(1);//set size of text, 1 = 10px
  screen.text("Value: ",0,0);//displays text at coordinates 0,0
  screen.setTextSize(2);//set text size to 20px
}

void loop() {
  int val = analogRead(A0);//read value from sensor
  int graphHeight = map(val, 0, 1023, 0, screen.height()-10);//map value from sensor to graph dimensions
  String str = String(val);//convert value to string
  str.toCharArray(printoutArr,4);//convert string to char array

  screen.stroke(0,0,255);//set color to blue
  screen.line(xPos, screen.height() - graphHeight, xPos, screen.height()-10);//draw bar for graph
  
  screen.stroke(0,0,0);//set text color to black
  screen.text(printoutArr, 0, 10);//display value from sensor
  delay(250);//delay for drawing
    
  //erase value written from screen
  screen.stroke(255,255,255);//set text color to white
  screen.text(printoutArr, 0, 10);//write over previous value with white

  if(xPos >= 160){//check if we have reached end of screen
    xPos = 0;//reset variable
    screen.background(255,255,255);//set background to white, clears screen
    //re-display text on screen
    screen.stroke(0,0,0);//set color of lines to black
    screen.setTextSize(1);//set size of text, 1 = 10px
    screen.text("Value: ",0,0);//displays text at coordinates 0,0
    screen.setTextSize(2);//set text size to 20px
  }
  else{
    xPos++;//move to next position
  }
  delay(16);
}
