/*program transfers the values of sequencial numbers squared 10 times to the slave from the Arduino(master)*/

#include <SPI.h> /*SPI stands for serial peripheral interface
                   To work requires 4 signal lines:
                      1. Serial clock (SCK)
                      2. Master in, slave out (MISO)
                      3. Master out, slave in (MOSI)
                      4. Slave select (SS)
                      https://i.stack.imgur.com/6cTce.png
                      */                   
                      
void setup() {
  pinMode(SS, OUTPUT); //sets as output
  SPI.begin(); //initializes SPI
  SPI.setBitOrder(MSBFIRST); //serial communication will be read starting with the most significant bit
}

void loop() {
  int iSquared; //to hold the value of the squared result
  for(int i; i < 10; i++){
    digitalWrite(SS, LOW); //slave is set low, begins waiting for transfer
    iSquared = i + i; //sets equal to i^2
    SPI.transfer(iSquared); //transfers the value of i^2
    digitalWrite(SS, HIGH); //stops slave from waiting for further transfer
  }
}
