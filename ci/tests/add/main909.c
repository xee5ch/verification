#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R9,#0"); 
  __asm volatile("add R9,R9,#0x94"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x27"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0xad"); 
  __asm volatile("lsl R9,R9,#8"); 
  __asm volatile("add R9,R9,#0x92"); 
  __asm volatile("ADD R4, R9, #0x1bf");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
