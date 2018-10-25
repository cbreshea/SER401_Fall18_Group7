//include to use built in functions
#include <Adafruit_NeoPixel.h>
//Number of NeoPixels in use
#define PIXEL_COUNT 1
//IO pin connected to NeoPixel
#define PIXEL_PIN 7

//declare object strip, include pixel count pixel pin
//for this example will be using NEO_RGB and NEOKHZ800
Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, NEO_RGB + NEO_KHZ800);

//
void setup(){
  //Initializes the digitial pin the neopixel is connected to
  strip.begin();
  //turn neopixel once it gets through
  strip.clear();
   strip.show();
}
/*
 * This very simple program will loop through red, blue, and green
 * for 1 second each continuously
 */
void loop(){
  //first arg is which NeoPixel we are talking to
  //second is brightness for red in range from 0-255
  //third is brightness for green in range from 0-255
  //fourth is brightness for blue in range from 0-255
  //here we will set the color (red)
  strip.setPixelColor(0, 255, 0, 0);
  //here we will show the color
  strip.show();
  //How long the color will show on the strip in milliseconds
  delay(1000);
  
  //set color to green
 strip.setPixelColor(0, 0, 0, 255);
 //show color
  strip.show();
  //show color for 1000 milliseconds
  delay(1000);

  //set color to blue
  strip.setPixelColor(0, 0, 0, 255);
  //show color
  strip.show();
  //show color for 1000 milliseconds
  delay(1000);
}
