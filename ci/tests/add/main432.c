#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0x66"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x3e"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xab"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x2b"); 
  __asm volatile("ADDS R9, R12, #0x98");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
