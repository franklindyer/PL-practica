%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include "tabla.h"

int linea_actual = 0;
int DEBUG = 1;
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
OP_BINARIO ("%"|"*"|"/"|"=="|"<"|">"|"<="|">="|"!="|"&&"|"||"|"^"|"@"|"–-"|"**")
OP_UNARIO ("!"|"++"|"#"|"?")
OP_UN_BIN ("+"|"-")
IDENTIFICADOR [a-zA-Z]([a-zA-Z0-9])*
CADENA \"[^\"]*\"
CONSTANTE (([0-9])+|([0-9])+(\.([0-9])+)?|\'[a-zA-Z0-9]\'|("cierto"|"falso"))
PARIZQ "("
PARDER ")"
CORIZQ "["
CORDER "]"
LLAVIZQ "{"
LLAVDER "}"
COMA ","
PYC ";"
ASIGN "="
PANICO (.|\n)

%%

" "       ;

{SUBPROG_CLAVE}+ {
    if (DEBUG) printf("Clave de subprograma\n");
    return SUBPROG_CLAVE; 
}

{TIPO_PRIM}+ {
    if (DEBUG) printf("Tipo primitivo: %s\n", yytext);
    return TIPO_PRIM;
}

{TIPO_LISTA}+ {
    if (DEBUG) printf("Tipo de lista\n");
    return TIPO_LISTA;
}

{NOMB_IF}+ {
    if (DEBUG) printf("Estructura if\n");
    return NOMB_IF;
}

{NOMB_THEN}+ {
    if (DEBUG) printf("Estructura then\n");
    return NOMB_THEN;
}

{NOMB_ELSE}+ {
    if (DEBUG) printf("Estructura else\n");
    return NOMB_ELSE;
}

{NOMB_WHILE}+ {
    if (DEBUG) printf("Estructura while\n");
    return NOMB_WHILE;
}

{NOMB_FOR}+ {
    if (DEBUG) printf("Estructura for\n");
    return NOMB_FOR;
}

{NOMB_ENTRADA}+ {
    return NOMB_ENTRADA;
}

{NOMB_SALIDA}+ {
    return NOMB_SALIDA;
}

{LISTA_SENT}+ {
    return LISTA_SENT;
}

{OP_TERN_PRIM}+ {
    return OP_TERN_PRIM;
}

{OP_TERN_SEG}+ {
    return OP_TERN_SEG;
}

{OP_BINARIO}+ {
    if (DEBUG) printf("Operación binaria: %s\n", yytext);
    return OP_BINARIO;
}

{OP_UNARIO}+ {
    if (DEBUG) printf("Operación unaria: %s\n", yytext);
    return OP_UNARIO;
}

{OP_UN_BIN}+ {
    if (DEBUG) printf("Operación que puede ser o unaria o binaria: %s\n", yytext);
    return OP_UN_BIN;
}

{IDENTIFICADOR}+ {
    return IDENTIFICADOR;
}

{CADENA}+ {
    return CADENA;
}

{CONSTANTE}+ {
    return CONSTANTE;
}

{PARIZQ}+ {
    return PARIZQ;
}

{PARDER}+ {
    return PARDER;
}

{CORIZQ}+ {
    return CORIZQ;
}

{CORDER}+ {
    return CORDER;
}

{LLAVIZQ}+ {
    return LLAVIZQ;
}

{LLAVDER}+ {
    return LLAVDER;
}

{COMA}+ {
    return COMA;
}

{PYC}+ {
    return PYC;
}

{ASIGN}+ {
    return ASIGN;
}

%%

main ()
{
	int val;
	val= yylex() ;
	while (val != 0)
	{
		printf (" %d\n", val);
		val= yylex() ;
	}
	exit (1);
}
