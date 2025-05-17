#include <stdio.h>
#include <ctype.h>

int main() {
    char letra = 'b';
    char mayuscula = toupper(letra);

    printf("Original: %c\n", letra);
    printf("En mayúscula: %c\n", mayuscula);
    return 0;
}