# Las plantillas de clase y la STL

La **STL (Standard Template Library)** constituye una parte fundamental del lenguaje C++ moderno. Su diseño está basado íntegramente en plantillas, lo que le permite ofrecer una colección rica de **contenedores**, **iteradores**, **algoritmos** y **funciones utilitarias** que funcionan de manera genérica sobre distintos tipos de datos.

Comprender cómo las plantillas se aplican en la STL permite al programador no solo usarla con mayor efectividad, sino también diseñar sus propias clases genéricas de forma coherente y compatible con el ecosistema estándar de C++.

## Contenedores genéricos

Los contenedores de la STL, tales como `std::vector`, `std::list`, `std::map`, `std::set`, entre otros, están implementados como **plantillas de clase parametrizadas por tipo**. Esto significa que pueden almacenar elementos de cualquier tipo que cumpla con ciertos requisitos mínimos (por ejemplo, ser copiables o comparables).

Ejemplo:

```cpp
#include <vector>
#include <string>

std::vector<int> enteros = {1, 2, 3};
std::vector<std::string> palabras = {"uno", "dos", "tres"};
```

Cada instancia de `std::vector<T>` genera una clase especializada para ese tipo `T`. Esto se traduce en eficiencia y seguridad de tipo, todo resuelto en tiempo de compilación.

## Algoritmos genéricos

La STL también proporciona una amplia gama de **algoritmos** genéricos, como `std::sort`, `std::find`, `std::accumulate`, entre otros. Estos algoritmos están implementados como **funciones plantilla**, capaces de operar sobre cualquier secuencia de elementos accesible mediante iteradores.

Ejemplo:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

std::vector<int> datos = {3, 1, 4, 1, 5};
std::sort(datos.begin(), datos.end());

for (int x : datos) {
    std::cout << x << " ";
}
```

`std::sort` es una función plantilla que ordena cualquier secuencia cuyos elementos sean comparables mediante el operador `<`.

## Iteradores como interfaz genérica

El concepto de **iterador** en la STL es una abstracción generalizada de los punteros. La mayoría de los algoritmos de la STL están diseñados para operar con iteradores, lo que permite una separación clara entre la estructura de datos (contenedor) y el algoritmo que opera sobre ella.

Ejemplo:

```cpp
#include <vector>
#include <algorithm>

std::vector<int> v = {2, 4, 6, 8};

auto it = std::find(v.begin(), v.end(), 6);
if (it != v.end()) {
    *it = 7;  // Modifica el elemento encontrado
}
```

## Compatibilidad con clases plantillas propias

Al diseñar clases genéricas personalizadas, es posible hacerlas compatibles con la STL si se respetan ciertas convenciones, como:

* Definir `begin()` y `end()` para permitir iteración.
* Proveer operadores necesarios (`==`, `<`, etc.) si se desea usarlas con algoritmos estándar.

Ejemplo:

```cpp
template <typename T>
class ContenedorSimple {
private:
    std::vector<T> elementos;
public:
    void agregar(const T& val) { elementos.push_back(val); }

    auto begin() { return elementos.begin(); }
    auto end() { return elementos.end(); }
};
```

Esto permite usar `ContenedorSimple<T>` con algoritmos de la STL como `std::for_each` o `std::find`.


# 5.7 Ventajas de la STL como biblioteca genérica

* **Eficiencia**: las plantillas permiten generar código optimizado y específico para cada tipo.
* **Reutilización**: separación entre estructuras y algoritmos facilita la reutilización y la extensión.
* **Seguridad**: se detectan errores de tipo en tiempo de compilación.
* **Modularidad**: componentes bien definidos y cohesionados.


## Ejemplo completo

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
void imprimir(const std::vector<T>& v) {
    for (const T& val : v)
        std::cout << val << " ";
    std::cout << '\n';
}

int main() {
    std::vector<int> numeros = {4, 2, 8, 1};
    std::sort(numeros.begin(), numeros.end());

    imprimir(numeros); // Salida: 1 2 4 8
    return 0;
}
```
