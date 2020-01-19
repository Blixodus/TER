%{

%}

%language "c++"

%token TYPE DIAM SIZE SPEED INIT ID FLOAT INT
%token COMMA SEMI OPARAN CPARAN EQUAL ARROW PLUS OBRACKET CBRACKET

%%

axiom: type diam listother

type: TYPE listtype SEMI

listtype: ID { }
	  | ID COMMA listtype { }

diam: DIAM EQUAL INT SEMI { }

listother: other
	   | other listother

other: reaction
       | size
       | speed
       | init

reaction: ID morereact ARROW ID morereact OBRACKET FLOAT CBRACKET SEMI { }

morereact: // Empty { }
	   | PLUS ID { }

size: SIZE OPARAN ID CPARAN EQUAL INT SEMI { }

speed: SPEED OPARAN ID CPARAN EQUAL FLOAT SEMI { }

init: INIT OPARAN ID CPARAN EQUAL INT SEMI { }

%%

int yyerror(void) {
    fprintf(stderr, "Syntax error!\n");
    return 1;
}
