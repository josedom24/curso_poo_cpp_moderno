# Herencia y polimorfismo

El término *polimorfismo* significa “muchas formas”. En POO, permite que un puntero o referencia a una clase base pueda referirse a objetos de clases derivadas diferentes y ejecutar el método apropiado para cada tipo.

Esto facilita la programación genérica y la extensión del código sin modificar la base.

## Tipos de polimorfismo en C++

1. **Polimorfismo estático (en tiempo de compilación):**
   * Sobrecarga de funciones.
   * Plantillas (templates).
2. **Polimorfismo dinámico (en tiempo de ejecución):**
   * Uso de funciones virtuales en clases base.
   * Permite que una llamada a función se resuelva en tiempo de ejecución según el tipo real del objeto.

## Polimorfismo dinámico con funciones virtuales

Las **funciones virtuales** permiten el **polimorfismo dinámico**, es decir, decidir en tiempo de ejecución qué versión de un método invocar según el tipo real del objeto, no el tipo del puntero o referencia.


## La palabra clave `virtual`

* Se declara en la clase base para marcar métodos que pueden ser redefinidos en clases derivadas.
* Cuando un método es `virtual`, las llamadas a ese método a través de punteros o referencias a la clase base ejecutan la versión correspondiente al tipo real del objeto (polimorfismo dinámico).
* Los destructores deben ser declarados `virtual` para asegurar que al destruir un objeto a través de un puntero base se invoquen todos los destructores correctamente.

```cpp
class Base {
public:
    virtual void funcion() {
        std::cout << "Función base\n";
    }
    virtual ~Base() = default; // Destructor virtual
};
```

## La palabra clave `override`

* Se usa en la declaración de un método en una clase derivada para indicar que está **sobrescribiendo** un método virtual de la clase base.
* Ayuda al compilador a verificar que el método realmente sobrescribe uno de la clase base, detectando errores si el nombre o la firma no coinciden.
* Mejora la legibilidad y el mantenimiento del código.

```cpp
class Derivada : public Base {
public:
    void funcion() override {  // Correcto uso de override
        std::cout << "Función derivada\n";
    }
};
```

## Ejemplo

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

    Animal* ptrAnimal = new Perro{};
    ptrAnimal->hablar();  // "El perro ladra."
    delete ptrAnimal;

    return 0;
}
```

* El polimorfismo dinámico se consigue con métodos declarados `virtual` en la clase base.
* La palabra clave `virtual` indica que el método puede ser redefinido en clases derivadas.
* Permite usar punteros o referencias a la clase base para manipular objetos derivados.
* Es fundamental para diseñar interfaces y extender el comportamiento sin cambiar código cliente.
* Siempre declarar destructores virtuales en clases base destinadas a ser heredadas para evitar fugas o comportamientos indefinidos.
* El destructor virtual asegura que al eliminar un objeto derivado a través de un puntero base se invoquen correctamente los destructores.


## La palabra clave `final`

La palabra calve `final` sirve para **impedir** que un método sea sobrescrito o que una clase sea derivada.

LAs ventajas de usar `final` son:

* **Control del diseño:** evita que otros programadores (o tú mismo) modifiquen la jerarquía de herencia accidentalmente.
* **Seguridad:** evita sobrescrituras no deseadas que pueden introducir bugs.
* **Optimización:** algunos compiladores pueden optimizar llamadas a métodos marcados como `final` porque saben que no habrá sobrescritura adicional.


### Uso de `final` en métodos

Cuando se declara un método virtual como `final` en una clase derivada, se indica que **no puede ser sobrescrito en clases derivadas posteriores**.

```cpp
class Base {
public:
    virtual void metodo() {
        std::cout << "Base::metodo\n";
    }
};

class Derivada : public Base {
public:
    void metodo() final {  // Este método no puede ser sobrescrito más adelante
        std::cout << "Derivada::metodo final\n";
    }
};

class SubDerivada : public Derivada {
public:
    // Error: intentar sobrescribir metodo() está prohibido
    // void metodo() override { }  // Error de compilación
};
```

### Uso de `final` en clases

Declarar una clase como `final` impide que sea utilizada como clase base para otras clases. Es decir, no puede ser heredada.

```cpp
class ClaseFinal final {
public:
    void funcion() {
        std::cout << "ClaseFinal::funcion\n";
    }
};

// Error: no se puede heredar de ClaseFinal
// class Derivada : public ClaseFinal { };  // Error de compilación
```

### Ejemplo completo del uso de `final`

```cpp
#include <iostream>

class Animal {
public:
    virtual void hacerSonido() const {
        std::cout << "Sonido genérico\n";
    }
    virtual ~Animal() = default;
};

class Perro final : public Animal {
public:
    void hacerSonido() const final {
        std::cout << "Guau\n";
    }
};

// class PerroEspecial : public Perro { }; // Error: no se puede derivar de Perro

int main() {
    Perro p;
    p.hacerSonido();
}
```

Claro, aquí tienes una sección para material didáctico que explica el concepto de operadores virtuales en C++:

## Polimorfismo aplicado a operadores

En C++, los operadores sobrecargados no son más que funciones miembro con una sintaxis especial. Por ello, es posible declararlos como **virtuales** dentro de una clase base, permitiendo que su comportamiento pueda ser redefinido en clases derivadas y que se utilice el enlace dinámico (polimorfismo) en tiempo de ejecución.

Ejemplo:

```cpp
#include <iostream>
#include <memory>

struct FuncionBase {
    virtual int operator()(int x) const {
        return x;
    }
    virtual ~FuncionBase() = default; // Destructor virtual
};

struct FuncionDoble : FuncionBase {
    int operator()(int x) const override {
        return x * 2;
    }
};

void ejecutarFuncion(const FuncionBase& f, int valor) {
    std::cout << f(valor) << "\n";
}

int main() {
    FuncionDoble doble;
    ejecutarFuncion(doble, 5);  // Imprime 10
}
```

En este ejemplo, `operator()` está declarado virtual en la clase base `FuncionBase` y redefinido en la clase derivada `FuncionDoble`. Al pasar una referencia a `FuncionBase`, la llamada `f(valor)` se resuelve dinámicamente a la implementación de `FuncionDoble`.

