# Clases genéricas con uno o varios parámetros de tipo

En el apartado anterior se introdujo la noción de plantillas de clases con un solo parámetro de tipo. Sin embargo, en muchas situaciones prácticas es necesario que una clase manipule simultáneamente objetos de distintos tipos. C++ permite extender el concepto de plantillas para incluir **múltiples parámetros de tipo**, proporcionando mayor flexibilidad y expresividad.

La definición de una plantilla de clase con varios parámetros de tipo sigue la siguiente forma:

```cpp
template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;
public:
    Par(const T1& a, const T2& b) : primero(a), segundo(b) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }
};
```

Aquí, la clase `Par` está parametrizada con dos tipos, `T1` y `T2`. Cada uno puede ser distinto e independiente.

Veamos un ejemplo:

```cpp
Par<int, std::string> par1(1, "uno");
std::cout << par1.getPrimero() << ", " << par1.getSegundo() << std::endl;

Par<double, char> par2(3.14, 'π');
```

Este enfoque permite modelar pares heterogéneos de manera genérica, sin necesidad de definir múltiples versiones especializadas de la clase.

## Comparación con `std::pair`

La STL (Standard Template Library) ya provee una clase plantilla genérica llamada `std::pair<T1, T2>`, que implementa precisamente esta idea. 

`std::pair` es una **plantilla de clase** definida en el encabezado `<utility>` de la STL (Standard Template Library). Su propósito es almacenar **dos valores de tipos posiblemente diferentes**, agrupados como una sola unidad. Es útil para devolver múltiples valores desde una función o para representar relaciones clave-valor simples. La sintaxis general es:

```cpp
std::pair<T1, T2> nombre;
```
Donde `T1` y `T2` pueden ser cualquier tipo de datos (como `int`, `std::string`, estructuras, etc.).

Veamos une ejemplo:

```cpp
#include <iostream>
#include <utility>  // Para std::pair y std::make_pair
#include <string>

int main() {
    std::pair<int, std::string> p = std::make_pair(2, "dos");

    std::cout << p.first << ", " << p.second << std::endl;

    return 0;
}
```

* `first`: representa el **primer elemento** del par.
* `second`: representa el **segundo elemento**.
* `std::make_pair` es una **función auxiliar** que construye un objeto `std::pair` **sin necesidad de especificar explícitamente los tipos**. El compilador deduce automáticamente los tipos a partir de los argumentos proporcionados. Es equivalente a: `std::pair<int, std::string> p(2, "dos");`.
¿Deseas que incluya un ejemplo de cómo retornar un `std::pair` desde una función o cómo usarlo dentro de un `std::map`?

El objetivo de este apartado es comprender cómo se construye y usa una estructura equivalente desde cero, lo cual fortalece la comprensión del modelo de tipos en C++.

Al crear estructuras propias, es posible agregar lógica adicional que `std::pair` no incluye, como validaciones o restricciones de tipo, lo que refuerza la utilidad de definir clases genéricas personalizadas. Veamos nuestra versión:

```cpp
#include <iostream>
#include <string>

template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;
public:
    Par(const T1& a, const T2& b) : primero(a), segundo(b) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }
};

int main() {
    Par<int, std::string> p(7, "siete");
    std::cout << "Primero: " << p.getPrimero() << "\n";
    std::cout << "Segundo: " << p.getSegundo() << "\n";

    return 0;
}
```

## Parámetros de tipo por valor

Además de tipos, las plantillas también pueden recibir valores constantes como parámetros. Por ejemplo:

```cpp
template <typename T, int N>
class Arreglo {
private:
    T datos[N];
public:
    T& operator[](int i) { return datos[i]; }
    const T& operator[](int i) const { return datos[i]; }
};
```

Este tipo de plantilla permite definir estructuras parametrizadas por tamaño en tiempo de compilación. Su uso es habitual en implementaciones de arrays estáticos o buffers con tamaño fijo.


Veamos un ejemplo: Clase plantilla `Arreglo` parametrizada por tamaño

```cpp
#include <iostream>

// Definición de plantilla con tipo T y entero constante N
template <typename T, int N>
class Arreglo {
private:
    T datos[N];  // Array estático de tamaño N
public:
    // Operador índice para acceso mutable
    T& operator[](int i) {
        return datos[i];
    }
    // Operador índice para acceso constante
    const T& operator[](int i) const {
        return datos[i];
    }
    // Función para obtener el tamaño del arreglo
    constexpr int size() const {
        return N;
    }
};

int main() {
    Arreglo<int, 5> arr;  // Creamos un arreglo de enteros de tamaño 5

    // Asignamos valores
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i * 10;
    }

    // Imprimimos valores
    for (int i = 0; i < arr.size(); ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << '\n';
    }

    return 0;
}
```

* `template <typename T, int N>` declara una plantilla que recibe un tipo `T` y un valor constante entero `N`.
* `T datos[N];` define un array estático cuyo tamaño es el valor `N` proporcionado como parámetro.
* Los operadores `operator[]` permiten acceder a los elementos del array, tanto en contexto mutable como constante.
* La función `size()` devuelve el tamaño del arreglo, que es el parámetro constante `N`, conocido en tiempo de compilación.
* Esta implementación de esta plantilla puede similar a plantillas que tenemos predefinidas en la STL, como `std::array`,...