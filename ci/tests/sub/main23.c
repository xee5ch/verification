#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R3,#0"); 
  __asm volatile("add R3,R3,#0xae"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x3b"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0x16"); 
  __asm volatile("lsl R3,R3,#8"); 
  __asm volatile("add R3,R3,#0xec"); 
  __asm volatile("SUB R11, R3, #0x0da");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
