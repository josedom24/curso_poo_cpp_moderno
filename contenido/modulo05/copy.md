# Copia de objetos: superficiales y profundas

La copia de objetos es un aspecto esencial de la programación orientada a objetos: permite duplicar el estado de un objeto existente en otro nuevo.
En C++ moderno, esta operación puede realizarse de forma automática o personalizada, y se controla mediante dos mecanismos especiales del lenguaje.

## Mecanismos para realizar la copia

* **Constructor de copia**: Se utiliza para crear un nuevo objeto a partir de otro. Se invoca cuando se **inicializa un objeto con otro del mismo tipo** o cuando **se pasa un objeto por valor a una función**.
    Sintaxis:
    ```cpp
    ClassName(const ClassName& other);
    ```
    Ejemplo:
    ```cpp
    MiClase a;
    MiClase b = a;  // Constructor de copia
    ``

* **Operador de asignación por copia**: Se usa cuando un objeto ya existente recibe el estado de otro.
    Sintaxis:
    ```cpp
    ClassName& operator=(const ClassName& other);
    ```
    Durante la asignación, el operador debe comprobar si el objeto se está asignando a sí mismo para evitar operaciones innecesarias o errores con recursos compartidos.
    Esto se logra mediante una verificación de autoasignación y la copia controlada del estado:

    Ejemplo:
    ```cpp
    ClassName& operator=(const ClassName& other) {
    if (this != &other) {
        // Copiar los datos desde 'other' a este objeto
       datos = other.datos;
       ...
    }
    return *this;
    }
    ```

## Tipos de copia

Ambos determinan cómo se duplica un objeto cuando se inicializa o se asigna. Además, en función de cómo se gestionen los recursos internos, podemos hablar de dos tipos de copia: **superficial y profunda**.

* **Copia superficial (*shallow copy*)**: Se copian directamente los valores de los atributos, incluidos los punteros.
Si el objeto contiene recursos dinámicos, ambos objetos terminan apuntando al mismo recurso compartido, lo que puede provocar errores como *double delete* o accesos a memoria liberada.
* **Copia profunda (*deep copy*)**: Se copian también los recursos apuntados o gestionados. Cada objeto resultante tiene su propia copia independiente de los datos, evitando interferencias entre ellos.
Esta es la forma más segura de duplicar objetos con recursos.

En C++ moderno, las clases de la STL (`std::vector`, `std::string`, etc.) implementan copias profundas automáticas, lo que reduce los problemas que antes causaban los punteros crudos.

## Ejemplo práctico: clase `Buffer`

A continuación se muestra una clase moderna que implementa constructor y asignación por copia. Usa `std::vector`, que gestiona su propia memoria (por tanto, realiza copias profundas automáticamente).

```cpp
#include <iostream>
#include <vector>

class Buffer {
private:
    std::vector<int> datos;  // Contenedor gestionado automáticamente

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
        if (this != &other) { // Evitar autoasignación
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

* El constructor de copia crea un nuevo objeto (`b2`) a partir de `b1`.
* El operador de asignación copia el contenido de `b1` sobre `b3`.
* Ambas operaciones realizan una copia profunda, ya que `std::vector` duplica internamente sus datos.
* En el C++ clásico, al usar punteros crudos, la copia por defecto sería superficial y requeriría código manual.

## Comparación: copia superficial y profunda

Para visualizar la diferencia, consideremos dos clases con comportamientos distintos:

```cpp
#include <iostream>
#include <vector>
#include <memory>

// Copia superficial: comparte el mismo recurso
class ContenedorSuperficial {
public:
    std::vector<int>* datos;  // No posee la memoria

    ContenedorSuperficial(std::vector<int>* ptr) : datos(ptr) {}

    void mostrar() const {
        for (int i : *datos) std::cout << i << " ";
        std::cout << "\n";
    }
};

// Copia profunda: mantiene su propia copia de los datos
class ContenedorProfundo {
public:
    std::vector<int> datos;

    ContenedorProfundo(const std::vector<int>& v) : datos(v) {}

    void mostrar() const {
        for (int i : datos) std::cout << i << " ";
        std::cout << "\n";
    }
};

int main() {
    std::vector<int> base1 = {1, 2, 3};
    std::vector<int> base2 = {1, 2, 3};

    std::cout << "== Copia superficial ==\n";
    ContenedorSuperficial s1(&base1);
    ContenedorSuperficial s2 = s1; // Copia superficial: comparten el puntero
    base1[1] = 99;

    s1.mostrar(); // 1 99 3
    s2.mostrar(); // 1 99 3 (comparten el mismo vector)

    std::cout << "\n== Copia profunda ==\n";
    ContenedorProfundo p1(base2);
    ContenedorProfundo p2 = p1; // Copia profunda: copia independiente
    base2[1] = 42;

    p1.mostrar(); // 1 2 3
    p2.mostrar(); // 1 2 3 (no se ve afectado)
}
```

* En la copia superficial, ambos objetos acceden al mismo recurso.
* En la copia profunda, cada objeto mantiene su propio estado.
* Las clases modernas de la STL realizan copias profundas de forma segura, evitando errores comunes del C++ clásico.

