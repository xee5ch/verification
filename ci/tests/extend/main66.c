#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xba"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x89"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x82"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xdd"); 
  __asm volatile("SXTB R2, R8");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
