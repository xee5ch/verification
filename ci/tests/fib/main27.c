#include <stdlib.h>
__attribute__((naked))
void main(void){
  __asm volatile("mov	R9,#7"); 
  __asm volatile("push	{R8}"); 
  __asm volatile("sub	sp, #28"); 
  __asm volatile("add	R8, sp, #0"); 
  __asm volatile("str	R9, [R8, #4]"); 
  __asm volatile("movs	R5, #0"); 
  __asm volatile("str	R5, [R8, #20]"); 
  __asm volatile("movs	R5, #1"); 
  __asm volatile("str	R5, [R8, #16]"); 
  __asm volatile("movs	R5, #0"); 
  __asm volatile("str	R5, [R8, #8]"); 
  __asm volatile("b.n	fibonaccix38"); 
  __asm volatile("fibonaccix16:"); 
  __asm volatile("ldr	R5, [R8, #8]"); 
  __asm volatile("cmp	R5, #1"); 
  __asm volatile("bgt.n	fibonaccix22"); 
  __asm volatile("ldr	R5, [R8, #8]"); 
  __asm volatile("str	R5, [R8, #12]"); 
  __asm volatile("b.n	fibonaccix32"); 
  __asm volatile("fibonaccix22:"); 
  __asm volatile("ldr	R6, [R8, #20]"); 
  __asm volatile("ldr	R5, [R8, #16]"); 
  __asm volatile("add	R5, R6"); 
  __asm volatile("str	R5, [R8, #12]"); 
  __asm volatile("ldr	R5, [R8, #16]"); 
  __asm volatile("str	R5, [R8, #20]"); 
  __asm volatile("ldr	R5, [R8, #12]"); 
  __asm volatile("str	R5, [R8, #16]"); 
  __asm volatile("fibonaccix32:"); 
  __asm volatile("ldr	R5, [R8, #8]"); 
  __asm volatile("adds	R5, #1"); 
  __asm volatile("str	R5, [R8, #8]"); 
  __asm volatile("fibonaccix38:"); 
  __asm volatile("ldr	R6, [R8, #8]"); 
  __asm volatile("ldr	R5, [R8, #4]"); 
  __asm volatile("cmp	R6, R5"); 
  __asm volatile("blt.n	fibonaccix16"); 
  __asm volatile("ldr	R5, [R8, #12]"); 
  __asm volatile("mov	R9, R5"); 
  __asm volatile("adds	R8, #28"); 
  __asm volatile("mov	sp, R8"); 
  __asm volatile("ldr.w	R8, [sp], #4"); 
  #ifndef KLEE
  while(1);
  #else
  __asm volatile("bx lr");
  #endif
}
