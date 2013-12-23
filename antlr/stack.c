#include "stack.h"

stk* stk_init(int v){
	 stk *s = (stk*)malloc(sizeof(stk));
	 s->val = v;
	 s->prev = NULL;
	 return s;
}

void stk_push(stk **s, int v){
	stk *nnode = (stk*)malloc(sizeof(stk));
	nnode->prev = *s;
	nnode->val = v;
	*s = nnode;
};

int stk_pop(stk **s){
	if (*s == NULL){
		fprintf(stderr, "%s\n", "empty stack");
		return 0;
	}
	int v = (*s)->val;
	stk *p = (*s)->prev;
	free(*s);
	*s = p;
	return v;
}

void stk_delete(stk **s){
	if (*s == NULL){
		fprintf(stderr, "%s\n", "empty stack");
		return;
	}
	while(*s != NULL){
		stk *p = (*s)->prev;
		free(*s);
		*s = p;
	}
}

void stk_print(stk *s){
	stk *sn = s;
	printf("stack: ");
	while(sn->prev != NULL){
		printf("%d|", sn->val);
		sn = sn->prev;
	}
	printf("%d\n", sn->val);
}

int stk_aggregate(stk **s, int accum, int (*f)(int,int)){
	while((*s)->prev != NULL){
		accum = f(accum, stk_pop(s));
	}
	return accum;
}
