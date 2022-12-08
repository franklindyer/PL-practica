%{
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include "tabla_simb.c"
#include "traduccion.c"
#include "codigos.h"
#define YYERROR_VERBOSE

#define YYSTYPE atributos

int yylineno;
int fd;

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
    if ((fd = open("generado.c", O_WRONLY | O_CREAT | O_TRUNC), S_IRWXU) < 0) {
        perror("Error en abrir archivo\n");
        exit(-1);
    }
    yyparse();
    close(fd);
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

Programa : CABECERA_PROGRAMA bloque {
                $$.codigo = malloc(sizeof(char) * (strlen($2.codigo) + 100));
                sprintf($$.codigo, PROGRAMA_ESQ, $2.codigo);
                escribir(fd, $$.codigo);
                if (close(fd) < 0)
                    perror("Error en cerrar\n");
            };

bloque : Inicio_de_bloque { 
                TS_InsertaMARCA(); 
                if (Subprog == 1) {
                    TS_CopiarParams();
                }
            } 
         Declar_de_variables_locales 
         Declar_de_subprogs 
         Sentencias 
         Fin_de_bloque { 
                $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen($5.codigo) + 5));
                sprintf($$.codigo, BLOQUE_ESQ, $3.codigo, $5.codigo);
                free($3.codigo);
                free($5.codigo);
                TS_QuitarHastaMarca();
            }
;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   |
;

Declar_subprog : Cabecera_subprograma  { Subprog = 1; }
                 bloque                { Subprog = 0; }
;

Declar_de_variables_locales : MARCA_INI_DECLAR_VARIABLES Variables_locales MARCA_FIN_DECLAR_VARIABLES {
                                    $$.codigo = $2.codigo;
                                }
                            | {
                                    $$.codigo = malloc(sizeof(char));
                                    *$$.codigo = '\n';
                                }
;

Cabecera_subprograma : SUBPROG_CLAVE 
                       IDENTIFICADOR {
                            TS_InsertaSUBPROG($2);
                        }
                       PARIZQ 
                       lista_argumentos 
                       PARDER {
                            TS_AsignarParams($2.lexema, $5.parametros);
                        }
;

Inicio_de_bloque : LLAVIZQ
;

Fin_de_bloque : LLAVDER
;

Variables_locales : Variables_locales Cuerpo_declar_variables {
                            if (*$1.codigo == '\0') $$.codigo = $2.codigo;
                            else {
                                $$.codigo = malloc(sizeof(char) * (1 + strlen($1.codigo) + strlen($2.codigo)));
                                sprintf($$.codigo, "%s\n%s", $1.codigo, $2.codigo);
                                free($2.codigo);
                            }
                            free($1.codigo);
                        }
                  | {
                        $$.codigo = malloc(sizeof(char));
                        *$$.codigo = '\0';
                    }
;

lista_argumentos : lista_argumentos COMA tipo IDENTIFICADOR {
                        $$.parametros = $1.parametros + 1;
                        $4.tipo = $3.tipo;
                        TS_InsertaPARAMF($4);
                    }
                 | tipo IDENTIFICADOR {
                        $$.parametros = 1;
                        $2.tipo = $1.tipo;
                        TS_InsertaPARAMF($2);
                    }
                 |
                 | error
;

lista_identificadores : lista_identificadores COMA IDENTIFICADOR {
                            int n = TS_RecogerEntrada($3.lexema);
                            if (n == -1)
                                printf("(Línea %d) Error semántico: identificador %s no declarado\n", yylineno, $3.lexema);                            
                        }
                      | IDENTIFICADOR {
                            int n = TS_RecogerEntrada($1.lexema);
                            if (n == -1)
                                printf("(Línea %d) Error semántico: identificador %s no declarado\n", yylineno, $1.lexema);                            
                        }
                      | error
;

lista_expresiones : lista_expresiones COMA expresion {
                            $$.parametros = $1.parametros + 1;
                            $3.parametros = $1.parametros + 1;
                            $3.lexema = $1.lexema;
                            if (TS_ComprobarTipoParamf($3.lexema, $3.parametros, $3.tipo) == 0)
                                printf("(Línea %d) Error semántico: argumento %d a procedimiento %s tiene tipo incorrecto\n", yylineno, $3.parametros, $3.lexema);
                        }
                  | expresion {
                            $$.parametros = 1;
                            $1.parametros = 1;
                            $1.lexema = $$.lexema;
                            if (TS_ComprobarTipoParamf($1.lexema, $1.parametros, $1.tipo) == 0)
                                printf("(Línea %d) Error semántico: argumento %d a procedimiento %s tiene tipo incorrecto\n", yylineno, $1.parametros, $1.lexema);
                            
                        }
                  | 
;

Cuerpo_declar_variables : tipo {
                                tipoTmp = $1.tipo;
                                esListaTmp = $1.esLista;
                            } 
                          declar_identificadores 
                          PYC {
                                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + 2));
                                sprintf($$.codigo, "%s %s;", $1.codigo, $3.codigo);
                                free($1.codigo);
                                free($3.codigo);
                            }
                        | error
;

