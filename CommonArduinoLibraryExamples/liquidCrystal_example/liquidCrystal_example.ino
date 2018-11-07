#include <LiquidCrystal.h>

/*
 * this example assumes use of an atmega168
 * assumes use of a 20x4 LCD dusplay
 * shows use of an LCD display using 4 data lines
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
  /*
   * print dislplays text on the lcd display but has different
   * behavior when passed int or (un)signed char. In these cases
   * print will convert these to ASCII characters.
   * functionally print will perform this formatting and then
   * call the write function
   * TL:DR use if you want ascii
   */
   lcd.print(55);//output: "55"
   delay(2000);
  /*
   * write will not format data and will just pass the raw data
   * through. numbers will we interpreted as single ASCII characters
   * use for printing strings
   * TL:DR - use for sending raw bytes
   */
   lcd.write(55);//output: 7
   delay(2000);
   /*
    * liquid crystal allows for creation of custom characters.
    * limit of 8 5x8 pixel characters. character is specified
    * by an array of 8 bytes with each byte representing a row
    * five least significant bits determine pixel in row
    */
    byte arr[8] = {//snake?
      B10000,
      B11111,
      B00001,
      B11111,
      B10000,
      B11111,
      B00001,
      B11111,
    };
    lcd.createChar(1, arr);
    /*
     * use write as we dont want ascii. if parameter is not
     * a variable then cast as byte or compiler will give
     * an error.
     */
    lcd.write(byte(1));
    delay(5000);
    lcd.clear();//clears lcd display
     int i = 0;
}

void loop() {
  /*
   * displays numbers 0-9 left to right then prints them
   * right to left
   * 
   */
  if(i == 10){
    i = 0;
    if(i%2 == 0){
      lcd.rightToLeft();//write text right to left
      lcd.clear();//clear display
    }
    else{
      lcd.leftToRight();//write text left to right
      lcd.clear();//clear display
    }
  }

  lcd.print(i);//print i

  ++i;
}
