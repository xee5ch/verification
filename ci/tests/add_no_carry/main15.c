#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0x68"); 
  __asm volatile("ADD R8, R5, #0x93");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
