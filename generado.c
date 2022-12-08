#include <stdio.h>

int main() {
{
float x0,x1;
float x2;
int x3,x4,x5;
int x6;

x0 = 3.000000;

x1 = 4.000000;


float t0;
t0 = x0 + x1;

float t1;
t1 = t0 / 2.000000;
x2 = t1;
etiq0: ; {


int t2;
t2 = x2 > 1.000000;
if(!(t2)) goto etiq1;
{




float t3;
t3 = x2 - 0.500000;
x2 = t3;
printf("z =");

printf("%f\n", x2);
}
}
goto etiq0;
etiq1: ;

x5 = 20;

x4 = 1;

x3 = 0;
etiq2: ; {


int t4;
t4 = x5 > 0;
if(!(t4)) goto etiq3;
{
int x7;

x7 = x4;


int t5;
t5 = x3 + x4;
x4 = t5;

x3 = x7;


int t6;
t6 = x5 - 1;
x5 = t6;
}
}
goto etiq2;
etiq3: ;
printf("fibooo ");

printf("%d\n", x4);

printf("%f ", x0);

printf("%f ", x1);

printf("%f\n", x2);


float t7;
t7 = x2 + 1.000000;


float t8;
t8 = 4.100000 - 0.900000;

float t9;
t9 = t8 / 5.500000;
int t10;
t10 = t7 < t9;
x6 = t10;
}
return 0;
}