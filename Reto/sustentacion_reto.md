# Sustentación del reto 🏋🏻‍♀️

## 1. Explicación del análisis del problema 🧠
El problema consistía en desarrollar un programa en C que leyera el contenido de un archivo de texto y permitiera al usuario interactuar con ese contenido mediante un menú de opciones. Las funciones principales que debía cumplir el programa eran:

- Leer correctamente el archivo completo.

- Contar estadísticas del texto como: número de caracteres, palabras, espacios y líneas.

- Contar cuántas veces aparece cada vocal (A, E, I, O, U).

- Permitir al usuario reemplazar una palabra por otra dentro del texto.

- Guardar los resultados obtenidos y el texto final en un nuevo archivo.

### ¿Cómo entendi el problema? ❓
Comprendi que el objetivo era ofrecer al usuario una herramienta básica de análisis de texto con funcionalidades de procesamiento, edición y exportación de resultados. El programa debía ser interactivo, claro y manejable para cualquier persona que trabajara con archivos .txt.
 
### Decisiones tomadas para resolverlo: 💭
1. Uso de memoria dinámica:
Se decidió leer todo el archivo en memoria utilizando malloc para poder procesar el texto completo fácilmente, sin depender del tamaño del archivo.

2. Separación en funciones:
Cada tarea del programa fue dividida en funciones específicas (leerArchivo, contarEstadisticas, contarVocales, etc.) para mantener un código limpio, modular y fácil de mantener.

3. Interfaz por consola:
Opté por un menú de opciones interactivo que permite al usuario ejecutar diferentes tareas paso a paso. Esto mejora la usabilidad y permite trabajar sobre el mismo texto cargado sin necesidad de reabrir el archivo cada vez.

4. Reemplazo de palabras:
Para hacer posible el reemplazo, se diseñó una función que calcula cuántas veces aparece la palabra buscada y luego construye una nueva cadena con el texto modificado. Se eligió esta estrategia para evitar errores al modificar el mismo texto en memoria.

5. Validación de errores:
Se incluyeron verificaciones básicas (como fallos al abrir archivos o falta de memoria) para garantizar que el programa funcione correctamente incluso ante problemas comunes.

6. Salida en archivo:
Se implementó una opción para guardar los resultados en un archivo nuevo, lo cual es útil para conservar el análisis o compartirlo.

### ¿Por qué tomamos esas decisiones? 🤷🏻‍♀️
1. Eficiencia y simplicidad: Leer el archivo completo permite trabajar más fácilmente con el texto en memoria que si se leyera línea por línea.

2. Claridad del código: Dividir el programa en funciones hace que el código sea más entendible y permite una depuración más sencilla.

3. Experiencia del usuario: Un menú interactivo guía al usuario paso a paso y evita que tenga que aprender comandos complejos.

4. Reusabilidad: Al dejar el texto modificado en memoria, el usuario puede seguir trabajando sobre ese mismo texto sin repetir procesos.

5. Robustez: Manejar errores comunes evita fallos inesperados durante la ejecución.

## 2. Estrategia de solución 💡
El enfoque general del código se basa en una estructura modular que divide el programa en funciones independientes, cada una con un propósito claro. Esto facilita la comprensión, el mantenimiento y la escalabilidad del código. A continuación, se describe la estrategia seguida:


### 🧱 Estructura general del programa
El programa está compuesto por tres bloques principales:

1. Entrada del usuario (archivo de texto y menú).

2. Procesamiento del texto (estadísticas, vocales, reemplazos).

3. Salida de resultados (pantalla o archivo).

### 🔧 Funciones o módulos principales
1. ```leerArchivo(const char* nombreArchivo)```
- Propósito: Leer el archivo completo y guardar su contenido en memoria dinámica.

- Conexión: Llamada al iniciar el programa; su salida (```char*```) se usa en todo el programa para trabajar sobre el texto.

2. ```contarEstadisticas(char* texto, int* caracteres, int* palabras, int* espacios, int* lineas)```
- Propósito: Contar cuántos caracteres, palabras, espacios y líneas hay en el texto.

- Conexión: Se invoca desde el menú para mostrar estadísticas o guardar resultados.

### 3. ```contarVocales(char* texto, int* a, int* e, int* i, int* o, int* u)```
- Propósito: Contar cuántas veces aparece cada vocal.

- Conexión: Se usa al seleccionar la opción correspondiente en el menú o al guardar resultados.

### 4.``` reemplazarPalabra(char* texto, const char* palabraVieja, const char* palabraNueva)```
Propósito: Reemplazar todas las apariciones de una palabra por otra.

Conexión: Se llama cuando el usuario quiere modificar el texto. Devuelve una nueva versión del texto, que reemplaza al original en memoria.

