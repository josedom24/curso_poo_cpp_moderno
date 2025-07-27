### Ejercicio 1: Implementación de una Estructura Genérica

Como ejemplo clásico, considere la implementación de una **pila (stack)**, una estructura de datos de tipo LIFO (Last In, First Out). La lógica de la pila es independiente del tipo de datos que almacena, por lo que es un candidato ideal para el uso de plantillas:

```cpp
#include <vector>

template <typename T>
class Pila {
private:
    std::vector<T> elementos;
public:
    void push(const T& valor) {
        elementos.push_back(valor);
    }

    void pop() {
        if (!elementos.empty()) {
            elementos.pop_back();
        }
    }

    T top() const {
        return elementos.back();
    }

    bool vacia() const {
        return elementos.empty();
    }
};
```

Esta implementación reutiliza tanto la clase `Pila` como el contenedor estándar `std::vector`, ambos definidos mediante plantillas. De este modo, el código puede ser aplicado sin cambios a enteros, cadenas, estructuras o cualquier otro tipo compatible con `std::vector`.


### 3.5 Ejemplo de Uso

```cpp
#include <iostream>
#include <string>

int main() {
    Pila<int> pilaEnteros;
    pilaEnteros.push(10);
    pilaEnteros.push(20);
    std::cout << "Cima (int): " << pilaEnteros.top() << "\n";

    Pila<std::string> pilaTextos;
    pilaTextos.push("Hola");
    pilaTextos.push("Mundo");
    std::cout << "Cima (string): " << pilaTextos.top() << "\n";

    return 0;
}
```

Cada instancia de la plantilla `Pila<T>` genera una clase completamente adaptada al tipo especificado (`int`, `std::string`, etc.), sin necesidad de redefinir su lógica.

