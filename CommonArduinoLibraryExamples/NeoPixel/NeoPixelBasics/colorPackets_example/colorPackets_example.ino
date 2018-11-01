//https://learn.adafruit.com/adafruit-neopixel-uberguide/arduino-library-use
//https://www.youtube.com/watch?v=KBKcZLF59kY
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
  //color packets, allow you to predefine colors based on brightness
  uint32_t red = strip.Color(255, 0, 0);
  uint32_t green = strip.Color(0, 255, 0);
  uint32_t blue = strip.Color(0, 0, 255);
  strip.setPixelColor(0, green);
  //show solid green led
  strip.show();
}
