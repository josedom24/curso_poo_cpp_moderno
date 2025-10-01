# Plantillas de clase:`std::variant` y `std::visit`

En el desarrollo de software, existen situaciones en las que una variable debe poder almacenar **uno de varios tipos posibles**, pero **solo uno a la vez**. Tradicionalmente, este problema se resolvía mediante uniones (`union`) en C o jerarquías de clases con polimorfismo dinámico en C++. Sin embargo, estas soluciones tienen limitaciones: la unión carece de seguridad de tipo y el polimorfismo implica sobrecarga en tiempo de ejecución.

C++17 introduce `std::variant`, una clase plantilla que representa una **alternativa segura en tiempo de compilación** a estos enfoques. Se trata de una forma moderna y robusta de implementar **tipos discriminados** o **sum types** (comunes en lenguajes funcionales), permitiendo escribir código más expresivo, seguro y eficiente.

## ¿Qué es `std::variant`?

`std::variant<Ts...>` es una clase plantilla que puede contener un valor de uno (y solo uno) de los tipos especificados como parámetros. Internamente, es similar a una unión discriminada con un índice que indica qué tipo está activo.

```cpp
#include <variant>

std::variant<int, float> valor;
valor = 10;     // contiene un int
valor = 3.14f;  // ahora contiene un float
```
## ¿Qué es `std::visit`?

`std::variant` es como una **caja** que puede guardar **un valor de varios tipos posibles**, pero **solo uno a la vez**. Al no saber el tipo que está guardado, necesitamos un mecanismo para descubrirlo, este es el objetivo de usar `std::visit`. Lo vemos con un ejemplo:

```cpp
#include <iostream>
#include <variant>

int main() {
    std::variant<int, std::string> dato = "Hola";

    std::visit([](auto&& valor) {
        std::cout << "Valor: " << valor << '\n';
    }, dato);
}
```

* `dato` puede contener un `int` o un `std::string`.
* `std::visit` llama a una **función** que tú le pasas (en este caso una *lambda*).
* Esa función se ejecuta **automáticamente con el tipo correcto** del valor que está guardado.
* No necesitas preguntar “¿es un `int` o un `std::string`?”
* `std::visit` ya lo sabe, y le pasa el valor correcto a tu función.
* `[](auto&& valor)` es una **lambda genérica**, como decir: *"Cuando me des el valor, lo imprimo sin importar si es un número o un texto"*.

## Ejemplo completo

Perfecto. A continuación te muestro un **ejemplo completo y más complejo** con `std::variant` y `std::visit`, en el que:

* Usamos un `std::variant` que puede contener varios tipos distintos.
* Aplicamos acciones específicas según el tipo que contenga.
* Usamos `std::visit` con un **visitor con sobrecarga de funciones**, no solo una lambda genérica.

---

## 🧩 Ejemplo: Procesar diferentes tipos de eventos

Supongamos que tenemos una aplicación que puede recibir distintos **eventos**:

* Un número (`int`) que representa una señal de control.
* Una cadena (`std::string`) que representa un mensaje.
* Un valor decimal (`double`) que representa una lectura de sensor.

Queremos procesarlos **de manera diferente**.


```cpp
#include <iostream>
#include <variant>
#include <string>
#include <vector>

// Tipo variante que puede ser uno de varios tipos
using Evento = std::variant<int, std::string, double>;

// Visitor que define cómo actuar según el tipo
class ProcesadorEvento {
public:
    void operator()(int codigo) const {
        std::cout << "Código de control recibido: " << codigo << '\n';
    }

    void operator()(const std::string& mensaje) const {
        std::cout << "Mensaje recibido: \"" << mensaje << "\"\n";
    }

    void operator()(double lectura) const {
        std::cout << "Lectura de sensor: " << lectura << " unidades\n";
    }
};

int main() {
    // Lista de eventos de distintos tipos
    std::vector<Evento> eventos = {
        42,
        std::string("Arranque del sistema"),
        23.7,
        std::string("Advertencia: temperatura alta"),
        0,
        18.2
    };

    // Procesar cada evento según su tipo
    for (const auto& evento : eventos) {
        std::visit(ProcesadorEvento{}, evento);
    }

    return 0;
}
```
* `std::variant<int, std::string, double>`: Es un tipo que **puede contener uno solo de esos tres tipos** a la vez. Aquí lo hemos llamado `Evento` (con `using`).
* `std::vector<Evento> eventos = { ... };`: Simulamos una secuencia de eventos heterogéneos: números, cadenas y decimales.
* `ProcesadorEvento`: Es una **clase que sobrecarga `operator()`** para distintos tipos.
* Esto permite que `std::visit` elija automáticamente la función correcta según el tipo almacenado.
* `std::visit(ProcesadorEvento{}, evento);`: Llama a la función adecuada de `ProcesadorEvento` con el contenido de `evento`.
* Si `evento` contiene un `std::string`, se llama a `operator()(const std::string&)`, y así sucesivamente.
* ¿Por qué no una sola lambda?: Una sola lambda genérica funciona si el comportamiento es **igual para todos los tipos** o **muy simple**.
* Pero cuando quieres **diferenciar claramente según el tipo**, es mejor usar una clase con sobrecargas como `ProcesadorEvento`.
