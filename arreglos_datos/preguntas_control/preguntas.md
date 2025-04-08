# Preguntas de Comprensión ❓

| Preguntas | Respuestas|
|--------------|--------------|
| ¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro? | Cuando envías un arreglo (o array) como parámetro a una función, lo que realmente se pasa es una referencia (o puntero) al arreglo, no una copia completa del arreglo. Esto tiene implicaciones importantes dependiendo del lenguaje de programación que estés utilizando.|
| ¿Qué diferencia hay entre declarar el parámetro como ``` int arr[]```  y ``` int *arr``` ? | En parámetros de funciones, int arr[] y int *arr son equivalentes. Ambas reciben un puntero al primer elemento del arreglo.|
| ¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?| Porque tanto en int arr[] como en int *arr, lo que se recibe es la dirección de memoria del arreglo original. Así que al hacer algo como arr[0] = 99;, estás modificando directamente ese espacio en memoria.|

# Preguntas finales para reforzar el aprendizaje 🧠

| Preguntas | Respuestas |
|--------------|--------------|
| ¿Cuál es exactamente la diferencia entre un arreglo y un puntero? | Un arreglo tiene tamaño fijo y su dirección no cambia. Un puntero puede apuntar a cualquier parte y se puede mover o reasignar. |
|¿Cómo están almacenados en la memoria los elementos de una matriz?| Las matrices en C se almacenan en memoria de manera contigua por filas (row-major). Es decir: primero todos los elementos de la primera fila, luego los de la segunda, y así sucesivamente. |
| ¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?|No acceder fuera del rango del arreglo, Asegúrate de que el puntero esté inicializado y válido, No mover el puntero más allá del final del arreglo, Presta atención al orden de las operaciones con punteros, Usa ```const``` si no vas a modificar los datos.

|
