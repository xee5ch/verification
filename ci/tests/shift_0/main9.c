#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x00"); 
  __asm volatile("ASR R11, R6, 32");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
