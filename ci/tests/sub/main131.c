#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0xc9"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xc5"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xfe"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xf1"); 
  __asm volatile("SUB R10, R8, #0x95a");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
