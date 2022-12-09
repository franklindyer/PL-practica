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
int err;

int yylex();

int yyparse();

void yyerror(const char *str)
{
    err = 1;
    printf("(Línea %d) Error sintáctico: %s", yylineno, str);
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
                if (err == 0) {
                $$.codigo = malloc(sizeof(char) * (strlen($2.codigo) + 50));
                sprintf($$.codigo, PROGRAMA_ESQ, $2.codigo);
                escribir(fd, $$.codigo);
                }
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
                TS_QuitarHastaMarca();

                if (!err) {
                $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen($4.codigo) + strlen($5.codigo) + 10));
                sprintf($$.codigo, BLOQUE_ESQ, $3.codigo, $4.codigo, $5.codigo);
                free($3.codigo);
                free($4.codigo);
                free($5.codigo);
                }
            }
;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog {
                        if (!err) {
                        $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + 3));
                        sprintf($$.codigo, "%s\n\n%s", $1.codigo, $2.codigo);
                        free($1.codigo);
                        free($2.codigo);
                        }
                    }
                   | {
                        if (!err) {
                        $$.codigo = malloc(sizeof(char));
                        *$$.codigo = 0;
                        }
                    }
;

Declar_subprog : Cabecera_subprograma  { Subprog = 1; }
                 bloque                { Subprog = 0; 
                        if (!err) {
                        $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + 2));
                        sprintf($$.codigo, "%s\n%s", $1.codigo, $3.codigo);
                        free($1.codigo);
                        free($3.codigo);
                        }
                    }
;

Declar_de_variables_locales : MARCA_INI_DECLAR_VARIABLES Variables_locales MARCA_FIN_DECLAR_VARIABLES {
                                    if (!err) $$.codigo = $2.codigo;
                                }
                            | {
                                    if (!err) {
                                    $$.codigo = malloc(2 * sizeof(char));
                                    *$$.codigo = '\n';
                                    }
                                }
;

Cabecera_subprograma : SUBPROG_CLAVE 
                       IDENTIFICADOR {
                            $2.codigo = procnuevo();
                            TS_InsertaSUBPROG($2);
                        }
                       PARIZQ 
                       lista_parametros
                       PARDER {
                            TS_AsignarParams($2.lexema, $5.parametros);

                            if (!err) {
                            $$.codigo = malloc(sizeof(char) * (strlen($2.codigo) + strlen($5.codigo) + 10));
                            sprintf($$.codigo, PROCED_ESQ, $2.codigo, $5.codigo);
                            free($2.codigo);
                            free($5.codigo);
                            }
                        }
;

Inicio_de_bloque : LLAVIZQ
;

Fin_de_bloque : LLAVDER
;

Variables_locales : Variables_locales Cuerpo_declar_variables {
                            if (!err) {
                            if (*$1.codigo == '\0') $$.codigo = $2.codigo;
                            else {
                                $$.codigo = malloc(sizeof(char) * (2 + strlen($1.codigo) + strlen($2.codigo)));
                                sprintf($$.codigo, "%s\n%s", $1.codigo, $2.codigo);
                                free($2.codigo);
                            }
                            free($1.codigo);
                            }
                        }
                  | {
                        if (!err) {
                        $$.codigo = malloc(2 * sizeof(char));
                        *$$.codigo = '\0';
                        }
                    }
;

lista_parametros : lista_parametros COMA tipo IDENTIFICADOR {
                        $$.parametros = $1.parametros + 1;
                        $4.tipo = $3.tipo;
                        $4.codigo = paramnuevo();
                        TS_InsertaPARAMF($4);

                        if (!err) {
                        $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen($4.codigo) + 4));
                        sprintf($$.codigo, "%s, %s %s", $1.codigo, $3.codigo, $4.codigo);
                        free($1.codigo);
                        free($3.codigo);
                        free($4.codigo);
                        }
                    }
                 | tipo IDENTIFICADOR {
                        $$.parametros = 1;
                        $2.tipo = $1.tipo;
                        $2.codigo = paramnuevo();
                        TS_InsertaPARAMF($2);

                        if (!err) {
                        $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + 2));
                        sprintf($$.codigo, "%s %s", $1.codigo, $2.codigo);
                        free($1.codigo);
                        free($2.codigo);
                        }
                    }
                 |
                 | error
;

