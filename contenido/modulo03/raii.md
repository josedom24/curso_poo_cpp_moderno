# Propiedad de recursos y patrón RAII

En C++, la gestión segura y eficiente de recursos se basa en dos conceptos estrechamente relacionados y fundamentales: el patrón **RAII** (*Resource Acquisition Is Initialization*) y la **propiedad** de los recursos.

Comprender estos conceptos es clave para evitar errores comunes como fugas de memoria, doble liberación o acceso a recursos liberados, y sienta las bases para utilizar mecanismos modernos como los punteros inteligentes.

## ¿Qué es RAII?

RAII es una técnica de diseño que vincula la **adquisición** y **liberación** de un recurso al ciclo de vida de un objeto:

* El recurso se adquiere en el **constructor** del objeto.
* El recurso se libera automáticamente en el **destructor** del objeto.

Este principio se aplica no solo a memoria dinámica, sino también a recursos como archivos abiertos, sockets, mutexes, conexiones de red, entre otros.

--Como es necesario aprender programación orientada a objetos para aplicar estos conceptos vermos los ejemplos detenidamente en ese apartado del curso.--

## Propiedad de los recursos

El concepto de **propiedad** responde a la pregunta: ¿qué entidad es responsable de liberar un recurso?

Cuando un objeto adquiere un recurso siguiendo el patrón RAII, se convierte en su **propietario**, es decir, es responsable de liberarlo cuando ya no sea necesario.

Existen diferentes modelos de propiedad:

* **Propiedad exclusiva**: Un único objeto posee el recurso.
* **Propiedad compartida**: Varios objetos comparten la responsabilidad del recurso.
* **Observador**: Un objeto observa el recurso, pero no lo posee.

Definir claramente la propiedad es esencial para:

* Evitar **fugas de recursos**, si nadie los libera.
* Prevenir **doble liberación**, si varios intentan liberar el mismo recurso.
* Impedir **accesos inválidos**, si se usa un recurso después de ser liberado.


## Gestión automática de recursos

El enfoque recomendado en C++ moderno es delegar la gestión de recursos a objetos que encapsulan y controlan su vida útil, aplicando los principios de RAII y propiedad. Esto implica:

* **Encapsulación:** el recurso se envuelve en un objeto que lo gestiona.
* **Transferencia de propiedad:** la propiedad puede pasar de un objeto a otro de forma explícita y controlada.
* **Liberación automática:** al destruirse el objeto propietario, el recurso se libera automáticamente.

Este modelo no solo reduce los errores de gestión manual, sino que además:

* Optimiza el rendimiento al evitar **copias innecesarias**, ya que los recursos se gestionan por propiedad y referencia.
* Mejora la seguridad, ya que los recursos se liberan de forma predecible incluso en presencia de excepciones.
* Hace el código más claro y mantenible, al expresar explícitamente las relaciones de propiedad.

En el siguiente apartado exploraremos cómo los punteros inteligentes de C++ son una aplicación práctica de estos principios para la gestión segura de memoria dinámica.

