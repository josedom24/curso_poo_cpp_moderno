# Herencia: clases base y derivadas

La **herencia** es uno de los pilares fundamentales de la programación orientada a objetos (POO). Permite definir una nueva clase a partir de otra existente, de modo que la nueva clase hereda atributos y comportamientos de la clase original, pudiendo además **agregar nuevas funcionalidades** o **modificar las existentes**.

## Ventajas de la herencia

* **Reutilización de código**: se evitan duplicaciones al compartir atributos y métodos comunes.
* **Organización jerárquica**: facilita estructurar conceptos en jerarquías claras.
* **Polimorfismo**: permite usar objetos derivados como objetos base en contextos genéricos.

## Clases base y derivadas

En herencia hablamos de dos tipos de clases:

* **Clase base** (o superclase): la clase que define atributos y métodos comunes.
* **Clase derivada** (o subclase): la clase que hereda de la base, extendiendo o especializando su comportamiento.

La herencia representa una relación de tipo **"es-un" (is-a)**:

* Un `Gato` es un `Animal`.
* Un `Círculo` es una `Figura`.
* Un `Coche` es un `Vehículo`.

La herencia más común y recomendada en C++ es la **herencia pública**, en la que:

* Los miembros `public` y `protected` de la clase base permanecen accesibles con las mismas reglas en la clase derivada.
* Los miembros `private` de la clase base **no son accesibles directamente** por la clase derivada.

El modificador **protected** se emplea para permitir que las clases derivadas accedan a ciertos atributos o métodos internos, sin exponerlos en la interfaz pública.

Veamos la sintaxis básica:

```cpp
#include <iostream>

// Clase base
class Base {
public:
    void funcionBase() {
        std::cout << "Función de la clase base" << std::endl;
    }
};

// Clase derivada
class Derivada : public Base {
public:
    void funcionDerivada() {
        std::cout << "Función específica de la clase derivada" << std::endl;
    }
};

int main() {
    Derivada obj;
    obj.funcionBase();     // Heredada de Base
    obj.funcionDerivada(); // Propia de Derivada
}
```

En este ejemplo, `Derivada` hereda de `Base`.
El objeto `obj` puede invocar tanto el método heredado `funcionBase()` como su propio método `funcionDerivada()`.

## Constructores en la herencia

Las clases derivadas deben **invocar explícitamente el constructor de la clase base** en su lista de inicialización.
Si no se indica nada, se llama automáticamente al **constructor por defecto de la base** (si existe).

Ejemplo:

```cpp
#include <iostream>
#include <string>

// Clase base
class Animal {
private:
    std::string nombre;

public:
    // Constructor de la clase base
    Animal(const std::string& n) : nombre{n} {}

    void mostrarNombre() const {
        std::cout << "Nombre: " << nombre << std::endl;
    }
};

// Clase derivada
class Perro : public Animal {
private:
    std::string raza;

public:
    // El constructor de Perro debe llamar explícitamente al de Animal
    Perro(const std::string& n, const std::string& r)
        : Animal{n}, raza{r} {}

    void mostrar() const {
        mostrarNombre();  // Método heredado
        std::cout << "Raza: " << raza << std::endl;
    }
};

int main() {
    Perro p("Toby", "Labrador");
    p.mostrar();
    return 0;
}
```

En este programa:

* La clase `Animal` inicializa su atributo `nombre` en el constructor.
* La clase `Perro` extiende `Animal` añadiendo el atributo `raza` y debe llamar al constructor de `Animal` en su lista de inicialización.
* Al ejecutar `p.mostrar()`, se imprimen tanto el nombre (definido en `Animal`) como la raza (definida en `Perro`).

## Destructores en la herencia

* Cuando se destruye un objeto derivado, **primero se ejecuta el destructor de la clase derivada y luego el de la clase base**.
* Si la clase base gestiona recursos (memoria dinámica, archivos, etc.), **su destructor debe declararse como `virtual`**.
* Esto asegura que, al destruir un objeto derivado a través de un puntero a la clase base, se invoquen correctamente ambos destructores.

