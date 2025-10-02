# Introducción a la gestión de recursos

En programación, la **gestión de recursos** se refiere al conjunto de técnicas que permiten reservar, utilizar y liberar recursos del sistema de manera eficiente y segura.

Entre los recursos más habituales se encuentran:

* **Memoria dinámica**
* **Archivos abiertos**
* **Conexiones de red o bases de datos**
* **Descriptores de dispositivos o handles**

Un manejo inadecuado puede causar:

* **Fugas de memoria** (*memory leaks*)
* **Bloqueos o corrupción de datos**
* **Consumo excesivo de recursos**
* **Fallas en la aplicación y mala experiencia de usuario**

## Gestión manual de recursos

En C++, el enfoque tradicional obliga al programador a reservar y liberar los recursos manualmente.

### Ejemplo: gestión manual de memoria

```cpp
#include <iostream>

int main() {
    int* ptr = new int;    // Reserva de memoria dinámica
    *ptr = 42;             // Uso de la memoria

    std::cout << "Valor: " << *ptr << "\n";

    delete ptr;            // Liberación manual de memoria

    return 0;
}
```

Si se omite `delete`, la memoria queda reservada sin liberarse → **fuga de memoria**.

### Ejemplo: gestión manual de archivos

```cpp
#include <cstdio>   // fopen, fclose

int main() {
    FILE* file = fopen("datos.txt", "r"); // Apertura manual del archivo
    if (file) {
        // ... uso del archivo ...
        fclose(file); // Cierre manual obligatorio
    }

    return 0;
}
```

Si se olvida `fclose`, el descriptor queda abierto, lo que puede causar **fugas de recursos** cuando se abren muchos archivos.

## Gestión moderna en C++

C++ moderno incorpora mecanismos que automatizan la gestión de recursos, reduciendo errores y mejorando la robustez del software.

Los más importantes son:

* **Punteros inteligentes (`std::unique_ptr`, `std::shared_ptr`)** → gestionan memoria automáticamente.
* **Patrón RAII (Resource Acquisition Is Initialization)** → los recursos se adquieren en el constructor y se liberan en el destructor de un objeto, garantizando seguridad incluso si hay excepciones.

Estos conceptos los desarrollaremos en los apartados siguientes.

