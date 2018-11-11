#include <LiquidCrystal.h>

/*
 * this example assumes use of an atmega168
 * assumes use of a 20x4 LCD dusplay
 * shows use of an LCD display using 4 data lines.
 * this example illustrates scrolling text, printing direction
 * and cursor display/movement
 */
const int rs= 12, en = 11, d4 = 5, d5 = 4, d6= 3, d7 = 2;
/*rs = pin connected to rs pin on lcd, selects registers
 * between instruction and data register
 * en = signals when data is ready to be read
 * rw, omitted as it is assumed to be tied to ground, signaling
 * we will only write to the display
 * d4-d7= pins that will serve as data lines for sending
 * data to be displayed
 */
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);

void setup() {
  lcd.begin(20,4);//initializes lcd interface, specifies columns then rows

      byte arr[8] = {//snake?
      B00000,
      B10001,
      B10001,
      B00000,
      B00100,
      B00000,
      B10001,
      B01110,
    };
    lcd.createChar(1, arr);
}

void loop() {
  lcd.home();//moves cursor to upper-left of lcd
  lcd.write(byte(1));

  lcd.autoscroll();//turn on autoscrolling
  for(int i = 1; i < 4; ++i){//print to each line
    lcd.setCursor(20,i);//move to next line
    lcd.write(byte(1));
  }
  lcd.noAutoscroll();//turns off autoscroll
  lcd.clear();//clear display

  lcd.rightToLeft();//output text right to left
  lcd.cursor(20,0);//move cursor to upper right of lcd
  lcd.print("test");

  for(int i = 1; i < 4; ++i){//print to each line
    lcd.setCursor(0,i);//move to next line
    lcd.write("test");
  }
  lcd.noAutoscroll();//turns off autoscroll
  lcd.clear();//clear display  
  
  lcd.leftToRight();//output text left to right

  lcd.home();//move cursor to upper left of lcd
  lcd.cursor();//display underscore cursor
  lcd.autoscroll();//turn on autoscroll
  delay(4000);

  lcd.noCursor();//hide underscore cursor
  lcd.blink();//turn on blinking block cursor
  delay(4000);

  lcd.noBlink();//turn off blinking block cursor
  lcd.noAutoscroll();//turn off autoscroll
}
