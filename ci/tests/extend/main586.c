#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#4"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R1,#0"); 
  __asm volatile("add R1,R1,#0x84"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x8d"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x77"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0xe3"); 
  __asm volatile("SXTB R10, R1");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
