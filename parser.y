%{
#include <iostream>
#include "typemolecule.h"
#include "molecule.h"
#include "reaction.h"
#include "simulation.h"
  
extern "C" int yylex();
extern int yyparse();
extern FILE* yyin;
extern "C" int yywrap();
  
extern Simulation simulation;
  
void yyerror(const char* s);
%}
			
%union {
    int ival;
    float fval;
    char* sval;
}
			
%token			TYPE		
%token			DIAM		
%token			SIZE		
%token			SPEED		
%token			INIT		
%token	<sval>		ID
%token	<fval>		FLOAT	
%token	<ival>		INT	
%token			COMMA		
%token			SEMI		
%token			OPARAN		
%token			CPARAN		
%token			EQUAL		
%token			ARROW		
%token			PLUS		
%token			OBRACKET		
%token			CBRACKET		
			
%%

axiom: 		type diam listother
		
type: 		TYPE listtype SEMI
		
listtype: 	ID	
	| 	ID COMMA listtype { free($1); }	
		
diam: 		DIAM EQUAL INT SEMI { }
		
listother: 	other
	| 	other listother
		
other: 		reaction	
	| 	size
	| 	speed	
	| 	init	
		
reaction: 	ID morereact ARROW ID morereact OBRACKET FLOAT CBRACKET SEMI { free($1); free($4); }
		
morereact: // 	Empty { }
	| 	PLUS ID { free($2); }
		
size: 		SIZE OPARAN ID CPARAN EQUAL INT SEMI { free($3); }
		
speed: 		SPEED OPARAN ID CPARAN EQUAL FLOAT SEMI { free($3); }
		
init: 		INIT OPARAN ID CPARAN EQUAL INT SEMI { free($3); }
		
%%

void yyerror(const char* s) {
    std::cout << "Parse error" << s << std::endl;
    exit(-1);
}
