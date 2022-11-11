%option noyywrap
%{
#include <stdio.h>
#include "y.tab.h"
#define DEBUG 1
%}

CABECERA_PROGRAMA "principal"
SUBPROG_CLAVE "proced"
MARCA_INI_DECLAR_VARIABLES "def variables"
MARCA_FIN_DECLAR_VARIABLES "enddef variables"
TIPO_PRIM ("entero"|"real"|"booleano"|"caracter"|"cadena")
TIPO_LISTA "lista de"
NOMB_IF "si"
NOMB_THEN "entonces"
NOMB_ELSE "sino"
NOMB_WHILE "mientras"
NOMB_FOR "para"
NOMB_ENTRADA "cin >>>"
NOMB_SALIDA "cout <<<"
LISTA_SENT (">>"|"<<"|"$")
OP_TERN_PRIM_UN "++"
OP_TERN_SEG "@"
OP_BINARIO ("%"|"*"|"/"|"=="|"<"|">"|"<="|">="|"!="|"&&"|"||"|"^"|"**")
OP_UNARIO ("!"|"#"|"?"|"--")
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
OTROS .

%%

"principal" {
    if (DEBUG) printf("Cabecera de programa\n");
    return CABECERA_PROGRAMA;
}

"proced" {
    if (DEBUG) printf("Clave de subprograma\n");
    return SUBPROG_CLAVE;
}

"def variables" {
    if (DEBUG) printf("Marca de inicio de declaración de variables\n");
    return MARCA_INI_DECLAR_VARIABLES;
}

"enddef variables" {
    if (DEBUG) printf("Marca de fin de declaración de variables\n");
    return MARCA_FIN_DECLAR_VARIABLES;
}

"entero" {
    if (DEBUG) printf("Tipo primitivo: entero\n");
    return TIPO_PRIM;
}

"real" {
    if (DEBUG) printf("Tipo primitivo: real\n");
    return TIPO_PRIM;
}

"caracter" {
    if (DEBUG) printf("Tipo primitivo: caracter\n");
    return TIPO_PRIM;
}

"booleano" {
    if (DEBUG) printf("Tipo primitivo: booleano\n");
    return TIPO_PRIM;
}

"cadena" {
    if (DEBUG) printf("Tipo primitivo: cadena\n");
    return TIPO_PRIM;
}

"lista de" {
    if (DEBUG) printf("Tipo de lista\n");
    return TIPO_LISTA;
}

"si" {
    if (DEBUG) printf("Estructura if\n");
    return NOMB_IF;
}

"entonces" {
    if (DEBUG) printf("Estructura then\n");
    return NOMB_THEN;
}

"sino" {
    if (DEBUG) printf("Estructura else\n");
    return NOMB_ELSE;
}

"mientras" {
    if (DEBUG) printf("Estructura while\n");
    return NOMB_WHILE;
}

"para" {
    if (DEBUG) printf("Estructura for\n");
    return NOMB_FOR;
}

"cin >>>" {
    if (DEBUG) printf("Aceptar entrada\n");
    return NOMB_ENTRADA;
}

"cout <<<" {
    if (DEBUG) printf("Producir salida\n");
    return NOMB_SALIDA;
}

"<<" {
    if (DEBUG) printf("Operación de listas: <<\n");
    return LISTA_SENT;
}

">>" {
    if (DEBUG) printf("Operación de listas: >>\n");
    return LISTA_SENT;
}

"$" {
    if (DEBUG) printf("Operación de listas: $\n");
    return LISTA_SENT;
}

"++" {
    if (DEBUG) printf("Primera parte de operación ternaria o bien una operación unaria: %s\n", yytext);
    return OP_TERN_PRIM_UN;
}

"@" {
    if (DEBUG) printf("Segunda parte de operación ternaria: %s\n", yytext);
    return OP_TERN_SEG;
}

"%" {
    if (DEBUG) printf("Operación binaria: %s\n", "%");
    return OP_BINARIO;
}

"*" {
    if (DEBUG) printf("Operación binaria: *\n");
    return OP_BINARIO;
}

"/" {
    if (DEBUG) printf("Operación binaria: /\n");
    return OP_BINARIO;
}

"==" {
    if (DEBUG) printf("Operación binaria: ==\n");
    return OP_BINARIO;
}

"<" {
    if (DEBUG) printf("Operación binaria: <\n");
    return OP_BINARIO;
}

">" {
    if (DEBUG) printf("Operación binaria: >\n");
    return OP_BINARIO;
}

"<=" {
    if (DEBUG) printf("Operación binaria: <=\n");
    return OP_BINARIO;
}

">=" {
    if (DEBUG) printf("Operación binaria: >=\n");
    return OP_BINARIO;
}

"!=" {
    if (DEBUG) printf("Operación binaria: !=\n");
    return OP_BINARIO;
}

"&&" {
    if (DEBUG) printf("Operación binaria: &&\n");
    return OP_BINARIO;
}

"||" {
    if (DEBUG) printf("Operación binaria: ||\n");
    return OP_BINARIO;
}

"^" {
    if (DEBUG) printf("Operación binaria: ^\n");
    return OP_BINARIO;
}

"**" {
    if (DEBUG) printf("Operación binaria: **\n");
    return OP_BINARIO;
}

"!" {
    if (DEBUG) printf("Operación unaria: !\n");
    return OP_UNARIO;
}

"#" {
    if (DEBUG) printf("Operación unaria: #\n");
    return OP_UNARIO;
}

"?" {
    if (DEBUG) printf("Operación unaria: ?\n");
    return OP_UNARIO;
}

"--" {
    if (DEBUG) printf("Operación unaria: --\n");
    return OP_UNARIO;
}



"+" {
    if (DEBUG) printf("Operación que puede ser o unaria o binaria: +\n");
    return OP_UN_BIN;
}

"-" {
    if (DEBUG) printf("Operación que puede ser o unaria o binaria: -\n");
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

"(" {
    if (DEBUG) printf("Parentesis izquierda\n");
    return PARIZQ;
}

")" {
    if (DEBUG) printf("Parentesis derecha\n");
    return PARDER;
}

"[" {
    if (DEBUG) printf("Corchete izquierda\n");
    return CORIZQ;
}

"]" {
    if (DEBUG) printf("Corchete derecha\n");
    return CORDER;
}

"{" {
    if (DEBUG) printf("Llave izquierda\n");
    return LLAVIZQ;
}

"}" {
    if (DEBUG) printf("Llave derecha\n");
    return LLAVDER;
}

"," {
    if (DEBUG) printf("Coma\n");
    return COMA;
}

";" {
    if (DEBUG) printf("Punto y coma\n");
    return PYC;
}

"=" {
    if (DEBUG) printf("Asignación =\n");
    return ASIGN;
}

"\n" {yylineno++;};
[ \t]+ ;

. {
    printf("\n(Linea %d) Error léxico: token %s\n", yylineno, yytext);
}

%%
