#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R1,#0xda"); 
  __asm volatile("ASR R11, R1, 7");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
