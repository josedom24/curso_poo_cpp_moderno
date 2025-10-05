# Plantillas de clase: `std::variant` y `std::visit`

En el desarrollo de software, es habitual que una variable deba poder almacenar **uno de varios tipos posibles**, pero **solo uno a la vez**.
Tradicionalmente, este problema se resolvía con *uniones* (`union`) en C o mediante jerarquías de clases y polimorfismo dinámico en C++.
Sin embargo, ambos enfoques presentan limitaciones:

* las uniones no ofrecen **seguridad de tipo**,
* el polimorfismo dinámico añade **sobrecarga en tiempo de ejecución**.

C++17 introduce **`std::variant`**, una clase plantilla que representa una **alternativa segura en tiempo de compilación** a estos mecanismos.
Se trata de una herramienta moderna para implementar **tipos discriminados** (*sum types*), comunes en lenguajes funcionales, que aporta expresividad, seguridad y eficiencia.

## ¿Qué es `std::variant`?

`std::variant<Ts...>` es una plantilla que puede almacenar **un valor de uno (y solo uno)** de los tipos indicados como parámetros.
Internamente mantiene un índice que indica cuál de los tipos está activo.

```cpp
#include <iostream>
#include <variant>

int main() {
    // Un std::variant que puede contener un int o un float
    std::variant<int, float> valor;

    valor = 10;      // Contiene un int
    std::cout << "Valor entero: " << std::get<int>(valor) << '\n';

    valor = 3.14f;   // Ahora contiene un float
    std::cout << "Valor flotante: " << std::get<float>(valor) << '\n';

    return 0;
}
```

* En este ejemplo, `valor` puede guardar un `int` o un `float`, pero nunca ambos a la vez. 
* El tipo activo se rastrea automáticamente en tiempo de compilación.
* `std::get<int>(variant)` devuelve el valor almacenado en el std::variant si el tipo activo es int, lanzando una excepción si no coincide.

## ¿Qué es `std::visit`?

Cuando un `std::variant` puede contener distintos tipos, necesitamos una forma segura de **acceder al valor almacenado sin conocer su tipo concreto**.
Esa función la cumple `std::visit`.

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
* `std::visit` ejecuta la función proporcionada (una *lambda* en este caso) con el valor actual.
* La lambda genérica `[](auto&& valor)` se adapta automáticamente al tipo del valor almacenado.
* En `[](auto&& valor)`:
    * `auto` significa que el tipo se deduce automáticamente (puede ser `int`, `std::string`, etc.).
    * `&&` significa que la función acepta el valor **por referencia universal**, es decir, **sirve para cualquier tipo** y **no hace copias innecesarias**.
* `auto&&` permite que la lambda funcione con **cualquier tipo** que contenga el `std::variant`, de forma eficiente.
*`std::visit` evita el uso de comprobaciones de tipo manuales (`if`, `dynamic_cast`, etc.) y garantiza seguridad de tipo en tiempo de compilación.


## Ejemplo completo: procesar distintos tipos de eventos

Supongamos una aplicación que puede recibir varios **eventos**: un número de control (`int`), un mensaje (`std::string`) o una lectura de sensor (`double`). Queremos procesar cada tipo de manera diferente.

```cpp
#include <iostream>
#include <variant>
#include <string>
#include <vector>

// Tipo variante que puede contener uno de varios tipos
using Evento = std::variant<int, std::string, double>;

// Visitor con sobrecarga de funciones
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

* `std::variant<int, std::string, double>` define un tipo que puede contener **uno solo de esos tres tipos** a la vez.
* `ProcesadorEvento` es una clase *visitor* que **sobrecarga `operator()`** para cada tipo posible.
* `std::visit(ProcesadorEvento{}, evento)` llama automáticamente a la versión correcta del método según el tipo almacenado.
* Así, se evita el uso de *casts* o comprobaciones manuales de tipo.
* Si todos los tipos pudieran procesarse de la misma forma, se podría usar directamente una **lambda genérica**, pero cuando el comportamiento depende del tipo concreto, un *visitor* con sobrecargas es más claro y seguro.

