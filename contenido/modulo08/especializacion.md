# Especialización de plantillas de clase

Las plantillas en C++ permiten definir clases genéricas que funcionan con distintos tipos.
Sin embargo, a veces es necesario **adaptar su comportamiento para tipos concretos**.
Esto se logra mediante la **especialización de plantillas**, que permite redefinir total o parcialmente la implementación para casos específicos.

## Especialización total

La **especialización total** consiste en proporcionar una versión completamente diferente de la clase plantilla **para un tipo concreto**.

```cpp
#include <iostream>
#include <string>

// Versión genérica
template <typename T>
class Caja {
public:
    void mostrar(const T& valor) const {
        std::cout << "Contenido genérico: " << valor << '\n';
    }
};

// Especialización total para std::string
template <>
class Caja<std::string> {
public:
    void mostrar(const std::string& valor) const {
        std::cout << "Texto: \"" << valor << "\"\n";
    }
};

int main() {
    Caja<int> c1;
    c1.mostrar(42);              // Contenido genérico: 42

    Caja<std::string> c2;
    c2.mostrar("Hola mundo");    // Texto: "Hola mundo"

    return 0;
}
```

Aquí `Caja` tiene un comportamiento genérico, pero se redefine completamente cuando el tipo es `std::string`.

## Especialización parcial

La **especialización parcial** modifica el comportamiento **solo para ciertos patrones de tipos**, manteniendo otros genéricos.
Por ejemplo, podemos tratar los punteros de manera diferente:

```cpp
#include <iostream>
#include <vector>
#include <string>

// Plantilla genérica (para cualquier tipo simple)
template <typename T>
class Contenedor {
private:
    T valor;

public:
    Contenedor(T v) : valor(v) {}

    void mostrar() const {
        std::cout << "Elemento único: " << valor << '\n';
    }
};

// Especialización parcial para std::vector<T>
template <typename T>
class Contenedor<std::vector<T>> {
private:
    std::vector<T> valores;

public:
    Contenedor(const std::vector<T>& v) : valores(v) {}

    void mostrar() const {
        std::cout << "Colección de elementos (" << valores.size() << "): ";
        for (const auto& e : valores)
            std::cout << e << " ";
        std::cout << '\n';
    }
};

int main() {
    Contenedor<int> c1(42);                          // versión genérica
    Contenedor<std::string> c2("Hola");              // versión genérica
    Contenedor<std::vector<int>> c3({1, 2, 3, 4});   // especialización parcial
    Contenedor<std::vector<std::string>> c4({"uno", "dos", "tres"}); // especialización parcial

    c1.mostrar();
    c2.mostrar();
    c3.mostrar();
    c4.mostrar();

    return 0;
}
```


* La plantilla genérica `Contenedor<T>` almacena un único valor y lo muestra con un mensaje simple.
* La **especialización parcial** `Contenedor<std::vector<T>>` redefine la clase solo cuando el parámetro de tipo es un `std::vector` de cualquier tipo `T`.
* En ese caso, la clase trata al objeto como una **colección** y muestra todos sus elementos.

