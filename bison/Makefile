STR1="mul(1,mul(2,3,mul(5)),4);"
STR2="mul(mul(),mul(2,3,mul(5)),4);"
STR3="sum(sum(),sum(1,2,3), 4,5);"
STR4="sum(sum(mul(1,2,3)),4,mul(5));"

all:
	yacc -y funcall.y --defines 
	flex funcall.l
	gcc y.tab.c lex.yy.c stack.c
debug:
	yacc -y funcall.y --defines 
	flex funcall.l
	gcc -DDEBUG y.tab.c lex.yy.c stack.c
test:
	sh -c "sleep 0.05; killall a.out" &
	echo $(STR1) > log
	echo $(STR1) | ./a.out >> log 2>&1
	sh -c "sleep 0.05; killall a.out" &
	echo $(STR2) >> log
	echo $(STR2) | ./a.out >> log 2>&1
	sh -c "sleep 0.05; killall a.out" &
	echo $(STR3) >> log
	echo $(STR3) | ./a.out >> log 2>&1
	sh -c "sleep 0.05; killall a.out" &
	echo $(STR4) >> log
	echo $(STR4) | ./a.out >> log 2>&1
clean:
	rm -f a.out \
	lex.yy.c \
	y.tab.h \
	y.tab.c \
	log \
	tags
