%{
/*********************************************************
**
** Fichero: PRUEBA.Y
** Función: Pruebas de YACC para practicas de PL
**
********************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/** La siguiente declaracion permite que ’yyerror’ se pueda invocar desde el
***fuente de lex (prueba.l)
**/

void yyerror(const char * msg ) ;

/**La siguiente variable se usará para conocer el numero de la línea
***que se esta leyendo en cada momento. También es posible usar la variable
***’yylineno’ que también nos muestra la línea actual. Para ello es necesario
***invocar a flex con la opción ’-l’ (compatibilidad con lex).
**/

int linea_actual = 1 ;
%}

/**Para uso de mensajes de error sintáctico con BISON.
***La siguiente declaración provoca que ’bison’, ante un error sintáctico,
***visualice mensajes de error con indicación de los tokens que se esperaban
***en el lugar en el que produjo el error (SÓLO FUNCIONA CON BISON>=2.1).
***Para Bison<2.1 es mediante
***
*** #define YYERROR_VERBOSE
***
*** En caso de usar mensajes de error mediante ’mes’ y ’mes2’ (ver apéndice D)
*** nada de lo anterior debe tenerse en cuenta.
**/

%define parse.error verbose

/** A continuación declaramos los nombres simbólicos de los tokens.
*** byacc se encarga de asociar a cada uno un código
**/

%token STRING
%token IDENTIFICADOR
%token TIPO_DATO
%token OP_UNARIO_BINARIO
%token OP_UNARIO_DELANTE
%token OP_UNARIO_LISTAS
%token OP_BINARIO_LISTAS
%token OP_AND_LOGICO
%token OP_OR_LOGICO
%token OP_XOR
%token OP_RELACION
%token OP_IGUALDAD
%token OP_MULT
%token OP_TERNARIO_PRIMERO
%token OP_TERNARIO_SEGUNDO
%token FOR
%token WHILE
%token IF
%token ELSE
%token PAR_IZQ
%token COR_IZQ
%token LLAV_IZQ
%token PAR_DER
%token COR_DER
%token LLAV_DER
%token CONSTANTE
%token PYC
%token INICIO_VAR
%token FIN_VAR
%token COMA
%token MAIN
%token LIST_OF
%token READ
%token WRITE
%token ASIGN

%start programa

%right OP_TERNARIO_SEGUNDO
%right OP_TERNARIO_PRIMERO
%left OP_OR_LOGICO
%left OP_AND_LOGICO
%left OP_XOR
%left OP_IGUALDAD
%left OP_RELACION
%left OP_UNARIO_BINARIO
%left OP_MULT 
%right OP_BINARIO_LISTAS
%right OP_UNARIO_DELANTE OP_UNARIO_LISTAS


%%

/**Sección de producciones que definen la gramática.
**/

programa : MAIN bloque ;

bloque : LLAV_IZQ
         Declar_de_variables_locales
         Declar_de_subprogs
         Sentencias
         LLAV_DER ;

Declar_de_subprogs : Declar_de_subprogs Declar_subprog
                   |
                   ;

Declar_subprog : Cabecera_subprog bloque
                ;

Declar_de_variables_locales : INICIO_VAR 
                              Variables_locales
                              FIN_VAR 
                              | INICIO_VAR FIN_VAR
                              |
                              ;

Variables_locales : Variables_locales Cuerpo_declar_variables
                  | Cuerpo_declar_variables
                  ;

Cuerpo_declar_variables : TIPO_DATO nombres_variables PYC
                        | LIST_OF TIPO_DATO nombres_variables PYC
                        | error
                        ;


nombres_variables : nombres_variables COMA IDENTIFICADOR 
                  | nombres_variables COMA asignacion 
                  | IDENTIFICADOR
                  | asignacion
                  | error IDENTIFICADOR {yyerrok;}
                  ;


Cabecera_subprog : IDENTIFICADOR PAR_IZQ Def_argumentos_subprogr PAR_DER 
		         | IDENTIFICADOR PAR_IZQ  PAR_DER
                 ;


Def_argumentos_subprogr : Def_argumentos_subprogr COMA Def_argumento_subprogr
                        | Def_argumento_subprogr 
                        ;

Def_argumento_subprogr : TIPO_DATO IDENTIFICADOR
                       | LIST_OF TIPO_DATO IDENTIFICADOR 
                       | error IDENTIFICADOR {yyerrok;} ;

Sentencias : Sentencias Sentencia
           | Sentencia;


Sentencia : bloque
                 | sentencia_if
                 | sentencia_if_else
                 | sentencia_while
                 | sentencia_for
                 | sentencia_entrada PYC
                 | sentencia_salida PYC
                 | llamada_proced
                 | expr_o_assign PYC
                 ;

asignacion : IDENTIFICADOR ASIGN expresion ;
expr_o_assign : expresion 
            | asignacion ;

sentencia_if : IF PAR_IZQ expresion PAR_DER Sentencia ;
sentencia_if_else : sentencia_if ELSE Sentencia ;

sentencia_while : WHILE PAR_IZQ expresion PAR_DER Sentencia;

expresion_o_vacio : expr_o_assign
                  | ;
cuerpo_for : expresion_o_vacio PYC expresion_o_vacio PYC expresion_o_vacio ;
sentencia_for : FOR PAR_IZQ cuerpo_for PAR_DER Sentencia ;

sentencia_entrada : READ lista_variables ;

lista_variables : lista_variables COMA IDENTIFICADOR
                | IDENTIFICADOR ;
sentencia_salida : WRITE lista_expresiones_o_cadena ;

lista_expresiones_o_cadena : lista_expresiones_o_cadena COMA expresion
                           | lista_expresiones_o_cadena COMA STRING
                           | expresion
                           | STRING
                           ;

llamada_proced : IDENTIFICADOR PAR_IZQ Argumentos_subprog PAR_DER PYC 
		| IDENTIFICADOR PAR_IZQ PAR_DER PYC ;

Argumentos_subprog : Argumentos_subprog COMA expresion
                   | expresion;
                   
expresion : PAR_IZQ expresion PAR_DER 
          | OP_UNARIO_DELANTE expresion 
          | OP_UNARIO_BINARIO expresion  %prec OP_UNARIO_DELANTE
          | expresion OP_UNARIO_LISTAS 
          | expresion OP_UNARIO_BINARIO expresion 
          | expresion OP_MULT expresion 
          | expresion OP_RELACION expresion 
          | expresion OP_IGUALDAD expresion 
          | expresion OP_OR_LOGICO expresion 
          | expresion OP_AND_LOGICO expresion 
          | expresion OP_XOR expresion 
          | expresion OP_BINARIO_LISTAS expresion 
          | expresion OP_TERNARIO_SEGUNDO expresion
          | expresion OP_TERNARIO_PRIMERO expresion OP_TERNARIO_SEGUNDO expresion 
          | IDENTIFICADOR
          | CONSTANTE  
          | lista
          | error
          ;
          



lista : COR_IZQ agregado COR_DER 
       | COR_IZQ COR_DER;

agregado : agregado COMA expresion
         | expresion ;


%%

/** aqui incluimos el fichero generado por el ’lex’
*** que implementa la función ’yylex’
**/

#ifdef DOSWINDOWS    /* Variable de entorno que indica la plataforma */
#include "lexyy.c"
#else
#include "lex.yy.c"
#endif

void yyerror(const char *msg )
{
    fprintf(stderr,"[Linea %d]: %s\n", yylineno, msg) ;
}
