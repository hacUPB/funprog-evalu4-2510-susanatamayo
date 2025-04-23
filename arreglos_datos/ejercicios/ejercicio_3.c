//  Ejercicio 3
//- Leer desde teclado 10 números.
//- Calcular y mostrar la suma, resta y multiplicación acumulada de esos números.

#include <stdio.h>

// Declaración de la función
int maximo(int a, int b);

int main() {
    int num1, num2, mayor;

    // Solicitar los números al usuario
    printf("Ingrese el primer número: ");
    scanf("%d", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);

    // Llamar a la función y mostrar el resultado
    mayor = maximo(num1, num2);
    printf("El número mayor es: %d\n", mayor);

    return 0;
}

// Definición de la función
int maximo(int a, int b) {
    return (a > b) ? a : b;
}
