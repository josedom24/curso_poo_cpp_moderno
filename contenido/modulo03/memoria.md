# Gestión manual de memoria

En C++, los datos y variables se almacenan en diferentes áreas de memoria con propósitos específicos. Comprender estas áreas es fundamental para escribir código eficiente y seguro.

## Modelos de memoria: stack y heap

### Memoria de pila (stack)

Es un área gestionada automáticamente por el compilador y el sistema en tiempo de ejecución. Aquí se almacenan:

* Variables locales de funciones
* Parámetros de funciones
* Información de control (direcciones de retorno)

Características:

* **Gestión automática**: al entrar en una función, se reservan las variables; al salir, se liberan.
* **Muy rápida**, debido a su gestión estructurada y proximidad al procesador.
* **Tamaño limitado**: abusar de la recursión o declarar estructuras grandes puede causar *stack overflow*.

```cpp
#include <iostream>

void funcion() {
    int x = 5;   // Variable local en el stack
    std::cout << "x = " << x << "\n";
} // al salir de la función, x se libera automáticamente

int main() {
    funcion();
    return 0;
}
```

### Memoria dinámica (heap)

Es un área de memoria cuya gestión depende del programador. Permite reservar bloques en tiempo de ejecución cuya duración no está ligada al alcance de una función.

Características:

* Vida útil extendida más allá del bloque en el que se creó.
* Flexibilidad: el tamaño puede definirse en tiempo de ejecución.
* Requiere gestión manual: si no se libera, aparecen fugas de memoria.
* Más lenta que el stack, por la complejidad de asignación.

## Gestión manual con `new` y `delete`

En C++ tradicional, se utilizan los operadores:

* `new`: reserva memoria en el heap y devuelve un puntero.
* `delete`: libera memoria previamente asignada con `new`.
* Para arrays: `new[]` y `delete[]`.

### Ejemplo: entero dinámico

```cpp
#include <iostream>

int main() {
    int* ptr = new int;   // Reserva espacio para un entero en el heap
    *ptr = 42;            // Uso de la memoria
    std::cout << "Valor: " << *ptr << "\n";

    delete ptr;           // Liberación manual
    return 0;
}
```

### Ejemplo: array dinámico

```cpp
#include <iostream>

int main() {
    int* array = new int[100]; // Reserva un array de 100 enteros en el heap

    array[0] = 10; // Uso del array
    array[99] = 50;

    std::cout << "Primer elemento: " << array[0] 
              << ", Último: " << array[99] << "\n";

    delete[] array; // Liberación de memoria del array
    return 0;
}
```

## Errores frecuentes en la gestión manual

### Fuga de memoria (*memory leak*)

Si se pierde la referencia a un bloque reservado, no se puede liberar:

```cpp
int* ptr = new int(10);
// Se pierde la referencia: fuga de memoria
ptr = nullptr;
```

### Doble liberación

Liberar la misma memoria dos veces causa comportamiento indefinido:

```cpp
int* ptr = new int(10);
delete ptr;
delete ptr;  // ERROR: ya estaba liberado
```

### Uso de memoria liberada (*dangling pointer*)

Acceder a memoria después de liberarla provoca errores difíciles de depurar:

```cpp
int* ptr = new int(10);
delete ptr;
*ptr = 5;  // ERROR: acceso a memoria liberada
```

