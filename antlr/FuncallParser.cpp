/* $ANTLR 2.7.7 (20130818): "funcall.g" -> "FuncallParser.cpp"$ */
#include "FuncallParser.hpp"
#include <antlr/NoViableAltException.hpp>
#include <antlr/SemanticException.hpp>
#include <antlr/ASTFactory.hpp>
#line 1 "funcall.g"
#line 8 "FuncallParser.cpp"
FuncallParser::FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,k)
{
}

FuncallParser::FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(tokenBuf,1)
{
}

FuncallParser::FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,k)
{
}

FuncallParser::FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(lexer,1)
{
}

FuncallParser::FuncallParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state)
: ANTLR_USE_NAMESPACE(antlr)LLkParser(state,1)
{
}

void FuncallParser::input() {
	
	try {      // for error handling
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == ID)) {
				stmt();
			}
			else {
				goto _loop3;
			}
			
		}
		_loop3:;
		} // ( ... )*
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_0);
	}
}

void FuncallParser::stmt() {
	
	try {      // for error handling
		expr();
		match(SC);
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_1);
	}
}

int  FuncallParser::expr() {
#line 24 "funcall.g"
	int r;
#line 71 "FuncallParser.cpp"
	
	try {      // for error handling
#line 25 "funcall.g"
		int v;
#line 76 "FuncallParser.cpp"
		v=fc();
#line 26 "funcall.g"
		
				r = v;
				printf("Result: %d\n", r);
			
#line 83 "FuncallParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_2);
	}
	return r;
}

int  FuncallParser::fc() {
#line 32 "funcall.g"
	int r;
#line 95 "FuncallParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefToken  v = ANTLR_USE_NAMESPACE(antlr)nullToken;
#line 32 "funcall.g"
	
			r = 0;
			stk *s = stk_init(0);
		
#line 102 "FuncallParser.cpp"
	
	try {      // for error handling
		v = LT(1);
		match(ID);
		match(OB);
		{ // ( ... )*
		for (;;) {
			if ((LA(1) == ID || LA(1) == INT)) {
				args(&s);
			}
			else {
				goto _loop8;
			}
			
		}
		_loop8:;
		} // ( ... )*
		match(CB);
#line 37 "funcall.g"
		
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
			
#line 140 "FuncallParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_3);
	}
	return r;
}

void FuncallParser::args(
	stk **s
) {
	
	try {      // for error handling
#line 58 "funcall.g"
		int v;
#line 156 "FuncallParser.cpp"
		{
		switch ( LA(1)) {
		case INT:
		{
			v=integer();
			break;
		}
		case ID:
		{
			v=fc();
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
#line 59 "funcall.g"
		stk_push(s,v);
#line 177 "FuncallParser.cpp"
		{
		switch ( LA(1)) {
		case COL:
		{
			match(COL);
			args(s);
			break;
		}
		case ID:
		case CB:
		case INT:
		{
			break;
		}
		default:
		{
			throw ANTLR_USE_NAMESPACE(antlr)NoViableAltException(LT(1), getFilename());
		}
		}
		}
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_4);
	}
}

int  FuncallParser::integer() {
#line 62 "funcall.g"
	int r;
#line 208 "FuncallParser.cpp"
	ANTLR_USE_NAMESPACE(antlr)RefToken  v = ANTLR_USE_NAMESPACE(antlr)nullToken;
	
	try {      // for error handling
		v = LT(1);
		match(INT);
#line 63 "funcall.g"
		r = atoi(v->getText().c_str());
#line 216 "FuncallParser.cpp"
	}
	catch (ANTLR_USE_NAMESPACE(antlr)RecognitionException& ex) {
		reportError(ex);
		recover(ex,_tokenSet_5);
	}
	return r;
}

void FuncallParser::initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& )
{
}
const char* FuncallParser::tokenNames[] = {
	"<0>",
	"EOF",
	"<2>",
	"NULL_TREE_LOOKAHEAD",
	"SC",
	"ID",
	"OB",
	"CB",
	"COL",
	"INT",
	"WS_",
	"DIGIT",
	0
};

const unsigned long FuncallParser::_tokenSet_0_data_[] = { 2UL, 0UL, 0UL, 0UL };
// EOF 
const ANTLR_USE_NAMESPACE(antlr)BitSet FuncallParser::_tokenSet_0(_tokenSet_0_data_,4);
const unsigned long FuncallParser::_tokenSet_1_data_[] = { 34UL, 0UL, 0UL, 0UL };
// EOF ID 
const ANTLR_USE_NAMESPACE(antlr)BitSet FuncallParser::_tokenSet_1(_tokenSet_1_data_,4);
const unsigned long FuncallParser::_tokenSet_2_data_[] = { 16UL, 0UL, 0UL, 0UL };
// SC 
const ANTLR_USE_NAMESPACE(antlr)BitSet FuncallParser::_tokenSet_2(_tokenSet_2_data_,4);
const unsigned long FuncallParser::_tokenSet_3_data_[] = { 944UL, 0UL, 0UL, 0UL };
// SC ID CB COL INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet FuncallParser::_tokenSet_3(_tokenSet_3_data_,4);
const unsigned long FuncallParser::_tokenSet_4_data_[] = { 672UL, 0UL, 0UL, 0UL };
// ID CB INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet FuncallParser::_tokenSet_4(_tokenSet_4_data_,4);
const unsigned long FuncallParser::_tokenSet_5_data_[] = { 928UL, 0UL, 0UL, 0UL };
// ID CB COL INT 
const ANTLR_USE_NAMESPACE(antlr)BitSet FuncallParser::_tokenSet_5(_tokenSet_5_data_,4);


