%{
#include "y.tab.h"
#include <stdlib.h>

%}

%option noyywrap

NUMBER 	-?[0-9]+
ID	[A-Za-z]([:alnum:])*

%%

{NUMBER} {
	yylval = atoi(yytext);
	return I;
	 }
{ID} {
	yylval = strdup(yytext);
	return ID;
     }

;      {
	return yytext[0];
}

[\,\n\(\)] return yytext[0];
