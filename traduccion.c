#include <stdio.h>
#include "esquema.h"

#define MAX_NOMB_LEN 10

typedef struct atributos atribs;

static int numvars = 0;
static int numtmps = 0;
static int numetiqs = 0;

char* varnuevo() {
    char* nomb = malloc(sizeof(char) * MAX_NOMB_LEN);
    sprintf(nomb, "x%d", numvars);
    numvars++;
    return nomb;
}

char* tmpnuevo() {
    char* nomb = malloc(sizeof(char) * MAX_NOMB_LEN);
    sprintf(nomb, "t%d", numtmps);
    numtmps++;
    return nomb;
}

char* etiqnuevo() {
    char* nomb = malloc(sizeof(char) * (MAX_NOMB_LEN + 3));
    sprintf(nomb, "etiq%d", numetiqs);
    numetiqs++;
    return nomb;
}

void escribir(int fd, char* texto) {
    if (write(fd, texto, strlen(texto)) < 0)
        perror("Error en escribir código\n");
}

