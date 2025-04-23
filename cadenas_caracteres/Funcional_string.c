#include <stdio.h>
#include <string.h>

int main() {
    char origen[] = "Hola, mundo!";
    char destino[50];  // Aseguramos espacio suficiente

    strcpy(destino, origen);

    printf("Cadena copiada: %s\n", destino);
    return 0;
}