#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r0,#0xab"); 
  __asm volatile("mov r0,#5"); 
  __asm volatile("lsrs r0,#1"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0x70"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xdc"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x47"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x69"); 
  __asm volatile("MOV R7, R12");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}