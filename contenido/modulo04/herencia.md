# Introducción a la herencia: clases base y derivadas

## Concepto de herencia

La **herencia** es uno de los pilares fundamentales de la programación orientada a objetos (POO). Permite definir una nueva clase basada en una clase existente, de modo que la nueva clase **herede atributos y comportamientos** de la clase original, pudiendo además agregar o modificar funcionalidades.

La ventajas del uso de la herencia son;

* **Reutilización de código:** evita duplicar atributos y métodos comunes.
* **Organización jerárquica:** facilita la estructuración de conceptos.
* **Polimorfismo:** permite usar objetos derivados como objetos base para interfaces genéricas.

## Clases base y derivadas

La **herencia** permite que una clase (denominada **derivada** o **subclase**) herede atributos y métodos de otra clase (denominada **base** o **superclase**).

Esto representa una relación **"es un"** (**is-a**)*

* Un **Gato** es un **Animal**.
* Un **Círculo** es una **Figura**.
* Un **Coche** es un **Vehículo**.

La herencia evita la duplicación de código y permite extender el comportamiento de las clases base.

La forma más habitual y recomendada de herencia en C++ es la **herencia pública**, que significa que los miembros `public` y `protected` de la clase base se mantienen accesibles con las mismas restricciones en la clase derivada. El control de acceso `protected` indica que un miembro no es accesible desde fuera de la clase, pero sí puede ser accedido por clases derivadas. Este modificador se utiliza comúnmente para permitir que las subclases interactúen directamente con ciertos atributos o métodos internos de la clase base, sin exponerlos completamente como parte de su interfaz pública.

La sintaxis básica es:

```cpp
class Base {
public:
    void funcionBase() {
        // Implementación común
    }
};

class Derivada : public Base {
public:
    void funcionDerivada() {
        // Función específica de la clase derivada
    }
};
```

* La clase `Derivada` hereda públicamente de `Base`.
* `Derivada` puede acceder a los miembros públicos y protegidos de `Base`.
* Los miembros privados de `Base` no son accesibles directamente por `Derivada`.


Las clases derivadas deben invocar explícitamente el constructor de la clase base dentro de su lista de inicialización. Si no se indica, se invoca automáticamente el constructor por defecto de la clase base (si existe). Ejemplo:

```cpp
class Animal {
private:
    std::string nombre;

public:
    Animal(const std::string& n) : nombre{n} {}

    void mostrarNombre() const {
        std::cout << "Nombre: " << nombre << std::endl;
    }
};
```

La clase derivada:

```cpp
class Perro : public Animal {
private:
    std::string raza;

public:
    Perro(const std::string& n, const std::string& r)
        : Animal{n}, raza{r} {}

    void mostrar() const {
        mostrarNombre();
        std::cout << "Raza: " << raza << std::endl;
    }
};
```

* El destructor de la clase base se invoca automáticamente después del destructor de la clase derivada.
* Si la clase base gestiona recursos, su destructor debe ser virtual (se explicará más adelante).

