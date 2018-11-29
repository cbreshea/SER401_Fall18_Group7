// This will see how much free memory is left in the system. 
// Sample code for larger project, this is just a snippet
// Some of this code is from the Ardunio Website. 
#if (ARDUINO >= 100)
#include <Arduino.h>
#include <WProgram.h>
extern unsigned int __heap_start;
extern void *__brkval;

struct __freelist {
  size_t sz;
  struct __freelist *nx;
};

/* The head of the free list structure */
extern struct __freelist *__flp;

// Finds the size
int freeListSize() {
  struct __freelist* current;
  int total = 0;
  for (current = __flp; current; current = current->nx) {
    total += 2; /* Add two bytes for the memory block's header  */
    total += (int) current->sz;
  }
  return total;
}
int freeMemory() {
  int free_memory_avail;
  if ((int)__brkval == 0) {
    free_memory_avail = ((int)&free_memory_avail) - ((int)&__heap_start);
  } else {
    free_memory_avail = ((int)&free_memory_avail) - ((int)__brkval);
    free_memory_avail += freeListSize();
  }
  return free_memory_avail;
}