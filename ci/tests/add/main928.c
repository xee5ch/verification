#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0"); 
  __asm volatile("adds r0,r1,#0xab"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0x3f"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x37"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x7b"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0xaa"); 
  __asm volatile("mov R4,#0"); 
  __asm volatile("add R4,R4,#0x2f"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0x25"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xa8"); 
  __asm volatile("lsl R4,R4,#8"); 
  __asm volatile("add R4,R4,#0xcd"); 
  __asm volatile("ADDS R3, R8, R4");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
