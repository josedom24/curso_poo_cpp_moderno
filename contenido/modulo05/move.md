# Movimiento de objetos

En C++ clásico, copiar un objeto complejo —por ejemplo, un `std::vector` con miles de elementos— podía ser una operación costosa, ya que implicaba duplicar toda su memoria interna.
Para solucionar este problema, a partir de **C++11** el lenguaje incorporó el **movimiento de objetos**, que permite **transferir recursos** de un objeto a otro en lugar de copiarlos.

El movimiento hace posible escribir programas más eficientes, especialmente cuando se trabaja con objetos temporales o estructuras grandes que no es necesario duplicar.

## Valores lvalue y rvalue

Antes de abordar cómo se realiza el movimiento de objetos, es necesario comprender dos categorías fundamentales de expresiones en C++:

* **lvalue (left value):** Expresiones que hacen referencia a una ubicación identificable en memoria y que pueden aparecer en el lado izquierdo de una asignación. Pueden ser referenciadas con `&`.

  ```cpp
  int x = 42;    // x es un lvalue
  int* p = &x;   // se puede tomar la dirección de x
  ```

* **rvalue (right value):** Expresiones temporales que no tienen nombre ni dirección permanente. No se les puede tomar la dirección (en general), y se usan típicamente en el lado derecho de una asignación.

  ```cpp
  int y = x + 1; // x + 1 es un rvalue
  ```

Con la llegada de C++11, se introdujo una nueva categoría de referencias, las **referencias a rvalue (`T&&`)**, que permiten capturar estos valores temporales y explotarlos para evitar copias innecesarias.

## Constructor de movimiento y operador de asignación por movimiento

El movimiento se implementa mediante dos funciones especiales:

```cpp
// Constructor de movimiento
ClassName(ClassName&& other);

// Operador de asignación por movimiento
ClassName& operator=(ClassName&& other);
```

* El parámetro `ClassName&&` es una **referencia a rvalue**, y por tanto puede recibir **valores temporales** (expresiones sin nombre). Esto permite que el constructor u operador de movimiento **tomen posesión de los recursos** de esos objetos temporales en lugar de copiarlos.
* La función `std::move()` **indica al compilador que un objeto con nombre (un lvalue)** puede tratarse **como un rvalue**.
No realiza el movimiento por sí misma, sino que **habilita** la llamada al constructor u operador de movimiento, permitiendo **transferir los recursos** del objeto original al nuevo.

## Ejemplo: clase `Buffer` con movimiento

```cpp
#include <iostream>
#include <vector>

class Buffer {
private:
    std::vector<int> datos;

public:
    // Constructor por defecto
    Buffer() = default;

    // Constructor con datos iniciales
    Buffer(std::initializer_list<int> lista) : datos(lista) {}

    // Constructor de movimiento
    Buffer(Buffer&& other) noexcept : datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento\n";
    }

    // Operador de asignación por movimiento
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento\n";
        }
        return *this;
    }

    void mostrar() const {
        if (datos.empty())
            std::cout << "(vacío)\n";
        else {
            for (int v : datos) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    Buffer b1{1, 2, 3};
    Buffer b2 = std::move(b1); // Invoca el constructor de movimiento
    Buffer b3;
    b3 = std::move(b2);        // Invoca el operador de asignación por movimiento

    std::cout << "b1: "; b1.mostrar(); // Estado válido pero vacío
    std::cout << "b2: "; b2.mostrar(); // Estado válido pero vacío
    std::cout << "b3: "; b3.mostrar(); // Contiene los datos originales
}
```

* `std::move(b1)` convierte el objeto `b1` en un **rvalue**, habilitando el constructor de movimiento.
* El vector interno de `b1` se transfiere a `b2` mediante `std::move(other.datos)`.
* Tras el movimiento, los objetos origen (`b1` y `b2`) quedan en un **estado válido pero vacío**: pueden destruirse sin problema, pero su contenido ya no está definido.
* La palabra clave `noexcept` indica que el movimiento **no lanza excepciones**, lo cual es importante para la STL: los contenedores como `std::vector` prefieren mover elementos en lugar de copiarlos si la operación se declara segura.

## Resumen

* La copia, duplica los recursos del objeto origen. Si copiamos un vector, obtenemos dos vectores con los mismos datos.
* El movimiento transfiere los recursos del objeto origen al destino. El origen queda vacío, el destino conserva los datos.
* El movimiento evita copias innecesarias y mejora notablemente el rendimiento en programas que manejan objetos grandes o temporales.
* El movimiento se activa cuando el compilador puede usar un **rvalue** (temporal o convertido con `std::move`).
* Permite **transferir la propiedad** de recursos costosos sin duplicarlos.
* En C++ moderno, las clases de la STL aprovechan automáticamente el movimiento cuando está disponible.
* Es una técnica esencial para escribir código eficiente y seguro basado en RAII.
