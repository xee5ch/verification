#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R2,#0"); 
  __asm volatile("add R2,R2,#0x86"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x2f"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x78"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0xe1"); 
  __asm volatile("SUB R11, R2, #0x42");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
