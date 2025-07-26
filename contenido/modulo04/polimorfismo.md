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
