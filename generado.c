#include <stdio.h>
#include "listas.c"
int main() {
{
lgestor *x0 = lista_vacia(LISTA_int);
lgestor *x1 = lista_vacia(LISTA_float),*x2 = lista_vacia(LISTA_float);
lgestor *x3 = lista_vacia(LISTA_char);


imprimir_lista(x0);
printf("\n");

int t0;
t0 = recoger_int(x0, -1);
printf("%d\n", t0);



lgestor* t1 = copiar_lista(x0);
dlista* t2 = dato_int(3);
insertar_dato(t1, t2, 0);

x0 = t1;



lgestor* t3 = copiar_lista(x0);
dlista* t4 = dato_int(4);
insertar_dato(t3, t4, 0);

x0 = t3;



lgestor* t5 = copiar_lista(x0);
dlista* t6 = dato_int(4);
insertar_dato(t5, t6, 0);

x0 = t5;



lgestor* t7 = copiar_lista(x0);
dlista* t8 = dato_int(4);
insertar_dato(t7, t8, 0);

x0 = t7;



lgestor* t9 = copiar_lista(x0);
dlista* t10 = dato_int(4);
insertar_dato(t9, t10, 0);

x0 = t9;



lgestor* t11 = copiar_lista(x2);
dlista* t12 = dato_float(2.000000);
insertar_dato(t11, t12, 0);

x1 = t11;



lgestor* t13 = copiar_lista(x1);
dlista* t14 = dato_float(3.000000);
insertar_dato(t13, t14, 1);

x1 = t13;

imprimir_lista(x0);
printf("\n");

imprimir_lista(x1);
printf("\n");

imprimir_lista(x2);
printf("\n");

imprimir_lista(x3);
printf("\n");

int t15;
t15 = x0->largo;
printf("%d\n", t15);

int t16;
t16 = recoger_int(x0, -1);
printf("%d\n", t16);
avanzar_puntero(x0);
avanzar_puntero(x0);
avanzar_puntero(x0);
avanzar_puntero(x0);

int t17;
t17 = recoger_int(x0, -1);
printf("%d\n", t17);
printf("pruebas adicionales"); printf("\n");

imprimir_lista(x0);
printf("\n");


lgestor* t18 = copiar_lista(x0);
borrar_despues(t18, 2);
x0 = t18;

imprimir_lista(x0);
printf("\n");


int t19;
t19 = recoger_int(x0, 0);
printf("%d\n", t19);


int t20;
t20 = recoger_int(x0, 1);
printf("%d\n", t20);


int t21;
t21 = recoger_int(x0, 2);
printf("%d\n", t21);


int t22;
t22 = recoger_int(x0, 3);
printf("%d\n", t22);


int t23;
t23 = recoger_int(x0, 4);
printf("%d\n", t23);


int t24;
t24 = recoger_int(x0, 5);
printf("%d\n", t24);
}
return 0;
}