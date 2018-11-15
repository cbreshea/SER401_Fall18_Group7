#include <TFT.h>
#include <SPI.h>
#include <SD.h>

/*
 * this example shows how to draw shapes and display images
 * from the sd card in a TFT display
 * this example assumes use of arduino uno and arduino tft screen
 */

//defines for pin usage
#define cs 10
#define dc 9
#define rst 8
#define sd 4

TFT screen = TFT(cs, dc, rst);//create instance of TFT

PImage logo;

void setup() {
  screen.begin();//initialize screen
  screen.background(255,255,255);//set background to white
  screen.stroke(0,0,0);//set stroke color to black
  SD.begin(sd)//connect to sd card
  logo = screen.loadImage("logo.bmp");//load image file from root of sd card
}

void loop() {
  if(logo.isValid() == false){//check if image loaded
    return;                   //stop execution if image didn't load
  }
  delay(5000);
  
  //draw smiley with dots
  //left eye
  screen.point(112,60);
  screen.point(112,61);

  //right eye
  screen.point(114,60);
  screen.point(114,61);

  //mouth
  screen.point(110,64);
  screen.point(110,65);
  screen.point(110,66);
  screen.point(111,66);
  screen.point(112,66);
  screen.point(113,66);
  screen.point(114,66);
  screen.point(115,66);
  screen.point(116,64);
  screen.point(116,65);
  screen.point(116,66);
  delay(5000);
  
  //draw circles
  screen.fill(255,0,0);//set fill color of shapes to red
  screen.circle(10,70,10)//draw circle
  delay(5000);
  
  screen.stroke(0,0,255);//set line color to blue
  screen.circle(40,70,10)//draw circle
  delay(5000);
  
  //draw rectangle
  screen.noFill();//stop fill for shapes drawn
  screen.stroke(0,0,0);//set outline of shapes to black
  screen.rect( 50, 0, 20, 20);
  delay(5000);
  
  //draw lines
  screen.stroke(0,255,0);//set line color to green
  scree.line(60,50,100,50);//draw line
  
  screen.stroke(255,0,0);//set line color to red
  screen.line(100,50,100,90);//draw line
  
  screen.stroke(0,0,255);//set line color to blue
  screen.line(60,50,100,90);//draw line
  
  screen.stroke(0,0,0);//set line color to black
  delay(5000);
  
  //display image from sd card
  screen.image(logo, 0, 0);
  delay(5000);
  
  screen.background(255,255,255);//clear screen
}
