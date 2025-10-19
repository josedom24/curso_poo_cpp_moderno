# El problema de devolver tipos concretos y objetos polimórficos

Hasta ahora hemos visto cómo las **interfaces puras** permiten definir contratos de comportamiento y cómo las clases derivadas pueden implementarlas para ofrecer distintas versiones de una misma operación.
Sin embargo, cuando una función o un componente necesita **crear y devolver un objeto** de una jerarquía de clases, aparece una dificultad importante: **¿cómo devolverlo sin exponer el tipo concreto ni comprometer la seguridad o la extensibilidad del código?**

Este apartado analiza los problemas derivados de **devolver tipos concretos o polimórficos de manera incorrecta**, y servirá de base para comprender, en el siguiente apartado, cómo **los punteros inteligentes** permiten resolverlos de forma segura.

## Devolver tipos concretos: un enfoque limitado

Cuando una función devuelve un tipo concreto (por ejemplo, `Circulo` o `Rectangulo`), el código cliente queda **directamente acoplado** a esas clases.
Esto significa que cualquier cambio o ampliación en la jerarquía obliga a modificar el código que las usa.

### Ejemplo: enfoque limitado

```cpp
#include <iostream>
#include <memory>

class Circulo {
public:
    void dibujar() const {
        std::cout << "Dibujando un círculo\n";
    }
};

class Rectangulo {
public:
    void dibujar() const {
        std::cout << "Dibujando un rectángulo\n";
    }
};

// Funciones que devuelven tipos concretos
std::unique_ptr<Circulo> crearCirculo() {
    return std::make_unique<Circulo>();
}

std::unique_ptr<Rectangulo> crearRectangulo() {
    return std::make_unique<Rectangulo>();
}

int main() {
    auto c = crearCirculo();
    auto r = crearRectangulo();

    c->dibujar();
    r->dibujar();
}
```

* Cada función devuelve un tipo distinto (`Circulo`, `Rectangulo`), de modo que el cliente **debe conocer todas las clases concretas**.
* No existe una interfaz común que unifique su tratamiento.
* No es posible almacenar distintas figuras en un mismo contenedor ni procesarlas mediante una función genérica.
* Cualquier nueva figura (`Triangulo`, `Poligono`, etc.) obliga a **modificar el código cliente**.

Este enfoque es válido en programas muy pequeños, pero **no escala** cuando el sistema crece o cuando se busca extensibilidad y bajo acoplamiento.

## La necesidad de devolver interfaces

Para evitar este acoplamiento excesivo, en C++ moderno se sigue el principio **“programar contra interfaces, no contra implementaciones”**. Esto significa que el código cliente debe depender **de un contrato abstracto**, no de una clase concreta.

En lugar de devolver un objeto de tipo `Circulo` o `Rectangulo`, la función debería devolver **un puntero o referencia a la interfaz común**, por ejemplo `Figura`. De ese modo, el cliente solo necesita conocer qué operaciones ofrece la interfaz (`dibujar()`, `mover()`, etc.), no cómo se implementan.

Ventajas de devolver interfaces:

* **Desacoplamiento:** el cliente no necesita incluir los encabezados de las clases concretas.
* **Extensibilidad:** se pueden añadir nuevas figuras sin modificar el código que las utiliza.
* **Reutilización:** distintas partes del programa pueden operar sobre la misma interfaz sin conocer los tipos concretos.
* **Polimorfismo dinámico:** el comportamiento concreto se determina en tiempo de ejecución según el tipo real del objeto.

Devolver interfaces es, por tanto, **la solución conceptual** al problema de acoplamiento; sin embargo, su implementación en C++ presenta **ciertos desafíos técnicos**, que veremos a continuación.

### Devolver por valor: *object slicing*

Cuando se devuelve un objeto por valor, solo se copia la parte de la clase base, perdiendo la información del tipo derivado. Este fenómeno se conoce como **object slicing**.

```cpp
Aquí tienes un **ejemplo completo y funcional** que demuestra claramente el fenómeno del **object slicing** (recorte de objeto) y cómo evitarlo en C++ moderno:

---

### 🔹 Ejemplo: *Devolver por valor y object slicing*

```cpp
#include <iostream>
#include <memory>

// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0;     // Método virtual puro
    virtual ~Figura() = default;          // Destructor virtual
};

// Clase derivada
class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un Círculo\n";
    }
};

// Función que devuelve un objeto por valor (provoca object slicing)
Figura crearFiguraPorValor() {
    Circulo c;
    return c;  // Se produce "object slicing"
}

// Solución moderna: devolver por puntero inteligente
std::unique_ptr<Figura> crearFiguraPorPuntero() {
    return std::make_unique<Circulo>();
}

