#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R6,#0x71"); 
  __asm volatile("ADCS R12, R6, #0xcb");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
