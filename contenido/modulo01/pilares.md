# Los pilares de la programación orientada a objetos

La Programación Orientada a Objetos (POO) se fundamenta en **cuatro pilares principales** que guían el diseño y construcción de sistemas de software bien estructurados: **encapsulación**, **abstracción**, **herencia** y **polimorfismo**. Estos pilares no solo permiten representar entidades del mundo real en términos computacionales, sino que también promueven principios sólidos de ingeniería de software como la modularidad, la reutilización y la escalabilidad.

## Encapsulación

La **encapsulación** consiste en **ocultar los detalles internos de un objeto** y exponer únicamente lo necesario para su uso externo. Esta técnica se basa en restringir el acceso directo al estado interno (atributos) de un objeto, permitiendo que dicho estado solo sea modificado o consultado a través de métodos específicos (interfaces públicas).

Este principio favorece la seguridad y la integridad del sistema, ya que protege los datos de modificaciones indebidas y reduce la dependencia entre componentes.

Veamos un ejemplo:

Imaginemos que en nuestro sistema de transporte tenemos un objeto que representa un **vehículo**. Este objeto posee un atributo interno llamado `velocidadActual`, que no debe ser modificado directamente por usuarios del sistema, sino a través de métodos controlados.

* El objeto **Vehículo** expone métodos como `acelerar()` y `frenar()`, pero **no permite modificar directamente** la velocidad.
* Esto evita que se introduzcan valores incorrectos o peligrosos (por ejemplo, una velocidad negativa o una demasiado elevada sin restricciones).

Obtenemos las siguientes ventajas:

* Se garantiza que la lógica de control de velocidad sea coherente y segura.
* El resto del sistema puede utilizar el objeto sin conocer cómo calcula la velocidad o cómo gestiona sus límites.

## Abstracción

La **abstracción** implica **modelar entidades complejas del mundo real destacando únicamente sus características relevantes**, ignorando los detalles innecesarios para la interacción con otros objetos. Se enfoca en el "qué hace" un objeto, no en "cómo lo hace".

En programación orientada a objetos, una clase representa una abstracción: define qué propiedades y comportamientos son esenciales para describir una entidad específica dentro del sistema.

Veamos un ejemplo:

En nuestro sistema de transporte, **un vehículo** puede ser un coche, una motocicleta, un autobús o un camión. A pesar de sus diferencias, todos comparten un conjunto común de características esenciales para el sistema: pueden arrancar, detenerse, transportar pasajeros o mercancías, y tienen una matrícula.

* Se define una clase conceptual llamada `Vehículo`, que encapsula **solamente** las propiedades necesarias para representar a todos los tipos de vehículos: `matrícula`, `capacidad`, `iniciarMarcha()`, `detenerMarcha()`.
* Detalles como el número de ruedas, el tipo de combustible o si tienen aire acondicionado se ignoran en esta abstracción si no son relevantes para el sistema en ese nivel.

Obtenemos las siguientes ventajas:

* Permite construir modelos simples y coherentes de entidades complejas.
* Facilita el enfoque en la funcionalidad esencial, sin sobrecargar el diseño con detalles innecesarios.

## Herencia

La **herencia** permite que una clase derive de otra, **heredando atributos y métodos** de una clase base. Esto permite **reutilizar código** y **extender funcionalidad** sin duplicación.

La clase base define un comportamiento genérico, mientras que las clases derivadas pueden **especializarse** o **añadir comportamientos adicionales**.

Veamos un ejemplo:

En nuestro sistema, definimos una clase general `Vehículo` (como vimos antes). A partir de ella, podemos definir clases especializadas como:

* `Coche`
* `Camión`
* `Motocicleta`
* `Autobús`

Estas clases heredan los atributos y métodos comunes de `Vehículo` (por ejemplo: `matrícula`, `iniciarMarcha()`, `detenerMarcha()`) y pueden añadir otros específicos:

* `Camión` puede tener un atributo `capacidadDeCarga`.
* `Autobús` puede tener un método `abrirPuertas()`.

Obtenemos las siguientes ventajas:

* Se evita duplicar código al reutilizar comportamientos comunes.
* Permite representar relaciones jerárquicas (general–particular) entre entidades.
* Facilita la extensión del sistema agregando nuevos tipos sin modificar clases existentes.

## Polimorfismo

El **polimorfismo** permite que objetos de distintas clases **compartan una misma interfaz y sean tratados de manera uniforme**, aunque se comporten de forma diferente internamente.

En otras palabras, **el mismo mensaje puede producir comportamientos distintos**, dependiendo del objeto que lo reciba. Esto permite diseñar software flexible y extensible.

Veamos un ejemplo:

Supongamos que tenemos una operación `realizarMantenimiento()` que debe aplicarse a distintos tipos de vehículos. Aunque todos responden a esa acción, cada tipo lo hace de forma diferente:

* Un **coche** revisa aceite, frenos y filtros.
* Una **motocicleta** revisa cadenas y neumáticos.
* Un **autobús** requiere verificación de puertas automáticas y sistemas eléctricos.

Al aplicar el polimorfismo:

* Todos los objetos derivan de la clase `Vehículo` y **exponen el método `realizarMantenimiento()`**.
* El sistema puede almacenar distintos vehículos en una misma lista y, al recorrerla, llamar al mismo método `realizarMantenimiento()` sin preocuparse por el tipo de vehículo.
* Cada clase ejecutará su propia versión específica de la operación.

Obtenemos las siguientes ventajas:

* Permite escribir código más general y reutilizable.
* Facilita la incorporación de nuevos tipos de objetos sin alterar el código existente.
* Reduce el acoplamiento entre componentes.

