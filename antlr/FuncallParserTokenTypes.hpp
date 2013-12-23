#ifndef INC_FuncallParserTokenTypes_hpp_
#define INC_FuncallParserTokenTypes_hpp_

/* $ANTLR 2.7.7 (20130818): "funcall.g" -> "FuncallParserTokenTypes.hpp"$ */

#ifndef CUSTOM_API
# define CUSTOM_API
#endif

#ifdef __cplusplus
struct CUSTOM_API FuncallParserTokenTypes {
#endif
	enum {
		EOF_ = 1,
		SC = 4,
		ID = 5,
		OB = 6,
		CB = 7,
		COL = 8,
		INT = 9,
		WS_ = 10,
		DIGIT = 11,
		NULL_TREE_LOOKAHEAD = 3
	};
#ifdef __cplusplus
};
#endif
#endif /*INC_FuncallParserTokenTypes_hpp_*/