lista_identificadores : IDENTIFICADOR COMA lista_identificadores {
                            int n = TS_RecogerEntrada($1.lexema);
                            if (n == -1) {
                                printf("(Línea %d) Error semántico: identificador %s no declarado\n", yylineno, $1.lexema);                           
                                err = 1;
                            }

                            if (!err) {
                            char* id = TS[n].alias;
                            char* formato = getCadenaFormato(TS[n].tipoDato);
                            $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen(formato) + strlen(id) + 20));
                            sprintf($$.codigo, ENTRADAS_ESQ, formato, id, $3.codigo);
                            free($3.codigo);
                            free(formato); 
                            }
                        }
                      | IDENTIFICADOR {
                            int n = TS_RecogerEntrada($1.lexema);
                            if (n == -1) {
                                printf("(Línea %d) Error semántico: identificador %s no declarado\n", yylineno, $1.lexema);                           
                                err = 1;
                            }

                            if (!err) {
                            char* id = TS[n].alias;
                            char* formato = getCadenaFormato(TS[n].tipoDato);
                            $$.codigo = malloc(sizeof(char) * (strlen(formato) + strlen(id) + 20));
                            sprintf($$.codigo, ENTRADA_ESQ, formato, id);
                            free(formato);
                            }
                        }
                      | error
;

lista_argumentos : lista_argumentos COMA IDENTIFICADOR {
                            $$.parametros = $1.parametros + 1;
                            $3.parametros = $1.parametros + 1;
                            $3.tipo = $1.tipo;
                            if (TS_ComprobarTipoParamf($3.lexema, $3.parametros, $3.tipo) == 0) {
                                printf("(Línea %d) Error semántico: argumento %d a procedimiento %s tiene tipo incorrecto\n", yylineno, $3.parametros, $3.lexema);
                                err = 1;
                            }

                            if (!err) {
                            int n = TS_RecogerEntrada($3.lexema);
                            char* id = TS[n].alias;
                            $3.codigo = id;
                            $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + 4));
                            sprintf($$.codigo, "%s, &%s", $1.codigo, $3.codigo);
                            free($1.codigo);
                            // free($3.codigo);
                            }
                        }
                  | IDENTIFICADOR {
                            $$.parametros = 1;
                            $1.parametros = 1;
                            $1.lexema = $$.lexema;
                            if (TS_ComprobarTipoParamf($1.lexema, $1.parametros, $1.tipo) == 0) {
                                printf("(Línea %d) Error semántico: argumento %d a procedimiento %s tiene tipo incorrecto\n", yylineno, $1.parametros, $1.lexema);
                                err = 1;
                            }
                            
                            if (!err) {
                            int n = TS_RecogerEntrada($1.lexema);
                            char* id = TS[n].alias;
                            $1.codigo = id;
                            $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + 2));
                            sprintf($$.codigo, "&%s", $1.codigo);
                            }
                        }
                  | 
;

Cuerpo_declar_variables : tipo {
                                tipoTmp = $1.tipo;
                                esListaTmp = $1.esLista;
                            } 
                          declar_identificadores 
                          PYC {
                                if (!err) {
                                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + 3));
                                sprintf($$.codigo, "%s %s;", $1.codigo, $3.codigo);
                                free($1.codigo);
                                free($3.codigo);
                                }
                            }
                        | error
;

declar_identificadores : declar_identificadores COMA IDENTIFICADOR {
                                $3.tipo = tipoTmp;
                                $3.esLista = esListaTmp;
                                $3.codigo = strdup(varnuevo());
                                if (TS_InsertaIDENT($3) == 1) {
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, $3.lexema);
                                    err = 1;
                                }
                                
                                if (!err) { 
                                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + 2 + strlen($3.codigo)));
                                sprintf($$.codigo, "%s,%s", $1.codigo, $3.codigo);
                                free($1.codigo);
                                free($3.codigo);
                                }
                            }
                       | IDENTIFICADOR {
                                $1.tipo = tipoTmp;
                                $1.esLista = esListaTmp;
                                $1.codigo = strdup(varnuevo());
                                if (TS_InsertaIDENT($1) == 1) {
                                    printf("(Línea %d) Error semántico: variable local %s duplicado\n", yylineno, $1.lexema);
                                    err = 1;
                                }
                                
                                if (!err) $$.codigo = $1.codigo;
                            }
