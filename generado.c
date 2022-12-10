#include <stdio.h>
#include "listas.c"
int main() {
{
float x0;
float x1;
int x2;


void proc0(float *p0, int *p1, float *p2)
{
float x3;
int x4;
float x5;


x3 = 1.000000;

*p2 = 1.000000;

x5 = 1.000000;

x4 = 0;
etiq0: ;


int t0;
t0 = x4 < *p1;
if(!t0) goto etiq1;
{





float t2 = *p0 / x5;
float t3 = x3 * t2;
x3 = t3;


float t4;
t4 = *p2 + x3;
*p2 = t4;


float t5;
t5 = x5 + 1.000000;
x5 = t5;
}


int t1;
t1 = x4 + 1;
x4 = t1;
goto etiq0;
etiq1: ;
}

x0 = 0.000000;

x2 = 10;

x1 = 1.000000;
proc0(&x1, &x2, &x0);

printf("%f\n", x0);

x1 = 2.000000;
proc0(&x1, &x2, &x0);

printf("%f\n", x0);
}
return 0;
}