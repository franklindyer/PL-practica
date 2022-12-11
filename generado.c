#include <stdio.h>
#include "listas.c"
int main() {
{
lgestor *x0 = lista_vacia(LISTA_int);
int x1;




lgestor* t0 = copiar_lista(x0);
dlista* t1 = dato_int(1);
insertar_dato(t0, t1, 0);

x0 = t0;

x1 = 0;
etiq0: ;


int t2;
t2 = x1 < 5;
if(!t2) goto etiq1;
{





int t4;
t4 = 1 - 2;

lgestor* t5;
t5 = mapear_mul_int(x0, t4);
lgestor* t6;
t6 = concatenar(x0, t5);
x0 = t6;
}


int t3;
t3 = x1 + 1;
x1 = t3;
goto etiq0;
etiq1: ;

imprimir_lista(x0);
printf("\n");
}
return 0;
}