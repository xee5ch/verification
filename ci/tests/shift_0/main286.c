#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R4,#0x96"); 
  __asm volatile("mov R5,#0x20"); 
  __asm volatile("LSR R5, R4, R5");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
