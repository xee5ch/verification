#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0x3a"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xeb"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x5b"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0xc0"); 
  __asm volatile("REV R8, R11");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
