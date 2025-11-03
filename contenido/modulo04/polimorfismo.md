# Herencia y polimorfismo dinámico

El término *polimorfismo* significa “muchas formas”. En programación orientada a objetos, se refiere a la capacidad de un mismo nombre (por ejemplo, una función o método) de **adoptar comportamientos diferentes** según el contexto o el tipo de datos con el que se utiliza.

Este concepto permite diseñar código más flexible y extensible, ya que las operaciones pueden definirse de forma genérica y adaptarse a distintos tipos sin necesidad de modificar la base.

## Tipos de polimorfismo en C++

**Polimorfismo estático (tiempo de compilación):**

* Se resuelve durante la compilación.
* Incluye:

  * Sobrecarga de funciones y métodos.
  * Plantillas (*templates*).

**Polimorfismo dinámico (tiempo de ejecución):**

* Se resuelve durante la ejecución del programa.
* Se logra mediante **métodos virtuales** en clases base.
* Permite que un **puntero o referencia a una clase base** invoque métodos de distintas clases derivadas, ejecutando el comportamiento adecuado según el tipo real del objeto.

## Métodos virtuales

Los **métodos virtuales** permiten que una clase derivada redefina el comportamiento de un método heredado.
Se declaran con la palabra clave `virtual` en la clase base.

Cuando un método es virtual:

* Una llamada a ese método a través de un puntero o referencia a la clase base ejecuta la versión del tipo real del objeto.
* El compilador construye una tabla de métodos virtuales (*vtable*) para resolver dinámicamente qué función llamar.

Ejemplo básico:

```cpp
#include <iostream>

class Base {
public:
    virtual void funcion() {
        std::cout << "Función base\n";
    }
    virtual ~Base() = default; // Destructor virtual
};

class Derivada : public Base {
public:
    void funcion() override {
        std::cout << "Función derivada\n";
    }
};

int main() {
    Base* b = new Derivada();
    b->funcion();  // Llama a la versión de Derivada
    delete b;
}
```

## La palabra clave `override`

Se utiliza en clases derivadas para indicar explícitamente que un método está sobrescribiendo un método virtual de la base.

Ventajas:

* El compilador detecta errores si la firma no coincide.
* Mejora la legibilidad.

Veamos un ejemplo:

```cpp
#include <iostream>
#include <string>

class Animal {
public:
    virtual void hablar() const {
        std::cout << "El animal emite un sonido." << std::endl;
    }

    virtual ~Animal() = default; // Destructor virtual recomendado
};

class Perro : public Animal {
public:
    void hablar() const override {
        std::cout << "El perro ladra." << std::endl;
    }
};

class Gato : public Animal {
public:
    void hablar() const override {
        std::cout << "El gato maúlla." << std::endl;
    }
};

void hacerHablar(const Animal& a) {
    a.hablar();
}

int main() {
    Perro p{};
    Gato g{};

    hacerHablar(p);  // "El perro ladra."
    hacerHablar(g);  // "El gato maúlla."

    // En lugar de usar un puntero:
    Perro otroPerro{};
    Animal& ref = otroPerro;  // referencia al objeto base
    ref.hablar();             // "El perro ladra."

    return 0;
}

```

En este ejemplo, gracias al polimorfismo dinámico:

* Una referencia o puntero a `Animal` puede comportarse como `Perro` o `Gato`.
* El método llamado depende del tipo **real** del objeto, no del tipo declarado del puntero.

## La palabra clave `final`

SClaro 👍. Aquí tienes una introducción más completa y estructurada, explicando claramente los **dos usos** de la palabra clave `final` en C++:

---

### 🔹 La palabra clave `final`

La palabra clave `final` se utiliza en C++ para **restringir la herencia o la sobrescritura** de métodos virtuales. Puede aplicarse tanto a **métodos** como a **clases**:

* **`final` en un método virtual:** impide que una clase derivada sobrescriba ese método.
* **`final` en una clase:** impide que la clase sea heredada.

Veamos un ejemplo:

```cpp
#include <iostream>
#include <string>

// Clase base general
class Animal {
public:
    virtual void hacerSonido() const {
        std::cout << "Sonido genérico de animal\n";
    }

    // Destructor virtual recomendado en jerarquías
    virtual ~Animal() = default;
};

// Clase Perro que hereda de Animal
class Perro : public Animal {
public:
    // Redefinimos el método virtual y lo marcamos como final
    // Esto significa que ninguna clase derivada de Perro podrá sobrescribirlo
    void hacerSonido() const final override {
        std::cout << "Guau guau\n";
    }
};

// Clase derivada de Perro (para demostrar el error si intentamos sobrescribir)
/*
class PerroEspecial : public Perro {
public:
    void hacerSonido() const override { // Error: método final en Perro
        std::cout << "Guau especial\n";
    }
};
*/

// Clase Gato declarada como final: no puede tener clases derivadas
class Gato final : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Miau miau\n";
    }
};

// Si intentamos heredar de Gato, el compilador también dará error
/*
class GatoSiames : public Gato { // Error: Gato es final
};
*/

int main() {
    Perro p;
    Gato g;

    // Uso de referencias en lugar de punteros
    Animal& a1 = p;
    Animal& a2 = g;

    a1.hacerSonido();  // Llama a Perro::hacerSonido -> "Guau guau"
    a2.hacerSonido();  // Llama a Gato::hacerSonido  -> "Miau miau"

    return 0;
}

```

* En `Perro`, el método `hacerSonido()` está marcado como **`final`**, por lo que **ninguna subclase** puede volver a redefinirlo.
* En `Gato`, la clase entera está marcada como **`final`**, de manera que **no puede servir como base** para ninguna otra clase.
* Si descomentas los ejemplos marcados, el compilador producirá un error, asegurando que el diseño de la jerarquía se respete.


## Buenas prácticas

* Usar **`override` siempre** al redefinir métodos virtuales.
* Declarar **destructores virtuales** en clases base pensadas para herencia.
* Usar **`final`** cuando se quiera cerrar explícitamente una jerarquía.
* Aplicar el polimorfismo dinámico solo cuando sea necesario: si el comportamiento es conocido en tiempo de compilación, preferir plantillas o sobrecarga (polimorfismo estático).
