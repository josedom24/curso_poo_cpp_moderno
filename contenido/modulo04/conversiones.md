# Conversiones implícitas y punteros base

Cuando trabajamos con herencia en C++, es común utilizar **punteros o referencias a la clase base** para manipular objetos derivados. Esto es posible porque C++ permite una **conversión implícita** de un puntero o referencia de una clase derivada hacia un puntero o referencia de su clase base.

Este mecanismo es fundamental para el **polimorfismo dinámico**, ya que permite tratar de forma uniforme a distintos objetos derivados mediante un único tipo común: la clase base. 

* Al hacer **conversiones implícitas**: el puntero o la referencia resultante solo puede acceder a los **miembros declarados en la clase base**, incluso si el objeto real pertenece a una clase derivada. 
* Si queremos acceder a los **miembros propios de la clase derivada**, tendremos que hacer una **conversión implícita** con `dynamic_cast`.

## Conversiones implícitas en herencia

Si tenemos un objeto de una clase derivada, podemos convertir su dirección a un puntero o referencia de la clase base sin necesidad de casting:

```cpp
#include <iostream>
#include <memory>

class Base {};
class Derivada : public Base {};

int main() {
    // --- Conversión implícita con punteros inteligentes ---
    // std::unique_ptr<Derivada> puede convertirse automáticamente
    // en std::unique_ptr<Base> porque existe una relación de herencia pública.
    std::unique_ptr<Derivada> ptrDerivada = std::make_unique<Derivada>();
    std::unique_ptr<Base> ptrBase = std::move(ptrDerivada); // Conversión implícita

    // --- Conversión implícita con referencias ---
    // Una referencia a un objeto Derivada puede asignarse a una referencia Base
    // sin necesidad de casting explícito.
    Derivada objDerivada;
    Base& refBase = objDerivada; // Conversión implícita

    std::cout << "Conversiones implícitas realizadas correctamente.\n";
    return 0;
}
```

* **Conversión con punteros inteligentes:**
  `std::unique_ptr<Derivada>` se convierte implícitamente en `std::unique_ptr<Base>` porque `Derivada` hereda públicamente de `Base`. No se necesita `dynamic_cast`.
* **Conversión con referencias:**
  Una referencia a `Derivada` puede vincularse directamente a una referencia a `Base` porque C++ aplica la conversión implícita correspondiente.
* Esta conversión es **segura** porque una clase derivada **es un** tipo de la clase base. La parte de la clase base está siempre presente en el objeto derivado.

## Uso típico con polimorfismo

Gracias a estas conversiones, podemos almacenar punteros a distintos objetos derivados en un mismo contenedor de punteros a la clase base y luego invocar métodos virtuales:

```cpp
#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual ~Animal() = default; // Destructor virtual
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Guau\n";
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Miau\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animales;

    animales.push_back(std::make_unique<Perro>());
    animales.push_back(std::make_unique<Gato>());

    for (const auto& animal : animales) {
        animal->hacerSonido(); // Se resuelve dinámicamente
    }

    return 0;
}
```

Aquí se observa que, aunque trabajamos con `std::unique_ptr<Animal>`, cada llamada a `hacerSonido()` invoca la implementación adecuada según el tipo real del objeto (`Perro` o `Gato`).

## Conversiones implícitas y punteros inteligentes

Las conversiones de derivada a base también funcionan con punteros inteligentes (`std::unique_ptr`, `std::shared_ptr`), siempre que la herencia sea pública:

```cpp
#include <iostream>
#include <memory>

class Animal {
public:
    virtual void sonido() const { std::cout << "Sonido genérico\n"; }
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void sonido() const override { std::cout << "Guau\n"; }
};

int main() {
    std::unique_ptr<Perro> pPerro = std::make_unique<Perro>();

    // Conversión implícita de unique_ptr<Perro> a unique_ptr<Animal>
    std::unique_ptr<Animal> pAnimal = std::move(pPerro);

    pAnimal->sonido(); // "Guau"
    return 0;
}
```

## Limitaciones y precauciones

* La conversión **solo funciona de derivada a base**.
* La conversión inversa (de base a derivada) **no es implícita**: se debe usar casting explícito (`dynamic_cast` con herencia polimórfica).
* Si la clase base **no declara destructores virtuales**, destruir objetos derivados a través de punteros base puede causar fugas de memoria o comportamiento indefinido.
* Si no hay métodos virtuales, el puntero base no se comportará polimórficamente, sino que llamará siempre a la versión de la clase base.

