%{
#include <stdio.h>
#include "codigos.h"
#include "tabla_structs.c"
#include "y.tab.h"
#define DEBUG 1

#define YYSTYPE atributos
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
LISTA_UNARIO_POSTFIJO (">>"|"<<")
LISTA_UNARIO_PREFIJO "$"
OP_TERN_PRIM_UN "++"
OP_TERN_SEG "@"
OP_BINARIO_MULT ("%"|"*"|"/")
OP_BINARIO_IG ("=="|"!=")
OP_BINARIO_COMP ("<"|">"|"<="|">=")
OP_BINARIO_AND_LOG "&&"
OP_BINARIO_OR_LOG "||"
OP_BINARIO_XOR "^"
OP_BINARIO_ASTAST "**"
OP_BINARIO_MENMEN "--"
OP_UNARIO ("!"|"#"|"?")
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
CONSTANTE (([0-9])+|([0-9])+(\.([0-9])+)?|\'[^\']*\'|("cierto"|"falso"))
CONSTANTE_ENTERO ([0-9])+
CONSTANTE_REAL ([0-9])+(\.([0-9])+)?
CONSTANTE_BOOLEANO ("cierto"|"falso")
CONSTANTE_CARACTER \'[^\']\'
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
    yylval.tipo = entero;

    yylval.codigo = malloc(sizeof(char) * 3);
    strcpy(yylval.codigo, "int");

    return TIPO_PRIM;
}

"real" {
    if (DEBUG) printf("Tipo primitivo: real\n");
    yylval.tipo = real;

    yylval.codigo = malloc(sizeof(char) * 5);
    strcpy(yylval.codigo, "float");

    return TIPO_PRIM;
}

"caracter" {
    if (DEBUG) printf("Tipo primitivo: caracter\n");
    yylval.tipo = caracter;

    yylval.codigo = malloc(sizeof(char) * 4);
    strcpy(yylval.codigo, "char");

    return TIPO_PRIM;
}

"booleano" {
    if (DEBUG) printf("Tipo primitivo: booleano\n");
    yylval.tipo = booleano;

    yylval.codigo = malloc(sizeof(char) * 5);
    strcpy(yylval.codigo, "short");

    return TIPO_PRIM;
}

"cadena" {
    if (DEBUG) printf("Tipo primitivo: cadena\n");
    yylval.tipo = cadena;

    yylval.codigo = malloc(sizeof(char) * 5);
    strcpy(yylval.codigo, "char*");

    return TIPO_PRIM;
}

"lista de" {
    if (DEBUG) printf("Tipo de lista\n");
    yylval.esLista = 1;
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
    yylval.atrib = OPLISTA_IZQ;
    return LISTA_UNARIO_POSTFIJO;
}

">>" {
    if (DEBUG) printf("Operación de listas: >>\n");
    yylval.atrib = OPLISTA_DER;
    return LISTA_UNARIO_POSTFIJO;
}

"$" {
    if (DEBUG) printf("Operación de listas: $\n");
    return LISTA_UNARIO_PREFIJO;
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
    yylval.atrib = OPBIN_MULT_MOD;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "%");
    
    return OP_BINARIO_MULT;
}

"*" {
    if (DEBUG) printf("Operación binaria: *\n");
    yylval.atrib = OPBIN_MULT_POR;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "*");
    
    return OP_BINARIO_MULT;
}

"/" {
    if (DEBUG) printf("Operación binaria: /\n");
    yylval.atrib = OPBIN_MULT_PART;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "/");
    
    return OP_BINARIO_MULT;
}

"==" {
    if (DEBUG) printf("Operación binaria: ==\n");
    yylval.atrib = OPBIN_IGUAL;

    yylval.codigo = malloc(2 * sizeof(char));
    strcpy(yylval.codigo, "==");
    
    return OP_BINARIO_IG;
}

"<" {
    if (DEBUG) printf("Operación binaria: <\n");
    yylval.atrib = OPBIN_COMP_MENOR;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "<");
    
    return OP_BINARIO_COMP;
}

">" {
    if (DEBUG) printf("Operación binaria: >\n");
    yylval.atrib = OPBIN_COMP_MAYOR;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, ">");
    
    return OP_BINARIO_COMP;
}

"<=" {
    if (DEBUG) printf("Operación binaria: <=\n");
    yylval.atrib = OPBIN_COMP_MENORIG;

    yylval.codigo = malloc(2 * sizeof(char));
    strcpy(yylval.codigo, "<=");
    
    return OP_BINARIO_COMP;
}

