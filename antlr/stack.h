#include <stdlib.h>
#include <stdio.h>
#ifndef STACK_H
#define STACK_H



typedef struct stk {
	int val;
	struct stk *prev;
} stk;

stk* stk_init(int v);
void stk_push(stk **s, int v);
int stk_pop(stk **s);
void stk_delete(stk **s);
void stk_print(stk *s);
int stk_aggregate(stk **s,int accum, int (*f)(int, int));

#endif
