#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0x65"); 
  __asm volatile("mov R11,#0x0e"); 
  __asm volatile("LSL R12, R1, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
