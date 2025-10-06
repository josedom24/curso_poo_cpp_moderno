# Control de creación y copia de objetos en C++

En C++ moderno, los constructores no solo sirven para inicializar objetos, sino también para **controlar cómo y cuándo se pueden crear, copiar o asignar instancias** de una clase.
Este control es fundamental al diseñar clases que deben cumplir restricciones estrictas, como:

* Impedir que se creen múltiples instancias de forma directa.
* Evitar la copia accidental de recursos no compartibles.
* Forzar la creación de objetos mediante funciones o mecanismos controlados.

Para conseguirlo, existen dos técnicas clave: **constructores privados** y la eliminación explícita de funciones especiales con `= delete`.


## Constructores privados

Un **constructor privado** es un constructor que no puede ser invocado desde fuera de la clase. Esto impide que los objetos se creen de forma libre y directa. En su lugar, se puede restringir la construcción a **funciones estáticas internas** o **funciones amigas** que controlen la creación.

Este patrón es útil, por ejemplo, cuando queremos que los objetos solo puedan crearse de manera validada o mediante una “fábrica” controlada.

Veamos un ejemplo:

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
    // Aquí podríamos generar un valor aleatorio, validar datos, etc.
    return Token("ABC123");
}

int main() {
    // Token t("XYZ"); // Error: el constructor es privado
    Token t = crearTokenSeguro();  // Creación controlada
    t.mostrar();
}
```

En este programa:

* El constructor de `Token` es privado, por lo que no se puede invocar directamente desde `main`.
* La única manera de crear un objeto es a través de la función amiga `crearTokenSeguro()`.
* Este enfoque permite añadir pasos adicionales al proceso de construcción, como validación o generación de valores únicos.


## Eliminar constructor de copia y operador de asignación con `= delete`

C++ permite **eliminar explícitamente funciones especiales** como constructores o operadores.
Esto significa que el compilador no generará versiones por defecto y, además, prohibirá su uso en el código.

Se emplea cuando:

* Los objetos poseen recursos **no copiables** (archivos, sockets, memoria exclusiva).
* Queremos evitar la copia accidental y hacer explícito que solo debe existir un propietario del recurso.
* Se sigue el principio de **propiedad única** en el diseño de clases.

Veamos un ejemplo:

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

    return 0;
}
```

En este programa:

* La clase `Archivo` permite crear objetos, pero **prohíbe expresamente la copia y asignación**.
* Esto asegura que cada objeto represente un recurso único (un archivo abierto en este caso).
* Si se intenta copiar o asignar, el compilador genera un error.

