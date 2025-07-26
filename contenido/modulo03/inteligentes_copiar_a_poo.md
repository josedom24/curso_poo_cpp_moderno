# Gestión de memoria con punteros inteligentes
**Falta por explicar las instrucciones make_. Que son los ciclos de recerencia.?**
En C++, la gestión segura y eficiente de memoria dinámica es un aspecto crítico del desarrollo robusto. Tras comprender los conceptos de **RAII** y **propiedad**, resulta natural introducir los **punteros inteligentes**, que son herramientas diseñadas precisamente para aplicar estos principios en la gestión de memoria.

## ¿Qué son los punteros inteligentes?

Los punteros inteligentes son clases plantilla de la biblioteca estándar de C++ (`<memory>`) que encapsulan punteros crudos y gestionan automáticamente la vida útil de los objetos a los que apuntan, siguiendo el patrón **RAII**.

Al utilizar punteros inteligentes:

* La **adquisición** de memoria ocurre al crear el puntero inteligente.
* La **liberación** de memoria se realiza automáticamente al destruirse el puntero inteligente, sin necesidad de llamadas manuales a `delete`.
* La **propiedad** del recurso es clara y controlada, reduciendo el riesgo de errores como fugas de memoria o accesos a memoria liberada.

Los punteros inteligentes más comunes son:

### `std::unique_ptr`

`std::unique_ptr` representa la **propiedad exclusiva** de un recurso. Solo puede existir un único propietario del recurso en un momento dado. Sus características son:

* No se puede copiar, solo mover (transferencia explícita de propiedad).
* Al destruirse, libera automáticamente el recurso que posee.
* Ideal para recursos que no deben compartirse, como objetos grandes o estructuras de datos dinámicas.

Ejemplo:

```cpp
#include <memory>
#include <iostream>

int main() {
    std::unique_ptr<int> ptr = std::make_unique<int>(42);

    std::cout << *ptr << std::endl;

    // Transferencia de propiedad mediante std::move
    std::unique_ptr<int> ptr2 = std::move(ptr);

    if (!ptr) {
        std::cout << "ptr ya no posee el recurso." << std::endl;
    }

    return 0; // El recurso se libera automáticamente al salir del ámbito
}
```

## `std::shared_ptr`

`std::shared_ptr` permite la **propiedad compartida** de un recurso mediante un mecanismo de **conteo de referencias**. Varios objetos pueden compartir la responsabilidad de un recurso, que se libera automáticamente cuando el último propietario desaparece. Sus características son:


* Permite múltiples copias que comparten la propiedad.
* El recurso se libera cuando el contador de referencias llega a cero.
* Útil en estructuras de datos compartidas o grafos.

Ejemplo:

```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(100);

    {
        std::shared_ptr<int> sp2 = sp1; // Comparte propiedad
        std::cout << "Valor: " << *sp2 << std::endl;
        std::cout << "Conteo de referencias: " << sp1.use_count() << std::endl;
    }

    std::cout << "Conteo tras salir del bloque: " << sp1.use_count() << std::endl;
    // El recurso se libera cuando el último shared_ptr desaparece

    return 0;
}
```
El uso incorrecto de `shared_ptr` puede provocar **ciclos de referencias**, causando fugas de memoria. Para evitarlo, se utiliza `std::weak_ptr`.

## `std::weak_ptr` 

`std::weak_ptr` es un puntero inteligente que observa un recurso gestionado por `shared_ptr`, pero **sin poseerlo**. Se le suele llamar **observador sin propiedad**. Su principal finalidad es romper ciclos de referencias y sus características son:

* No contribuye al conteo de referencias.
* Permite comprobar si el recurso aún existe mediante `.lock()`.
* Ideal para estructuras de datos que requieren referencias débiles, como árboles o grafos con punteros hacia atrás.

Ejemplo:

```cpp
#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sp = std::make_shared<int>(200);
    std::weak_ptr<int> wp = sp;

    if (auto spt = wp.lock()) { // Obtiene un shared_ptr temporal si el recurso aún existe
        std::cout << *spt << std::endl;
    } else {
        std::cout << "El recurso ha sido liberado." << std::endl;
    }

    return 0;
}
```
