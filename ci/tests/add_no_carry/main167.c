#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R12,#0x68"); 
  __asm volatile("ADDS R7, R12, #0x96");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
