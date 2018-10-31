/*
 * File:   main.c
 * Author: Jared
 *
 * Created on October 25, 2018, 8:00 PM
 */

#include <avr/io.h>

   #define F_CPU 4000000

static void
uart_9600(void)
{
   #define BAUD 9600
   #include <util/setbaud.h>
UBRR0H = UBRRH_VALUE;
UBRR0L = UBRRL_VALUE;
   #if USE_2X
   UCSRA |= (1 << U2X);
   #else
   UCSR0A &= ~(1 << U2X0);
   #endif
   UCSR0B = (1 << TXEN0) | (1 << RXEN0);
   UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);   /* 8 data bits, 1 stop bit */
   }

int main(void) {
    uart_9600();
    char serialChar;
    
    DDRB = 0xff;
            
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
