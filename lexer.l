%{
#include <math.h>
#include "y.tab.h"
%}

%%

espece			{ return TYPE; }
diametre 		{ return DIAM; }
taille 			{ return SIZE; }
vitesse 		{ return SPEED;	}
init 			{ return INIT; }
[A-Za-z_][A-Za-z_0-9]*	{ return ID; }
[0-9]+\.[0-9]+ 		{ yylval = atof(yytext);
			  return FLOAT; }
[0-9]+ 			{ yylval = atoi(yytext);
			  return INT; }
\/\/.*\n 		{ } # Ignore comments
","			{ return COMMA; }
";"			{ return SEMI; }
"("			{ return OPARAN; }
")"			{ return CPARAN; }
"="			{ return EQUAL; }
"->"			{ return ARROW; }
"+"			{ return PLUS; }
"["			{ return OBRACKET; }
"]"			{ return CBRACKET; }
[ \t\n]			{ } # Ignore whitespace

%%

int main(int argc, char **argv) {
    ++argv, --argc; # Skip filename
    if(argc > 0) yyin = fopen(argv[0], "r");
    else yyin = stdin;
    yylex();
}
