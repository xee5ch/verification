#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x5a"); 
  __asm volatile("ADD R6, R2, #0x272");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
