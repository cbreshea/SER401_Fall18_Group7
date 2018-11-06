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

// simple example using FastLED library to turn a single pixel white from a set of leds

#define pin 3
#define ledNum 60
CRGB ledArray[ledNum];

void setup() {
  // put your setup code here, to run once:
  // set up LEDS
   FastLED.addLeds<TM1803, pin, RGB>(ledArray, ledNum);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < ledNum; i++) {
      // turn current led white
      ledArray[i] = CRGB::White;

      // display led
      FastLED.show();
      // reset led back to black
      ledArray[i] = CRGB::Black;
   }

}
