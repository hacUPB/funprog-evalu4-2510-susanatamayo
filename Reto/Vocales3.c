//3. **Calcular la frecuencia de aparición de las vocales (a, e, i, o, u)**
 // - Mostrar cuántas veces aparece cada vocal (mayúsculas y minúsculas combinadas).

 #include <stdio.h>
#include <ctype.h> 

void contarVocalesDesdeArchivo(const char *nombreArchivo) {  // Abre el arcchivo y lee caracter por caractere, y cuenta cauntas veces aparece. 
    FILE *archivo = fopen(nombreArchivo, "r"); //Cuando el archivo no se puede abrir o no existe, fopen devuelve NULL.

    if (archivo == NULL) {
        printf("No se pudo abrir el archivo: %s\n", nombreArchivo);  //Cuando el archivo no se abre correctamente, muestra un mensaje de error y sale de la función usando return.

    }

    int a = 0, e = 0, i = 0, o = 0, u = 0;  // Se crean 5 variabales enteras correspondientes de las 5 vocales del abecadario, para contar cuantas veces aparece cada una de las vocales. 
    char c;

    while ((c = fgetc(archivo)) != EOF) {  // Lee el archivo caracter por caracterer, el ciclo de While termina cuando termina el archivo (EOF)
        c = tolower(c); // El comando [tolower(c)] asegura que las letras mayúsculas se traten como minúsculas.
        switch (c) {   // El comando switch compara el carácter con cada vocal y aumenta el contador correspondiente si coincide.
            case 'a': a++; break;
            case 'e': e++; break;
            case 'i': i++; break;
            case 'o': o++; break;
            case 'u': u++; break;
        }
    }

    fclose(archivo); // Cierra el archivo para liberar recursos.

    // Mostrar resultados
    printf("Frecuencia de vocales en el archivo:\n");
    printf("a: %d\n", a);
    printf("e: %d\n", e);
    printf("i: %d\n", i);
    printf("o: %d\n", o);
    printf("u: %d\n", u);
}

int main() {
    const char *nombreArchivo = "texto.txt"; 
    contarVocalesDesdeArchivo(nombreArchivo);
    return 0;
}
