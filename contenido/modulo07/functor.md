# Functores y clases con `operator()`

En C++ una clase puede comportarse como una función si **sobrecarga el operador de llamada `operator()`**. A estas clases se les denomina **functores** (o *function objects*), y permiten encapsular lógica dentro de objetos que pueden ser **invocados como si fueran funciones**. Este mecanismo ofrece una forma poderosa y flexible de representar comportamiento configurable, con la ventaja de poder mantener **estado interno** y **estructurar el código orientado a objetos**.

Antes de la introducción de lambdas en C++11, los functores eran la principal forma de representar funciones genéricas. Aun hoy, tienen aplicaciones clave cuando se necesita combinar **invocabilidad y estado** de forma explícita.

Un **functor** es cualquier objeto que sobrecarga el operador `()`:

```cpp
class Sumar {
public:
    int operator()(int a, int b) const {
        return a + b;
    }
};
int main() {
    Sumar sumar;
    int resultado = sumar(3, 4); // 7
}
```

Ventajas de los functores:

* **Permiten almacenar estado** en atributos internos.
* **Pueden reutilizarse** como cualquier otra clase.
* Son compatibles con **algoritmos de la STL**.
* Funcionan en contextos donde se requiere un objeto invocable pero también configurable.

## Ejemplo: functor con estado interno

```cpp
class Multiplicador {
public:
    explicit Multiplicador(int factor) : factor_(factor) {}

    int operator()(int valor) const {
        return valor * factor_;
    }

private:
    int factor_;
};
int main() {
    Multiplicador por2(2);
    std::cout << por2(5); // 10

    Multiplicador por10(10);
    std::cout << por10(3); // 30
}
```

Claro, aquí tienes la explicación del código en formato de lista:

---

* Se declara la clase `Multiplicador`, que representa un *functor* (objeto invocable) configurable con un factor de multiplicación.
* `explicit Multiplicador(int factor)` es el constructor que inicializa el atributo `factor_` con el valor proporcionado.* La palabra clave `explicit` evita conversiones implícitas no deseadas al construir objetos de esta clase a partir de un `int`.
* Se define `int operator()(int valor) const`, lo que convierte al objeto en invocable como una función.
* Este método toma un entero y devuelve su producto con `factor_`.
* `factor_` almacena el valor del factor de multiplicación.
* En el `main()`:**
   * Se crean dos instancias de `Multiplicador`:
     * `por2(2)` representa una función que multiplica por 2.
     * `por10(10)` representa una función que multiplica por 10.
   * Luego se invocan como si fueran funciones:
     * `por2(5)` devuelve `5 * 2 = 10`.
     * `por10(3)` devuelve `3 * 10 = 30`.
   * Ambos resultados se imprimen en la salida estándar.

Este ejemplo demuestra cómo los **funtores** permiten encapsular comportamiento configurable (en este caso, una operación de multiplicación con un factor dado), y cómo su uso es similar al de una lambda, pero con la ventaja de tener estado interno más explícito y organizado.


## Uso con algoritmos de STL

Muchos algoritmos estándar aceptan objetos invocables como criterios de orden, filtros, transformaciones, etc.

```cpp
#include <algorithm>
#include <vector>
#include <iostream>

struct EsPar {
    bool operator()(int valor) const {
        return valor % 2 == 0;
    }
};

int main() {
    std::vector<int> datos = {1, 2, 3, 4, 5};
    auto it = std::find_if(datos.begin(), datos.end(), EsPar{});
    if (it != datos.end()) {
        std::cout << "Primer número par: " << *it << '\n';
    }
}
```

## Uso de functores

Los functores son especialmente adecuados cuando se desea **persistir comportamiento con configuración o estado interno**, y se prefiere un enfoque fuertemente tipado.


* Usar functores cuando:
  * Se necesita **configurar o parametrizar el comportamiento** mediante atributos.
  * Se busca un diseño orientado a objetos claro y reutilizable.
  * Se trabaja con algoritmos genéricos donde el tipo debe ser conocido en tiempo de compilación.
* Si el comportamiento es simple y localizado, una **lambda** es más apropiada.
