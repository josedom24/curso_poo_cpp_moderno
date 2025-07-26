# Gestión manual de memoria

A continuación nos vamos a centrar en uno de los tipos de recursos que hemos comentado anteriormente: **la memoria**. En los programas escritos en C++, los datos y las variables se almacenan en diferentes áreas de memoria, cada una con características y propósitos específicos. Comprender estos tipos de memoria es fundamental para escribir código eficiente, seguro y libre de errores relacionados con la gestión de recursos.

## Modelos de memoria: stack y heap

Los dos tipos principales de memoria que debe conocer todo programador de C++ son:

### Memoria de pila (*Stack*)

Es un área de memoria gestionada automáticamente por el compilador y el sistema en tiempo de ejecución. En esta zona se almacenan:

* Variables locales de funciones
* Parámetros de funciones
* Información necesaria para el control de flujo, como direcciones de retorno

El stack sigue un modelo de gestión tipo **LIFO** (*Last In, First Out*), donde los datos se apilan y desapilan conforme se ejecutan las funciones.

Características:

* La gestión es automática: al entrar en una función, se reservan las variables locales; al salir de la función, la memoria se libera automáticamente.
* Es muy rápida, debido a su gestión estructurada y su proximidad al procesador.
* El tamaño disponible para el stack es limitado, lo que puede derivar en errores como **desbordamiento de pila** (*stack overflow*) si se abusa de la recursión o se declaran grandes estructuras de datos en esta zona.

Ejemplo:

```cpp
void funcion() {
    int x = 5;   // Variable local, almacenada en el stack
}
```

En este ejemplo, la variable `x` se almacena en el stack y se libera automáticamente al terminar la ejecución de la función.

### Memoria dinámica o *Heap*

Es un área de memoria gestionada de forma manual o semi-automática por el programador. Se utiliza para reservar bloques de memoria en tiempo de ejecución, cuya duración no está ligada al alcance de una función o bloque de código concreto.

En C++, se accede a la memoria del heap mediante los operadores `new` y `delete`, o a través de mecanismos modernos como los punteros inteligentes.

Características:

* Permite reservar memoria cuya vida útil se extiende más allá de la función en la que se solicita.
* Ofrece mayor flexibilidad, ya que la cantidad de memoria puede determinarse en tiempo de ejecución.
* Requiere una gestión cuidadosa: si la memoria no se libera correctamente, pueden producirse **fugas de memoria** (*memory leaks*) o accesos indebidos a memoria liberada.
* Las operaciones en el heap son, en general, más lentas que las del stack, debido a la mayor complejidad en la asignación y liberación de memoria.

## Gestión manual de memoria

Para gestionar la memoria dinámica *Heap, C++ proporciona los operadores `new` y `delete`.

* El operador `new` reserva un bloque de memoria en el **heap** y devuelve un puntero a la dirección de memoria asignada (este concpto lño estudiaremos en el siguiente apartado). Ejemplos:
    * Si queremos reservar un array (estructura de datos que nos permite guardar varios elementos del mismo tipo utilizamos el operador `new[]`).
    * Cuando se usa `new`, el objeto o array permanece en memoria **hasta que se libere explícitamente** mediante `delete` o `delete[]`.
* El operador `delete` libera la memoria previamente asignada con `new`, devolviendo el recurso al sistema operativo.

Ejemplo de gestión dinámica de un entero:

```cpp
int* ptr = new int;  // Reserva espacio para un entero en el heap
*ptr = 42;           // Asignación de valor
delete ptr;
```

Ejemplo de gestión dinámica de un array de enteros:

```cpp
int* array = new int[100];  // Reserva espacio para 100 enteros en el heap
delete[] array;
```

Veamos ejemplos con errores rípicos que se pueden dar en la gestión manual de memoria:

* Fuga de memoria:

    ```cpp
    int* ptr = new int(10);
    // Se pierde la referencia, no se puede liberar la memoria
    ptr = nullptr;
    ```

* Doble liberación de memoria:

    ```cpp
    int* ptr = new int(10);
    delete ptr;
    delete ptr;  // ERROR: la memoria ya fue liberada
    ```

* Uso de memoria liberada:

    ```cpp
    int* ptr = new int(10);
    delete ptr;
    *ptr = 5;  // ERROR: acceso a memoria liberada (puntero colgante)
    ```

