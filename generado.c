#include <stdio.h>

int main() {
{
int x0;


x0 = 5;
etiq0: ;


int t0;
t0 = x0 < 100;
if(!t0) goto etiq1;

printf("%d\n", x0);


int t1;
t1 = x0 + 7;
x0 = t1;
goto etiq0;
etiq1: ;
}
return 0;
}
