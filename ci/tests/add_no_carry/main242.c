#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0xa7"); 
  __asm volatile("ADDS R8, R8, #0xbb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
