#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R11,#7"); 
  __asm volatile("push	{R4}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R4, sp, #0"); 
  __asm volatile("str	R11, [R4, #4]"); 
  __asm volatile("movs	R10, #0"); 
  __asm volatile("str	R10, [R4, #20]"); 
  __asm volatile("movs	R10, #1"); 
  __asm volatile("str	R10, [R4, #16]"); 
  __asm volatile("movs	R10, #0"); 
  __asm volatile("str	R10, [R4, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R10, [R4, #8]"); 
  __asm volatile("cmp	R10, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R10, [R4, #8]"); 
  __asm volatile("str	R10, [R4, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R12, [R4, #20]"); 
  __asm volatile("ldr	R10, [R4, #16]"); 
  __asm volatile("add	R10, R12"); 
  __asm volatile("str	R10, [R4, #12]"); 
  __asm volatile("ldr	R10, [R4, #16]"); 
  __asm volatile("str	R10, [R4, #20]"); 
  __asm volatile("ldr	R10, [R4, #12]"); 
  __asm volatile("str	R10, [R4, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R10, [R4, #8]"); 
  __asm volatile("adds	R10, #1"); 
  __asm volatile("str	R10, [R4, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R12, [R4, #8]"); 
  __asm volatile("ldr	R10, [R4, #4]"); 
  __asm volatile("cmp	R12, R10"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R10, [R4, #12]"); 
  __asm volatile("mov	R11, R10"); 
  __asm volatile("adds	R4, #28"); 
  __asm volatile("mov	sp, R4"); 
  __asm volatile("ldr.w	R4, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}