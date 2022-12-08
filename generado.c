#include <stdio.h>

int main() {
{
int x0;
int x1;
int x2;
int x3;

x0 = 100;

x2 = 2;
etiq3: ; {


int t0;
t0 = x2 < x0;
if(!(t0)) goto etiq4;
{



x1 = 2;

x3 = 1;
etiq0: ; {


int t1;
t1 = x1 < x2;
if(!(t1)) goto etiq1;
{





int t2;
t2 = x2 % x1;

int t3;
t3 = t2 != 0;
int t4;
t4 = x3 && t3;
x3 = t4;


int t5;
t5 = x1 + 1;
x1 = t5;
}
}
goto etiq0;
etiq1: ;

if(!(x3)) goto etiq2;

printf("%d\n", x2);
etiq2: ;


int t6;
t6 = x2 + 1;
x2 = t6;
}
}
goto etiq3;
etiq4: ;
}
return 0;
}