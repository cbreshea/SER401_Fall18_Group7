/*
 * File:   main.c
 * Author: Jared
 *
 * Created on October 25, 2018, 8:00 PM
 */


#include <avr/io.h>
#include <util/setbaud.h>

int main(void) {
    char serialChar;
    
    DDRB = 0xff;
    
    UBRR0H = UBRRH_VALUE; //defined in setbaud.h
    UBRR0L = UBRRL_VALUE; //defined in setbaud.h
  #if USE_2X
    UCSR0A |= (1 << U2X0);
  #else
    UCSR0A &= ~(1 << U2X0);
  #endif
                                    /* Enable USART transmitter/receiver */
    UCSR0B = (1 << TXEN0) | (1 << RXEN0);
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   /* 8 data bits, 1 stop bit */
    
            
    while (1) {
      loop_until_bit_is_set(UCSR0A, UDRE0);
      UDR0 = serialChar;
    }
}

void printString(const char myString[]) {
  uint8_t i = 0;
  while (myString[i]) {
      //Transmits the Byte
      loop_until_bit_is_set(UCSR0A, UDRE0);
      UDR0 = myString[i];
    i++;
  }
}