">=" {
    if (DEBUG) printf("Operación binaria: >=\n");
    yylval.atrib = OPBIN_COMP_MAYORIG;

    yylval.codigo = malloc(2 * sizeof(char));
    strcpy(yylval.codigo, ">=");
    
    return OP_BINARIO_COMP;
}

"!=" {
    if (DEBUG) printf("Operación binaria: !=\n");
    yylval.atrib = OPBIN_DESIGUAL;

    yylval.codigo = malloc(2 * sizeof(char));
    strcpy(yylval.codigo, "!=");
    
    return OP_BINARIO_IG;
}

"&&" {
    if (DEBUG) printf("Operación binaria: &&\n");

    yylval.codigo = malloc(2 * sizeof(char));
    strcpy(yylval.codigo, "&&");
    
    return OP_BINARIO_AND_LOG;
}

"||" {
    if (DEBUG) printf("Operación binaria: ||\n");

    yylval.codigo = malloc(2 * sizeof(char));
    strcpy(yylval.codigo, "||");
    
    return OP_BINARIO_OR_LOG;
}

"^" {
    if (DEBUG) printf("Operación binaria: ^\n");

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "^");
    
    return OP_BINARIO_XOR;
}

"**" {
    if (DEBUG) printf("Operación binaria: **\n");
    return OP_BINARIO_ASTAST;
}

"!" {
    if (DEBUG) printf("Operación unaria: !\n");
    yylval.atrib = OPUN_NO;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "!");
    
    return OP_UNARIO;
}

"#" {
    if (DEBUG) printf("Operación unaria: #\n");
    yylval.atrib = OPUN_HASH;
    return OP_UNARIO;
}

"?" {
    if (DEBUG) printf("Operación unaria: ?\n");
    yylval.atrib = OPUN_INTER;
    return OP_UNARIO;
}

"--" {
    if (DEBUG) printf("Operación unaria: --\n");
    return OP_BINARIO_MENMEN;
}



"+" {
    if (DEBUG) printf("Operación que puede ser o unaria o binaria: +\n");
    yylval.atrib = OPUNBIN_MAS;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "+");
    
    return OP_UN_BIN;
}

"-" {
    if (DEBUG) printf("Operación que puede ser o unaria o binaria: -\n");
    yylval.atrib = OPUNBIN_MENOS;

    yylval.codigo = malloc(sizeof(char));
    strcpy(yylval.codigo, "-");
    
    return OP_UN_BIN;
}


{CADENA} {
    if (DEBUG) printf("Cadena: %s\n", yytext);
    yylval.tipo = cadena;
    yylval.atrib = COD_TIPO_CADENA;
    return CADENA;
}

{CONSTANTE_ENTERO} {
    if (DEBUG) printf("Constante entero: %s\n", yytext);
    yylval.tipo = entero;
    yylval.atrib = COD_TIPO_ENTERO;

    yylval.codigo = malloc(sizeof(char) * 20);
    sprintf(yylval.codigo, "%d",(int)strtol(yytext, NULL, 10));
    
    return CONSTANTE;
}

{CONSTANTE_REAL} {
    if (DEBUG) printf("Constante real: %s\n", yytext);
    yylval.tipo = real;
    yylval.atrib = COD_TIPO_REAL;

    yylval.codigo = malloc(sizeof(char) * 20);
    sprintf(yylval.codigo, "%f",strtof(yytext, NULL));
    
    return CONSTANTE;
}

{CONSTANTE_BOOLEANO} {
    if (DEBUG) printf("Constante booleano: %s\n", yytext);
    yylval.tipo = booleano;
    yylval.atrib = COD_TIPO_BOOLEANO;

    yylval.codigo = malloc(sizeof(char));
    if (strcmp(yytext, "cierto") == 0) strcpy(yylval.codigo, "1");
    else strcpy(yylval.codigo, "0");
    
    return CONSTANTE;
}

{CONSTANTE_CARACTER} {
    if (DEBUG) printf("Constante caracter: %s\n", yytext);
    yylval.tipo = caracter;
    yylval.atrib = COD_TIPO_CARACTER;

    yylval.codigo = malloc(3 * sizeof(char));
    sprintf(yylval.codigo, "%s", yytext);
    
    return CONSTANTE;
}

{IDENTIFICADOR} {
    if (DEBUG) printf("Identificador: %s\n", yytext);
    yylval.lexema = strdup(yytext);
    return IDENTIFICADOR;
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
