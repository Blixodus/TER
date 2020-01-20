%{
  #include <iostream>

  extern "C" int yylex();
  extern int yyparse();
  extern FILE* yyin;

  void yyerror(const char* s);
%}

%union {
  int ival;
  float fval;
  char* sval;
}

%token TYPE
%token DIAM
%token SIZE
%token SPEED
%token INIT
%token <sval> ID
%token <fval> FLOAT
%token <ival> INT
%token COMMA
%token SEMI
%token OPARAN
%token CPARAN
%token EQUAL
%token ARROW
%token PLUS
%token OBRACKET
%token CBRACKET

%%

axiom: type diam listother

type: TYPE listtype SEMI

listtype: ID { free($1); }
	  | ID COMMA listtype { std::cout << "ID!" << $1 << std::endl;
	       	     	      	free($1); }

diam: DIAM EQUAL INT SEMI { }

listother: other
	   | other listother

other: reaction
       | size
       | speed
       | init

reaction: ID morereact ARROW ID morereact OBRACKET FLOAT CBRACKET SEMI { free($1); free($4); }

morereact: // Empty { }
	   | PLUS ID { free($2); }

size: SIZE OPARAN ID CPARAN EQUAL INT SEMI { free($3); }

speed: SPEED OPARAN ID CPARAN EQUAL FLOAT SEMI { free($3); }

init: INIT OPARAN ID CPARAN EQUAL INT SEMI { free($3); }

%%

      //int main(int argc, char** argv) {
      //yyin = fopen(argv[1], "r");
      //yyparse();
      //}

void yyerror(const char* s) {
    std::cout << "Parse error" << s << std::endl;
    exit(-1);
}
