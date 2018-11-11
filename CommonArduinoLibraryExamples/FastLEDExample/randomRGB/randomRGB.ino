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

// code to set colors together and indovodually 
// makes use of random number from math component of library
// uses created function 

#define ledNum 60
#define pin 9

CRGB ledArray[ledNum];
int num = random8(); // random number between 0 and 255
int choose = random8(1,5); // random number between 1 and 4

// function to set two values random and one fixed
int setColor(int newRed, int newGreen, int newBlue){

  newRed = num;
  newGreen = choose;
  newBlue = 200;
}


void setup() {
  // put your setup code here, to run once:
  LEDS.addLeds<TM1803, pin, GRB>(ledArray, ledNum); 
  

}

void loop() {
  // put your main code here, to run repeatedly:
   for(int i = 0; i < ledNum; i++){
      if(choose == 1){
        ledArray[i].setRGB( 255, 68, 221);
      }else if(num == 2){
        ledArray[i].setRGB(224, 187, 255);
      }else if(num == 3){
        ledArray[i].setRGB(0, 0, 0);
      }else{
        int red = ledArray[i].r;
        int green = ledArray[i].g;
        int blue = ledArray[i].b;
        setColor(red, green, blue);
      }
   }

   LEDS.show();
}
