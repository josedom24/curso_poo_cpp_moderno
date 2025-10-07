# Clonación de objetos

En programación orientada a objetos, a veces es necesario **duplicar un objeto existente** sin modificar el original.
A esta operación se la denomina **clonación**.

En C++, clonar un objeto no es una característica del lenguaje, sino un **comportamiento que debe implementarse explícitamente**.
La clonación se apoya en los mecanismos de copia (constructor y operador de asignación) y, en la práctica, suele realizar **copias profundas**, para garantizar que el nuevo objeto es totalmente independiente del original.

Esto es especialmente importante cuando el objeto posee **recursos dinámicos** (memoria, archivos, conexiones, etc.), que no pueden compartirse entre instancias sin riesgo.

## Clonación básica

La forma más simple de clonación consiste en implementar un método `clone()` que devuelva una nueva instancia copiada del objeto actual.
Se suele usar `std::unique_ptr` para gestionar automáticamente la memoria del clon.

```cpp
#include <iostream>
#include <memory>
#include <vector>

class Buffer {
private:
    std::vector<int> datos;

public:
    Buffer(std::initializer_list<int> lista) : datos(lista) {}

    // Método de clonación
    std::unique_ptr<Buffer> clone() const {
        return std::make_unique<Buffer>(*this);  // Copia profunda
    }

    void mostrar() const {
        for (int v : datos) std::cout << v << " ";
        std::cout << "\n";
    }
};

int main() {
    Buffer original{1, 2, 3};
    auto copia = original.clone();  // Clonación profunda

    std::cout << "Original: ";
    original.mostrar();
    std::cout << "Copia:    ";
    copia->mostrar();
}
```

* El método `clone()` crea una nueva instancia mediante el **constructor de copia**.
* La copia es profunda porque `std::vector` gestiona su propia memoria y duplica los datos.
* El clon es completamente independiente del objeto original.

## Clonación polimórfica

En sistemas con herencia, puede ser necesario **clonar objetos sin conocer su tipo concreto**.
Para ello, se define un método virtual `clone()` en la clase base, que cada clase derivada debe sobrescribir.

```cpp
#include <iostream>
#include <memory>
#include <vector>

// Clase base con clonación virtual
class Clonable {
public:
    virtual std::unique_ptr<Clonable> clone() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Clonable() = default;
};

// Clase derivada A
class DerivadoA : public Clonable {
private:
    int dato;

public:
    DerivadoA(int d) : dato(d) {}

    std::unique_ptr<Clonable> clone() const override {
        return std::make_unique<DerivadoA>(*this);  // Copia profunda
    }

    void mostrar() const override {
        std::cout << "DerivadoA: " << dato << "\n";
    }
};

// Clase derivada B
class DerivadoB : public Clonable {
private:
    std::vector<int> datos;

public:
    DerivadoB(const std::vector<int>& v) : datos(v) {}

    std::unique_ptr<Clonable> clone() const override {
        return std::make_unique<DerivadoB>(*this);  // Copia profunda
    }

    void mostrar() const override {
        std::cout << "DerivadoB: ";
        for (int n : datos) std::cout << n << " ";
        std::cout << "\n";
    }
};

int main() {
    std::unique_ptr<Clonable> a = std::make_unique<DerivadoA>(42);
    std::unique_ptr<Clonable> b = std::make_unique<DerivadoB>(std::vector<int>{1, 2, 3});

    auto clonA = a->clone();
    auto clonB = b->clone();

    a->mostrar();
    clonA->mostrar();

    b->mostrar();
    clonB->mostrar();
}
```

* La clase base `Clonable` define una interfaz común con un método `clone()` virtual puro.
* Cada clase derivada devuelve un clon de su propio tipo mediante `std::make_unique`.
* La clonación es profunda: los datos internos de cada objeto se copian, no se comparten.
* Esto permite clonar objetos **a través de punteros a la clase base**, sin conocer su tipo en tiempo de compilación.
