#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

typedef enum {
    marca,
    procedimiento,
    variable,
    parametro_formal,
} tipoEntrada;

typedef enum {
    entero,
    real,
    caracter,
    booleano,
    lista,
    cadena,
    desconocido,
    no_asignado
} dtipo;

typedef struct {
    tipoEntrada entrada;
    char* nombre;
    char* alias;
    dtipo tipoDato;
    unsigned int parametros;
    char esLista;
    int tamDimen;
} entradaTS;

typedef struct {
    int atrib;
    unsigned int parametros;
    char *lexema;
    char *codigo;
    char *tmp;
    dtipo tipo;
    char esLista;
} atributos;

#define YYSTYPE atributos
