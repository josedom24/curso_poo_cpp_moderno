# Las plantillas de clase y la STL

La **STL (Standard Template Library)** es una parte esencial del lenguaje C++ moderno.
Está diseñada íntegramente con **plantillas de clase y de función**, lo que le permite ofrecer componentes **reutilizables, seguros y eficientes** que se adaptan a cualquier tipo de dato en tiempo de compilación.

La STL se organiza en tres grandes familias:

* **Contenedores genéricos** – almacenan colecciones de elementos (`std::vector`, `std::list`, `std::map`, etc.).
* **Algoritmos genéricos** – procesan secuencias de datos (`std::sort`, `std::find`, `std::accumulate`, etc.).
* **Iteradores** – proporcionan una interfaz uniforme para recorrer contenedores.

## Ejemplo: contenedores y algoritmos genéricos

El siguiente programa muestra cómo las plantillas permiten que un mismo algoritmo funcione con cualquier tipo de dato compatible.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Función plantilla genérica para imprimir un vector
template <typename T>
void imprimir(const std::vector<T>& v) {
    for (const T& val : v)
        std::cout << val << " ";
    std::cout << '\n';
}

int main() {
    // Contenedor genérico
    std::vector<int> numeros = {4, 2, 8, 1};

    // Algoritmo genérico: ordena la secuencia
    std::sort(numeros.begin(), numeros.end());

    // Iteradores y función plantilla
    imprimir(numeros); // Salida: 1 2 4 8

    return 0;
}
```

* `std::vector<int>` es una **instancia** de la plantilla `std::vector<T>`.
* `std::sort` es una **función plantilla** que ordena cualquier secuencia cuyos elementos sean comparables.
* `imprimir<T>` es una **función genérica definida por el usuario**, compatible con cualquier `std::vector<T>`.

Gracias a las plantillas, todos estos componentes funcionan juntos sin necesidad de herencia o polimorfismo dinámico.

## Compatibilidad con clases plantilla propias

También es posible diseñar **clases genéricas personalizadas** que sean compatibles con los algoritmos de la STL.
Para ello, basta con ofrecer una interfaz similar a la de los contenedores estándar (por ejemplo, métodos `begin()` y `end()`).

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

// Clase genérica personalizada compatible con la STL
template <typename T>
class ContenedorSimple {
private:
    std::vector<T> elementos;
public:
    void agregar(const T& val) { elementos.push_back(val); }

    auto begin() { return elementos.begin(); }
    auto end() { return elementos.end(); }
    auto begin() const { return elementos.begin(); }
    auto end() const { return elementos.end(); }
};

int main() {
    ContenedorSimple<int> c;
    c.agregar(3);
    c.agregar(1);
    c.agregar(2);

    // Podemos usar algoritmos de la STL
    std::sort(c.begin(), c.end());

    // Iteración compatible con range-based for
    for (int v : c)
        std::cout << v << " ";

    // Salida: 1 2 3
}
```

* `ContenedorSimple<T>` es una clase plantilla que **envuelve un `std::vector<T>`**.
* Al definir los métodos `begin()` y `end()`, puede usarse directamente con **algoritmos estándar** como `std::sort` o `std::find`.
* Además, soporta la **sintaxis `for` basada en rango**, igual que los contenedores de la STL.

