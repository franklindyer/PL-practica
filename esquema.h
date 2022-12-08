#define PROGRAMA_ESQ "#include <stdio.h>\n\nint main() {\n%s\nreturn 0;\n}"
#define BLOQUE_ESQ "{\n%s\n%s\n}"
#define ASIGN_ESQ "%s\n%s = %s;"
#define OPUN_ESQ "%s\n%s %s;\n%s = %s %s;"
#define OPBIN_ESQ "%s\n%s\n%s %s;\n%s = %s %s %s;"

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
        nombre = malloc(5 * sizeof(char));
        strcpy(nombre, "short");
    }
    return nombre;
}
