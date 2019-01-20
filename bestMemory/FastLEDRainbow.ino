#include <noise.h>
#include <bitswap.h>
#include <fastspi_types.h>
#include <pixelset.h>
#include <fastled_progmem.h>
#include <led_sysdefs.h>
#include <hsv2rgb.h>
#include <fastled_delay.h>
#include <colorpalettes.h>
#include <color.h>
#include <fastspi_ref.h>
#include <fastspi_bitbang.h>
#include <controller.h>
#include <fastled_config.h>
#include <colorutils.h>
#include <chipsets.h>
#include <pixeltypes.h>
#include <fastspi_dma.h>
#include <fastpin.h>
#include <fastspi_nop.h>
#include <platforms.h>
#include <lib8tion.h>
#include <cpp_compat.h>
#include <fastspi.h>
#include <FastLED.h>
#include <dmx.h>
#include <power_mgt.h>

// This example provides a rainbow pattern to display in the led

#define ledNum 26 // number of leds
#define pin 7

CRGB ledArray[ledNum];
float hueOffset = 0;
float rainbowIterator  = 0.01;
float stopsNum = round(255/ledNum); // number of stops in the hue wheel 

void setup() {
  // put your setup code here, to run once:
  LEDS.addLeds<TM1803, pin, GRB>(ledArray, ledNum); //led initalizer

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < ledNum; i++){
    ledArray[i] = CHSV(i*stopsNum*hueOffset, 255, 255);
    hueOffset = hueOffset + rainbowIterator;
    // if gone through all hues 
    if(hueOffset >= 255){
      hueOffset = 0;
    }
  }

  LEDS.show();

}
