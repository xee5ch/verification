#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0x69"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xd1"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x44"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xd1"); 
  __asm volatile("ADD R5, R8, #0xa8c");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
