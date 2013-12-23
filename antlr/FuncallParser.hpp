#ifndef INC_FuncallParser_hpp_
#define INC_FuncallParser_hpp_

#line 1 "funcall.g"

#include"stack.h"
#include"functions.h"

#line 10 "FuncallParser.hpp"
#include <antlr/config.hpp>
/* $ANTLR 2.7.7 (20130818): "funcall.g" -> "FuncallParser.hpp"$ */
#include <antlr/TokenStream.hpp>
#include <antlr/TokenBuffer.hpp>
#include "FuncallParserTokenTypes.hpp"
#include <antlr/LLkParser.hpp>

class CUSTOM_API FuncallParser : public ANTLR_USE_NAMESPACE(antlr)LLkParser, public FuncallParserTokenTypes
{
#line 1 "funcall.g"
#line 21 "FuncallParser.hpp"
public:
	void initializeASTFactory( ANTLR_USE_NAMESPACE(antlr)ASTFactory& factory );
protected:
	FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf, int k);
public:
	FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenBuffer& tokenBuf);
protected:
	FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer, int k);
public:
	FuncallParser(ANTLR_USE_NAMESPACE(antlr)TokenStream& lexer);
	FuncallParser(const ANTLR_USE_NAMESPACE(antlr)ParserSharedInputState& state);
	int getNumTokens() const
	{
		return FuncallParser::NUM_TOKENS;
	}
	const char* getTokenName( int type ) const
	{
		if( type > getNumTokens() ) return 0;
		return FuncallParser::tokenNames[type];
	}
	const char* const* getTokenNames() const
	{
		return FuncallParser::tokenNames;
	}
	public: void input();
	public: void stmt();
	public: int  expr();
	public: int  fc();
	public: void args(
		stk **s
	);
	public: int  integer();
public:
	ANTLR_USE_NAMESPACE(antlr)RefAST getAST()
	{
		return returnAST;
	}
	
protected:
	ANTLR_USE_NAMESPACE(antlr)RefAST returnAST;
private:
	static const char* tokenNames[];
#ifndef NO_STATIC_CONSTS
	static const int NUM_TOKENS = 12;
#else
	enum {
		NUM_TOKENS = 12
	};
#endif
	
	static const unsigned long _tokenSet_0_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_0;
	static const unsigned long _tokenSet_1_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_1;
	static const unsigned long _tokenSet_2_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_2;
	static const unsigned long _tokenSet_3_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_3;
	static const unsigned long _tokenSet_4_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_4;
	static const unsigned long _tokenSet_5_data_[];
	static const ANTLR_USE_NAMESPACE(antlr)BitSet _tokenSet_5;
};

#endif /*INC_FuncallParser_hpp_*/
