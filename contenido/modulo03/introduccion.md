# Introducción a la gestión de recursos

En el ámbito de la programación, **la gestión de recursos** se refiere al conjunto de técnicas y prácticas que permiten reservar, utilizar y liberar recursos del sistema de manera eficiente y segura. Estos recursos pueden incluir:

* **Memoria dinámica**
* **Archivos abiertos**
* **Conexiones de red o a bases de datos**
* **Handles o descriptores de dispositivos**, entre otros.

El correcto manejo de estos recursos es crucial para evitar problemas como **fugas de memoria** (*memory leaks*), **fugas de recursos**, bloqueos, corrupción de datos o consumo innecesario de recursos del sistema. Todos estos errores pueden derivar en fallos graves de la aplicación o una mala experiencia para el usuario.

## Gestión manual de recursos

En C++, tradicionalmente, el programador es responsable de gestionar los recursos manualmente. Esto implica que debe reservar explícitamente un recurso y, una vez que ya no se necesita, liberarlo o cerrarlo adecuadamente.

### Ejemplo: gestión manual de memoria

Lo estudiaremos más detenidamente en el siguiente apartado, pero si queremos reservar memoria para guardar nuestros datos, el programador será responsable de reservar la memoria (operador `new`) y posteriormente liberar dicha memoria (operador `delete`).

```cpp
int* ptr = new int;        // Reserva de memoria dinámica
// ... uso de ptr ...
delete ptr;             // Liberación manual de memoria
```

Aquí, el recurso que gestionamos es **memoria**. Si olvidamos llamar a `delete`, se producirá una **fuga de memoria**, es decir, memoria reservada que nunca se libera.

### Ejemplo: gestión manual de archivos

```cpp
#include <fstream>

int main() {
    FILE* file = fopen("datos.txt", "r");  // Apertura manual del archivo
    if (file) {
        // ... uso del archivo ...
        fclose(file);                      // Cierre manual del archivo
    }
}
```

En este caso, el recurso es el **descriptor de archivo** devuelto por `fopen`. Si olvidamos llamar a `fclose`, el descriptor permanece abierto, lo que puede causar una **fuga de recursos**, especialmente si el programa abre muchos archivos.

## Problemas frecuentes de la gestión manual

Este enfoque manual, aunque flexible, es propenso a errores como:

* **Fugas de memoria o recursos:** olvidar liberar un recurso después de su uso.
* **Doble liberación:** intentar liberar un recurso dos veces, lo que puede provocar fallos o comportamientos indefinidos.
* **Acceso a recursos liberados:** intentar utilizar memoria o recursos que ya han sido liberados, lo que suele provocar errores sutiles y difíciles de depurar.

## Gestión moderna y automatizada de recursos en C++

Con el avance del lenguaje y las bibliotecas estándar, **C++ moderno** proporciona mecanismos para facilitar y automatizar la gestión de recursos. Estos mecanismos permiten minimizar errores y mejorar la robustez del código.

Entre los conceptos y herramientas que exploraremos en los próximos apartados se encuentran:

* **Punteros inteligentes**: objetos que gestionan automáticamente la memoria dinámica.
* **El patrón RAII (*Resource Acquisition Is Initialization*)**, que garantiza que los recursos se liberen de forma automática y segura, vinculando su ciclo de vida al de un objeto.

