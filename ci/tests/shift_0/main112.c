#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0x82"); 
  __asm volatile("mov R5,#0x05"); 
  __asm volatile("LSR R4, R8, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
