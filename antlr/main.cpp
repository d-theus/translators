#include "FuncallLexer.hpp"
#include "FuncallParser.hpp"
#include <iostream>
#include <sstream>

int main( int argc, char* argv[] )
{
	ANTLR_USING_NAMESPACE(std)
	ANTLR_USING_NAMESPACE(antlr)
	try
	{
		ostringstream expr;
		istringstream input_string;
		istream *input = &cin;
		const char *filename = "<cin>";

		if( argc > 1 )
		{
			// write the argv strings to a ostringstream...
			for( int i = 1; i < argc; i++ )
			{
				if( i > 1 && i != (argc-1))
					expr << ' ';
				expr << argv[i];
			}
			input_string.str(expr.str());
			input = &input_string;
			filename = "<arguments>";
		}

		FuncallLexer lexer(*input);
		lexer.setFilename(filename);

		FuncallParser parser(lexer);
		parser.setFilename(filename);

		parser.input();
	}
	catch(ANTLRException& e)
	{
		cerr << "Parse exception: " << e.toString() << endl;
		return -1;
	}
	catch(exception& e)
	{
		cerr << "exception: " << e.what() << endl;
		return -1;
	}
	return 0;
}
