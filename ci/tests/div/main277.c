#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0x3f"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xcb"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x34"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xfb"); 
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0xe4"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x4a"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x01"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xf7"); 
  __asm volatile("UDIV R11, R11, R9");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
