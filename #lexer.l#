%{
#include <math.h>
#include "parser.h"

extern "C" int yylex();
%}

%option noyywrap
						
%%

"# solver = entity"     { return ENTITY; }
"# solver = population" { return POPULATION; }
espece			{ return TYPE; }
diametre 		{ return DIAM; }
taille 			{ return SIZE; }
vitesse 		{ return SPEED;	}
init 			{ return INIT; }
[A-Za-z_][A-Za-z_0-9]*	{ yylval.sval = strdup(yytext);
			  return ID; }
[0-9]+\.[0-9]+ 		{ yylval.fval = atof(yytext);
			  return FLOAT; }
[0-9]+ 			{ yylval.ival = atoi(yytext);
			  return INT; }
\/\/.* 		{ } // Ignore comments
","			{ return COMMA; }
";"			{ return SEMI; }
"("			{ return OPARAN; }
")"			{ return CPARAN; }
"="			{ return EQUAL; }
"->"			{ return ARROW; }
"+"			{ return PLUS; }
"["			{ return OBRACKET; }
"]"			{ return CBRACKET; }
[ \t\n]			{ } // Ignore whitespace

%%