declar_identificadores : declar_identificadores COMA IDENTIFICADOR {
                                $3.tipo = tipoTmp;
                                $3.esLista = esListaTmp;
                                $3.codigo = strdup(varnuevo());
                                if (TS_InsertaIDENT($3) == 1)
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, $3.lexema);
                                
                                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + 1 + strlen($3.codigo)));
                                sprintf($$.codigo, "%s,%s", $1.codigo, $3.codigo);
                                free($1.codigo);
                                free($3.codigo);
                            }
                       | IDENTIFICADOR {
                                $1.tipo = tipoTmp;
                                $1.esLista = esListaTmp;
                                $1.codigo = strdup(varnuevo());
                                if (TS_InsertaIDENT($1) == 1)
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, $1.lexema);
                                
                                $$.codigo = $1.codigo;
                            }
;

tipo : TIPO_PRIM { 
            $$.tipo = $1.tipo; 
            $$.esLista = 0;

            $$.codigo = $1.codigo;
        }
     | TIPO_LISTA TIPO_PRIM { 
            $$.tipo = $2.tipo; 
            $$.esLista = 1;
        }
;

Sentencias : Sentencia Sentencias {
                    if (*$2.codigo == 0) {
                        $$.codigo = $1.codigo;
                    } else {
                        $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + 1));
                        sprintf($$.codigo, "%s\n%s", $1.codigo, $2.codigo);
                    }
                }
           | {
                $$.codigo = malloc(sizeof(char));
                *$$.codigo = '\0';
            }
;

Sentencia : bloque
          | sentencia_asignacion {
                $$.codigo = $1.codigo;
            }
          | sentencia_if
          | sentencia_while
          | sentencia_for
          | sentencia_entrada
          | sentencia_salida
          | llamada_proced
          | lista_sent
;

lista_sent : IDENTIFICADOR LISTA_UNARIO_POSTFIJO PYC {
                    if ($1.esLista != 1)
                        printf("(Línea %d) Error semántico: intento de realizar operación de listas en algo que no sea lista\n", yylineno);
                }
           | LISTA_UNARIO_PREFIJO IDENTIFICADOR PYC {
                    if ($2.esLista != 1)
                        printf("(Línea %d) Error semántico: intento de realizar operación de listas en algo que no sea lista\n", yylineno);
                }
;

llamada_proced : IDENTIFICADOR PARIZQ lista_expresiones PARDER PYC {
                        int n = TS_RecogerProced($1.lexema);
                        if (n == -1)
                            printf("(Línea %d) Error semántico: llamada a procedimiento que no existe\n", yylineno);
                        else {
                            unsigned int params = TS[n].parametros;
                            if (params != $3.parametros)
                                printf("(Línea %d) Error semántico: procedimiento espera %d argumentos\n", yylineno, params);
                        }
                        $3.lexema = $1.lexema;
                    }
;

sentencia_asignacion : IDENTIFICADOR ASIGN expresion PYC {
                                int indice = TS_RecogerEntrada($1.lexema);
                                if (indice == -1) {
                                    printf("(Línea %d) Error semántico: variable %s no ha sido declarado\n", yylineno, $1.lexema);
                                }
                                if (TS[indice].tipoDato != $3.tipo)
                                    printf("(Línea %d) Error semántico: intento de asignar un variable a un valor de tipo distinto\n", yylineno);

                                int n = TS_RecogerEntrada($1.lexema);
                                char* id = TS[n].alias;
                                $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen(id) + strlen($3.tmp) + 5));
                                sprintf($$.codigo, ASIGN_ESQ, $3.codigo, id, $3.tmp);
                                free($3.tmp);
                                free($3.codigo);
                            }
;

sentencia_if : NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia {
                    if ($3.tipo != booleano)
                            printf("(Línea %d) Error semántico: intento de usar condición no booleano en condicional\n", yylineno);
                }
             | NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia NOMB_ELSE Sentencia {
                    if ($3.tipo != booleano)
                            printf("(Línea %d) Error semántico: intento de usar condición no booleano en condicional\n", yylineno);
                }
;

sentencia_while : NOMB_WHILE PARIZQ expresion PARDER Sentencia {
                        if ($3.tipo != booleano)
                            printf("(Línea %d) Error semántico: intento de usar condición de fin de bucle no booleano\n", yylineno);
                    }
;

sentencia_for : NOMB_FOR PARIZQ sentencia_asignacion expresion PYC Sentencia PARDER Sentencia {
                        if ($4.tipo != booleano)
                            printf("(Línea %d) Error semántico: intento de usar condición de fin de bucle no booleano\n", yylineno);
                    }
;

sentencia_entrada : NOMB_ENTRADA lista_identificadores PYC
;

sentencia_salida : NOMB_SALIDA lista_expresiones_o_cadena PYC
;

