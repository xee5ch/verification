#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x15"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xa5"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x71"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x2c"); 
  __asm volatile("SUB R10, R5, #0xe3");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
