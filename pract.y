%{
#include <stdio.h>
#include <string.h>

int yylineno;

int yylex();

int yyparse();

void yyerror(const char *str)
{
    fprintf(stderr, "error: %s, linea %d\n", str, yylineno);
}

int yywrap()
{
    return 1;
}

main()
{
    yyparse();
}

%}
%error-verbose

%token SUBPROG_CLAVE CABECERA_PROGRAMA
%token TIPO_PRIM TIPO_LISTA
%token NOMB_IF NOMB_THEN NOMB_ELSE NOMB_WHILE NOMB_FOR NOMB_ENTRADA NOMB_SALIDA
%token LISTA_SENT
%token OP_TERN_PRIM_UN OP_TERN_SEG
%token OP_UN_BIN
%token OP_UNARIO
%token OP_BINARIO
%token IDENTIFICADOR CADENA CONSTANTE PARIZQ PARDER CORIZQ CORDER LLAVIZQ LLAVDER
%token COMA PYC
%token ASIGN
%token MARCA_INI_DECLAR_VARIABLES MARCA_FIN_DECLAR_VARIABLES

%start Programa

%left NOMB_WHILE NOMB_FOR
%right NOMB_IF NOMB_THEN NOMB_ELSE

%right OP_UNARIO
%left OP_BINARIO
%right OP_UN_BIN
%left OP_TERN_PRIM_UN OP_TERN_SEG

%left NOMB_ENTRADA NOMB_SALIDA
%left IDENTIFICADOR

%%

Programa : CABECERA_PROGRAMA bloque;

bloque : Inicio_de_bloque Declar_de_variables_locales Declar_de_subprogs Sentencias Fin_de_bloque
;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   |
;

Declar_subprog : Cabecera_subprograma bloque
;

Declar_de_variables_locales : MARCA_INI_DECLAR_VARIABLES Variables_locales MARCA_FIN_DECLAR_VARIABLES
                            |
;

Cabecera_subprograma : SUBPROG_CLAVE IDENTIFICADOR PARIZQ lista_argumentos PARDER
;

Inicio_de_bloque : LLAVIZQ
;

Fin_de_bloque : LLAVDER
;

Variables_locales : Variables_locales Cuerpo_declar_variables
                  |
;

lista_argumentos : lista_argumentos COMA tipo IDENTIFICADOR
                 | tipo IDENTIFICADOR
                 |
;

lista_identificadores : lista_identificadores COMA IDENTIFICADOR
                      | IDENTIFICADOR
                      |
                      | lista_identificadores IDENTIFICADOR error
                        { printf("Hace falta un coma en la lista de identificadores en la linea %d\n", yylineno); }
;

lista_expresiones : lista_expresiones COMA expresion
                  | expresion
                  |
;

Cuerpo_declar_variables : tipo lista_identificadores PYC
;

tipo : TIPO_PRIM
     | TIPO_LISTA TIPO_PRIM
;

Sentencias : Sentencia Sentencias
           |
;

Sentencia : bloque
          | sentencia_asignacion
          | sentencia_if
          | sentencia_while
          | sentencia_for
          | sentencia_entrada
          | sentencia_salida
          | llamada_proced
          | IDENTIFICADOR LISTA_SENT
;

llamada_proced : IDENTIFICADOR PARIZQ lista_expresiones PARDER PYC
;

sentencia_asignacion : IDENTIFICADOR ASIGN expresion PYC
;

sentencia_if : NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia
             : NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia NOMB_ELSE Sentencia
;

sentencia_while : NOMB_WHILE PARIZQ expresion PARDER Sentencia
;

sentencia_for : NOMB_FOR PARIZQ sentencia_asignacion expresion PYC Sentencia PARDER Sentencia
;

sentencia_entrada : NOMB_ENTRADA lista_identificadores PYC
;

sentencia_salida : NOMB_SALIDA lista_expresiones_o_cadena PYC
;

lista_expresiones_o_cadena : expresion COMA lista_expresiones_o_cadena
                           | CADENA COMA lista_expresiones_o_cadena
                           | expresion
                           | CADENA
                           |
;

expresion : PARIZQ expresion PARDER
          | OP_UNARIO expresion
          | expresion OP_BINARIO expresion
          | OP_UN_BIN expresion
          | expresion OP_UN_BIN expresion
          | expresion OP_TERN_PRIM_UN expresion OP_TERN_SEG expresion
          | IDENTIFICADOR
          | CONSTANTE
          | constante_lista
          | error { printf("Error en expresión aritmeto-lógica.\n"); }
;

constante_lista : CORIZQ lista_expresiones CORDER
;
