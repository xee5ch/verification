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
  __asm volatile("mov R9,sp"); 
  __asm volatile("mov R0,#0"); 
  __asm volatile("add R0,R0,#0x05"); 
  __asm volatile("lsl R0,R0,#8"); 
  __asm volatile("add R0,R0,#0x9a"); 
  __asm volatile("lsl R0,R0,#8"); 
  __asm volatile("add R0,R0,#0x91"); 
  __asm volatile("lsl R0,R0,#8"); 
  __asm volatile("add R0,R0,#0xe1"); 
  __asm volatile("mov R2,#0"); 
  __asm volatile("add R2,R2,#0x18"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x1e"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x29"); 
  __asm volatile("lsl R2,R2,#8"); 
  __asm volatile("add R2,R2,#0x0a"); 
  __asm volatile("mov R5,#0"); 
  __asm volatile("add R5,R5,#0x6c"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0xb9"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x18"); 
  __asm volatile("lsl R5,R5,#8"); 
  __asm volatile("add R5,R5,#0x5e"); 
  __asm volatile("mov R7,#0"); 
  __asm volatile("add R7,R7,#0x40"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0x1f"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xe4"); 
  __asm volatile("lsl R7,R7,#8"); 
  __asm volatile("add R7,R7,#0xfc"); 
  __asm volatile("mov R10,#0"); 
  __asm volatile("add R10,R10,#0xc1"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0x6c"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xf5"); 
  __asm volatile("lsl R10,R10,#8"); 
  __asm volatile("add R10,R10,#0xc5"); 
  __asm volatile("mov R11,#0"); 
  __asm volatile("add R11,R11,#0xe7"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x1b"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x87"); 
  __asm volatile("lsl R11,R11,#8"); 
  __asm volatile("add R11,R11,#0x03"); 
  __asm volatile("mov R12,#0"); 
  __asm volatile("add R12,R12,#0xea"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x92"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0x38"); 
  __asm volatile("lsl R12,R12,#8"); 
  __asm volatile("add R12,R12,#0xeb"); 
  __asm volatile("mov R1,#0"); 
  __asm volatile("add R1,R1,#0x00"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x00"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x00"); 
  __asm volatile("lsl R1,R1,#8"); 
  __asm volatile("add R1,R1,#0x7d"); 
  __asm volatile("STRB R12, [R9, +R1, LSL #2]");
  #ifndef KLEE
  __asm volatile("stop: b stop");
  #else
  __asm volatile("bl dump");
  __asm volatile("bx lr");
  #endif
}
