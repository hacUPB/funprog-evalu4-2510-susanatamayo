// 2. **Calcular estadísticas del texto:**
   // - Total de caracteres (excluyendo `\n` si se desea).
    //- Total de palabras (definidas como secuencias separadas por espacios).
    //- Total de espacios en blanco.
    //- Total de líneas.
 #include <stdio.h>
#include <ctype.h>

int main() {
    char c;
    int caracteres = 0;  // Declaración de variables 
    int palabras = 0;
    int espacios = 0;
    int lineas = 0;
    int en_palabra = 0;

    printf("Introduce el texto (Ctrl+D para terminar en Linux/Mac o Ctrl+Z en Windows):\n"); // Indica como finalizar la entrada

    while ((c = getchar()) != EOF) { //Lectura de carateres: Usamos "getchar()"" para leer un carácter a la vez, el ciclo termina cuando se detecta un EOF
        // Contar líneas
        if (c == '\n') {
            lineas++;
        } else {
            caracteres++; // No contamos '\n' como carácter
        }

        // Contar palabras
        if (isspace(c)) {  //detecta si c es un carácter de espacio (puede ser ' ', '\n', '\t', etc.).
            en_palabra = 0; espacios++;
        } else if (!en_palabra) { //Si estamos en un espacio, terminamos la palabra actual (en_palabra = 0)
            en_palabra = 1;
            palabras++;
        }
    }
     // Se imprime en pantalla el resumen de las estadísticas.
    printf("\nEstadísticas del texto:\n"); 
    printf("Total de caracteres (sin saltos de línea): %d\n", caracteres);
    printf("Total de palabras: %d\n", palabras);
    printf("Total de espacios en blanco: %d\n", espacios);
    printf("Total de líneas: %d\n", lineas);

    return 0;
}