;

tipo : TIPO_PRIM { 
            $$.tipo = $1.tipo; 
            $$.esLista = 0;

            if (!err) $$.codigo = $1.codigo;
        }
     | TIPO_LISTA TIPO_PRIM { 
            $$.tipo = $2.tipo; 
            $$.esLista = 1;
        }
;

Sentencias : Sentencia Sentencias {
                    if (!err) {
                    if (*$2.codigo == 0) {
                        $$.codigo = $1.codigo;
                    } else {
                        $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + 3));
                        sprintf($$.codigo, "%s\n%s", $1.codigo, $2.codigo);
                    }
                    }
                }
           | {
                if (!err) {
                $$.codigo = malloc(sizeof(char));
                *$$.codigo = '\0';
                }
            }
;

Sentencia : bloque {
                if (!err) $$.codigo = $1.codigo;
            }
          | sentencia_asignacion {
                if (!err) $$.codigo = $1.codigo;
            }
          | sentencia_if {
                if (!err) $$.codigo = $1.codigo;
            }
          | sentencia_while {
                if (!err) $$.codigo = $1.codigo;
            }
          | sentencia_for {
                if (!err) $$.codigo = $1.codigo;
            }
          | sentencia_entrada {
                if (!err) $$.codigo = $1.codigo;
            }
          | sentencia_salida {
                if (!err) $$.codigo = $1.codigo;
            }
          | llamada_proced {
                if (!err) $$.codigo = $1.codigo;
            }
          | lista_sent
;

lista_sent : IDENTIFICADOR LISTA_UNARIO_POSTFIJO PYC {
                    if ($1.esLista != 1) {
                        printf("(Línea %d) Error semántico: intento de realizar operación de listas en algo que no sea lista\n", yylineno);
                        err = 1;
                    }
                }
           | LISTA_UNARIO_PREFIJO IDENTIFICADOR PYC {
                    if ($2.esLista != 1) {
                        printf("(Línea %d) Error semántico: intento de realizar operación de listas en algo que no sea lista\n", yylineno);
                        err = 1;
                    }
                }
;

llamada_proced : IDENTIFICADOR PARIZQ lista_argumentos PARDER PYC {
                        int n = TS_RecogerProced($1.lexema);
                        if (n == -1) {
                            printf("(Línea %d) Error semántico: llamada a procedimiento que no existe\n", yylineno);
                            err = 1;
                        } else {
                            unsigned int params = TS[n].parametros;
                            if (params != $3.parametros) {
                                printf("(Línea %d) Error semántico: procedimiento espera %d argumentos\n", yylineno, params);
                                err = 1;
                            }
                        }
                        $3.lexema = $1.lexema;

                        if (!err) {
                        char* handle = TS[n].alias;
                        $$.codigo = malloc(sizeof(char) * (4 + strlen(handle) + strlen($3.codigo)));
                        sprintf($$.codigo, "%s(%s);", handle, $3.codigo);
                        free($3.codigo); 
                        }
                    }
;

sentencia_asignacion : IDENTIFICADOR ASIGN expresion PYC {
                                int indice = TS_RecogerEntrada($1.lexema);
                                if (indice == -1) {
                                    printf("(Línea %d) Error semántico: variable %s no ha sido declarado\n", yylineno, $1.lexema);
                                    err = 1;
                                }
                                if (TS[indice].tipoDato != $3.tipo) {
                                    printf("(Línea %d) Error semántico: intento de asignar un variable a un valor de tipo distinto\n", yylineno);
                                    err = 1;
                                }

                                if (!err) {
                                int n = TS_RecogerEntrada($1.lexema);
                                char* id = TS[n].alias;
                                $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen(id) + strlen($3.tmp) + 6));
                                sprintf($$.codigo, ASIGN_ESQ, $3.codigo, id, $3.tmp);
                                free($3.tmp);
                                free($3.codigo);
                                }
                            }
;

