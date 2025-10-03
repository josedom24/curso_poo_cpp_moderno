# Clonación de objetos: copias superficiales y profundas

En programación orientada a objetos es habitual necesitar **duplicar un objeto** para preservar su estado o generar una variante sin alterar el original. Este proceso se denomina **clonación**.

En C++ la clonación puede hacerse de distintas formas, y su importancia depende de si los objetos contienen o no **recursos dinámicos** (memoria, archivos, sockets, etc.). Aquí distinguimos dos enfoques:

* **Copia superficial (shallow copy)**:
  Se copian directamente los valores de los atributos, incluidos los punteros. Si el objeto contiene recursos dinámicos, ambos objetos terminan apuntando al mismo recurso compartido. Esto puede provocar errores como *double delete* o accesos a memoria liberada.

* **Copia profunda (deep copy)**:
  Se duplican también los recursos a los que apuntan los punteros o referencias. El nuevo objeto tiene **su propia copia independiente** de los datos. Es más costosa en rendimiento, pero más segura.

Esta diferencia era crítica en el C++ clásico, donde el uso de punteros crudos obligaba a implementar manualmente las copias profundas para evitar errores. En C++ moderno, gracias a **std::vector** o **std::unique_ptr**, muchos de estos problemas se reducen automáticamente.

## Ejemplo de copia superficial y profunda

Supongamos que queremos duplicar un objeto que contiene datos almacenados en un `std::vector<int>`:

```cpp
#include <iostream>
#include <vector>
#include <memory>

// Copia superficial: solo comparte el puntero
class ContenedorSuperficial {
public:
    std::vector<int>* datos;  // No es dueño de la memoria

    ContenedorSuperficial(std::vector<int>* ptr) : datos(ptr) {}

    std::unique_ptr<ContenedorSuperficial> clone() const {
        return std::make_unique<ContenedorSuperficial>(datos);
    }

    void mostrar() const {
        for (int i : *datos) std::cout << i << " ";
        std::cout << "\n";
    }
};

// Copia profunda: mantiene su propia copia del vector
class ContenedorProfundo {
public:
    std::vector<int> datos;

    ContenedorProfundo(const std::vector<int>& v) : datos(v) {}

    std::unique_ptr<ContenedorProfundo> clone() const {
        return std::make_unique<ContenedorProfundo>(datos);
    }

    void mostrar() const {
        for (int i : datos) std::cout << i << " ";
        std::cout << "\n";
    }
};

int main() {
    std::vector<int> base = {1, 2, 3};

    std::cout << "== Copia superficial ==\n";
    ContenedorSuperficial s1(&base);
    auto s2 = s1.clone();  // Ambos comparten el mismo vector
    base[1] = 99;          // Modificamos el vector original

    s1.mostrar(); // 1 99 3
    s2->mostrar();// 1 99 3

    std::cout << "\n== Copia profunda ==\n";
    ContenedorProfundo p1(base);
    auto p2 = p1.clone();  // Copia independiente
    base[1] = 42;

    p1.mostrar(); // 1 99 3
    p2->mostrar();// 1 99 3
}
```

* En la **copia superficial**, los dos objetos comparten el mismo recurso. Cambiar el `base` afecta a todos.
* En la **copia profunda**, cada objeto tiene su propio vector, y los cambios no se comparten.
* Se usa `std::unique_ptr` en el método `clone()` para garantizar seguridad en la gestión de memoria.


## Clonación en jerarquías de clases

Cuando trabajamos con **herencia**, la clonación requiere otro mecanismo. Si manejamos punteros a una clase base, necesitamos clonar polimórficamente el objeto sin conocer su tipo concreto en tiempo de compilación.

Esto se logra con un método **virtual clone()**, lo que sienta las bases del patrón *Prototype*.

```cpp
#include <iostream>
#include <memory>
#include <vector>

// Clase base con clone virtual
class Clonable {
public:
    virtual std::unique_ptr<Clonable> clone() const = 0;
    virtual ~Clonable() = default;
};

// Clase derivada A
class DerivadoA : public Clonable {
public:
    int dato;
    DerivadoA(int d) : dato(d) {}

    std::unique_ptr<Clonable> clone() const override {
        return std::make_unique<DerivadoA>(*this);
    }
};

// Clase derivada B
class DerivadoB : public Clonable {
public:
    std::vector<int> datos;
    DerivadoB(const std::vector<int>& v) : datos(v) {}

    std::unique_ptr<Clonable> clone() const override {
        return std::make_unique<DerivadoB>(*this);
    }
};

void imprimirClon(const Clonable& obj) {
    auto copia = obj.clone();  
    std::cout << "Objeto clonado con éxito.\n";
}

int main() {
    DerivadoA a(42);
    DerivadoB b({1, 2, 3});

    imprimirClon(a);
    imprimirClon(b);
}
```
* `clone()` es virtual puro en la base y cada derivada implementa su propia clonación.
* Se devuelve un `std::unique_ptr` para gestionar la memoria automáticamente.
* Esto permite al cliente clonar sin conocer el tipo concreto del objeto.

