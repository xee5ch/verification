#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x4d"); 
  __asm volatile("mov R0,#0x02"); 
  __asm volatile("LSL R7, R12, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
