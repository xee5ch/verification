#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R0,#0xee"); 
  __asm volatile("ASR R6, R0, 25");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
