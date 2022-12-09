#include <stdio.h>

int main() {
{
int x0;
int x1,x2;


void proc0(int *p0, int *p1, int *p2)
{
int x3;


x3 = 0;
etiq0: ;


int t0;
t0 = x3 < *p2;
if(!t0) goto etiq1;
{





int t2;
t2 = *p0 + *p1;
*p1 = t2;


int t3;
t3 = *p1 - *p0;
*p0 = t3;
}


int t1;
t1 = x3 + 1;
x3 = t1;
goto etiq0;
etiq1: ;
}

x1 = 1;

x2 = 1;

x0 = 20;
proc0(&x1, &x2, &x0);

printf("%d\n", x0);

printf("%d\n", x2);
}
return 0;
}