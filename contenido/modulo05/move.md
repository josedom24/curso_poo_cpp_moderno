# Semántica de movimiento

En C++ clásico, copiar un objeto complejo (como un `std::vector` con miles de elementos) podía ser costoso, ya que implicaba **duplicar todos sus recursos**.
Con la llegada de C++11, se introdujo la **semántica de movimiento**, que permite **transferir recursos** de un objeto a otro, en lugar de copiarlos.

Esto hace posible escribir programas más **eficientes**, evitando copias innecesarias y aprovechando valores temporales que están a punto de destruirse.

## Constructor de movimiento y operador de asignación por movimiento

La semántica de movimiento se implementa con dos funciones especiales:

```cpp
// Constructor de movimiento
ClassName(ClassName&& other);

// Operador de asignación por movimiento
ClassName& operator=(ClassName&& other);
```

* El parámetro `ClassName&&` es una **referencia a rvalue**, que captura valores temporales.
* Se utilizan junto con `std::move`, que convierte un lvalue en un rvalue, indicando al compilador que podemos "robar" sus recursos.


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

    // Constructor con datos
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
        for (int v : datos) std::cout << v << " ";
        std::cout << "\n";
    }
};

int main() {
    Buffer b1{1, 2, 3};
    Buffer b2 = std::move(b1); // Constructor de movimiento
    Buffer b3;
    b3 = std::move(b2);        // Operador de asignación por movimiento

    std::cout << "b1: "; b1.mostrar(); // Estado válido pero indefinido
    std::cout << "b2: "; b2.mostrar(); // Estado válido pero indefinido
    std::cout << "b3: "; b3.mostrar(); // Contiene los datos originales
}
```

* `std::move(b1)` convierte el objeto `b1` en un **rvalue**, habilitando el constructor de movimiento.
* Los recursos (el `std::vector` interno) son **transferidos** de `b1` a `b2`, en lugar de ser copiados.
* Después del movimiento, el objeto origen (`b1` en este caso) queda en un estado **válido pero indefinido**: se puede destruir sin problema, pero no debería usarse.
* La palabra clave `noexcept` indica que el movimiento **no lanza excepciones**, lo cual es importante para optimizaciones en la STL (por ejemplo, `std::vector` prefiere mover elementos antes que copiarlos si sabe que la operación es segura).


## Relación con la eficiencia

* **Copia:** duplica los recursos (dos vectores con los mismos elementos).
* **Movimiento:** transfiere los recursos (solo un vector mantiene los datos).

Esto convierte al movimiento en una técnica fundamental en C++ moderno, especialmente en programas que trabajan con grandes estructuras de datos.


La **semántica de movimiento** permite:

* Optimizar el rendimiento al evitar copias innecesarias.
* Transferir la propiedad de recursos costosos entre objetos.
* Integrarse con la STL, que aprovecha automáticamente constructores y asignaciones por movimiento cuando están disponibles.


