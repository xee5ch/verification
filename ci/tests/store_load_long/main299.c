#include <stdlib.h>
int STACK[2050];__attribute__((naked))
void foo(void){
  #ifndef KLEE
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
  #endif
  __asm volatile("mov R2,#0x5f"); 
  __asm volatile("mov R3,#0xe4"); 
  __asm volatile("mov R7,#0x48"); 
  __asm volatile("mov R8,#0x15"); 
  __asm volatile("mov R9,#0xe7"); 
  __asm volatile("mov R10,#0x07"); 
  __asm volatile("mov R12,#0x1e"); 
  __asm volatile("mov R14,#0x61"); 
  __asm volatile("STMDB SP!, {R8, LR, R9, R3, R2, R12, R8, R7, R10}");
  __asm volatile("mov R2,#0x30"); 
  __asm volatile("mov R3,#0x9b"); 
  __asm volatile("mov R7,#0x2e"); 
  __asm volatile("mov R8,#0xca"); 
  __asm volatile("mov R9,#0x50"); 
  __asm volatile("mov R10,#0x20"); 
  __asm volatile("mov R12,#0x12"); 
  __asm volatile("mov R14,#0x7b"); 
  __asm volatile("LDMDB SP!, {R8, LR, R9, R3, R2, R12, R8, R7, R10}");
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
void main(void){
  int i;  for(i=0;i<2050;i++){
      STACK[2050-1-i]=i;
  }
  foo();
}
