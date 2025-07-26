# Funciones como argumentos

En los lenguajes de programación modernos, la capacidad de tratar a las funciones como valores —es decir, de **pasarlas como argumentos a otras funciones**— permite lograr una **mayor modularidad** y **reutilización de código**.
Aunque este tipo de abstracción está fuertemente asociado a paradigmas funcionales, en C++ también es posible utilizar funciones como parámetros **sin necesidad de clases ni programación orientada a objetos**.

Este recurso resulta particularmente útil para **modificar el comportamiento de una función genérica**, sin tener que escribir múltiples versiones similares del mismo código.

## Paso de funciones como argumentos

En C++, una función puede ser pasada como argumento a otra función mediante el uso de **punteros a función**.
Dado que los nombres de funciones en C++ pueden convertirse en punteros automáticamente, la sintaxis resulta sencilla. La sintaxis general de un puntero a función es:

```cpp
TipoRetorno (*nombre)(TipoArg1, TipoArg2, ...);
```

Por ejemplo, un puntero a una función que recibe un `int` y devuelve `bool` se declara así:

```cpp
bool (*criterio)(int);
```

Este puntero puede apuntar a cualquier función con la misma firma:

```cpp
bool es_par(int x) {
    return x % 2 == 0;
}
```

Y se puede usar como argumento de una función:

```cpp
void imprimir_si(std::vector<int> datos, bool (*condicion)(int)) {
    for (int valor : datos) {
        if (condicion(valor)) {
            std::cout << valor << " ";
        }
    }
}
```

En este ejemplo, `condicion` representa un comportamiento configurable, y la lógica principal (`imprimir_si`) permanece inalterada.

## Cambiar comportamiento con funciones

La capacidad de pasar funciones como parámetros permite **generalizar el comportamiento** de una función sin duplicar código.

Por ejemplo, supongamos que queremos imprimir sólo ciertos elementos de un vector según una condición:

* Sólo los pares
* Sólo los mayores que 10
* Sólo los negativos

Podríamos escribir una función distinta para cada caso, pero esto **repite el mismo patrón** con ligeras variaciones.

Al parametrizar la condición, podemos reusar una única función genérica:

```cpp
bool mayor_que_diez(int x) {
    return x > 10;
}
```

Y luego invocar:

```cpp
imprimir_si(datos, es_par);
imprimir_si(datos, mayor_que_diez);
```

Esto **reduce la duplicación**, **separa el qué del cómo**, y promueve **modularidad**.

## Ejemplo completo: filtros con funciones como parámetros

Veamos un programa completo que ilustra estos conceptos:

```cpp
#include <iostream>
#include <vector>

bool es_par(int x) {
    return x % 2 == 0;
}

bool negativo(int x) {
    return x < 0;
}

void imprimir_si(const std::vector<int>& datos, bool (*cond)(int)) {
    for (int x : datos) {
        if (cond(x)) {
            std::cout << x << " ";
        }
    }
    std::cout << '\n';
}

int main() {
    std::vector<int> numeros = {1, 2, -3, 4, 5, -6, 7, 8};

    std::cout << "Números pares: ";
    imprimir_si(numeros, es_par);

    std::cout << "Números negativos: ";
    imprimir_si(numeros, negativo);
}
```

Pasar funciones como argumentos permite separar **la lógica de procesamiento** de los **criterios específicos**, lo que favorece la reutilización, la flexibilidad y el diseño modular.
Este mecanismo puede emplearse sin necesidad de clases ni técnicas avanzadas, lo cual lo convierte en un recurso valioso incluso en programas estructurados simples.

En C++ moderno, existen herramientas adicionales como **lambdas** y **`std::function`**, que permiten expresar estos conceptos con mayor flexibilidad. Sin embargo, comprender primero el paso de funciones tradicionales es clave para sentar las bases de la **abstracción de comportamiento**.

