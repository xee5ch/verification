#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x3d"); 
  __asm volatile("LSR R7, R6, 26");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
