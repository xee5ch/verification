#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xf9"); 
  __asm volatile("LSL R9, R1, 21");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
