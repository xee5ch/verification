#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x8b"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xd6"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x57"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xc4"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0x17"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x20"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xb8"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xb4"); 
  __asm volatile("ADD R11, R5, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
