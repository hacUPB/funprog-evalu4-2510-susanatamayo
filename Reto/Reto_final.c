///AnalizadorTexto/
 //analizador.c         ← Código fuente principal
 //entrada.txt          ← Archivo de texto de entrada
 //salida.txt           ← Archivo de salida generado
//README.md            ← Explicación del programa y cómo compilarlo

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE 1024

// Función para leer todo el contenido del archivo en memoria dinámica
char* leerArchivo(const char* nombreArchivo) {
    FILE* archivo = fopen(nombreArchivo, "r");
    if (!archivo) {
        perror("No se pudo abrir el archivo");
        return NULL;
    }

    fseek(archivo, 0, SEEK_END);
    long tamaño = ftell(archivo);
    rewind(archivo);

    char* buffer = (char*)malloc(tamaño + 1);
    if (!buffer) {
        perror("Memoria insuficiente");
        fclose(archivo);
        return NULL;
    }

    fread(buffer, 1, tamaño, archivo);
    buffer[tamaño] = '\0';

    fclose(archivo);
    return buffer;
}

// Función para contar estadísticas
void contarEstadisticas(char* texto, int* caracteres, int* palabras, int* espacios, int* lineas) {
    *caracteres = *palabras = *espacios = *lineas = 0;
    int enPalabra = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        char c = texto[i];
        if (c != '\n') (*caracteres)++;

        if (isspace(c)) {
            (*espacios)++;
            enPalabra = 0;
            if (c == '\n') (*lineas)++;
        } else if (!enPalabra) {
            enPalabra = 1;
            (*palabras)++;
        }
    }

    if (texto[0] != '\0') (*lineas)++;
}

// Función para contar vocales
void contarVocales(char* texto, int* a, int* e, int* i, int* o, int* u) {
    *a = *e = *i = *o = *u = 0;

    for (int j = 0; texto[j] != '\0'; j++) {
        switch (tolower(texto[j])) {
            case 'a': (*a)++; break;
            case 'e': (*e)++; break;
            case 'i': (*i)++; break;
            case 'o': (*o)++; break;
            case 'u': (*u)++; break;
        }
    }
}

// Función para reemplazar una palabra por otra
char* reemplazarPalabra(char* texto, const char* palabraVieja, const char* palabraNueva) {
    char* resultado;
    int i, contador = 0;
    int lenVieja = strlen(palabraVieja);
    int lenNueva = strlen(palabraNueva);

    // Contar cuántas veces aparece la palabra
    for (i = 0; texto[i] != '\0'; i++) {
        if (strstr(&texto[i], palabraVieja) == &texto[i]) {
            contador++;
            i += lenVieja - 1;
        }
    }

    // Reservar memoria para el nuevo texto
    resultado = (char*)malloc(i + contador * (lenNueva - lenVieja) + 1);
    if (!resultado) {
        perror("Memoria insuficiente para reemplazo");
        return NULL;
    }

    i = 0;
    while (*texto) {
        if (strstr(texto, palabraVieja) == texto) {
            strcpy(&resultado[i], palabraNueva);
            i += lenNueva;
            texto += lenVieja;
        } else {
            resultado[i++] = *texto++;
        }
    }

    resultado[i] = '\0';
    return resultado;
}

// Función para guardar resultados
void guardarResultados(const char* nombreSalida, int caracteres, int palabras, int espacios, int lineas,
                       int a, int e, int i, int o, int u, char* textoFinal) {
    FILE* archivo = fopen(nombreSalida, "w");
    if (!archivo) {
        perror("No se pudo abrir el archivo de salida");
        return;
    }

    fprintf(archivo, "=== Estadísticas del texto ===\n");
    fprintf(archivo, "Caracteres: %d\n", caracteres);
    fprintf(archivo, "Palabras: %d\n", palabras);
    fprintf(archivo, "Espacios: %d\n", espacios);
    fprintf(archivo, "Líneas: %d\n", lineas);

    fprintf(archivo, "\n=== Frecuencia de vocales ===\n");
    fprintf(archivo, "A: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", a, e, i, o, u);

    fprintf(archivo, "\n=== Texto Final ===\n%s\n", textoFinal);

    fclose(archivo);
    printf("Resultados guardados en '%s'\n", nombreSalida);
}

// Menú interactivo
int main() {
    char nombreArchivo[100], nombreSalida[100];
    char palabraBuscar[50], palabraReemplazo[50];
    char* texto = NULL;
    char* textoModificado = NULL;
    int opcion;

    printf("Ingrese el nombre del archivo de entrada (.txt): ");
    scanf("%s", nombreArchivo);
    texto = leerArchivo(nombreArchivo);
    if (!texto) return 1;

    do {
        printf("\n--- Menú ---\n");
        printf("1. Ver estadísticas del texto\n");
        printf("2. Ver frecuencia de vocales\n");
        printf("3. Reemplazar palabra\n");
        printf("4. Guardar resultados\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        int caracteres, palabras, espacios, lineas;
        int a, e, i, o, u;

        switch (opcion) {
            case 1:
                contarEstadisticas(texto, &caracteres, &palabras, &espacios, &lineas);
                printf("\nCaracteres: %d\nPalabras: %d\nEspacios: %d\nLíneas: %d\n", caracteres, palabras, espacios, lineas);
                break;
            case 2:
                contarVocales(texto, &a, &e, &i, &o, &u);
                printf("\nFrecuencia de vocales:\nA: %d\nE: %d\nI: %d\nO: %d\nU: %d\n", a, e, i, o, u);
                break;
            case 3:
                printf("Palabra a buscar: ");
                scanf("%s", palabraBuscar);
                printf("Palabra a reemplazar: ");
                scanf("%s", palabraReemplazo);
                textoModificado = reemplazarPalabra(texto, palabraBuscar, palabraReemplazo);
                if (textoModificado) {
                    free(texto);
                    texto = textoModificado;
                    printf("Reemplazo completado.\n");
                }
                break;
            case 4:
                printf("Nombre del archivo de salida: ");
                scanf("%s", nombreSalida);
                contarEstadisticas(texto, &caracteres, &palabras, &espacios, &lineas);
                contarVocales(texto, &a, &e, &i, &o, &u);
                guardarResultados(nombreSalida, caracteres, palabras, espacios, lineas, a, e, i, o, u, texto);
                break;
            case 0:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida.\n");
        }

    } while (opcion != 0);

    free(texto);
    return 0;
}
