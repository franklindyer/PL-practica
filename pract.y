%{
#include <stdio.h>
#include <string.h>
#include "tabla_simb.c"
#include "codigos.h"
#define YYERROR_VERBOSE

#define YYSTYPE atributos

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

int main()
{
    yyparse();
}

%}
%error-verbose

%token SUBPROG_CLAVE CABECERA_PROGRAMA
%token TIPO_PRIM TIPO_LISTA
%token NOMB_IF NOMB_THEN NOMB_ELSE NOMB_WHILE NOMB_FOR NOMB_ENTRADA NOMB_SALIDA
%token LISTA_UNARIO_PREFIJO LISTA_UNARIO_POSTFIJO
%token OP_TERN_PRIM_UN 
%token OP_TERN_SEG
%token OP_UN_BIN
%token OP_UNARIO
%token OP_BINARIO_OR_LOG 
%token OP_BINARIO_AND_LOG 
%token OP_BINARIO_XOR 
%token OP_BINARIO_IG 
%token OP_BINARIO_COMP 
%token OP_BINARIO_MULT
%token IDENTIFICADOR CADENA CONSTANTE PARIZQ PARDER CORIZQ CORDER LLAVIZQ LLAVDER
%token COMA PYC
%token ASIGN
%token MARCA_INI_DECLAR_VARIABLES MARCA_FIN_DECLAR_VARIABLES

%start Programa

%left NOMB_WHILE NOMB_FOR

%left OP_BINARIO_OR_LOG
%left OP_BINARIO_AND_LOG
%left OP_BINARIO_XOR
%left OP_BINARIO_IG
%left OP_BINARIO_COMP
%left OP_BINARIO_ASTAST
%left OP_BINARIO_MENMEN
%left OP_UN_BIN
%left OP_BINARIO_MULT
%right OP_UNARIO
%left OP_TERN_PRIM_UN 
%left OP_TERN_SEG


%%

Programa : CABECERA_PROGRAMA bloque;

bloque : Inicio_de_bloque { 
                TS_InsertaMARCA(); 
                if (Subprog == 1) {
                    TS_CopiarParams();
                }
            } 
         Declar_de_variables_locales 
         Declar_de_subprogs 
         Sentencias 
         Fin_de_bloque { TS_QuitarHastaMarca(); }
;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   |
;

Declar_subprog : Cabecera_subprograma  { Subprog = 1; }
                 bloque                { Subprog = 0; }
;

Declar_de_variables_locales : MARCA_INI_DECLAR_VARIABLES Variables_locales MARCA_FIN_DECLAR_VARIABLES {
                                    TS_imprimir();
                                }
                            |
;

Cabecera_subprograma : SUBPROG_CLAVE 
                       IDENTIFICADOR {
                            TS_InsertaSUBPROG($2);
                        }
                       PARIZQ 
                       lista_argumentos 
                       PARDER
;

Inicio_de_bloque : LLAVIZQ
;

Fin_de_bloque : LLAVDER
;

Variables_locales : Variables_locales Cuerpo_declar_variables
                  |
;

lista_argumentos : lista_argumentos COMA tipo IDENTIFICADOR {
                        $4.tipo = $3.tipo;
                        TS_InsertaPARAMF($4);
                    }
                 | tipo IDENTIFICADOR {
                        $2.tipo = $1.tipo;
                        TS_InsertaPARAMF($2);
                    }
                 |
                 | error
;

lista_identificadores : lista_identificadores COMA IDENTIFICADOR
                      | IDENTIFICADOR
                      | error
;

lista_expresiones : lista_expresiones COMA expresion
                  | expresion
                  | 
;

Cuerpo_declar_variables : tipo {
                                tipoTmp = $1.tipo;
                                esListaTmp = $1.esLista;
                            } 
                          declar_identificadores 
                          PYC
                        | error
;

declar_identificadores : declar_identificadores COMA IDENTIFICADOR {
                                $3.tipo = tipoTmp;
                                $3.esLista = esListaTmp;
                                if (TS_InsertaIDENT($3) == 1)
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, $3.lexema);
                            }
                       | IDENTIFICADOR {
                                $1.tipo = tipoTmp;
                                $1.esLista = esListaTmp;
                                if (TS_InsertaIDENT($1) == 1)
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, $1.lexema);
                            }
;

tipo : TIPO_PRIM { 
            $$.tipo = $1.tipo; 
            $$.esLista = 0;
        }
     | TIPO_LISTA TIPO_PRIM { 
            $$.tipo = $2.tipo; 
            $$.esLista = 1;
        }
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
          | lista_sent
;

