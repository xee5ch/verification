#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0x46"); 
  __asm volatile("mov R12,#0x01"); 
  __asm volatile("LSR R9, R2, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
