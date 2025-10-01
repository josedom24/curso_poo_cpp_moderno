# Introducción a las relaciones entre clases

En la programación orientada a objetos, las clases no actúan de manera aislada. A medida que un sistema crece en complejidad, se hace necesario modelar cómo **colaboran e interactúan** entre sí. Esta colaboración se expresa mediante diferentes **relaciones entre clases**, cada una con un propósito y un nivel de acoplamiento distinto.

Estas relaciones ayudan a organizar el diseño del sistema, clarifican responsabilidades, permiten la reutilización de código y sientan las bases para aplicar técnicas más avanzadas como los **patrones de diseño**.

A continuación se presentan las principales relaciones entre clases, desde las más simples y transitorias hasta las más estructurales y duraderas.

## Dependencia

* Representa una relación **temporal y débil**.
* Una clase utiliza a otra para realizar una acción puntual.
* No implica que la clase dependiente almacene a la otra como parte de su estado interno.
* Es la relación más básica entre clases.

## Asociación

* Relación más estable que la dependencia.
* Una clase **almacena una referencia o vínculo** a otra clase.
* Puede ser:
  * **Unidireccional**: solo una clase conoce a la otra.
  * **Bidireccional**: ambas clases se conocen mutuamente.
* Puede representar relaciones como: "un pedido tiene un cliente", "un alumno pertenece a una clase".

## Agregación

* Tipo especial de asociación.
* Una clase **utiliza a otra pero no la posee**.
* El objeto agregado puede **existir independientemente** del agregador.
* Ejemplo típico: un curso utiliza un profesor existente, pero el curso no es dueño del profesor.
* Relación **débil**, pero estructural.

## Composición

* Tipo fuerte de asociación.
* Una clase **posee completamente a otra** y es responsable de su existencia y destrucción.
* El objeto contenido **no tiene sentido sin su contenedor**.
* Ejemplo típico: un automóvil contiene un motor; si el automóvil desaparece, también lo hace el motor.
* Relación **fuerte** y con propiedad exclusiva.

## Herencia (o Generalización)

* Relación jerárquica donde una clase **derivada hereda** características de una clase base.
* Permite modelar relaciones tipo “es-un” (por ejemplo, un `Perro` es un `Animal`).
* Establece una estructura común para múltiples clases relacionadas.
* Facilita el **polimorfismo**.

## Realización (Implementación de una interfaz)

* Relación entre una **clase concreta** y una **interfaz o clase abstracta**.
* Indica que una clase implementa el comportamiento definido por otra.
* Es clave para la **programación orientada a interfaces**, permitiendo mayor flexibilidad y desacoplamiento.