sentencia_if : NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia {
                    if ($3.tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición no booleano en condicional\n", yylineno);
                            err = 1;
                    }

                    if (!err) {
                    char* etiq = etiqnuevo();
                    $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen($3.tmp) + 2*strlen(etiq) + strlen($6.codigo) + 20));
                    sprintf($$.codigo, IF_ESQ, $3.codigo, $3.tmp, etiq, $6.codigo, etiq);
                    free(etiq);
                    free($3.codigo);
                    free($3.tmp);
                    free($6.codigo);
                    }
                }
             | NOMB_IF PARIZQ expresion PARDER NOMB_THEN Sentencia NOMB_ELSE Sentencia {
                    if ($3.tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición no booleano en condicional\n", yylineno);
                            err = 1;
                    }

                    if (!err) {
                    char* etiq1 = etiqnuevo();
                    char* etiq2 = etiqnuevo();
                    $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + strlen($3.tmp) + 2*strlen(etiq1) + 2*strlen(etiq1) + strlen($6.codigo) + strlen($8.codigo) + 50));
                    sprintf($$.codigo, IFELSE_ESQ, $3.codigo, $3.tmp, etiq1, $6.codigo, etiq2, etiq1, $8.codigo, etiq2);
                    free(etiq1);
                    free(etiq2);
                    free($3.codigo);
                    free($3.tmp);
                    free($6.codigo);
                    free($8.codigo);
                    }
                }
;

sentencia_while : NOMB_WHILE PARIZQ expresion PARDER Sentencia {
                        if ($3.tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición de fin de bucle no booleano\n", yylineno);
                            err = 1;
                        }

                        if (!err) {
                        char* etiq1 = etiqnuevo();
                        char* etiq2 = etiqnuevo();
                        $$.codigo = malloc(sizeof(char) * (strlen(etiq1) + 2*strlen(etiq2) + strlen($3.codigo) + strlen($3.tmp) + strlen($5.codigo) + 35));
                        sprintf($$.codigo, WHILE_ESQ, etiq1, $3.codigo, $3.tmp, etiq2, $5.codigo, etiq1, etiq2);
                        free(etiq1);
                        free(etiq2);
                        free($3.codigo);
                        free($3.tmp);
                        free($5.codigo);
                        }
                    }
;

sentencia_for : NOMB_FOR PARIZQ sentencia_asignacion expresion PYC Sentencia PARDER Sentencia {
                        if ($4.tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de usar condición de fin de bucle no booleano\n", yylineno);
                            err = 1;
                        }

                        if (!err) {
                        char* etiq1 = etiqnuevo();
                        char* etiq2 = etiqnuevo();
                        $$.codigo = malloc(sizeof(char) * (strlen($3.codigo) + 2*strlen(etiq1) + 2*strlen(etiq2) + strlen($4.codigo) + strlen($4.tmp) + strlen($8.codigo) + strlen($6.codigo) + 40));
                        sprintf($$.codigo, FOR_ESQ, $3.codigo, etiq1, $4.codigo, $4.tmp, etiq2, $8.codigo, $6.codigo, etiq1, etiq2);
                        free($3.codigo);
                        free($4.codigo);
                        free($4.tmp);
                        free($8.codigo);
                        free($6.codigo);
                        }
                    }
;

sentencia_entrada : NOMB_ENTRADA lista_identificadores PYC {
                        if (!err) $$.codigo = $2.codigo;
                    }
;

sentencia_salida : NOMB_SALIDA lista_expresiones_o_cadena PYC {
                        if (!err) $$.codigo = $2.codigo;
                    }
;

lista_expresiones_o_cadena : expresion COMA lista_expresiones_o_cadena {
                                    $$.tipo = $1.tipo;

                                    if (!err) {
                                    char* formato = getCadenaFormato($1.tipo);
                                    $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen(formato) + strlen($1.tmp) + strlen($3.codigo) + 21));
                                    sprintf($$.codigo, SALIDAS_ESQ, $1.codigo, formato, $1.tmp, $3.codigo);
                                    free(formato);
                                    free($1.codigo);
                                    free($3.codigo);
                                    free($1.tmp);
                                    }
                                }
                           | CADENA COMA lista_expresiones_o_cadena {
                                    $$.tipo = cadena;

                                    if (!err) {
                                    $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + 11));
                                    sprintf($$.codigo, "printf(%s);\n%s", $1.codigo, $3.codigo);
                                    free($1.codigo);
                                    free($3.codigo);
                                    }
                                }
                           | expresion {
                                    $$.tipo = $1.tipo;
                                   
                                    if (!err) { 
                                    char* formato = getCadenaFormato($1.tipo);
                                    $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($1.tmp) + 21));
                                    sprintf($$.codigo, SALIDA_ESQ, $1.codigo, formato, $1.tmp);
                                    free(formato);
                                    free($1.codigo);
                                    free($1.tmp);
                                    }
                                }
                           | CADENA {
                                    $$.tipo = cadena;

                                    if (!err) {
                                    $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + 30));
                                    sprintf($$.codigo, "printf(%s); printf(\"\\n\");", $1.codigo);
                                    free($1.codigo);
                                    }
                                }
                           |
