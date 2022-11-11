#include <stdio.h>
#include "lex.yy.c"

main() {
    int val;

    val = yylex();
    while (val != 0) {
        val = yylex();
    }
    exit(0);
}
