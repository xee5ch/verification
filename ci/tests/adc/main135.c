#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R10,#0x14"); 
  __asm volatile("mov R0,#0x83"); 
  __asm volatile("ADCS R4, R10, R0");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
