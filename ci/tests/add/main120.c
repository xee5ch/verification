#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0x16"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x24"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xd3"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x18"); 
  __asm volatile("ADD R10, R10, #0x68");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}