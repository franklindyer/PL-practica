#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "tabla_structs.c"

#define MAX_TS 500

unsigned int TOPE = 0;
unsigned int Subprog;
unsigned int prevProced;
dtipo tipoTmp;
char esListaTmp;
entradaTS TS[MAX_TS];

int TS_BuscarAntesMarca(char* nombre) {
    int n = TOPE - 1;
    entradaTS entrada;
    
    while (n >= 0) {
        entrada = TS[n];
        if (entrada.entrada == marca) break;
        if (strcmp(entrada.nombre, nombre) == 0) {
            return 1;
        }
        n += -1;
    }
    return 0;
}

void TS_QuitarHastaMarca() {
    int n = TOPE - 1;
    entradaTS entrada;
    tipoEntrada tipo;

    while (n >= 0) {
        entrada = TS[n];
        tipo = entrada.entrada;
        TOPE += -1;
        n += -1;
        if (tipo == marca) break;
        
    }
}

int TS_InsertaIDENT(atributos atrib) {
    if (TS_BuscarAntesMarca(atrib.lexema) == 0) {
        entradaTS nuevo;
        nuevo.entrada = variable;
        nuevo.nombre = strdup(atrib.lexema);
        nuevo.alias = strdup(atrib.codigo);
        nuevo.tipoDato = atrib.tipo;
        nuevo.esLista = atrib.esLista;

        TS[TOPE] = nuevo;
        TOPE++;
        return 0;
    } else {
        return 1;
    }
}

void TS_InsertaMARCA() {

    entradaTS nuevo;
    nuevo.entrada = marca;

    TS[TOPE] = nuevo;
    TOPE++;
}

void TS_InsertaSUBPROG(atributos atrib) {
    entradaTS nuevo;
    nuevo.entrada = procedimiento;
    nuevo.nombre = strdup(atrib.lexema);
    nuevo.alias = strdup(atrib.codigo);
    nuevo.tipoDato = no_asignado;
    nuevo.parametros = atrib.parametros;
    nuevo.esLista = 0;

    TS[TOPE] = nuevo;
    prevProced = TOPE;
    TOPE++;
}

void TS_InsertaPARAMF(atributos atrib) {
    entradaTS nuevo;
    nuevo.entrada = parametro_formal;
    nuevo.nombre = strdup(atrib.lexema);
    nuevo.alias = strdup(atrib.codigo);
    nuevo.tipoDato = atrib.tipo;
    nuevo.esLista = atrib.esLista;

    TS[TOPE] = nuevo;
    TS[prevProced].parametros += 1;
    TOPE++;
}

void TS_CopiarParams() {
    unsigned int n = prevProced + 1;
    entradaTS viejo = TS[n];

    while (viejo.entrada == parametro_formal) {
        entradaTS nuevo;
        nuevo.entrada = variable;
        nuevo.nombre = viejo.nombre;
        nuevo.tipoDato = viejo.tipoDato;
        nuevo.alias = viejo.alias;
        nuevo.esLista = viejo.esLista;        

        TS[TOPE] = nuevo;
        TOPE++;

        n += 1;
        viejo = TS[n];
    }
}

int TS_RecogerEntrada(char* nombre) {
    int n = TOPE - 1;
    entradaTS entrada;

    while (n != 0) {
        entrada = TS[n];
        if (entrada.entrada == variable && 
                strcmp(entrada.nombre, nombre) == 0) {
            return n;
        }    
        n += -1;
    }

    return -1;
}

int TS_RecogerProced(char* nombre) {
    int n = TOPE - 1;
    entradaTS entrada;

    while (n != 0) {
        entrada = TS[n];
        if (entrada.entrada == procedimiento &&
                strcmp(entrada.nombre, nombre) == 0) {
            return n;
        }
        n += -1;
    }

    return -1;
}

void TS_imprimir() {
    int n = 0;
    entradaTS entrada;

    printf("\n");
    while (n < TOPE) {
        entrada = TS[n];
        if (entrada.entrada == marca) {
            printf("%d. marca\n", n);
        } else {
            printf("%d. %s %d %d %d %d\n", n, 
                                  entrada.nombre,
                                  entrada.entrada,
                                  entrada.tipoDato,
                                  entrada.esLista,
                                  entrada.parametros);
        }
        n += 1;
    }
}

int TS_AsignarParams(char* nombre, unsigned int params) {
    int n = TS_RecogerProced(nombre);
    if (n == -1) return -1;
    TS[n].parametros = params;
    return 0;
}

int TS_ComprobarTipoParamf(char* proced, int numarg, dtipo tipo) {
    int n = TS_RecogerProced(proced);
    return (TS[n + numarg].tipoDato == tipo);
}
