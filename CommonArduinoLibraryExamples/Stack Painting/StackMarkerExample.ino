// Please note this is merely example code from the following website: https://ucexperiment.wordpress.com/2015/01/02/arduino-stack-painting/
// This is an example of stack painting
// All copyright to the orginal author, I do not take credit for this

#define STACK_MARKER 0xfe
extern uint8_t _end, __stack;
extern char *__bss_end;
 
void __attribute__ ((naked, section (".init1"))) StackPaint(void) {
  uint8_t *p = (uint8_t *)&__bss_end;
   
  while(p <= &__stack)
    *p++ = STACK_MARKER;
}
 
uint16_t StackUsed(void) {
    const uint8_t *p = (uint8_t *)RAMEND;
    uint16_t c = 0;
     
    while(*p != STACK_MARKER && p >= (uint8_t *)&__bss_end) {
        p--;
        c++;
    }
    return c;
}
 
extern "C" { 
  uint16_t Summation(uint16_t n) {
    asm volatile (
      "sbiw r24,0x00   \n" //test for n==0
      "breq 1f         \n" //n==0
      "add r30,r24     \n" //n = n +1 (word addition) 
      "adc r31,r25     \n"
      "sbiw r24,0x01   \n" //n = n - 1
      "call Summation  \n" //recurse
      "1: movw r24,r30 \n" //save n for return from subroutine
      "ret             \n"
      : :
    );
  /*
  //the above is the same as the following c code, however
  //optimization removes the recursion hence, we coded the 
  //function inline in assembly
  if (n > 0)
    n = n + Summation(n - 1);
  return (n);
  */
  }
}
 
void setup(void) {
  uint16_t c;
     
  Serial.begin(19200);
  asm(
    "push r30 \n"    //save r30/31 on stack
    "push r31 \n"
    "ldi r30,0x00\n" //zeroize r30/31 for use in recursion
    "ldi r31,0x00\n"
  );
  c = Summation(40);
  asm(
    "pop r31 \n" //restore r30/31
    "pop r30 \n"
  );
  Serial.print("Summation: "); Serial.println(c);
  c = StackUsed();
  Serial.print("Stack Used: "); Serial.println(c);
}
 
void loop(void) { }