#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0x6a"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x46"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x72"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x1a"); 
  __asm volatile("SUB R4, R7, #0x2ab");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
