#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x17"); 
  __asm volatile("ASR R5, R6, 9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