lista_expresiones_o_cadena : expresion COMA lista_expresiones_o_cadena {
                                    if ($1.tipo != $3.tipo)
                                        printf("(Línea %d) Error semántico: lista de expresiones con tipos distintos\n", yylineno);
                                    $$.tipo = $1.tipo;
                                }
                           | CADENA COMA lista_expresiones_o_cadena {
                                    if ($3.tipo != cadena)
                                        printf("(Línea %d) Error semántico: lista de expresiones con tipos distintos\n", yylineno);
                                    $$.tipo = cadena;
                                }
                           | expresion {
                                    $$.tipo = $1.tipo;
                                }
                           | CADENA {
                                    $$.tipo = cadena;
                                }
                           |
;

expresion : PARIZQ expresion PARDER {
                $$.tipo = $2.tipo;

                $$.codigo = $2.codigo;
                $$.tmp = $2.tmp;
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

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.tmp) + 9));
                sprintf($$.codigo, OPUN_ESQ, $2.codigo, tipo, $$.tmp, $$.tmp, $1.codigo, $2.tmp);
            }
          | expresion OP_BINARIO_MULT expresion {
                if ($1.tipo != $3.tipo)
                    printf("(Línea %d) Error semántico: intento de operar en dos números de tipos distintos\n", yylineno);
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
                $$.tipo = $1.tipo;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_BINARIO_IG expresion {
                if ($1.tipo != $3.tipo || $1.esLista != $3.esLista)
                    printf("(Línea %d) Error semántico: intento de comparar variables de tipos distintos\n", yylineno);
                $$.tipo = booleano;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_BINARIO_COMP expresion {
                if ($1.tipo != entero && $1.tipo != real)
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                else if ($3.tipo != entero && $3.tipo != real)
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                else if ($1.tipo != $3.tipo)
                    printf("(Línea %d) Error semántico: intento de operar en dos números de tipos distintos\n", yylineno);
                $$.tipo = booleano;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_BINARIO_AND_LOG expresion {
                if ($1.tipo != booleano || $3.tipo != booleano)
                    printf("(Línea %d) Error semántico: intento de realizar AND con variables no booleanos\n", yylineno);
                $$.tipo = booleano;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_BINARIO_OR_LOG expresion {
                if ($1.tipo != booleano || $3.tipo != booleano)
                    printf("(Línea %d) Error semántico: intento de realizar OR con variables no booleanos\n", yylineno);
                $$.tipo = booleano;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_BINARIO_XOR expresion {
                if ($1.tipo != booleano || $3.tipo != booleano)
                    printf("(Línea %d) Error semántico: intento de realizar XOR con variables no booleanos\n", yylineno);
                $$.tipo = booleano;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_BINARIO_ASTAST expresion {
                if ($1.tipo != lista || $3.tipo != lista)
                    printf("(Línea %d) Error semántico: intento de concatenar variables que no son listas\n", yylineno);
                $$.tipo = $3.tipo;
                $$.esLista = 1;
            }
          | OP_UN_BIN expresion %prec OP_UNARIO {
               switch ($1.atrib) {
                    case OPUNBIN_MAS :
                        /* ????? */
                        break;

                    case OPUNBIN_MENOS :
                        if ($2.tipo != real && $2.tipo != entero)
                            printf("(Línea %d) Error semántico: intento de negar un variable no numérico\n", yylineno);
                }
                $$.tipo = $2.tipo; 
            }
          | expresion OP_UN_BIN expresion {
                if ($1.tipo != $3.tipo)
                    printf("(Línea %d) Error semántico: intento de operar en dos valores de tipos distintos\n", yylineno);
                if ($1.tipo != real && $1.tipo != entero)
                    printf("(Línea %d) Error semántico: intento de operar en valores no numéricos\n", yylineno);
                if ($3.tipo != real && $3.tipo != entero)
                    printf("(Línea %d) Error semántico: intento de operar en valores no numéricos\n", yylineno);
                $$.tipo = $1.tipo;

                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
            }
          | expresion OP_TERN_PRIM_UN expresion OP_TERN_SEG expresion {
                if ($1.esLista == 0)
                    printf("(Línea %d) Error semántico: intento de realizar operación de listas con algo que no sea lista\n", yylineno);
                if ($1.tipo != $3.tipo)
                    printf("(Línea %d) Error semántico: intento de meter valor en una lista de tipo distinto\n", yylineno);
                if ($5.tipo != entero)
                    printf("(Línea %d) Error semántico: los índices de una lista deben ser números enteros\n", yylineno);
                $$.tipo = $1.tipo;
                $$.esLista = 1;
            }
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

                printf("pr1\n");
                $$.codigo = malloc(sizeof(char));
                $$.codigo = "";
                int n = TS_RecogerEntrada($1.lexema);
                char* id = TS[n].alias;
                $$.tmp = malloc(sizeof(char) * strlen(id));
                $$.tmp = strdup(id); 
                printf("pr2\n");
            }
          | CONSTANTE {
                $$.tipo = $1.tipo;

                $$.codigo = malloc(sizeof(char));
                *$$.codigo = 0;
                $$.tmp = $1.codigo;
            }
          | constante_lista {
                $$.tipo = $1.tipo;
                $$.esLista = 1;
            }
          | error
;

constante_lista : CORIZQ lista_expresiones_o_cadena CORDER {
                        $$.tipo = $2.tipo;
                        $$.esLista = 1;
                    }
;
