%{
#include <iostream>
#include "entitysimulation.h"
#include "populationsimulation.h"
  
extern "C" int yylex();
extern int yyparse();
extern FILE* yyin;
extern "C" int yywrap();

extern EntitySimulation entitySimulation;
extern PopulationSimulation populationSimulation;
extern bool solver;
  
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
%token ENTITY
%token POPULATION


%type	<sval>		morereact
			
%%

axiom: solver type diam listother

solver: ENTITY { solver = true; }
| POPULATION { solver = false; }

type: 		TYPE listtype SEMI
		
listtype: 	ID { if(solver) {entitySimulation.addTypeMolecule($1);}
				else {populationSimulation.addTypeMolecule($1);}
				}
		    | 	ID COMMA listtype { if(solver) {entitySimulation.addTypeMolecule($1);}
									else {populationSimulation.addTypeMolecule($1);}
			 }	
	        
diam: 		DIAM EQUAL INT SEMI { if(solver){entitySimulation.setDiameter($3);}
								  /*else {populationSimulation.setDiameter($3);}*/

			}
		
listother: 	other
	| 	other listother
		
other: 		reaction	
	| 	size
	| 	speed	
	| 	init	
		
reaction: 	ID morereact ARROW ID morereact OBRACKET FLOAT CBRACKET SEMI {
				if(solver){entitySimulation.addReaction($1, $2, $4, $5, $7); free($1); free($2); free($4); free($5);} 
				else{populationSimulation.addReaction($1, $2, $4, $5, $7); free($1); free($2); free($4); free($5);}
	}
		
morereact: { $$ = NULL; }
	| 	PLUS ID { $$ = $2; }
		
size: 		SIZE OPARAN ID CPARAN EQUAL INT SEMI { 
				if(solver){entitySimulation.setTypeMoleculeSize($3, $6); free($3);}
				/*else {populationSimulation.setTypeMoleculeSize($3, $6); free($3);} */
			}
		
speed: 		SPEED OPARAN ID CPARAN EQUAL FLOAT SEMI { 
				if(solver){entitySimulation.setTypeMoleculeSpeed($3, $6); free($3);}
				/*else {populationSimulation.setTypeMoleculeSpeed($3, $6); free($3);}*/ 
			}
		
init: 		INIT OPARAN ID CPARAN EQUAL INT SEMI { 
				if(solver){entitySimulation.addMolecule($3, $6); free($3);}
				/*else{populationSimulation.addMolecule($3, $6); free($3);}*/ 
			}
		
%%

void yyerror(const char* s) {
    std::cerr << std::endl << "Parse error : " << s << std::endl;
    exit(-1);
}
