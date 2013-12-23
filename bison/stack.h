#include "funcall.h"
#include <stdlib.h>
#include <stdio.h>
#ifndef STACK_H
#define STACK_H

typedef struct stk {
	YYSTYPE val;
	struct stk *prev;
} stk;

stk* stk_init(YYSTYPE v);
void stk_push(stk **s, YYSTYPE v);
YYSTYPE stk_pop(stk **s);
void stk_delete(stk **s);
void stk_print(stk *s);
#endif
