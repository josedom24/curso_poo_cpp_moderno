
# ¿Qué es la programación orientada a objetos?

La Programación Orientada a Objetos (POO) es un **paradigma de desarrollo de software** que permite modelar sistemas complejos mediante la construcción de **objetos** que representan entidades del mundo real o conceptual. Esta aproximación, basada en la interacción entre objetos que poseen atributos y comportamientos propios, ha transformado la manera en que se diseñan y desarrollan aplicaciones informáticas.

La POO no solo mejora la capacidad de abstracción del programador, sino que también introduce principios que favorecen la reutilización de código, la modularidad, la escalabilidad y el mantenimiento a largo plazo del software.

## Origen y Motivación

La POO surgió como respuesta a las limitaciones observadas en paradigmas más tradicionales, especialmente en la programación estructurada. A medida que los sistemas crecían en tamaño y complejidad, se hacía evidente que una organización puramente secuencial y procedimental del código dificultaba su mantenimiento, extensión y comprensión.

Inspirada en conceptos de simulación y en la forma en que interactuamos con el mundo (donde los objetos tienen identidad, estado y comportamiento), la POO propone un modelo de programación más cercano a la realidad.

## Comparación con la Programación Estructurada

En la programación estructurada, el enfoque principal está en **dividir el programa en funciones o procedimientos**. Los datos son globales o pasados como parámetros, y el control del flujo se gestiona mediante estructuras como condicionales y bucles. Este enfoque resulta adecuado para programas sencillos, pero presenta limitaciones cuando se trata de sistemas complejos. Esta forma de trabajar tiene algunas limitaciones:

* **Acoplamiento excesivo** entre datos y funciones.
* **Repetición de código** debido a la falta de mecanismos de reutilización.
* **Difícil mantenimiento** al no haber separación clara de responsabilidades.
* **Escalabilidad limitada**: al aumentar el tamaño del sistema, el código se vuelve difícil de gestionar.

La POO, en cambio, **integra datos y funciones en una misma unidad lógica llamada "objeto"**. Cada objeto es una instancia de una "clase", y actúa como una unidad autónoma que contiene tanto el estado como el comportamiento relacionado. Las ventajas que obtenemos son:

* **Modularidad**: El código se organiza en clases independientes, facilitando el desarrollo colaborativo.
* **Reutilización**: Las clases pueden reutilizarse en múltiples contextos y proyectos.
* **Mantenibilidad**: Cambios en una clase pueden realizarse sin afectar el resto del sistema si se respetan las interfaces públicas.
* **Abstracción**: Se puede trabajar con modelos conceptuales del problema, sin necesidad de conocer detalles internos de implementación.
* **Escalabilidad**: El sistema puede crecer de forma controlada, agregando nuevas clases o especializando las existentes.
* **Encapsulamiento**: Se protege el estado interno del objeto mediante niveles de acceso, reduciendo errores y aumentando la seguridad.

## Conceptos Fundamentales

* **Clase**: Es una plantilla o modelo que define las características (atributos) y comportamientos (métodos) comunes a un conjunto de objetos. No representa un objeto concreto, sino el concepto general.
* **Objeto**: Es una instancia concreta de una clase. Tiene su propio estado y puede ejecutar los métodos definidos en la clase.

Ejemplo conceptual: supongamos que estamos desarrollando un sistema para gestionar una biblioteca:

* Podemos definir una **clase `Libro`** que tenga atributos como:
    * `titulo`
    * `autor`
    * `añoPublicacion`
* Y métodos como:
    * `prestar()`
    * `devolver()`
Un **objeto** de esa clase podría representar un libro específico, como:
    * `titulo`: *"Cien años de soledad"*
    * `autor`: *"Gabriel García Márquez"*
    * `añoPublicacion`: *1967*

Cada objeto "libro" tendrá sus propios datos, pero todos compartirán la estructura y el comportamiento definidos por la clase `Libro`.

* **Atributos**: Representan el estado del objeto. Son variables que se almacenan dentro de cada instancia.
* **Métodos**: Representan el comportamiento del objeto. Son funciones que operan sobre los atributos del objeto o que permiten interactuar con otros objetos.
* En la POO, los objetos **interactúan entre sí mediante el envío de mensajes**. Un mensaje es simplemente una llamada a un método. Esta comunicación permite que los objetos colaboren para resolver tareas complejas sin conocer los detalles internos unos de otros.

## Ejemplo general 

Veamos un ejemplo en pseudocódigo:

```plaintext
Clase Persona:
    Atributos:
        nombre
        edad
    Métodos:
        saludar()
            Mostrar "Hola, mi nombre es " + nombre
        cumplirAnios()
            edad = edad + 1

// Crear un objeto
persona1 = nueva Persona()
persona1.nombre = "Ana"
persona1.edad = 30

// Usar métodos del objeto
persona1.saludar()        // Resultado: Hola, mi nombre es Ana
persona1.cumplirAnios()
```

Este ejemplo muestra cómo se define una clase con atributos y métodos, cómo se crea un objeto (instancia de la clase) y cómo se utiliza. No está vinculado a un lenguaje específico, lo cual permite entender los principios sin necesidad de saber sintaxis.
