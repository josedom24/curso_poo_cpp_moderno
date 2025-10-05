# Plantilla de clase: `std::optional`

En C++ clásico, la ausencia de valor se representaba con punteros nulos (`nullptr`) o valores especiales como `-1` o `""`.
Este enfoque era poco seguro y propenso a errores en tiempo de ejecución, además de poco expresivo desde el punto de vista semántico.

C++17 introduce la plantilla de clase **`std::optional<T>`**, que permite **representar de manera explícita y segura un valor que puede o no estar presente**.
Su uso mejora la claridad, la seguridad y la legibilidad del código moderno.

## Concepto básico

`std::optional<T>` encapsula un valor de tipo `T` o la ausencia de él. Cuando no contiene valor, se encuentra en el estado **vacío**, representado por la constante `std::nullopt`.

```cpp
#include <iostream>
#include <optional>

// Función que puede devolver un número o ningún valor
std::optional<int> obtenerNumero(bool exito) {
    if (exito)
        return 42;           // Valor presente
    else
        return std::nullopt; // Sin valor
}

int main() {
    // Caso 1: la función devuelve un valor
    std::optional<int> resultado1 = obtenerNumero(true);

    if (resultado1.has_value()) {
        std::cout << "Valor encontrado: " << resultado1.value() << '\n';
    }

    // También puede usarse directamente como condición lógica
    if (resultado1) {
        std::cout << "Acceso con *resultado1: " << *resultado1 << '\n';
    }

    // Caso 2: la función no devuelve valor
    std::optional<int> resultado2 = obtenerNumero(false);

    // Usar value_or() para obtener un valor por defecto
    int numero = resultado2.value_or(0);
    std::cout << "Valor devuelto o 0 por defecto: " << numero << '\n';

    // Comprobar si está vacío
    if (!resultado2) {
        std::cout << "Sin valor en resultado2.\n";
    }

    return 0;
}
```

* `std::optional<int>` encapsula un entero que puede o no estar presente.
* `std::nullopt` representa la ausencia de valor.
* `has_value()` o `if (resultado)` permiten comprobar si existe valor.
* `value()` o `*resultado` acceden al valor almacenado.
* `value_or(valor_defecto)` devuelve un valor alternativo si el `optional` está vacío.

En este ejemplo, la función puede devolver un entero válido o ninguno, sin recurrir a punteros ni valores centinela.

## Métodos y operaciones principales

El siguiente programa muestra el uso de los métodos más importantes de `std::optional` y cómo comprobar, obtener y modificar su valor de forma segura:

```cpp
#include <iostream>
#include <optional>
#include <string>

int main() {
    // Declaración vacía: no contiene valor
    std::optional<std::string> mensaje;

    // Comprobar si contiene un valor
    if (!mensaje.has_value()) {
        std::cout << "Sin valor inicial.\n";
    }

    // Asignar un valor
    mensaje = "Hola mundo";

    // Comprobar valor usando operator bool()
    if (mensaje) {
        std::cout << "Valor asignado: " << *mensaje << '\n';
    }

    // Acceder al valor con value()
    std::cout << "Con value(): " << mensaje.value() << '\n';

    // Obtener valor con valor por defecto
    std::optional<std::string> otroMensaje;
    std::cout << "Valor o por defecto: " << otroMensaje.value_or("Vacío") << '\n';

    // Reiniciar (vaciar) el optional
    mensaje.reset();
    std::cout << "Tras reset(), has_value(): "
              << std::boolalpha << mensaje.has_value() << '\n';

    return 0;
}
```

* `*opcional`: Permite acceder directamente al valor, igual que `value()`.
* `reset()`: Elimina el valor contenido, dejando el objeto vacío.

## Ejemplo completo

```cpp
#include <iostream>
#include <vector>
#include <optional>

// Busca un número en un vector y devuelve un std::optional<int>
std::optional<int> buscar(const std::vector<int>& datos, int objetivo) {
    for (int valor : datos) {
        if (valor == objetivo)
            return valor;          // Valor encontrado
    }
    return std::nullopt;           // Sin valor
}

int main() {
    std::vector<int> numeros = {3, 5, 7, 9};

    auto resultado = buscar(numeros, 5);

    if (resultado) {
        std::cout << "Encontrado: " << *resultado << '\n';
    }

    std::cout << "Valor o -1: " << resultado.value_or(-1) << '\n';

    auto resultado2 = buscar(numeros, 100);
    if (!resultado2) {
        std::cout << "No encontrado.\n";
    }

    std::cout << "Resultado2 con valor por defecto: "
              << resultado2.value_or(-1) << '\n';
}
```

`std::optional` es una herramienta esencial del C++ moderno: combina seguridad de tipo, expresividad y simplicidad.
