#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0xe8"); 
  __asm volatile("mov R1,#0x1e"); 
  __asm volatile("LSL R2, R2, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
