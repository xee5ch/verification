#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0x7a"); 
  __asm volatile("mov R12,#0x0a"); 
  __asm volatile("LSR R9, R3, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
