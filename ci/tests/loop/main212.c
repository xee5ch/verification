#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5, #0"); 
  __asm volatile("outer_loop:"); 
  __asm volatile("mov R1, #100"); 
  __asm volatile("loop:"); 
  __asm volatile("add R1,R1,#-1"); 
  __asm volatile("cmp R1,#0"); 
  __asm volatile("bne loop"); 
  __asm volatile("add R5,R5,#1"); 
  __asm volatile("cmp R5,#0x100"); 
  __asm volatile("blo outer_loop"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
