#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0x96"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xfd"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x35"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xd1"); 
  __asm volatile("mov R6,#0"); 
  __asm volatile("add R6,R6,#0x94"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x66"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xe4"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x73"); 
  __asm volatile("UDIV R3, R10, R6");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
