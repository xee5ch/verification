#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0x2b"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xa4"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xb1"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x80"); 
  __asm volatile("SXTB R5, R12, ror #8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}