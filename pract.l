%option noyywrap
%{
#include <stdio.h>
#include <string.h>
#include "tabla.h"

int linea_actual = 0;
int DEBUG = 1;
%}

CABECERA_PROGRAMA "principal"
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
CADENA \"[^\"]*\"
PARIZQ "("
PARDER ")"
CORIZQ "["
CORDER "]"
LLAVIZQ "{"
LLAVDER "}"
COMA ","
PYC ";"
ASIGN "="
CONSTANTE (([0-9])+|([0-9])+(\.([0-9])+)?|\'[a-zA-Z0-9]\'|("cierto"|"falso"))
IDENTIFICADOR [a-zA-Z]([a-zA-Z0-9])*
ESPACIO ("\t"|" "|"\n")
PANICO .

%%

{ESPACIO}+ ;

{CABECERA_PROGRAMA} {
    if (DEBUG) printf("Cabecera de programa\n");
}

{SUBPROG_CLAVE} {
    if (DEBUG) printf("Clave de subprograma\n");
    return SUBPROG_CLAVE; 
}

{TIPO_PRIM} {
    if (DEBUG) printf("Tipo primitivo: %s\n", yytext);
    return TIPO_PRIM;
}

{TIPO_LISTA} {
    if (DEBUG) printf("Tipo de lista\n");
    return TIPO_LISTA;
}

{NOMB_IF} {
    if (DEBUG) printf("Estructura if\n");
    return NOMB_IF;
}

{NOMB_THEN} {
    if (DEBUG) printf("Estructura then\n");
    return NOMB_THEN;
}

{NOMB_ELSE} {
    if (DEBUG) printf("Estructura else\n");
    return NOMB_ELSE;
}

{NOMB_WHILE} {
    if (DEBUG) printf("Estructura while\n");
    return NOMB_WHILE;
}

{NOMB_FOR} {
    if (DEBUG) printf("Estructura for\n");
    return NOMB_FOR;
}

{NOMB_ENTRADA} {
    if (DEBUG) printf("Aceptar entrada\n");
    return NOMB_ENTRADA;
}

{NOMB_SALIDA} {
    if (DEBUG) printf("Producir salida\n");
    return NOMB_SALIDA;
}

{LISTA_SENT} {
    if (DEBUG) printf("Lista literal: %s\n", yytext);
    return LISTA_SENT;
}

{OP_TERN_PRIM} {
    if (DEBUG) printf("Primera parte de operación ternaria: %s\n", yytext);
    return OP_TERN_PRIM;
}

{OP_TERN_SEG} {
    if (DEBUG) printf("Segunda parte de operación ternaria: %s\n", yytext);
    return OP_TERN_SEG;
}

{OP_BINARIO} {
    if (DEBUG) printf("Operación binaria: %s\n", yytext);
    return OP_BINARIO;
}

{OP_UNARIO} {
    if (DEBUG) printf("Operación unaria: %s\n", yytext);
    return OP_UNARIO;
}

{OP_UN_BIN} {
    if (DEBUG) printf("Operación que puede ser o unaria o binaria: %s\n", yytext);
    return OP_UN_BIN;
}

{IDENTIFICADOR} {
    if (DEBUG) printf("Identificador: %s\n", yytext);
    return IDENTIFICADOR;
}

{CADENA} {
    if (DEBUG) printf("Cadena: %s\n", yytext);
    return CADENA;
}

{CONSTANTE} {
    if (DEBUG) printf("Constante: %s\n", yytext);
    return CONSTANTE;
}

{PARIZQ} {
    if (DEBUG) printf("Parentesis izquierda\n");
    return PARIZQ;
}

{PARDER} {
    if (DEBUG) printf("Parentesis derecha\n");
    return PARDER;
}

{CORIZQ} {
    if (DEBUG) printf("Corchete izquierda\n");
    return CORIZQ;
}

{CORDER} {
    if (DEBUG) printf("Corchete derecha\n");
    return CORDER;
}

{LLAVIZQ} {
    if (DEBUG) printf("Llave izquierda\n");
    return LLAVIZQ;
}

{LLAVDER} {
    if (DEBUG) printf("Llave derecha\n");
    return LLAVDER;
}

{COMA} {
    if (DEBUG) printf("Coma\n");
    return COMA;
}

{PYC} {
    if (DEBUG) printf("Punto y coma\n");
    return PYC;
}

{ASIGN} {
    if (DEBUG) printf("Asignación =\n");
    return ASIGN;
}

{PANICO} {
    if (DEBUG) printf("Modo pánico!\n");
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
	exit (0);
}
