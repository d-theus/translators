all:
	runantlr2 funcall.g
	g++ -c main.cpp FuncallLexer.cpp FuncallParser.cpp stack.c functions.c  -I/usr/local/include
	g++ -o a.out *.o -L/usr/local/lib -lantlr
test:
	cat test1.in | ./a.out
clean:
	rm -f *.o ./a.out
