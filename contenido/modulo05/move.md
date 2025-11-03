## Movimiento de objetos

En C++ clásico, copiar un objeto complejo —por ejemplo, un `std::vector` con miles de elementos— podía ser una operación costosa, ya que implicaba duplicar toda su memoria interna.
Para optimizar este proceso, a partir de C++11 el lenguaje incorporó el **movimiento de objetos**, que permite **transferir recursos** de un objeto a otro en lugar de copiarlos.

El movimiento hace posible escribir programas más eficientes, especialmente cuando se trabaja con **objetos temporales** o con **estructuras grandes** que no es necesario duplicar.

## Valores *lvalue* y *rvalue*

Para comprender cómo funciona el movimiento, es necesario distinguir dos categorías fundamentales de expresiones en C++:

* **lvalue (left value):**
  Son expresiones que hacen referencia a una ubicación identificable en memoria, es decir, **tienen nombre** y **pueden aparecer en el lado izquierdo de una asignación**.
  Se puede obtener su dirección con el operador `&`.

  ```cpp
  int x = 42;    // x es un lvalue
  int* p = &x;   // se puede tomar la dirección de x
  ```

* **rvalue (right value):**
  Son **valores temporales** que no tienen nombre ni dirección persistente.
  No se les puede tomar la dirección (en general) y se usan normalmente en el lado derecho de una asignación.

  ```cpp
  int y = x + 1; // x + 1 es un rvalue
  ```

Con la llegada de C++11, se introdujo una nueva categoría de referencias: las **referencias a rvalue** (`T&&`), que permiten **capturar estos valores temporales** y aprovecharlos para **mover recursos** en lugar de copiarlos.

La función `std::move()` es la herramienta que indica explícitamente al compilador que un objeto con nombre (un *lvalue*) puede tratarse como un *rvalue*.
Importante: `std::move()` **no mueve nada por sí misma**; simplemente habilita el uso del **constructor** o del **operador de asignación por movimiento**.

## Constructor y operador de movimiento

El movimiento se implementa mediante dos mecanismos especiales del lenguaje:

* **Constructor de movimiento:** crea un nuevo objeto transfiriendo los recursos del objeto origen.
* **Operador de asignación por movimiento:** transfiere los recursos de un objeto existente a otro que ya estaba construido.

Ambos mecanismos se definen utilizando referencias a *rvalue* (`T&&`) y suelen declararse como `noexcept`, indicando que **no lanzan excepciones**.
Esto permite a los contenedores de la STL (como `std::vector` o `std::map`) mover sus elementos de forma segura y eficiente.


## Ejemplo 1: Movimiento con `std::unique_ptr`

En este ejemplo, la clase `BufferMovil` gestiona su recurso mediante un puntero exclusivo (`std::unique_ptr`).
El **constructor de movimiento** y el **operador de asignación por movimiento** transfieren la propiedad del recurso en lugar de copiarlo.

```cpp
#include <iostream>
#include <memory>
#include <vector>

class BufferMovil {
private:
    std::unique_ptr<std::vector<int>> datos;

public:
    // Constructor por defecto
    BufferMovil() = default;

    // Constructor con datos iniciales
    BufferMovil(std::initializer_list<int> lista)
        : datos(std::make_unique<std::vector<int>>(lista)) {}

    // Constructor de movimiento
    BufferMovil(BufferMovil&& other) noexcept
        : datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento\n";
    }

    // Operador de asignación por movimiento
    BufferMovil& operator=(BufferMovil&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento\n";
        }
        return *this;
    }

    void mostrar() const {
        if (!datos || datos->empty()) {
            std::cout << "(vacío)\n";
        } else {
            for (int v : *datos) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    BufferMovil b1{1, 2, 3};
    BufferMovil b2 = std::move(b1);  // Invoca el constructor de movimiento
    BufferMovil b3;
    b3 = std::move(b2);              // Invoca el operador de asignación por movimiento

    std::cout << "b1: "; b1.mostrar();  // (vacío)
    std::cout << "b2: "; b2.mostrar();  // (vacío)
    std::cout << "b3: "; b3.mostrar();  // 1 2 3
}
```
* `std::move(b1)` convierte `b1` en un *rvalue*, habilitando el constructor de movimiento.
* El recurso (el `std::vector<int>`) se transfiere desde `b1` a `b2` sin copiar los elementos.
* Tras el movimiento, `b1` y `b2` quedan en un estado **válido pero vacío**.
* El uso de `noexcept` indica que la operación es segura y no lanzará excepciones.

## Ejemplo 2: Movimiento con `std::shared_ptr`

En este segundo ejemplo, se usa un puntero compartido (`std::shared_ptr`) para demostrar que el movimiento también puede aplicarse a recursos **compartidos entre objetos**.
El movimiento simplemente **transfiere el control del puntero compartido**, sin copiar ni incrementar el contador de referencias.

```cpp
#include <iostream>
#include <memory>
#include <vector>

class BufferCompartido {
private:
    std::shared_ptr<std::vector<int>> datos;

public:
    // Constructor con datos iniciales
    BufferCompartido(std::initializer_list<int> lista)
        : datos(std::make_shared<std::vector<int>>(lista)) {}

    // Constructor de movimiento
    BufferCompartido(BufferCompartido&& other) noexcept
        : datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento (shared)\n";
    }

    // Operador de asignación por movimiento
    BufferCompartido& operator=(BufferCompartido&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento (shared)\n";
        }
        return *this;
    }

    void mostrar() const {
        if (!datos || datos->empty()) {
            std::cout << "(vacío)\n";
        } else {
            for (int v : *datos) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    BufferCompartido a{1, 2, 3};
    BufferCompartido b = std::move(a);  // Mueve la propiedad compartida

    std::cout << "a: "; a.mostrar();  // (vacío)
    std::cout << "b: "; b.mostrar();  // 1 2 3
}
```

* El movimiento transfiere el puntero compartido sin copiar los datos ni modificar el contador de referencias.
* Tras el movimiento, el objeto origen (`a`) pierde la propiedad del recurso, pero el destino (`b`) lo conserva íntegro.

