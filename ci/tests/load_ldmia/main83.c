#include <stdlib.h>
void dump(void){
  #ifndef NOPRINT
  #ifdef KLEE
  inception_dump_stack(0,2050);
  #endif
  #endif
}
__attribute__((naked))
void main(void){
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("add r1,r1,#1025");
  __asm volatile("mov r2,sp");
  __asm volatile("loop:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("add r2,#1025");
  __asm volatile("lsl r2,#2");
  __asm volatile("add r2,sp");
  __asm volatile("loop2:");
  __asm volatile("str r1,[r2]");
  __asm volatile("sub r0,r0,#1");
  __asm volatile("add r1,r1,#1");
  __asm volatile("sub r2,r2,#4");
  __asm volatile("cmp r0,#-1024");
  __asm volatile("bge loop2");
  __asm volatile("mov r0,#0");
  __asm volatile("mov r1,#0");
  __asm volatile("mov r2,#0");
  __asm volatile("mov R0,sp"); 
  __asm volatile("mov R1,#0"); 
  __asm volatile("add R1,R1,#0x27"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x4e"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x53"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0xbe"); 
  __asm volatile("mov R6,#0"); 
  __asm volatile("add R6,R6,#0x2a"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xb0"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0xcc"); 
  __asm volatile("lsl R6,R6,#8"); 
  __asm volatile("add R6,R6,#0x72"); 
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0xc1"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xc4"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x57"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x8b"); 
  __asm volatile("mov R8,#0"); 
  __asm volatile("add R8,R8,#0x00"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x00"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x00"); 
  __asm volatile("lsl R8,R8,#8"); 
  __asm volatile("add R8,R8,#0x5f"); 
  __asm volatile("LDMIA R0!, {R6}");
  #ifndef KLEE
  __asm volatile("stop: b stop");
  #else
  __asm volatile("bl dump");
  __asm volatile("bx lr");
  #endif
}