lista_sent : IDENTIFICADOR LISTA_UNARIO_POSTFIJO PYC
           | LISTA_UNARIO_PREFIJO IDENTIFICADOR PYC
;

llamada_proced : IDENTIFICADOR PARIZQ lista_expresiones PARDER PYC
;

sentencia_asignacion : IDENTIFICADOR ASIGN expresion PYC
;

sentencia_if : NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia
             | NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia NOMB_ELSE Sentencia
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

expresion : PARIZQ expresion PARDER {
                $$.tipo = $2.tipo;
            }
          | OP_UNARIO expresion {
                switch ($2.atrib) {
                    case OPUN_NO :
                        if ($2.tipo != booleano)
                            printf("(Línea %d) Error semántico: intento de negar expresión no booleano\n", yylineno);
                        $$.tipo = booleano;
                        break;

                    case OPUN_HASH :
                        if ($2.esLista == 0)
                            printf("(Línea %d) Error semántico: sólo se puede calcular el número de elementos de una lista\n", yylineno);
                        $$.tipo = entero;
                        break;

                    case OPUN_INTER :
                        if ($2.esLista == 0)
                            printf("(Línea %d) Error semántico: sólo se puede coger elementos de una lista\n", yylineno);
                        $$.tipo = $2.tipo;
                        break;

                    default :
                        break;
                }                
            }
          | expresion OP_BINARIO_MULT expresion {
                switch ($2.atrib) {
                    case OPBIN_MULT_MOD :
                        if ($1.tipo != entero || $3.tipo != entero)
                            printf("(Línea %d) Error semántico: sólo se puede calcular el módulo de dos enteros\n", yylineno);
                        $$.tipo = entero;
                        break;

                    case OPBIN_MULT_POR :
                        if (($1.tipo != entero && $1.tipo != real) || ($3.tipo != entero && $3.tipo != real)) {
                            printf("(Línea %d) Error semántico: intento de multiplicar expresiones no numéricas\n", yylineno);
                        }
                        if ($1.esLista && $3.esLista) {
                            printf("(Línea %d) Error semántico: intento de multiplicar dos listas\n", yylineno);
                        }
                        $$.tipo = entero;
                        if ($1.tipo == real || $3.tipo == real) $$.tipo = real;
                        $$.esLista = $1.esLista || $3.esLista;
                }
                $$.tipo = entero;
            }
          | expresion OP_BINARIO_IG expresion {
                $$.tipo = booleano;
            }
          | expresion OP_BINARIO_COMP expresion {
                if ($1.tipo != entero && $1.tipo != real)
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                else if ($3.tipo != entero && $3.tipo != real)
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                $$.tipo = booleano;
            }
          | expresion OP_BINARIO_AND_LOG expresion {
                if ($1.tipo != booleano || $3.tipo != booleano)
                    printf("(Línea %d) Error semántico: intento de realizar AND con variables no booleanos\n", yylineno);
                $$.tipo = booleano;
            }
          | expresion OP_BINARIO_OR_LOG expresion {
                if ($1.tipo != booleano || $3.tipo != booleano)
                    printf("(Línea %d) Error semántico: intento de realizar OR con variables no booleanos\n", yylineno);
                $$.tipo = booleano;
            }
          | expresion OP_BINARIO_XOR expresion {
                if ($1.tipo != booleano || $3.tipo != booleano)
                    printf("(Línea %d) Error semántico: intento de realizar XOR con variables no booleanos\n", yylineno);
                $$.tipo = booleano;
            }
          | expresion OP_BINARIO_ASTAST expresion {
                if ($1.tipo != lista || $3.tipo != lista)
                    printf("(Línea %d) Error semántico: intento de concatenar variables que no son listas\n", yylineno);
                $$.tipo = lista;
            }
          | OP_UN_BIN expresion %prec OP_UNARIO {
                
            }
          | expresion OP_UN_BIN expresion
          | expresion OP_TERN_PRIM_UN expresion OP_TERN_SEG expresion
          | IDENTIFICADOR {
                int indice = TS_RecogerEntrada($1.lexema);
                if (indice == -1) {
                    printf("(Línea %d) Error semántico: variable %s no ha sido declarado\n", yylineno, $1.lexema);
                    $$.tipo = no_asignado;
                } else {
                    entradaTS entrada = TS[indice];
                    $$.tipo = entrada.tipoDato;
                    $$.esLista = entrada.esLista;
                } 
            }
          | CONSTANTE {
                $$.tipo = $1.tipo;
            }
          | constante_lista
          | error
;

constante_lista : CORIZQ lista_expresiones CORDER
;
