# Functores y clases con `operator()`

En C++, una clase puede comportarse como una función si **sobrecarga el operador de llamada `operator()`**.
A estos objetos se les denomina **functores** (*function objects*).
Permiten **encapsular lógica configurable** dentro de un objeto invocable, combinando:

* la **sintaxis de las funciones**, y
* la **organización y el estado interno de las clases**.

Antes de las lambdas (introducidas en C++11), los functores eran la forma más habitual de representar acciones o estrategias intercambiables.
Aun hoy siguen siendo útiles cuando se necesita **comportamiento configurable con estado persistente**.

## Ejemplo básico: un objeto invocable

```cpp
#include <iostream>

class Sumar {
public:
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    Sumar sumar;
    std::cout << "Resultado: " << sumar(3, 4) << '\n';  // 7
}
```

La clase `Sumar` define `operator()`, lo que permite **invocar el objeto como si fuera una función**:
`sumar(3, 4)` llama internamente a `sumar.operator()(3, 4)`.


## Functor con estado interno

Los functores pueden **guardar información** que modifique su comportamiento:

```cpp
#include <iostream>

class Multiplicador {
private:
    int factor_;
public:
    explicit Multiplicador(int factor) : factor_(factor) {}

    int operator()(int x) const {
        return x * factor_;
    }

};

int main() {
    Multiplicador por2(2);
    Multiplicador por10(10);

    std::cout << por2(5) << '\n';   // 10
    std::cout << por10(3) << '\n';  // 30
}
```

Cada instancia de `Multiplicador` representa un comportamiento distinto.
El estado `factor_` personaliza la acción sin necesidad de escribir clases derivadas.

## Inyección de comportamiento con functores

Los functores también pueden usarse para **inyectar comportamiento configurable** en otras clases o funciones,
igual que hicimos antes con lambdas o `std::function`.

```cpp
#include <iostream>
#include <vector>

template <typename Accion>
class Procesador {
public:
    explicit Procesador(Accion accion) : accion_(accion) {}

    void ejecutar(const std::vector<int>& datos) const {
        for (int valor : datos)
            accion_(valor);  // Inyección de comportamiento
    }

private:
    Accion accion_;
};

class Mostrar {
public:
    void operator()(int x) const {
        std::cout << "Valor: " << x << '\n';
    }
};

class Cuadrado {
public:
    void operator()(int x) const {
        std::cout << x << "² = " << x * x << '\n';
    }
};

int main() {
    std::vector<int> numeros = {1, 2, 3};

    Procesador<Mostrar> p1(Mostrar{});
    Procesador<Cuadrado> p2(Cuadrado{});

    p1.ejecutar(numeros);
    p2.ejecutar(numeros);
}
```

* `Procesador` es una clase genérica que **no sabe qué hacer con los datos**. Solo los recorre y **llama al comportamiento inyectado** mediante `accion_`.
* `Mostrar` y `Cuadrado` son functores distintos, con comportamientos diferentes.
* El mismo `Procesador` puede reutilizarse con distintas acciones, sin modificarse.
* `Mostrar{}` y `Cuadrado{}` nos permiten construir objetos temporales usando inicialización uniforme, que se pasan directamente a `Procesador` para usarlo internamente, y posteriormente se eliminan.
* Este patrón reproduce la idea de "comportamiento intercambiable", pero usando clases invocables en lugar de funciones o lambdas.

## Uso con algoritmos de la STL

Los functores también se utilizan como **criterios** o **acciones** en algoritmos genéricos de la biblioteca estándar, del mismo modo que las lambdas.

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

class EsPar {
public:
    bool operator()(int valor) const {
        return valor % 2 == 0;
    }
};

int main() {
    std::vector<int> datos = {1, 2, 3, 4, 5};

    // Usamos el functor como criterio de búsqueda
    auto it = std::find_if(datos.begin(), datos.end(), EsPar{});

    if (it != datos.end())
        std::cout << "Primer número par: " << *it << '\n';
}
```
* `EsPar` es una **clase functora** que define el operador `()` para comprobar si un valor es par.
* `std::find_if` recorre el contenedor y aplica este criterio a cada elemento.
* Al encontrar el primer número par, devuelve un iterador al elemento correspondiente.
* El functor se crea de forma temporal (`EsPar{}`), sin necesidad de instanciarlo previamente.

En el siguiente apartado estudiaremos cómo **inyectar comportamientos mediante composición**,
lo que nos llevará al **patrón de estrategia** y a un uso más estructurado del diseño polimórfico.
