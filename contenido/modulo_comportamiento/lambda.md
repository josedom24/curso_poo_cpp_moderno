# Uso de lambdas para comportamiento flexible

En C++ moderno, las **expresiones lambda** permiten definir funciones **de forma concisa**, **en línea** y **flexible**. Este mecanismo forma parte de un conjunto de herramientas que permiten **abstraer comportamiento**, es decir, **parametrizar el *qué hacer*** sin necesidad de crear nuevas clases o funciones independientes.

## Funciones lambda

Una **expresión lambda** es una forma de definir una función anónima (sin nombre) que puede capturar variables del entorno en el que se define. Su sintaxis general es:

```cpp
[captura](parámetros) -> tipo_retorno {
    cuerpo;
};
```

Donde:

* `captura` indica qué variables externas se usan dentro de la lambda.
* `parámetros` son los argumentos que acepta la lambda.
* `tipo_retorno` es opcional si puede deducirse.
* `cuerpo` es el bloque de código que se ejecuta al invocar la lambda.

Veamos un ejemplo simple:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> datos = {1, 2, 3, 4, 5};

    std::for_each(datos.begin(), datos.end(), [](int x) {
        std::cout << x * 2 << ' ';
    });
}
```

* Recordamos que `std::for_each` nos permite recorrer  y aplicar una función a cada elemento del iterador.
* La lambda `[](int x) { std::cout << x * 2 << ' '; }` actúa como una función que se aplica a cada elemento del vector. Este enfoque evita declarar una función externa y hace el código más compacto y local.

## Captura de variables

Las lambdas pueden capturar variables del entorno mediante:

* Captura por valor (`[=]`): copia las variables externas utilizadas.
* Captura por referencia (`[&]`): utiliza referencias a las variables externas.
* Captura explícita: se puede especificar individualmente qué capturar y cómo (`[x, &y]`).

Veamos un ejemplo:

```cpp
int a = 10, b = 20;

auto lambda = [a, &b]() {
    std::cout << "a: " << a << ", b: " << b << '\n';
    // a es copia; b es referencia
};

b = 99;
lambda();  // a: 10, b: 99
```

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



Nueva versión


Perfecto. A continuación te presento el material didáctico correspondiente al apartado:

---

# 📘 Expresiones lambda: funciones anónimas

## 1. Introducción

En C++ moderno, una **expresión lambda** permite definir una función **de manera anónima** (es decir, sin nombre) directamente en el lugar donde se necesita. Este recurso es especialmente útil cuando se desea expresar un comportamiento simple de forma **concisa**, **localizada** y **efímera**, sin necesidad de declarar una función externa.

Las lambdas son ideales para ser utilizadas como **argumentos a otras funciones**, especialmente en combinación con algoritmos de la STL, donde se requiere especificar condiciones o acciones concretas de forma clara.

---

## 2. Sintaxis básica de lambdas

La forma general de una lambda es:

```cpp
[captura](parámetros) -> tipo_retorno {
    cuerpo;
};
```

Para muchas situaciones, el compilador puede deducir el tipo de retorno, por lo que este se puede omitir.

### Ejemplo básico:

```cpp
auto cuadrado = [](int x) {
    return x * x;
};

std::cout << cuadrado(5);  // Imprime 25
```

### Expresión lambda sin almacenarla:

También es posible definir y utilizar una lambda **sin asignarla a una variable**:

```cpp
std::cout << [](int x) { return x * 2; }(10);  // Imprime 20
```

Esto se conoce como **invocación inmediata**.

---

## 3. Uso en lugar de funciones normales

Supongamos que queremos una función que reciba un número y verifique si es impar. Podemos hacerlo de forma tradicional:

```cpp
bool es_impar(int x) {
    return x % 2 != 0;
}
```

Pero si sólo necesitamos este comportamiento en un punto concreto, podemos usar una lambda en su lugar:

```cpp
auto es_impar = [](int x) {
    return x % 2 != 0;
};
```

Este enfoque evita la proliferación de funciones auxiliares triviales. Además, hace el código más **modular** y **localizado**, ya que el comportamiento queda expresado en el lugar donde se necesita.

---

## 4. Ventajas de la notación lambda

Las expresiones lambda ofrecen múltiples beneficios prácticos:

### 🟦 1. **Código más conciso**

Eliminan la necesidad de escribir funciones auxiliares innecesarias. Esto reduce el tamaño y la complejidad del código.

```cpp
std::for_each(v.begin(), v.end(), [](int x) { std::cout << x << ' '; });
```

### 🟦 2. **Mayor legibilidad local**

El comportamiento está **definido junto al uso**, lo cual facilita la comprensión sin necesidad de desplazarse a otra parte del código.

### 🟦 3. **Captura de contexto**

Permiten acceder a variables definidas fuera de la lambda, mediante mecanismos de captura. Esto aporta flexibilidad sin recurrir a clases o estructuras externas.

Ejemplo con captura:

```cpp
int umbral = 5;

std::for_each(v.begin(), v.end(), [umbral](int x) {
    if (x > umbral)
        std::cout << x << ' ';
});
```

### 🟦 4. **Mayor modularidad sin clases**

Permiten expresar **comportamientos parametrizables**, como condiciones, acciones o transformaciones, sin necesidad de diseñar una jerarquía de clases.

---

## 5. Ejemplo práctico: uso en algoritmos

Veamos un ejemplo completo que muestra cómo las lambdas permiten aplicar filtros personalizados:

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> datos = {1, 4, 6, 9, 12, 15};

    std::cout << "Valores mayores que 10:\n";

    std::for_each(datos.begin(), datos.end(), [](int x) {
        if (x > 10)
            std::cout << x << ' ';
    });

    std::cout << '\n';
}
```

**Ventajas observadas**:

* No fue necesario definir una función externa como `mayor_que_diez`.
* El comportamiento está expresado directamente en el lugar donde se utiliza.
* El código es compacto y claro.

---

## 6. Conclusión

Las expresiones lambda son una herramienta poderosa para definir **funciones anónimas** y facilitar una **programación más modular y expresiva**.
Permiten parametrizar comportamientos, capturar el contexto, y reducir la complejidad de programas estructurados, sin necesidad de recurrir a orientación a objetos.

Su dominio es fundamental para aprovechar al máximo las capacidades de la STL y escribir código limpio, reutilizable y moderno.

---

¿Quieres que prepare ejercicios específicos para este apartado? También puedo escribir una clase dedicada exclusivamente a la **captura de variables en lambdas**.
