header "pre_include_hpp" {
#include"stack.h"
#include"functions.h"
}

options {
	language="Cpp";
}


class FuncallParser extends Parser;
options {
	buildAST = false;
}


//{{{----------GRAMMAR
input	: (stmt)*
	;

stmt	:  expr SC
	;

expr	returns [int r]:
	{ int v;}
	v=fc {
		r = v;
		printf("Result: %d\n", r);
	}
	;

fc	returns [int r]
	{
		r = 0;
		stk *s = stk_init(0);
	}:
	v:ID OB (args [&s])* CB {
		std::string id(v->getText().c_str());
		int (*f)(int,int);
		if (id.compare("sum") == 0){
			r = 0;
			f = sum;
		} else
		if (id.compare("mul") == 0){
			r = 1;
			f = mul;
		} else {
			fprintf(stderr, "Unknown function\n");
		}
		while(s->prev != NULL){
			r = stk_aggregate(&s, r, f);
		}
		stk_delete(&s);
	}
	;

args	[stk **s]:
	{int v;}
		(v=integer|v=fc){stk_push(s,v);}(COL args[s])?
	;

integer	returns[int r]:
	v:INT {r = atoi(v->getText().c_str());}
	;

//}}}------fold:GRAMMAR



class FuncallLexer extends Lexer;

//{{{-----------LEXICAL MATCH RULES
WS_	:	(' '
	|	'\t'
	|	'\n'
	|	'\r')
		{ _ttype = ANTLR_USE_NAMESPACE(antlr)Token::SKIP; }
	;

OB	:	'('
	;


CB	:	')'
	;

ID	:	('A'..'Z'|'a'..'z')('A'..'Z'|'a'..'z'|'0'..'9')*
	;

SC	:	';'
	;

COL	:	','
	;

INT	: ('-')?(DIGIT)+
	;


protected
DIGIT
	:	'0'..'9'
	;

//}}}
