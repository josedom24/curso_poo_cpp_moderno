# Plantilla de clase: `std::optional`

En la programación tradicional en C++, el uso de punteros nulos (`nullptr`) ha sido una técnica común para representar la **ausencia de valor**. Sin embargo, este enfoque tiene múltiples limitaciones: falta de seguridad de tipo, posibilidad de errores en tiempo de ejecución (como desreferenciar punteros nulos), y escasa expresividad semántica.

Para abordar estos problemas, C++17 introdujo la clase plantilla `std::optional`, una herramienta que permite **representar explícitamente un valor que puede estar presente o ausente** de forma segura y expresiva. Se trata de una solución moderna, fuertemente tipada y alineada con prácticas de diseño robusto.

`std::optional<T>` es una plantilla de clase que encapsula un valor de tipo `T`, o la ausencia de dicho valor. Permite evitar el uso de punteros o valores especiales (como `-1` o `""`) para indicar condiciones especiales, y mejora la claridad del código.

Para utilizar `std::optional`, es necesario incluir el encabezado `<optional>`.

La sintaxis básica es:

```cpp
#include <optional>

std::optional<int> obtenerNumero(bool exito) {
    if (exito) {
        return 42;
    } else {
        return std::nullopt;
    }
}
```

Aquí, `std::nullopt` representa la ausencia de valor. La función puede retornar un número válido o ninguno, sin necesidad de punteros ni valores centinela.

## Operaciones comunes

* Puede estar en **estado vacío** (no contiene valor).
* Puede estar en **estado ocupado** (contiene un valor de tipo `T`).
* Proporciona operadores y funciones miembro para:
    * Consultar si hay valor (`has_value()`, `operator bool` (se puede usar como una expresión lógica por ejemplo en un `if`)).
    * Acceder al valor (`*`, `value()`).
    * Obtener un valor por defecto (`value_or()`).
    * Construir y destruir el valor de forma controlada.


**Comprobar si contiene un valor**

```cpp
if (resultado.has_value()) {
    std::cout << "Valor: " << resultado.value() << "\n";
    std::cout << "Valor: " << *resultado << "\n";  //Devuelve el valor como con value()
}
```

**Obtener el valor con valor por defecto**

```cpp
int valor = resultado.value_or(0);  // Si no hay valor, devuelve 0
```

**Asignar y modificar**

```cpp
std::optional<std::string> nombre;
nombre = "Carlos";
```

## Ventajas de `std::optional`

* Mejora la **expresividad del código** al declarar explícitamente cuándo un valor puede no estar presente.
* Elimina la necesidad de usar **punteros nulos** o valores mágicos.
* Proporciona **seguridad de tipo** en tiempo de compilación.
* Compatible con operaciones funcionales como encadenamiento y composición (a partir de C++23 con `and_then`, `transform`, etc.).

A tener en cuenta:

* El método `value()` lanza una excepción (`std::bad_optional_access`) si se accede al valor sin comprobar su presencia.
* `std::optional<T>` debe usarse principalmente con tipos **ligeros o triviales**. Para tipos grandes o costosos de copiar, puede implicar sobrecarga.
* Ideal para funciones que **pueden fallar pero no requieren detalles del error**.

## Ejemplo completo

Ejemplo: Buscar un número en un vector:

```cpp
#include <iostream>
#include <vector>
#include <optional>

// Función que busca un valor en un vector
std::optional<int> buscar(const std::vector<int>& datos, int objetivo) {
    for (int valor : datos) {
        if (valor == objetivo) {
            return valor;  // Estado ocupado
        }
    }
    return std::nullopt;   // Estado vacío
}

int main() {
    std::vector<int> numeros = {3, 5, 7, 9};

    std::optional<int> resultado = buscar(numeros, 5);

    // Consultar si hay valor
    if (resultado.has_value()) {
        std::cout << "Encontrado con has_value(): " << *resultado << '\n';
    }

    // También se puede usar como condición lógica
    if (resultado) {
        std::cout << "Encontrado con if(resultado): " << resultado.value() << '\n';
    }

    // Obtener el valor o un valor por defecto si está vacío
    std::cout << "Valor o -1 si no está: " << resultado.value_or(-1) << '\n';

    // Buscar un valor que no está
    std::optional<int> resultado2 = buscar(numeros, 100);

    if (!resultado2) {
        std::cout << "No se encontró el número 100.\n";
    }

    std::cout << "Resultado2 con value_or(-1): " << resultado2.value_or(-1) << '\n';
}
```

* `std::optional<int> resultado` puede estar vacío (`std::nullopt`) o contener un entero.
* Se retorna `std::nullopt` si no se encuentra el valor.
* `resultado.has_value()` devuelve `true` si contiene valor.
* También puede usarse `if (resultado)` gracias a `operator bool`.
* `*resultado` desreferencia el valor.
* `resultado.value()` lanza una excepción (`std::bad_optional_access`) si no hay valor.
* `resultado.value_or(-1)` devuelve el valor si existe, o `-1` si no.
