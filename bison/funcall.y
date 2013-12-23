%{
#include<stdio.h>
#include"funcall.h"
#include"stack.h"
int yylex();
YYSTYPE aggregate(YYSTYPE accum, stk **s, YYSTYPE (*f)(YYSTYPE,YYSTYPE), size_t c); //accum = f(accum, s_i)
YYSTYPE sum(YYSTYPE,YYSTYPE);//function to make ptr to
YYSTYPE mul(YYSTYPE,YYSTYPE);//function to make ptr to
stk *s; //args stack
size_t c; //deepest function arg couner
%}

%token I ID

%%

input: %empty 
     | input ln
     ;

ln   : expr '\n' {printf ("res: %d\n", $1);}
     | '\n'
     | error
     ;

expr : fc ';' {$$ = $1;}
     ;

fc   : ID '(' args ')'{
#ifdef DEBUG
	printf("fc(args){\n");
	printf("ID: %s\n", $1);
#endif
	YYSTYPE (*f)(YYSTYPE,YYSTYPE);
	int accum = 0;
	if(strcmp($1, "mul") == 0){
		f = mul;
		accum = 1;
	}else
	if(strcmp($1, "sum") == 0){
		f = sum;
		accum = 0;
	}
	else{
		fprintf(stderr, "Undefined function");
	}
     	$$ = aggregate(accum, &s,f,c);
	c = 0;
#ifdef DEBUG
     	printf("counter: %d\n",c);
	printf("value "); stk_print(s);
	printf("}fc: %d\n", $$);
#endif
     }
     | ID '(' ')' {
#ifdef DEBUG
	printf("fc(){\n");
	printf("ID: %s", $1);
#endif
	if(strcmp($1, "mul") == 0){
		$$ = 0;
	}else
	if(strcmp($1, "sum") == 0){
		$$ = 0;
	}else{
		fprintf(stderr, "Undefined function\n");
	};

     }

args : I  ',' args { 
#ifdef DEBUG
	printf("%d,args\n",$1);
#endif
     	c++;
	stk_push(&s,$1);
#ifdef DEBUG
     	printf("counter: %d\n",c);
	printf("value "); stk_print(s);
	printf("}%d:\n", $$);
#endif
     }
     | fc ',' args {
#ifdef DEBUG
	printf("fc,args\n");
#endif
     	c++;
	stk_push(&s,$1);
#ifdef DEBUG
     	printf("counter: %d\n",c);
	printf("value "); stk_print(s);
	printf("}fc: %d\n", $$);
#endif
     }
     | I {
#ifdef DEBUG
     printf("%d{\n",$1);
#endif
     	stk_push(&s,$1);
	c = 1;
#ifdef DEBUG
     	printf("counter: %d\n",c);
	printf("value "); stk_print(s);
	printf("}%d:\n", $$);
#endif
     }  
     | fc{
#ifdef DEBUG
     printf("fc\n");
#endif
     	stk_push(&s,$1);
	c = 1;
#ifdef DEBUG
     	printf("counter: %d\n",c);
	printf("value "); stk_print(s);
	printf("}fc: %d\n", $$);
#endif
     }
     ;

%%
#include<stdio.h>
main() {
	s = stk_init(0);
	c = 0;
	yyparse();
	stk_delete(&s);
}
int yyerror(char *mes) { printf("%s\n", mes);}
YYSTYPE aggregate(YYSTYPE accum, stk **s, YYSTYPE (*f)(YYSTYPE,YYSTYPE), size_t n){
#ifdef DEBUG
	printf("aggregate(){\n");
     	printf("counter: %d\n",c);
	printf("value "); stk_print(*s);
#endif
	for(; n > 0; n--){
#ifdef DEBUG
		printf("f(%d, %d)", accum, (*s)->val);
#endif
		accum = f(accum,stk_pop(s));
#ifdef DEBUG
		printf("counter: %d\n", n-1);
		printf("value "); stk_print(*s);
		printf("r: %d\n",accum);
#endif
	}
#ifdef DEBUG
	printf("}\n");
#endif
	return accum;
}

YYSTYPE sum(YYSTYPE a,YYSTYPE b){
	return a + b;
}

YYSTYPE mul(YYSTYPE a,YYSTYPE b){
	return a * b;
}


