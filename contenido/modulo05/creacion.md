# Control de creación, copia y movimiento de objetos

En C++ moderno, los constructores no solo sirven para inicializar objetos, sino también para **controlar cómo y cuándo se pueden crear, copiar o mover instancias** de una clase.
Este control resulta esencial cuando una clase gestiona **recursos exclusivos** (como archivos, memoria o conexiones) o cuando su diseño requiere **restricciones explícitas** sobre la creación de instancias.

Los objetivos habituales de este control son:

* Impedir la creación directa de objetos fuera de un mecanismo controlado.
* Evitar la copia accidental de recursos no compartibles.
* Permitir el movimiento cuando la transferencia de recursos sea segura.
* Expresar con claridad qué operaciones están disponibles para cada tipo.

Para ello, C++ moderno ofrece tres herramientas principales:

1. **Constructores privados**, que limitan quién puede crear objetos.
2. **Eliminación explícita de operaciones** mediante `= delete`.
3. **Definición o habilitación explícita** de operaciones mediante `= default`.

## Constructores privados

Un **constructor privado** impide que los objetos se creen libremente desde fuera de la clase.
Esto obliga a usar funciones o métodos específicos que controlen la creación.

```cpp
#include <iostream>
#include <string>

class Token {
private:
    std::string valor;

    // Constructor privado
    Token(const std::string& v) : valor(v) {}

public:
    void mostrar() const { std::cout << "Token: " << valor << '\n'; }

    // Función estática controlada
    static Token crearSeguro(const std::string& texto) {
        // Aquí podrían hacerse validaciones o transformaciones
        return Token(texto);
    }
};

int main() {
    // Token t("XYZ"); // Error: constructor privado
    Token t = Token::crearSeguro("ABC123"); // Creación controlada
    t.mostrar();
}
```

* El constructor no puede usarse directamente, pero una función estática interna (`crearSeguro`) puede construir y devolver un objeto válido.
* Esta técnica se emplea cuando se desea **validar** o **controlar el proceso de creación**.

## Evitar copia o movimiento con `= delete`

El especificador `= delete` permite **prohibir explícitamente** ciertas operaciones especiales, como el constructor o el operador de copia o movimiento.
El compilador emitirá un error si se intenta usarlas.

```cpp
#include <iostream>
#include <string>

class Archivo {
public:
    Archivo(const std::string& nombre) {
        std::cout << "Abriendo archivo: " << nombre << '\n';
    }

    // Impedimos la copia y asignación
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;
};

int main() {
    Archivo a("datos.txt");
    // Archivo b = a;   // Error: copia prohibida
}
```

* Cada objeto `Archivo` representa un recurso único.
* Prohibir la copia evita que dos objetos intenten gestionar el mismo recurso.

## Controlar también el movimiento

El movimiento de objetos puede **permitirse o prohibirse explícitamente**, igual que la copia.
Esto resulta útil para **proteger recursos exclusivos** o para **permitir su transferencia eficiente** cuando sea seguro hacerlo.

### Prohibir el movimiento

Hay clases en las que **mover un objeto no tiene sentido**.
Por ejemplo, si el objeto representa un recurso externo (como un identificador del sistema operativo, un socket o un archivo abierto), moverlo podría dejar el recurso en un estado incoherente.

En estos casos, se eliminan las operaciones de movimiento con `= delete`:

```cpp
#include <iostream>

class Recurso {
public:
    Recurso() { std::cout << "Recurso adquirido\n"; }
    ~Recurso() { std::cout << "Recurso liberado\n"; }

    // Prohibimos copia y movimiento
    Recurso(const Recurso&) = delete;
    Recurso& operator=(const Recurso&) = delete;
    Recurso(Recurso&&) = delete;
    Recurso& operator=(Recurso&&) = delete;
};

int main() {
    Recurso r1;
    // Recurso r2 = std::move(r1); // Error: movimiento prohibido
}
```

* Ni la copia ni el movimiento están permitidos.
* Cada objeto controla de forma **exclusiva** su recurso.
* El compilador impedirá cualquier intento de transferir la propiedad.

Este diseño garantiza que el recurso se gestione **únicamente desde su objeto original**, evitando pérdidas o duplicaciones.

### Permitir el movimiento

Cuando el movimiento **es seguro y útil**, puede habilitarse de forma explícita.
Esto indica al compilador que la clase **puede transferir sus recursos sin riesgo**.


```cpp
#include <iostream>
#include <utility> // std::move

class Registro {
public:
    Registro() { std::cout << "Registro creado\n"; }
    ~Registro() { std::cout << "Registro destruido\n"; }

    Registro(const Registro&) = delete;            // No copiable
    Registro& operator=(const Registro&) = delete;

    Registro(Registro&&) noexcept = default;       // Movible
    Registro& operator=(Registro&&) noexcept = default;
};

int main() {
    Registro r1;                 // Creación normal
    Registro r2 = std::move(r1); // Movimiento permitido

    // Registro r3 = r2;          // Error: copia prohibida
    // r3 = r1;                   // Error: asignación por copia prohibida

    std::cout << "Fin del programa\n";
}
```

* `r1` se crea normalmente con el constructor por defecto.
* `r2` se construye **moviendo** desde `r1` mediante `std::move()`.
* Las líneas comentadas muestran que **no es posible copiar** objetos de esta clase.
* El compilador genera automáticamente las funciones de movimiento (`= default`), y al marcarlas como `noexcept`, se garantiza que son seguras y eficientes.
