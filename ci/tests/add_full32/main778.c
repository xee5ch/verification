#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0xc3"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x14"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xf3"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x67"); 
  __asm volatile("ADC R4, R7, #0xd8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}