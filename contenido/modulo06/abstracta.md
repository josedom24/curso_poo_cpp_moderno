# Clases abstractas y métodos virtuales puros

## Introducción al diseño orientado a interfaces

En apartados anteriores se estudió el **polimorfismo dinámico**, que permite que un mismo método se comporte de manera diferente según el tipo real del objeto.
En esta sección profundizaremos en el **diseño polimórfico orientado a interfaces**, un enfoque que aprovecha el polimorfismo para desacoplar la definición de un comportamiento (*qué se hace*) de su implementación concreta (*cómo se hace*).

El objetivo es aprender a **definir contratos abstractos** que las clases concretas deben cumplir, garantizando coherencia y extensibilidad del sistema sin comprometer la seguridad o la claridad del código.


## Clases abstractas

En la programación orientada a objetos, una **clase abstracta** define una interfaz común que describe un conjunto de operaciones que las clases derivadas deben implementar.
Se utiliza para **representar conceptos generales** que no tienen sentido por sí solos, sino únicamente a través de sus especializaciones.

Las clases abstractas se basan en el uso de **métodos virtuales puros**, que actúan como **contratos** que las subclases concretas deben cumplir.
Este mecanismo es la base del **diseño polimórfico**, permitiendo escribir código que trabaje con distintos tipos de objetos de manera uniforme, sin conocer su tipo concreto.

Una **clase abstracta** en C++ se caracteriza por contener al menos una **función miembro virtual pura**, declarada con el sufijo `= 0`.
La presencia de este tipo de función convierte automáticamente a la clase en **no instanciable**.

Veamos un  ejemplo, donde se define una jerarquía de clases que representan figuras geométricas. Cada figura puede dibujarse, pero la forma concreta de hacerlo depende del tipo de figura.

```cpp
#include <iostream>
#include <memory>
#include <vector>

// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0;  // Método virtual puro
    virtual ~Figura() = default;       // Destructor virtual
};

// Clases derivadas concretas
class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

class Rectangulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un rectángulo\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Figura>> figuras;

    figuras.push_back(std::make_unique<Circulo>());
    figuras.push_back(std::make_unique<Rectangulo>());

    for (const auto& figura : figuras)
        figura->dibujar();  // Llamada polimórfica
}
```

* La clase `Figura` no proporciona una implementación concreta de `dibujar()`. Declara el método `dibujar()` como virtual puro (`= 0`), convirtiéndose en una clase abstracta. No puede instanciarse directamente y sirve como **interfaz común** para todas las figuras.
* Cualquier clase derivada que herede de `Figura` estará **obligada** a implementar dicho método para ser instanciable. Las clases `Circulo` y `Rectangulo` redefinen el método `dibujar()` utilizando la palabra clave `override`, que garantiza que coincida exactamente con la función virtual de la base.
* Si una clase derivada no implementa todos los métodos virtuales puros heredados, también será abstracta.
* El destructor de una clase base polimórfica debe ser **virtual**, para garantizar la destrucción correcta de objetos derivados.
* Se emplea `std::unique_ptr<Figura>` para gestionar los objetos polimórficos. Esto asegura la liberación automática de memoria mediante RAII, evitando fugas.
* Un `std::vector` de punteros a `Figura` puede contener objetos de distintos tipos (`Circulo`, `Rectangulo`). En el bucle, la llamada `figura->dibujar()` se resuelve dinámicamente según el tipo real del objeto.
* Es esencial para que, al destruir un `unique_ptr<Figura>`, se llame correctamente al destructor de `Circulo` o `Rectangulo`.

## UML

![uml](img/diagrama1.png
)

