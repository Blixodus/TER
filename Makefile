LEX = flex -+
YACC = bison -d

main: main.cpp parser.tab.cc lex.yy.cc
	$(CXX) -o $@ main.cpp parser.tab.cc lex.yy.cc

parser.tab.cc: parser.y
	$(YACC) parser.y

lex.yy.cc: lexer.l
	$(LEX) lexer.l
