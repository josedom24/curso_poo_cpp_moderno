# Introducción a la Programación Orientada a Objetos

La **Programación Orientada a Objetos (POO)** es un paradigma de programación que organiza el código en torno a **objetos**, los cuales representan entidades del mundo real o conceptos abstractos. Cada objeto combina datos y comportamientos, encapsulándolos en una misma unidad.

La POO busca modelar sistemas complejos de una forma más natural y modular, facilitando el desarrollo, mantenimiento y comprensión de los programas. A diferencia de la programación estructurada, que organiza el código en funciones y estructuras de control, la POO agrupa los datos y las operaciones que se pueden realizar sobre ellos dentro de objetos.

## Ventajas de la POO frente a la programación estructurada

A continuación se presentan algunas de las ventajas más relevantes que ofrece la POO en comparación con la programación estructurada tradicional:

* **Modularidad**: El código se organiza en clases, lo que facilita su división en módulos reutilizables.
* **Abstracción**: Permite ocultar los detalles de implementación y trabajar con modelos conceptuales.
* **Encapsulamiento**: Los datos y los métodos se agrupan en clases, lo que protege el estado interno del objeto.
* **Reutilización de código**: Gracias a la herencia y la composición, es posible reutilizar código existente sin duplicación.
* **Mantenimiento simplificado**: Al estar el código dividido en componentes bien definidos, resulta más sencillo localizar y corregir errores.
* **Extensibilidad**: Los programas se pueden ampliar y modificar de forma controlada, gracias a mecanismos como la herencia y el polimorfismo.

## Conceptos básicos: objetos, clases, atributos y métodos

Para comprender la POO en C++, es necesario familiarizarse con sus conceptos fundamentales:

* **Clases**: Una **clase** es un plano o plantilla que define las características y comportamientos de un conjunto de objetos. Especifica:
    * Los **atributos** o **miembros de datos**: las propiedades o características de los objetos.
    * Los **métodos** o **miembros función**: las operaciones o comportamientos que los objetos pueden realizar.
* **Objetos**: Un **objeto** es una instancia concreta de una clase. Representa una entidad específica que posee un estado propio y puede ejecutar acciones definidas por la clase.
* **Atributos**: Los **atributos** son las variables que describen el estado de un objeto. Cada objeto mantiene sus propios valores de estos atributos.
* **Métodos**: Los **métodos** son funciones asociadas a la clase que definen el comportamiento de los objetos. Pueden consultar o modificar el estado del objeto, o realizar acciones.

## Ejemplo 1: Clase `Persona`

```cpp
#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor
    Persona(const std::string& n, int e) : nombre(n), edad(e) {}

    // Método para mostrar información
    void presentar() const {
        std::cout << "Hola, mi nombre es " << nombre << " y tengo " << edad << " años." << std::endl;
    }
};

int main() {
    Persona persona1("Ana", 30);
    Persona persona2("Carlos", 25);

    persona1.presentar();
    persona2.presentar();

    return 0;
}
```

* **`Persona`** es una clase que representa a una persona.
* Tiene dos atributos: `nombre` y `edad`.
* Tiene un método: `presentar`, que muestra información sobre la persona.
* En la función `main`, se crean dos objetos de tipo `Persona` y se invoca el método `presentar` en cada uno.

## Ejemplo 2: Agenda de contactos

Supongamos que queremos crear un programa para gestionar una agenda de contactos. Si utilizamos programación estructurada, tendríamos que definir estructuras y funciones separadas, y ser muy cuidadosos con los datos.

Con la POO, podemos definir una clase `Contacto`, con sus atributos y métodos, y así:

* Agrupamos los datos y las funciones.
* Evitamos errores de manipulación indebida.
* Reutilizamos código para crear tantos contactos como necesitemos.

```cpp
class Contacto {
private:
    std::string nombre;
    std::string telefono;

public:
    Contacto(const std::string& n, const std::string& t) : nombre(n), telefono(t) {}

    void mostrar() const {
        std::cout << "Nombre: " << nombre << ", Teléfono: " << telefono << std::endl;
    }
};
```

Con este enfoque, gestionar múltiples contactos se vuelve sencillo, ordenado y escalable.

