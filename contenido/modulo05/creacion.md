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

En C++ moderno, las operaciones especiales de una clase —como los constructores de copia y movimiento, y sus operadores de asignación— pueden **controlarse explícitamente**.
El especificador `= delete` permite **prohibir** ciertas operaciones, evitando que el compilador las genere de forma implícita.
Esto es esencial cuando un objeto gestiona recursos que no deben copiarse ni transferirse arbitrariamente.


### Ejemplo 1: Prohibir la copia

En este ejemplo, la clase `Archivo` representa un recurso exclusivo (un archivo abierto).
Prohibir la copia impide que dos objetos intenten gestionar el mismo recurso.

```cpp
#include <iostream>
#include <string>

class Archivo {
public:
    explicit Archivo(const std::string& nombre) {
        std::cout << "Abriendo archivo: " << nombre << '\n';
    }

    ~Archivo() {
        std::cout << "Cerrando archivo\n";
    }

    // Prohibimos la copia
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;
};

int main() {
    Archivo a("datos.txt");
    // Archivo b = a;        // Error: constructor de copia eliminado
    // b = a;                // Error: asignación por copia eliminada
}
```

Cada objeto `Archivo` gestiona un **recurso único**.
Al eliminar las operaciones de copia, se garantiza que solo exista un objeto responsable de cerrarlo, evitando duplicaciones o pérdidas del recurso.


### Ejemplo 2: Prohibir el movimiento

En otras ocasiones, mover un objeto tampoco tiene sentido.
Por ejemplo, si el objeto representa un **recurso externo** del sistema operativo (como un identificador, un socket o un archivo abierto), moverlo podría dejar el recurso en un estado incoherente.

En este caso, se eliminan también las operaciones de movimiento:

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

Ni la copia ni el movimiento están permitidos.
Cada objeto `Recurso` es el único responsable de su recurso, y el compilador impide cualquier intento de duplicarlo o transferirlo.

## Habilitar operaciones con `= default`

El especificador `= default` indica al compilador que **genere automáticamente** la implementación estándar de una operación.
Esto es útil cuando queremos permitir ciertas operaciones sin definirlas manualmente, garantizando además su corrección semántica.

Por ejemplo, una clase que se puede mover pero no copiar:

```cpp
#include <iostream>
#include <utility>

class Registro {
public:
    Registro() = default;                    // Constructor por defecto
    ~Registro() = default;                   // Destructor por defecto

    Registro(const Registro&) = delete;      // No copiable
    Registro& operator=(const Registro&) = delete;

    Registro(Registro&&) noexcept = default; // Movible
    Registro& operator=(Registro&&) noexcept = default;
};

int main() {
    Registro r1;
    Registro r2 = std::move(r1);  // Movimiento permitido
    std::cout << "Fin del programa\n";
}
```

En este diseño:

* `= delete` **bloquea la copia**, evitando duplicar el objeto.
* `= default` **habilita el movimiento**, dejando que el compilador genere la versión óptima y segura.
* La palabra clave `noexcept` garantiza que el movimiento no lanzará excepciones, permitiendo su uso eficiente en contenedores de la STL.


