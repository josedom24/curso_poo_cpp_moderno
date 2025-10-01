# Representación de acciones con funciones lambda

En C++ moderno (desde C++11), las **expresiones lambda** ofrecen una forma compacta y muy expresiva de definir funciones anónimas directamente en el lugar donde se necesitan. Esto permite representar comportamientos intercambiables de manera sencilla, sin necesidad de crear clases o interfaces explícitas.

Una lambda es una función sin nombre que puede capturar variables del entorno, y que se puede pasar, almacenar y ejecutar igual que cualquier función. Gracias a esto, las lambdas son ideales para definir pequeñas acciones o estrategias que pueden variar en distintos contextos, facilitando un diseño flexible y desacoplado.

## ¿Qué es una lambda?

La sintaxis básica de una lambda es:

```cpp
[captura](parámetros) -> tipo_retorno {
    cuerpo
};
```

* **captura**: indica qué variables externas puede usar la lambda y cómo (por valor `[=]` o referencia `[&]`).
* **parámetros**: los argumentos que recibe, como una función normal.
* **tipo\_retorno**: opcional, el compilador puede deducirlo.
* **cuerpo**: el código que se ejecuta cuando se llama la lambda.

Ejemplo:

```cpp
auto saludar = [](const std::string& nombre) {
    std::cout << "Hola, " << nombre << "!\n";
};

saludar("Ana"); // Imprime: Hola, Ana!
```

## Lambdas para comportamiento intercambiable

Las lambdas pueden usarse para intercambiar acciones fácilmente. Por ejemplo, para ordenar una lista con distintos criterios:

```cpp
#include <vector>
#include <algorithm>
#include <iostream>

int main() {
    std::vector<int> numeros = {3, 1, 4, 2};

    // Orden ascendente
    std::sort(numeros.begin(), numeros.end(), [](int a, int b) {
        return a < b;
    });

    for (int n : numeros) std::cout << n << " "; // 1 2 3 4
}
```

Aquí, la función de comparación se define “al vuelo” con una lambda, sin necesidad de una clase o función aparte.

Veamos otro ejemplo, que nos permite modificar el comportamiento según un valor que captura la función lambda:

```cpp
#include <iostream>

int main() {
    int factor = 3;

    // Lambda que captura 'factor' por valor
    auto multiplicar = [factor](int x) {
        return x * factor;
    };

    std::cout << multiplicar(10) << "\n";  // Imprime 30
}
```

En este caso, la lambda captura la variable `factor` y la usa dentro de su cuerpo para multiplicar el argumento `x`. Así, el comportamiento de la lambda depende del valor capturado en el momento de su creación.

## Uso en funciones y algoritmos

Las lambdas se utilizan ampliamente con algoritmos estándar:

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> valores = {1, 3, 5, 7, 9};
    
    // Buscar el primer valor mayor que 4
    auto it = std::find_if(valores.begin(), valores.end(), [](int x) {
        return x > 4;
    });

    if (it != valores.end())
        std::cout << "Encontrado: " << *it << '\n';
}
```

* Recuerda que `std::find_if` nos permite buscar un elemento que cumpla una condición.
* La condición se establece por una función lambda.
* El uso de lambdas nos aporta varias ventajas:
    * Eliminan la necesidad de funciones auxiliares triviales.
    * Permiten escribir código más expresivo y localizado.
    * Facilitan la programación funcional y el paso de comportamiento como argumento.
    * Pueden capturar el contexto (estado externo) cuando se necesita.

## Ventajas de usar lambdas para el comportamiento intercambiable

* **Simplicidad y concisión**: evitan la sobrecarga de definir clases o funciones adicionales.
* **Flexibilidad**: pueden capturar y usar variables del entorno sin necesidad de pasarlas explícitamente.
* **Claridad**: la lógica está localizada en el lugar de uso, mejorando la legibilidad.
* **Intercambiabilidad**: se pueden pasar como argumentos, almacenar o modificar fácilmente.

