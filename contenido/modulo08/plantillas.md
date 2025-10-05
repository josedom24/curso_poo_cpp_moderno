# Introducción a las plantillas de clases

En el desarrollo de software, es habitual la necesidad de definir clases que operen sobre distintos tipos de datos. Una solución ingenua consistiría en crear múltiples versiones de una misma clase —una por cada tipo necesario—, lo cual genera duplicación de código, mayores costes de mantenimiento y pérdida de claridad.

La **programación genérica** en C++ moderno ofrece una solución elegante a este problema mediante el uso de **plantillas (templates)**.
Una plantilla permite definir estructuras de datos y algoritmos en términos de **tipos genéricos**, de forma que el compilador genera automáticamente las versiones concretas necesarias al ser instanciadas.

Perfecto 👍
Aquí tienes la **versión unificada y revisada** de esa parte, con una explicación más fluida y un **ejemplo completo, compilable y comentado**, manteniendo el tono formal y didáctico del curso:

---

## Definición e instanciación de una plantilla de clase

Una **plantilla de clase** permite definir una estructura genérica cuyos miembros pueden operar sobre distintos tipos de datos, sin duplicar código.
El tipo concreto se especifica en el momento de la **instanciación**, y el compilador genera automáticamente la versión correspondiente de la clase.

A continuación se muestra un ejemplo completo de una plantilla básica:

```cpp
#include <iostream>
#include <string>

// Definición de una clase plantilla con un parámetro de tipo T
template <typename T>
class Contenedor {
private:
    T valor;  // Atributo genérico del tipo T

public:
    void setValor(const T& v) { valor = v; }  // Asigna el valor
    T getValor() const { return valor; }      // Devuelve el valor almacenado
};

int main() {
    // Instanciación con tipo int
    Contenedor<int> entero;
    entero.setValor(42);
    std::cout << "Valor entero: " << entero.getValor() << "\n";

    // Instanciación con tipo std::string
    Contenedor<std::string> texto;
    texto.setValor("Hola mundo");
    std::cout << "Valor de texto: " << texto.getValor() << "\n";

    return 0;
}
```
* `template <typename T>` declara que la clase depende de un parámetro de tipo genérico `T`.
* `Contenedor<int>` y `Contenedor<std::string>` son **instancias concretas** de la plantilla.
* El compilador genera automáticamente el código específico para cada tipo utilizado.

Este proceso se denomina **instanciación de la plantilla**, y es la base de la **programación genérica** en C++ moderno.


## Características principales

* **Generación automática de código:** el compilador crea las versiones necesarias en función de los tipos utilizados.
* **Seguridad de tipo:** las operaciones se verifican en tiempo de compilación, evitando errores de conversión.
* **Reutilización sin pérdida de rendimiento:** las plantillas permiten escribir código genérico que se expande a código específico, evitando el coste del polimorfismo dinámico.
* **Separación de interfaz y tipo concreto:** los algoritmos o estructuras se diseñan de forma independiente al tipo de dato que manipulan.
* **Ubicación habitual:** las definiciones de plantillas suelen incluirse en archivos de encabezado (`.h` o `.hpp`), ya que el compilador necesita conocer su implementación completa al instanciarlas.

## Ejemplo completo

El siguiente ejemplo muestra una clase plantilla `Caja` que puede almacenar un valor de cualquier tipo:

```cpp
#include <iostream>
#include <string>

// Definición de la plantilla
template <typename T>
class Caja {
private:
    T contenido;  // Tipo genérico

public:
    void setContenido(const T& valor) { contenido = valor; }
    T getContenido() const { return contenido; }
};

int main() {
    // Instanciación con int
    Caja<int> cajaEntera;
    cajaEntera.setContenido(10);
    std::cout << "Entero: " << cajaEntera.getContenido() << "\n";

    // Instanciación con std::string
    Caja<std::string> cajaTexto;
    cajaTexto.setContenido("Texto genérico");
    std::cout << "Texto: " << cajaTexto.getContenido() << "\n";

    return 0;
}
```

* Las **plantillas de clase** permiten definir clases que operan sobre tipos genéricos.
* El compilador genera automáticamente versiones concretas según los tipos usados.
* Garantizan **seguridad de tipo**, **reutilización de código** y **rendimiento equivalente al código especializado**.
* Constituyen la base de la **STL (Standard Template Library)** y de muchos componentes modernos de C++.

