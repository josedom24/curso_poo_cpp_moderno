# Semántica de copia en C++

En el apartado anterior vimos que clonar un objeto puede hacerse de forma **superficial** o **profunda**.
En C++ moderno, estos conceptos se concretan a través de dos mecanismos especiales:

* **Constructor de copia**
* **Operador de asignación por copia**

Ambos se encargan de definir cómo debe duplicarse un objeto cuando se inicializa o cuando se asigna a otro ya existente.

## Constructor de copia

El **constructor de copia** crea un nuevo objeto a partir de otro ya existente.
Su firma general es:

```cpp
ClassName(const ClassName& other);
```

Se invoca en situaciones como:

* Inicialización de un objeto a partir de otro:

  ```cpp
  MiClase a;
  MiClase b = a;  // constructor de copia
  ```

* Paso de objetos por valor a funciones.

## Operador de asignación por copia

El **operador de asignación por copia** define cómo se comporta la clase cuando un objeto ya existente recibe el valor de otro del mismo tipo.

Su firma es:

```cpp
ClassName& operator=(const ClassName& other);
```

Se invoca en expresiones como:

```cpp
MiClase a, b;
b = a;  // operador de asignación por copia
```

## Ejemplo práctico: clase `Buffer`

Supongamos una clase que gestiona un contenedor de enteros con `std::vector`.
Aquí implementamos constructor y asignación por copia para ver cuándo se llaman:

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

    // Constructor de copia
    Buffer(const Buffer& other) : datos(other.datos) {
        std::cout << "Constructor de copia\n";
    }

    // Operador de asignación por copia
    Buffer& operator=(const Buffer& other) {
        if (this != &other) { // Evitar auto-asignación
            datos = other.datos;
            std::cout << "Asignación por copia\n";
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
    Buffer b2 = b1;   // Llama al constructor de copia
    Buffer b3;
    b3 = b1;          // Llama al operador de asignación por copia

    b1.mostrar();
    b2.mostrar();
    b3.mostrar();
}
```

* **Constructor de copia**: se ejecuta cuando se crea un objeto nuevo a partir de otro.
* **Operador de asignación por copia**: se ejecuta cuando un objeto ya existente recibe el estado de otro.
* Ambos hacen una **copia profunda** porque `std::vector` gestiona internamente su memoria y duplica los datos.
* En C++ clásico, si usáramos punteros crudos, la copia por defecto sería **superficial**, y habría que implementar manualmente la copia profunda.


La **semántica de copia** en C++ define cómo los objetos se duplican en memoria.
En C++ moderno:

* Los contenedores de la STL (`std::vector`, `std::string`, etc.) ya implementan copia profunda.
* Es raro necesitar implementar manualmente la copia, salvo en clases que gestionan recursos de bajo nivel.
* Este concepto se complementa con la **semántica de movimiento**, que permite transferir recursos en lugar de copiarlos, para ganar eficiencia.

