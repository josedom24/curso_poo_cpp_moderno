# Clases y Objetos

La **programación orientada a objetos (POO)** es un paradigma de programación que organiza el código en **objetos** que combinan **estado (datos)** y **comportamiento (métodos)**. En C++, la implementación de este paradigma se realiza mediante el uso de **clases**.

## ¿Qué es una clase?

Una **clase** es una plantilla o molde que define:

* **Atributos** (también llamados **miembros de datos**): variables que representan el estado de los objetos.
* **Métodos** (también llamados **funciones miembro**): funciones que representan el comportamiento de los objetos.

La clase encapsula estos elementos y define cómo los objetos deben comportarse.

Veamos la sintaxis básica:

```cpp
class Persona {
public:
    // Atributos (miembros de datos)
    std::string nombre;
    int edad;

    // Métodos (funciones miembro)
    void saludar() {
        std::cout << "Hola, me llamo " << nombre << " y tengo " << edad << " años.\n";
    }
};
```

* Se define la clase `Persona` que tiene:
    * Dos atributos públicos: `nombre` y `edad`.
    * Y un método público: `saludar()`, que accede al valor de los atributos públicos.

## ¿Qué es un objeto?

Un **objeto** es una **instancia concreta de una clase**. Cada objeto tiene su propio estado (valores de los atributos) y puede ejecutar los métodos definidos por la clase. Veamos un ejemplo:


```cpp
int main() {
    Persona p1;
    p1.nombre = "Ana";
    p1.edad = 30;

    Persona p2;
    p2.nombre = "Luis";
    p2.edad = 25;

    p1.saludar();  // Hola, me llamo Ana y tengo 30 años.
    p2.saludar();  // Hola, me llamo Luis y tengo 25 años.
}
```

* Creamos dos personas `p1` y `p2`.
* Inicializamos sus atributos, cada persona tiene los mismos atributos pero sus valores pueden ser diferentes.
* Cada una de las personas ejecuta su método.

Las clases y objetos:
* Permiten **organizar el código** en unidades coherentes.
* Favorecen la **reutilización**, **mantenibilidad** y **extensibilidad** del software.
* Son la base para aplicar principios como **encapsulamiento**, **herencia** y **polimorfismo**.


---

## Ejemplo práctico ampliado

Supongamos que queremos definir una clase `Persona` más completa, con un constructor y un método para actualizar la edad.

```cpp
#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    // Constructor
    Persona(const std::string& n, int e) : nombre(n), edad(e) {}

    // Método para saludar
    void saludar() const {
        std::cout << "Hola, soy " << nombre << " y tengo " << edad << " años.\n";
    }

    // Método para actualizar la edad
    void cumplirAnios() {
        edad++;
    }
};

int main() {
    Persona p("Claudia", 28);
    p.saludar();         // Hola, soy Claudia y tengo 28 años.
    p.cumplirAnios();
    p.saludar();         // Hola, soy Claudia y tengo 29 años.
}
```

---

## Representación UML del ejemplo ampliado

![diagrama1](img/diagrama1.png)

