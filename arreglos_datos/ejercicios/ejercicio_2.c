//  Ejercicio 2
// - Crear un array que contenga números pares desde el 2 hasta el 10.
// - Imprimir los valores en orden ascendente.

#include <stdio.h>

int main() 
{
    int numeros[5];

    // Rellenar el array con números pares del 2 al 10
    for (int i = 2;i < 10;i ++) 
    {
        numeros[i] = 2 * (i + 1); // 2, 4, 6, 8, 10
    }

    // Imprimir en orden ascendente
    for (int i = 2;i < 10;i ++)
    {
        printf("%d ", numeros[i]);
    }

    printf("\n");
   return 0;
}