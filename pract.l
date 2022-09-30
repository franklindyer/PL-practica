%{
#include <stdio.h>
#include <string.h>
#include "tab.h"

int linea_actual = 0;
%}

SUBPROG_CLAVE "proced"
TIPO_PRIM ("entero"|"real"|"booleano"|"caracter"|"cadena")
TIPO_LISTA "lista de"
NOMB_IF "si"
NOMB_THEN "entonces"
NOMB_ELSE "sino"
NOMB_WHILE "mientras"
NOMB_FOR "para"
NOMB_ENTRADA "cin <<<"
NOMB_SALIDA "cout >>>"
LISTA_SENT (">>"|"<<"|"$")
OP_TERN_PRIM "++"
OP_TERN_SEG "@"
OP_BINARIO ("+"|"%"|"*"|"/"|"=="|"<"|">"|"<="|">="|"!="|"&&"|"||"|"^"|"@"|"–-"|"**"|"
OP_UNARIO ("!"|"++"|"#"|"?")
IDENTIFICADOR [a-zA-Z]([a-zA-Z0-9])*
CONSTANTE_ENTERO (“-”)? ([0-9])+
CONSTANTE_REAL (“-”)? ([0-9])+ (“.” [0-9]+)?
CONSTANTE_CARACTER “‘” [a-zA-Z0-9] “‘”
CONSTANTE_BOOLEANO (“true” | “false”)
PARIZQ "("
PARDER ")"
CORIZQ "["
CORDER "]"
LAVIZQ "{"
LLAVDER "}"
COMA ","
PYC ";"
ASIGN "="


%%

" "       ;

%%

main ()
{
	int val;
	val= yylex() ;
	while (val != 0)
	{
		printf (“ %d\n”, val);
		val= yylex() ;
	}
	exit (1);
}