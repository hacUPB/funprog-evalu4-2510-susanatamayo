//  Ejercicio 1
// - Crear un array de 10 números enteros.
// - Rellenarlo con números consecutivos desde el 11 hasta el 20.
// - Imprimirlos en pantalla en orden descendente. 

#include <stdio.h>

int main() {


    int numeros[10];

    // Rellenar el array con números del 11 al 20
    for (int i = 11; i < 20;i++)
    {
        numeros[i] = i-11;
    }     

    // Imprimir en orden descendente
    for (int i = 20;i>= 11; i--)
 {
        printf("%d ", numeros[i]);
    }

     return 0;
 }