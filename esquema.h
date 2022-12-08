#define PROGRAMA_ESQ "#include <stdio.h>\n\nint main() {\n%s\nreturn 0;\n}"
#define BLOQUE_ESQ "{\n%s\n%s\n}"
#define ASIGN_ESQ "%s\n%s = %s;"
#define OPUN_ESQ "%s\n%s %s;\n%s = %s %s;"
#define OPBIN_ESQ "%s\n%s\n%s %s;\n%s = %s %s %s;"
#define ENTRADA_ESQ "scanf(\"%s\", &%s);"
#define ENTRADAS_ESQ "scanf(\"%s\\n\", &%s);\n%s"
#define SALIDA_ESQ "%s\nprintf(\"%s\\n\", %s);"
#define SALIDAS_ESQ "%s\nprintf(\"%s \", %s);\n%s"
#define WHILE_ESQ "%s: ; {\n%s\nif(!(%s)) goto %s;\n%s\n}\ngoto %s;\n%s: ;"
#define IFELSE_ESQ "%s\nif(!(%s)) goto %s;\n%s\ngoto %s;\n%s: ;\n%s\n%s: ;"
#define IF_ESQ "%s\nif(!(%s)) goto %s;\n%s\n%s: ;"
#define FOR_ESQ "%s\n%s: ;\n%s\nif(!%s) goto %s;\n%s\n%s\ngoto %s;\n%s: ;"

enum dtipo;

char* getTipoNombre(dtipo tipo) {
    char* nombre;
    if (tipo == entero) {
        nombre = malloc(3 * sizeof(char));
        strcpy(nombre, "int");
    } else if (tipo == real) {
        nombre = malloc(5 * sizeof(char));
        strcpy(nombre, "float");
    } else if (tipo == caracter) {
        nombre = malloc(4 * sizeof(char));
        strcpy(nombre, "char");
    } else if (tipo == booleano) {
        nombre = malloc(3 * sizeof(char));
        strcpy(nombre, "int");
    }
    return nombre;
}

char* getCadenaFormato(dtipo tipo) {
    char* formato = malloc(2 * sizeof(char));
    if (tipo == entero) {
        strcpy(formato, "%d");
    } else if (tipo == real) {
        strcpy(formato, "%f");
    } else if (tipo == caracter) {
        strcpy(formato, "%c");
    } else if (tipo == booleano) {
        strcpy(formato, "%d");
    } else if (tipo == cadena) {
        strcpy(formato, "%s");
    }
    return formato;
}