### 5. ``guardarResultados(...)``
Propósito: Crear un archivo con las estadísticas, conteo de vocales y el texto final.

Conexión: Se activa desde el menú cuando el usuario decide guardar su trabajo

## 📋 Función principal (main)
- Rol central del programa: Controla el flujo general.

- Pasos clave:

1. Solicita el archivo de entrada.

2. Llama a ``leerArchivo`` y almacena el texto en memoria.

3.  Muestra un menú en un bucle ``do-while`` que permite al usuario:  
  - Ver estadísticas.

  - Contar vocales.

  - Reemplazar palabras.

  - Guardar resultados.

  - Salir.

## 4. Libera memoria antes de finalizar.

### 🔗 Conexión entre componentes
- Todas las funciones trabajan sobre la variable `` texto`` , que almacena el contenido leído.

- Las estadísticas y análisis se pueden repetir cuantas veces el usuario desee, ya que el menú es cíclico.

- Si se modifica el texto, se actualiza el puntero para trabajar siempre sobre la versión más reciente.

- `` guardarResultados``  se encarga de compilar toda la información en un archivo.

### ✅ Ventajas de esta estrategia
- Modularidad: Cada función hace una sola tarea, lo que hace el código más fácil de entender y modificar.

- Reutilización: El texto se reutiliza en diferentes opciones del menú sin necesidad de recargarlo.

- Flexibilidad: El usuario puede realizar múltiples acciones sobre el mismo texto sin reiniciar el programa.

- Manejo eficiente de memoria: Se evita la duplicación innecesaria de texto y se libera memoria al final.

## 3. Variables por Función 

### 📌 Función: `leerArchivo`

| Tipo    | Nombre          | Descripción                                   |
| ------- | --------------- | --------------------------------------------- |
| Entrada | `nombreArchivo` | Nombre del archivo de entrada (`const char*`) |
| Salida  | `return`        | Texto completo leído del archivo (`char*`)    |

### 📌 Función: `contarEstadisticas`

| Tipo    | Nombre       | Descripción                                       |
| ------- | ------------ | ------------------------------------------------- |
| Entrada | `texto`      | Texto sobre el cual se hará el conteo (`char*`)   |
| Salida  | `caracteres` | Cantidad de caracteres (sin contar `\n`) (`int*`) |
| Salida  | `palabras`   | Cantidad total de palabras en el texto (`int*`)   |
| Salida  | `espacios`   | Cantidad de espacios en blanco (`int*`)           |
| Salida  | `lineas`     | Cantidad de líneas en el texto (`int*`)        
   |

### 📌 Función: `contarVocales`
| Tipo    | Nombre  | Descripción                            |
| ------- | ------- | -------------------------------------- |
| Entrada | `texto` | Texto a analizar (`char*`)             |
| Salida  | `a`     | Cantidad de vocales 'a' o 'A' (`int*`) |
| Salida  | `e`     | Cantidad de vocales 'e' o 'E' (`int*`) |
| Salida  | `i`     | Cantidad de vocales 'i' o 'I' (`int*`) |
| Salida  | `o`     | Cantidad de vocales 'o' o 'O' (`int*`) |
| Salida  | `u`     | Cantidad de vocales 'u' o 'U' 

(`int*`) |


### 📌Función: `reemplazarPalabra`
| Tipo    | Nombre         | Descripción                                         |
| ------- | -------------- | --------------------------------------------------- |
| Entrada | `texto`        | Texto original donde se hará el reemplazo (`char*`) |
| Entrada | `palabraVieja` | Palabra a buscar en el texto (`const char*`)        |
| Entrada | `palabraNueva` | Palabra con la que se reemplazará (`const char*`)   |
| Salida  | `return`       | Nuevo texto con las palabras reemplazadas (`char*`) |

### 📌Función: `guardarResultados`

| Tipo    | Nombre          | Descripción                                                          |
| ------- | --------------- | -------------------------------------------------------------------- |
| Entrada | `nombreSalida`  | Nombre del archivo donde se guardarán los resultados (`const char*`) |
| Entrada | `caracteres`    | Total de caracteres (`int`)                                          |
| Entrada | `palabras`      | Total de palabras (`int`)                                            |
| Entrada | `espacios`      | Total de espacios (`int`)                                            |
| Entrada | `lineas`        | Total de líneas (`int`)                                              |
| Entrada | `a, e, i, o, u` | Cantidades de vocales (`int`)                                        |
| Entrada | `textoFinal`    | Texto final a guardar (`char*`)                                      |
| Salida  | `void`          | No retorna valor, solo genera el archivo de salida                   |

## 4. 
![Pseudocodigo](<Imagenes/Pseudocodigo reto 4.jpg>))