;

expresion : PARIZQ expresion PARDER {
                $$.tipo = $2.tipo;

                if (!err) {
                $$.codigo = $2.codigo;
                $$.tmp = $2.tmp;
                }
            }
          | OP_UNARIO expresion {
                switch ($2.atrib) {
                    case OPUN_NO :
                        if ($2.tipo != booleano) {
                            printf("(Línea %d) Error semántico: intento de negar expresión no booleano\n", yylineno);
                            err = 1;
                        }
                        $$.tipo = booleano;
                        break;

                    case OPUN_HASH :
                        if ($2.esLista == 0) {
                            printf("(Línea %d) Error semántico: sólo se puede calcular el número de elementos de una lista\n", yylineno);
                            err = 1;
                        }

                        $$.tipo = entero;
                        break;

                    case OPUN_INTER :
                        if ($2.esLista == 0) {
                            printf("(Línea %d) Error semántico: sólo se puede coger elementos de una lista\n", yylineno);
                            err = 1;
                        }

                        $$.tipo = $2.tipo;
                        break;

                    default :
                        break;
                }                

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.tmp) + 9));
                sprintf($$.codigo, OPUN_ESQ, $2.codigo, tipo, $$.tmp, $$.tmp, $1.codigo, $2.tmp);
                }
            }
          | expresion OP_BINARIO_MULT expresion {
                if ($1.tipo != $3.tipo) {
                    printf("(Línea %d) Error semántico: intento de operar en dos números de tipos distintos\n", yylineno);
                    err = 1;
                }

                switch ($2.atrib) {
                    case OPBIN_MULT_MOD :
                        if ($1.tipo != entero || $3.tipo != entero) {
                            printf("(Línea %d) Error semántico: sólo se puede calcular el módulo de dos enteros\n", yylineno);
                            err = 1;
                        }

                        $$.tipo = entero;
                        break;

                    case OPBIN_MULT_POR :
                        if (($1.tipo != entero && $1.tipo != real) || ($3.tipo != entero && $3.tipo != real)) {
                            printf("(Línea %d) Error semántico: intento de multiplicar expresiones no numéricas\n", yylineno);
                            err = 1;
                        }
                        if ($1.esLista && $3.esLista) {
                            printf("(Línea %d) Error semántico: intento de multiplicar dos listas\n", yylineno);
                            err = 1;
                        }
                        $$.tipo = entero;
                        if ($1.tipo == real || $3.tipo == real) $$.tipo = real;
                        $$.esLista = $1.esLista || $3.esLista;
                }
                $$.tipo = $1.tipo;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_BINARIO_IG expresion {
                if ($1.tipo != $3.tipo || $1.esLista != $3.esLista) {
                    printf("(Línea %d) Error semántico: intento de comparar variables de tipos distintos\n", yylineno);
                    err = 1;
                }

                $$.tipo = booleano;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_BINARIO_COMP expresion {
                if ($1.tipo != entero && $1.tipo != real) {
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                    err = 1;
                } else if ($3.tipo != entero && $3.tipo != real) {
                    printf("(Línea %d) Error semántico: intento de comparar variables no numéricos\n", yylineno);
                    err = 1;
                } else if ($1.tipo != $3.tipo) {
                    printf("(Línea %d) Error semántico: intento de operar en dos números de tipos distintos\n", yylineno);
                    err = 1;
                }

                $$.tipo = booleano;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_BINARIO_AND_LOG expresion {
                if ($1.tipo != booleano || $3.tipo != booleano) {
                    printf("(Línea %d) Error semántico: intento de realizar AND con variables no booleanos\n", yylineno);
                    err = 1;
                }

                $$.tipo = booleano;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 11));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_BINARIO_OR_LOG expresion {
                if ($1.tipo != booleano || $3.tipo != booleano) {
                    printf("(Línea %d) Error semántico: intento de realizar OR con variables no booleanos\n", yylineno);
                    err = 1;
                }

                $$.tipo = booleano;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 12));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_BINARIO_XOR expresion {
                if ($1.tipo != booleano || $3.tipo != booleano) {
                    printf("(Línea %d) Error semántico: intento de realizar XOR con variables no booleanos\n", yylineno);
                    err = 1;
                }

                $$.tipo = booleano;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 12));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_BINARIO_ASTAST expresion {
                if ($1.tipo != lista || $3.tipo != lista) {
                    printf("(Línea %d) Error semántico: intento de concatenar variables que no son listas\n", yylineno);
                    err = 1;
                }

                $$.tipo = $3.tipo;
                $$.esLista = 1;
            }
          | OP_UN_BIN expresion %prec OP_UNARIO {
               switch ($1.atrib) {
                    case OPUNBIN_MAS :
                        /* ????? */
                        break;

                    case OPUNBIN_MENOS :
                        if ($2.tipo != real && $2.tipo != entero) {
                            printf("(Línea %d) Error semántico: intento de negar un variable no numérico\n", yylineno);
                            err = 1;
                        }
                }
                $$.tipo = $2.tipo; 

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($2.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.tmp) + 10));
                sprintf($$.codigo, OPUN_ESQ, $2.codigo, tipo, $$.tmp, $$.tmp, $1.codigo, $2.tmp);
                }
            }
          | expresion OP_UN_BIN expresion {
                if ($1.tipo != $3.tipo) {
                    printf("(Línea %d) Error semántico: intento de operar en dos valores de tipos distintos\n", yylineno);
                    err = 1;
                }
                if ($1.tipo != real && $1.tipo != entero) {
                    printf("(Línea %d) Error semántico: intento de operar en valores no numéricos\n", yylineno);
                    err = 1;
                }
                if ($3.tipo != real && $3.tipo != entero) {
                    printf("(Línea %d) Error semántico: intento de operar en valores no numéricos\n", yylineno);
                    err = 1;
                }
                $$.tipo = $1.tipo;

                if (!err) {
                $$.tmp = tmpnuevo();
                char* tipo = getTipoNombre($$.tipo);
                $$.codigo = malloc(sizeof(char) * (strlen($1.codigo) + strlen($3.codigo) + strlen(tipo) + 2*strlen($$.tmp) + strlen($2.codigo) + strlen($1.tmp) + strlen($3.tmp) + 12));
                sprintf($$.codigo, OPBIN_ESQ, $1.codigo, $3.codigo, tipo, $$.tmp, $$.tmp, $1.tmp, $2.codigo, $3.tmp);
                }
            }
          | expresion OP_TERN_PRIM_UN expresion OP_TERN_SEG expresion {
                if ($1.esLista == 0) {
                    printf("(Línea %d) Error semántico: intento de realizar operación de listas con algo que no sea lista\n", yylineno);
                    err = 1;
                }
                if ($1.tipo != $3.tipo) {
                    printf("(Línea %d) Error semántico: intento de meter valor en una lista de tipo distinto\n", yylineno);
                    err = 1;
                }
                if ($5.tipo != entero) {
                    printf("(Línea %d) Error semántico: los índices de una lista deben ser números enteros\n", yylineno);
                    err = 1;
                }
                $$.tipo = $1.tipo;
                $$.esLista = 1;
            }
          | IDENTIFICADOR {
                int indice = TS_RecogerEntrada($1.lexema);
                if (indice == -1) {
                    printf("(Línea %d) Error semántico: variable %s no ha sido declarado\n", yylineno, $1.lexema);
                    $$.tipo = no_asignado;
                    err = 1;
                } else {
                    entradaTS entrada = TS[indice];
                    $$.tipo = entrada.tipoDato;
                    $$.esLista = entrada.esLista;
                }

                if (!err) {
                $$.codigo = malloc(sizeof(char));
                *$$.codigo = '\0';
                int n = TS_RecogerEntrada($1.lexema);
                char* id = TS[n].alias;
                $$.tmp = malloc(sizeof(char) * (strlen(id) + 1));
                $$.tmp = strdup(id);
                }
            }
          | CONSTANTE {
                $$.tipo = $1.tipo;

                if (!err) {
                $$.codigo = malloc(2 * sizeof(char));
                *$$.codigo = 0;
                $$.tmp = $1.codigo;
                }
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
