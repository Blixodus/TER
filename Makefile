LEX = flex
YACC = bison -d



lex.yy.c: lexer.l
	$(LEX) lexer.l

parser.tab.c: parser.y
	$(YACC) parser.y
