#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("ADD R9, R15, #0x3f");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}