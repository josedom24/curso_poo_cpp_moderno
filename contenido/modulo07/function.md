Perfecto, a continuación tienes el material didáctico correspondiente a la cuarta sección del capítulo **"Abstracción de comportamiento y composición flexible"**, titulada:

---

# Uso de `std::function` para encapsular comportamiento configurable

## Introducción

En C++ moderno, `std::function` es un componente de la biblioteca estándar que permite **almacenar, copiar y ejecutar cualquier objeto invocable**, como funciones, lambdas, punteros a funciones o functores. Actúa como un contenedor polimórfico para comportamientos, lo que permite pasar funciones como argumentos o configurarlas dinámicamente, **sin necesidad de conocer su tipo exacto en tiempo de compilación**.

Este mecanismo proporciona una forma de **abstracción de comportamiento más flexible** que las interfaces tradicionales o las plantillas, permitiendo desacoplar componentes de sus dependencias funcionales de forma dinámica y uniforme.

## ¿Qué es `std::function`?

`std::function` es una plantilla de clase definida en `<functional>` que representa cualquier objeto que se pueda invocar con una determinada firma.

### Sintaxis general:

```cpp
std::function<tipo_retorno(parámetros)>
```

Por ejemplo:

```cpp
std::function<bool(int, int)> comparador;
```

Este objeto puede almacenar cualquier lambda, función o clase con `operator()` que reciba dos `int` y devuelva `bool`.

## Ventajas de `std::function`

* **Homogeneidad**: permite tratar por igual a funciones, lambdas y objetos con `operator()`.
* **Flexibilidad en tiempo de ejecución**: se puede cambiar el comportamiento dinámicamente.
* **Desacoplamiento**: evita depender de clases concretas o plantillas, permitiendo interfaces limpias.
* **Interoperabilidad**: facilita la interacción entre componentes que aceptan comportamientos como parámetros.

## Ejemplo básico: selección dinámica de comportamiento

```cpp
#include <iostream>
#include <functional>

void ejecutarOperacion(int a, int b, std::function<int(int, int)> operacion) {
    std::cout << "Resultado: " << operacion(a, b) << '\n';
}

int main() {
    auto suma = [](int x, int y) { return x + y; };
    auto resta = [](int x, int y) { return x - y; };

    ejecutarOperacion(5, 3, suma);   // Resultado: 8
    ejecutarOperacion(5, 3, resta);  // Resultado: 2
}
```

## Almacenamiento de comportamientos

`std::function` puede ser miembro de una clase para **almacenar una estrategia configurable**:

```cpp
class Procesador {
public:
    void setOperacion(std::function<int(int, int)> op) {
        operacion_ = op;
    }

    int procesar(int a, int b) const {
        return operacion_(a, b);
    }

private:
    std::function<int(int, int)> operacion_;
};
```

Y puede utilizarse así:

```cpp
Procesador p;
p.setOperacion([](int x, int y) { return x * y; });
std::cout << p.procesar(4, 5); // 20
```

## Comparación con punteros a función

`std::function` es más general que un puntero a función:

```cpp
// Solo admite funciones o punteros:
int sumar(int a, int b) { return a + b; }
int (*pf)(int, int) = &sumar;
```

En cambio, `std::function<int(int, int)>` puede almacenar:

* `sumar` (función)
* `[](int a, int b){ return a + b; }` (lambda)
* Un objeto con `int operator()(int, int)` (functor)

## Costo y consideraciones

* `std::function` tiene **cierto coste adicional** respecto al uso directo de lambdas o punteros, ya que realiza **type erasure** (borrado de tipo) y puede implicar **asignación dinámica**.
* Sin embargo, su flexibilidad y expresividad justifican su uso en muchos escenarios donde se necesita **comportamiento configurable** o **modularidad**.

---

## Resumen

* `std::function` encapsula **cualquier objeto invocable** con una firma dada, permitiendo desacoplar comportamiento.
* Es útil para **delegar acciones**, **almacenar estrategias configurables**, o **pasar lógica como parámetro**.
* Proporciona una solución homogénea y dinámica para representar comportamiento intercambiable, especialmente útil cuando se combinan lambdas, funciones y clases.

---

¿Deseas que continuemos ahora con la siguiente sección: **"Functores (objetos invocables) y clases con `operator()`"**?
