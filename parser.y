%{
#include <iostream>
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
		    | 	ID COMMA listtype { simulation.addTypeMolecule($1); free($1); }	
		
diam: 		DIAM EQUAL INT SEMI { simulation.setDiameter($3); }
		
listother: 	other
	| 	other listother
		
other: 		reaction	
	| 	size
	| 	speed	
	| 	init	
		
reaction: 	ID morereact ARROW ID morereact OBRACKET FLOAT CBRACKET SEMI { simulation.addReaction($1, $2, $4, $5, $7); free($1); free($2); free($4); free($5); }
		
morereact: /* Empty */ { return ""; }
	| 	PLUS ID { return $2; }
		
size: 		SIZE OPARAN ID CPARAN EQUAL INT SEMI { simulation.setTypeMoleculeSize($3, $6); free($3); }
		
speed: 		SPEED OPARAN ID CPARAN EQUAL FLOAT SEMI { simulation.setTypeMoleculeSpeed($3, $6); free($3); }
		
init: 		INIT OPARAN ID CPARAN EQUAL INT SEMI { simulation.addMolecule($3, $6); free($3); }
		
%%

void yyerror(const char* s) {
    std::cerr << "Parse error" << s << std::endl;
    exit(-1);
}
