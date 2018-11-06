// Please note this is merely example code from the following website: https://ucexperiment.wordpress.com/2015/01/02/arduino-stack-painting/
// This is an example of stack painting
// All copyright to the orginal author, I do not take credit for this

void example(void) {
  char buffer[16]; //space will be reserved on the stack
 
  //
  //do something here. . .
  //
 
}
 
//result in this machine code:
 
;prologue
  PUSH r28         ;save registers on stack 
  PUSH r29 
  IN   r28,SPL     ;get stack pointer    
  IN   r29,SPH   
  SBIW r28,16      ;reserve 16 bytes space on stack
  OUT  SPH,r29     ;update new stack pointer
  OUT  SPL,r28 
 
;
;do something here. . .
;
 
;epilogue
  ADIW r28,16      ;remove the 16 bytes from the stack
  OUT  SPH,r29     ;restore stack pointer
  OUT  SPL,r28 
  POP  r29         ;restore registers from stack
  POP  r28 
  RET 
}