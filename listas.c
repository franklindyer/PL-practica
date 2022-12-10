#include <stdio.h>
#include <stdlib.h>

#define LISTA_int 1
#define LISTA_float 2
#define LISTA_char 3

union lista_dato {
    int n;
    float x;
    char c;
};

typedef union lista_dato dlista;

struct lista_nodo {
    dlista* dato;
    struct lista_nodo* sig;
    struct lista_nodo* prev;
};

typedef struct lista_nodo lnodo;

struct lista_gestor {
    lnodo* comienzo;
    lnodo* puntero;
    int largo;
    int tipo;
};

typedef struct lista_gestor lgestor;

lgestor* lista_vacia(int tipo) {
    lgestor* gestor = malloc(sizeof(lgestor));
    gestor->comienzo = NULL;
    gestor->puntero = NULL;
    gestor->largo = 0;
    gestor->tipo = tipo;
    return gestor;
}

void imprimir_ldato(lnodo* nodo, int tipo) {
    if (tipo == LISTA_int) printf("%d", nodo->dato->n);
    if (tipo == LISTA_float) printf("%f", nodo->dato->x);
    if (tipo == LISTA_char) printf("%c", nodo->dato->c);
}

void imprimir_lista(lgestor* gestor) {
    printf("[");
    lnodo* actual = gestor->comienzo;
    if (actual == NULL) {
        printf("]");
        return;
    }
    while(actual->sig != NULL) {
        imprimir_ldato(actual, gestor->tipo);
        printf(",");
        actual = actual->sig;
    }
    imprimir_ldato(actual, gestor->tipo);
    printf("]");
}

lnodo* get_nodo(lgestor* gestor, int n) {
    int i = 0;
    lnodo* actual = gestor->comienzo;
    while (i < n) {
        if (actual == NULL) return NULL;
        actual = actual->sig;
        i++;
    }
    return actual;
}

dlista* dato_int(int x) {
    dlista* dato = malloc(sizeof(dlista));
    dato->n = x;
    return dato;
}

dlista* dato_float(float x) {
    dlista* dato = malloc(sizeof(dlista));
    dato->x = x;
    return dato;
}

dlista* dato_char(char x) {
    dlista* dato = malloc(sizeof(dlista));
    dato->n = x;
    return dato;
}

int recoger_int(lgestor* gestor, int n) {
    lnodo* nodo = get_nodo(gestor, n);
    if (n == -1) nodo = gestor->puntero;
    if (nodo == NULL) {
        printf("Error de ejecución: intento de acceder a elemento que no existe\n");
        return 0;
    }
    return nodo->dato->n;
}

float recoger_float(lgestor* gestor, int n) {
    lnodo* nodo = get_nodo(gestor, n);
    if (nodo == NULL) {
        printf("Error de ejecución: intento de acceder a elemento que no existe\n");
        return 0;
    }
    return nodo->dato->x;
}

char recoger_char(lgestor* gestor, int n) {
    lnodo* nodo = get_nodo(gestor, n);
    if (nodo == NULL) {
        printf("Error de ejecución: intento de acceder a elemento que no existe\n");
        return ' ';
    }
    return nodo->dato->c;
}



void insertar_dato(lgestor* gestor, dlista* dato, int n) {
    if (n < 0 || n > gestor->largo)
        printf("Error de ejecución: intento de insertar elemento en índice no valido\n");

    lnodo* nodo = malloc(sizeof(lnodo));
    nodo->dato = dato;
   
    if (n < gestor->largo) {
        lnodo* sig_nodo = get_nodo(gestor, n);
        nodo->sig = sig_nodo;
        sig_nodo->prev = nodo;
    }

    if (n > 0) {
        lnodo* prev_nodo = get_nodo(gestor, n-1);
        nodo->prev = prev_nodo;
        prev_nodo->sig = nodo;
    }

    if (n == 0) {
        gestor->comienzo = nodo;
    }   
 
    gestor->largo += 1;
    gestor->puntero = gestor->comienzo;
}

dlista* copiar_dato(dlista* dato) {
    dlista* nuevo = malloc(sizeof(dlista));
    *nuevo = *dato;
    return nuevo;
}

lgestor* copiar_lista(lgestor* gestor) {
    int i = 0;
    lnodo* actual = gestor->comienzo;
    lgestor* gest_nuevo = lista_vacia(gestor->tipo);

    while(actual != NULL) {
        dlista* d = copiar_dato(actual->dato);
        insertar_dato(gest_nuevo, d, i);
        i++;
        actual = actual->sig;
    }

    return gest_nuevo;
}

void avanzar_puntero(lgestor* gestor) {
    if (gestor->puntero != NULL && gestor->puntero->sig != NULL)
        gestor->puntero = gestor->puntero->sig;
}

void retroceder_puntero(lgestor* gestor) {
    if (gestor->puntero != NULL && gestor->puntero->prev != NULL)
        gestor->puntero = gestor->puntero->prev;
}

void comienzo_puntero(lgestor* gestor) {
    gestor->puntero = gestor->comienzo;
}

int borrar_posicion(lgestor* gestor, int n) {
    lnodo* nodo = get_nodo(gestor, n);
    if (nodo == NULL) return 1;

    if (nodo == gestor->comienzo)
        gestor->comienzo = nodo->sig;

    gestor->largo += -1;
    if (nodo->sig != NULL) {
        nodo->sig->prev = nodo->prev;
    }
    if (nodo->prev != NULL) {
        nodo->prev->sig = nodo->sig;
    }

    return 0;
}

void borrar_despues(lgestor* gestor, int n) {
    while (borrar_posicion(gestor, n) == 0);
}

/*
int main() {
    dlista* d1 = dato_entero(5);
    dlista* d2 = dato_entero(4);
    dlista* d3 = dato_entero(3);
    
    lgestor* l1 = lista_vacia(LISTA_int);
    imprimir_lista(l1);
    insertar_dato(l1, d1, 0);
    insertar_dato(l1, d2, 0);
    insertar_dato(l1, d3, 0);
    imprimir_lista(l1);

    lgestor* l2 = copiar_lista(l1);
    dlista* d4 = dato_entero(6);
    insertar_dato(l2, d4, 0);
    imprimir_lista(l2);
    imprimir_lista(l1);
    return 0;
}
*/
