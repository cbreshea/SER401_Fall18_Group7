#include <Arduino.h>

//LEDs for bit manipulation demo
//LEDs are numbered right to left like bit order
#define LED0 14//PB0
#define LED1 15//PB1
#define LED2 16//PB2
#define LED3 17//PB3
#define LED4 18//PB4
#define LED5 19//PB5
#define LED6 9//PB6
#define LED7 10//PB7
#define LED_PORT PORTB

//7 Segment Display
#define DISPLAY_PORT PORTD

#define DELAYTIME 1000

#define toggleBit(sfr, bitNum) (_SFR_BYTE(sfr) ^= (1 << bitNum))

void setup() {
    DDRB |= 0b11111111;  //enable output on digital pins 8-13 for LEDs
    DDRD |= 0b11111111;  //enable output on digital pins 0-7 for 7 segment display
}

void loop() {

    //DEMO 1
    //display 1 on segment display
    DISPLAY_PORT = 0b00000110;

    //set each led on using set bit
    bitSet(LED_PORT, LED0);    //turn on LED0
    delay(DELAYTIME);

    bitSet(LED_PORT, LED1);    //turn on LED1
    delay(DELAYTIME);

    bitSet(LED_PORT, LED2);    //turn on LED2
    delay(DELAYTIME);

    bitSet(LED_PORT, LED3);    //turn on LED3
    delay(DELAYTIME);

    bitSet(LED_PORT, LED4);    //turn on LED4
    delay(DELAYTIME);

    bitSet(LED_PORT, LED5);    //turn on LED5
    delay(DELAYTIME);

    bitSet(LED_PORT, LED6);    //turn on LED6
    delay(DELAYTIME);

    bitSet(LED_PORT, LED7);    //turn on LED7
    delay(DELAYTIME);
    
    /*----------------------------------------------------------------------------------*/
    //DEMO 2
    //display 2 on segment display
    DISPLAY_PORT = 0b01011011;

    //turn each LED off with clear bit
    for(int i = 0; i < 8; ++i){
      bitClear(LED_PORT, i); //turn off LED
      delay(DELAYTIME);
    }

/*-----------------------------------------------------------------------*/
    //DEMO 3
    //display 3 on segment display
    DISPLAY_PORT = 0b01001111;

    //use toggle bit on each LED twice
    for(int i = 0; i < 8; ++i){
      toggleBit(LED_PORT, i); //toggle LED on
      delay(DELAYTIME);

      toggleBit(LED_PORT, i); //toggle LED off
      delay(DELAYTIME);
    }


/*-----------------------------------------------------------------------------------*/
    //DEMO 4
    //display 4 on segment display
    DISPLAY_PORT = 0b01100110;

    //use shift bit on each LED
    bitSet(LED_PORT, LED0);     //set first led to on
    delay(DELAYTIME);

    for(int i = 0; i < 8; ++i){
      LED_PORT = (LED_PORT << 1); //shift lit LED one left
      delay(DELAYTIME);
    }

}
