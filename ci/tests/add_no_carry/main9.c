#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R11,#0xcc"); 
  __asm volatile("ADD R1, R11, #0x009");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
