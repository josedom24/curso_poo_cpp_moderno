# Control de creación, copia y movimiento de objetos

En C++ moderno, los constructores no solo sirven para inicializar objetos, sino también para **controlar cómo y cuándo se pueden crear, copiar o mover instancias** de una clase.
Este control es fundamental al diseñar clases que deben cumplir restricciones estrictas, como:

* Impedir que se creen múltiples instancias de forma directa.
* Evitar la copia accidental de recursos no compartibles.
* Restringir o permitir el movimiento cuando la transferencia de recursos sea segura.
* Forzar la creación de objetos mediante funciones o mecanismos controlados.

Para conseguirlo, C++ ofrece varias herramientas: **constructores privados**, **eliminación explícita de funciones especiales** con `= delete`, y **definición explícita del comportamiento de movimiento**.

## Constructores privados

Un **constructor privado** es un constructor que no puede ser invocado desde fuera de la clase.
Esto impide que los objetos se creen de forma libre y directa. En su lugar, se puede restringir la construcción a **funciones estáticas internas** o **funciones amigas** que controlen el proceso.

Este patrón es útil cuando los objetos solo deben crearse de forma validada, o mediante una función que garantice reglas específicas.

```cpp
#include <iostream>
#include <string>

// Clase Token que restringe su creación
class Token {
private:
    std::string valor;

    // Constructor privado: no accesible desde fuera
    Token(const std::string& v) : valor(v) {}

public:
    void mostrar() const {
        std::cout << "Token: " << valor << '\n';
    }

    // Función amiga que puede construir objetos Token
    friend Token crearTokenSeguro();
};

// Función amiga que tiene acceso al constructor privado
Token crearTokenSeguro() {
    // Aquí podríamos generar un valor aleatorio o validar datos
    return Token("ABC123");
}

int main() {
    // Token t("XYZ"); // Error: el constructor es privado
    Token t = crearTokenSeguro();  // Creación controlada
    t.mostrar();
}
```

* El constructor de `Token` es privado, por lo que no se puede invocar directamente desde `main`.
* Solo la función `crearTokenSeguro()` puede crear instancias.
* Este enfoque permite añadir validaciones o procesos previos a la creación.


## Eliminar copia y asignación con `= delete`

C++ permite **eliminar explícitamente** funciones especiales, como constructores o operadores.
Esto impide su uso y evita que el compilador genere versiones por defecto.

Esta técnica se usa cuando:

* Los objetos poseen recursos **no copiables** (archivos, sockets, memoria exclusiva).
* Queremos **evitar copias accidentales** y asegurar propiedad única del recurso.
* El diseño debe dejar claro que solo un objeto puede poseer un recurso concreto.

```cpp
#include <iostream>
#include <string>

// Clase Archivo que no permite ser copiada ni asignada
class Archivo {
public:
    // Constructor que simula abrir un archivo
    Archivo(const std::string& nombre) {
        std::cout << "Abriendo archivo: " << nombre << '\n';
    }

    // Se eliminan las operaciones de copia y asignación
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;
};

int main() {
    Archivo a("datos.txt");

    // Archivo b = a;   // Error: constructor de copia eliminado
    // Archivo c;
    // c = a;           // Error: operador de asignación eliminado
}
```

En este programa:

* La clase `Archivo` puede crearse, pero no copiarse ni asignarse.
* Cada objeto representa un recurso único (un archivo abierto).
* Si se intenta copiar o asignar, el compilador emite un error.


## Controlar también el movimiento

El mismo mecanismo `= delete` puede aplicarse a las **operaciones de movimiento**, cuando la transferencia de recursos no tiene sentido o podría comprometer la integridad del objeto.

Por ejemplo, una clase que gestiona un recurso externo (como un identificador del sistema operativo) puede querer **prohibir el movimiento**, asegurando que el recurso permanece asociado a su objeto original.

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
    // Recurso r2 = r1;           // Error: copia prohibida
    // Recurso r3 = std::move(r1); // Error: movimiento prohibido
}
```

* Ni la copia ni el movimiento están permitidos.
* Cada objeto controla de forma exclusiva su propio recurso.
* Al finalizar el programa, el recurso se libera automáticamente en el destructor.


## Definir explícitamente qué operaciones se permiten

El control no siempre implica prohibir: también puede hacerse **explícito** qué operaciones se permiten, usando `= default`.

```cpp
class Registro {
public:
    Registro() = default;
    Registro(const Registro&) = delete;            // No copiable
    Registro& operator=(const Registro&) = delete;
    Registro(Registro&&) noexcept = default;       // Movible
    Registro& operator=(Registro&&) noexcept = default;
};
```

Esta combinación indica claramente que:

* `Registro` no se puede copiar, pero sí **mover**.
* El movimiento se considera seguro (`noexcept`).
* El compilador genera automáticamente las operaciones de movimiento.


## Ejemplo resumen: control completo

```cpp
#include <iostream>
#include <utility>

class RecursoControlado {
public:
    RecursoControlado() { std::cout << "Creado\n"; }
    ~RecursoControlado() { std::cout << "Destruido\n"; }

    // No copiable
    RecursoControlado(const RecursoControlado&) = delete;
    RecursoControlado& operator=(const RecursoControlado&) = delete;

    // Movible
    RecursoControlado(RecursoControlado&&) noexcept {
        std::cout << "Movido (constructor)\n";
    }

    RecursoControlado& operator=(RecursoControlado&&) noexcept {
        std::cout << "Movido (asignación)\n";
        return *this;
    }
};

int main() {
    RecursoControlado a;
    RecursoControlado b = std::move(a); // movimiento permitido
    // RecursoControlado c = b;         // Error: copia prohibida
}
```

Este ejemplo resume el control completo:

* Se prohíbe la copia para evitar duplicación de recursos.
* Se permite el movimiento para transferir propiedad de forma eficiente.
* La salida del programa muestra exactamente qué operaciones se ejecutan.