int main() {
    std::cout << "== Ejemplo con devolución por valor ==\n";
    Figura f = crearFiguraPorValor();
    f.dibujar();  // Error conceptual: no se llama a Circulo::dibujar()
                  // Se comporta como una Figura “recortada”

    std::cout << "\n== Ejemplo con devolución mediante puntero ==\n";
    auto figuraPtr = crearFiguraPorPuntero();
    figuraPtr->dibujar();  //  Llama correctamente a Circulo::dibujar()

    return 0;
}
```

* En la función `crearFiguraPorValor()`, el objeto `Circulo` se **devuelve por valor** como tipo `Figura`.
  * Solo se copia la **parte base (`Figura`)** del objeto,
  * La parte específica de `Circulo` se **pierde** → esto es el *object slicing*.
  * El polimorfismo dinámico **no funciona**, ya que la copia no conserva el tipo real.
* En la función `crearFiguraPorPuntero()`, se devuelve un **puntero inteligente a la clase base (`std::unique_ptr<Figura>`)**.
  * El polimorfismo se mantiene,
  * No hay pérdida de información del tipo dinámico (`Circulo`),
  * Se garantiza una **gestión automática y segura de memoria** gracias a RAII.

### Devolver por referencia: referencia colgante

Si se devuelve una **referencia a un objeto local**, esa referencia apuntará a un objeto destruido cuando la función termine. Esto provoca **comportamiento indefinido**, ya que se intenta acceder a memoria que ya no pertenece al programa.

```cpp
#include <iostream>

class Figura {
public:
    virtual void dibujar() const = 0;
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

// Función incorrecta: devuelve referencia a un objeto local
Figura& crearFigura() {
    Circulo c;  // Objeto local (vida limitada al ámbito de la función)
    return c;   // Se devuelve una referencia a un objeto que será destruido
}

int main() {
    Figura& f = crearFigura();  // La referencia queda colgante
    f.dibujar();                // Comportamiento indefinido
}
```


* El objeto `c` se crea dentro de la función `crearFigura()`.
* Al salir de la función, `c` se destruye automáticamente.
* La referencia devuelta (`f`) apunta a una zona de memoria que ya no contiene un objeto válido.
* Llamar a `f.dibujar()` produce **comportamiento indefinido**: puede parecer funcionar en algunos entornos, pero el resultado es impredecible.

Nunca se debe devolver una referencia (ni un puntero) a un objeto local, ya que su **tiempo de vida termina al salir de la función**.
En el siguiente apartado se mostrará cómo los **punteros inteligentes** permiten devolver objetos creados dinámicamente de forma segura y sin fugas de memoria.

### Devolver un puntero crudo: inseguridad de memoria

Devolver un puntero dinámico (`T*`) preserva el polimorfismo, pero deja en manos del cliente la responsabilidad de liberar la memoria. Esto rompe el principio **RAII** (*Resource Acquisition Is Initialization*) y hace el código propenso a errores.

```cpp
#include <iostream>

class Figura {
public:
    virtual void dibujar() const = 0;
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

// Función que devuelve un puntero crudo
Figura* crearFigura() {
    return new Circulo();  // El cliente es responsable de liberar la memoria
}

int main() {
    Figura* f1 = crearFigura();   // Se crea dinámicamente un Circulo
    f1->dibujar();                // Llamada polimórfica correcta

    //  Si el cliente olvida liberar la memoria:
    // delete f1;  // ← Debería hacerse, pero si se omite hay fuga de memoria

    //  Si se hace delete dos veces por error:
    delete f1;
    // delete f1;  // ← Doble liberación: comportamiento indefinido
}
```
* La función `crearFigura()` crea un objeto en el **montículo (heap)** con `new` y devuelve un puntero a la clase base `Figura`.
* El polimorfismo funciona correctamente: `f1->dibujar()` llama a `Circulo::dibujar()`.
* Sin embargo, el objeto **no se destruye automáticamente** al salir del ámbito.
   * Si el cliente **olvida llamar a `delete`**, se produce una **fuga de memoria**.
   * Si el cliente **libera la memoria dos veces**, el programa entra en **comportamiento indefinido**.
* Estos errores son difíciles de detectar y muy costosos en aplicaciones grandes.

Aunque devolver punteros crudos permite el polimorfismo, **traslada la responsabilidad de gestión de memoria al cliente**, lo que es peligroso e ineficiente.
En el siguiente apartado veremos cómo los **punteros inteligentes** (`std::unique_ptr` y `std::shared_ptr`) permiten devolver interfaces polimórficas **de forma segura y automática**, evitando fugas y dobles liberaciones.

Estas limitaciones muestran que, aunque el polimorfismo dinámico es una herramienta poderosa, **su uso directo en la devolución de objetos no es seguro sin una gestión adecuada de recursos**. En el siguiente apartado veremos cómo el C++ moderno soluciona estos problemas mediante **punteros inteligentes** (`std::unique_ptr` y `std::shared_ptr`), que permiten **devolver interfaces polimórficas** de forma **segura, eficiente y desacoplada**.
