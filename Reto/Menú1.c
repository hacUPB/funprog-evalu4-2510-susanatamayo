
#include <stdio.h>

int main() {
    int opcion;

    do {
        // Mostrar menú
        printf("\n=== Menú Principal ===\n");
        printf("1. Contar líneas\n");
        printf("2. Contar palabras\n");
        printf("3. Contar caracteres\n");
        printf("4. Buscar una palabra específica\n");
        printf("5. Guardar resultados en un archivo\n");
        printf("6. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Procesar opción
        switch (opcion) {
            case 1:
                printf("Opción 1 seleccionada: Contar líneas\n");
                break;
            case 2:
                printf("Opción 2 seleccionada: Contar palabras\n");
                break;
            case 3:
                printf("Opción 3 seleccionada: Contar caracteres\n");
                break;
            case 4:
                printf("Opción 4 seleccionada: Buscar una palabra específica\n");
                break;
            case 5:
                printf("Opción 5 seleccionada: Guardar resultados\n");
                break;
            case 6:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

    } while (opcion != 6);

    return 0;
}
