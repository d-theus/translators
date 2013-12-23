#ifndef INC_FuncallLexer_hpp_
#define INC_FuncallLexer_hpp_

#line 1 "funcall.g"

#include"stack.h"
#include"functions.h"

#line 10 "FuncallLexer.hpp"
#include <antlr/config.hpp>
/* $ANTLR 2.7.7 (20130818): "funcall.g" -> "FuncallLexer.hpp"$ */
#include <antlr/CommonToken.hpp>
#include <antlr/InputBuffer.hpp>
#include <antlr/BitSet.hpp>
#include "FuncallParserTokenTypes.hpp"
#include <antlr/CharScanner.hpp>
class CUSTOM_API FuncallLexer : public ANTLR_USE_NAMESPACE(antlr)CharScanner, public FuncallParserTokenTypes
{
#line 1 "funcall.g"
#line 21 "FuncallLexer.hpp"
private:
	void initLiterals();
public:
	bool getCaseSensitiveLiterals() const
	{
		return true;
	}
public:
	FuncallLexer(ANTLR_USE_NAMESPACE(std)istream& in);
	FuncallLexer(ANTLR_USE_NAMESPACE(antlr)InputBuffer& ib);
	FuncallLexer(const ANTLR_USE_NAMESPACE(antlr)LexerSharedInputState& state);
	ANTLR_USE_NAMESPACE(antlr)RefToken nextToken();
	public: void mWS_(bool _createToken);
	public: void mOB(bool _createToken);
	public: void mCB(bool _createToken);
	public: void mID(bool _createToken);
	public: void mSC(bool _createToken);
	public: void mCOL(bool _createToken);
	public: void mINT(bool _createToken);
	protected: void mDIGIT(bool _createToken);
private:
	
};

#endif /*INC_FuncallLexer_hpp_*/
