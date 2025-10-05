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
template <typename T>
class Contenedor {
public:
    void imprimir(const T& valor) const {
        std::cout << "Valor: " << valor << '\n';
    }
};

// Especialización parcial para punteros
template <typename T>
class Contenedor<T*> {
public:
    void imprimir(const T* valor) const {
        if (valor)
            std::cout << "Puntero a: " << *valor << '\n';
        else
            std::cout << "Puntero nulo\n";
    }
};
```

Así, `Contenedor<int>` imprime valores directamente, mientras que `Contenedor<int*>` muestra el contenido apuntado.


