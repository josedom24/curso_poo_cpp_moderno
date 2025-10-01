# Separación entre interfaz y detalle de implementación (Pimpl idiom)

En C++, la **separación entre interfaz y detalle de implementación** es clave para lograr código modular, mantenible y eficiente.

Si bien separar la interfaz y la implementación en archivos `.h` y `.cpp` es una práctica estándar, esta separación no siempre es suficiente para evitar la exposición de dependencias internas ni para acelerar los tiempos de compilación, especialmente en proyectos grandes.

El **Pimpl idiom** (Pointer to IMPLementation) es una técnica avanzada que **refuerza el encapsulamiento ocultando completamente los detalles de implementación** en la clase, evitando que cambien las dependencias en el archivo de interfaz.

## Clases internas

En la programación orientada a objetos, la organización y encapsulación del código son fundamentales para mantener sistemas claros, modulares y fáciles de mantener. Una herramienta poderosa que ofrece C++ para lograr estos objetivos es la **clase interna** o **clase anidada**.

Una **clase interna** es una clase definida dentro del ámbito de otra clase, conocida como **clase externa**. Esta característica permite agrupar conceptos relacionados y ocultar detalles de implementación que no deben ser accesibles directamente desde el exterior.


Una clase interna se declara dentro de la definición de otra clase. Por ejemplo:

```cpp
class Exterior {
public:
    void metodo();

private:
    class Interna {
    public:
        void accion();
    };

    Interna objInterno;
};
```

En este ejemplo:

* `Interna` es una clase definida dentro de la clase `Exterior`.
* `Interna` está declarada como `private`, por lo que solo es visible dentro de `Exterior`.
* `Exterior` contiene un objeto de tipo `Interna` como atributo.

Características:

* **Ámbito restringido**: La clase interna existe dentro del espacio de nombres de la clase externa. Su nombre completo sería `Exterior::Interna`.
* **Control de visibilidad**: La clase interna puede declararse como `public`, `protected` o `private`, controlando su acceso desde fuera de la clase externa.
* **Acceso a miembros**: Por defecto, la clase interna no tiene acceso directo a los miembros privados de la clase externa (ni viceversa), a menos que se establezcan relaciones de amistad (`friend`) o se usen métodos públicos para comunicar datos.
* **Encapsulamiento**: Permite ocultar detalles internos, ya que la clase interna puede implementarse completamente dentro de la clase externa, sin exponer su definición a otros componentes.
* **Organización lógica**: Facilita la agrupación de clases relacionadas, mejorando la legibilidad y modularidad del código.

## ¿Qué es el Pimpl idiom?

El Pimpl idiom consiste en:

* Declarar una clase con una interfaz limpia y mínima en el archivo `.h`.
* Encapsular toda la implementación en una clase interna (normalmente llamada `Impl` o similar) definida en el archivo `.cpp`.
* Mantener un puntero privado único (`std::unique_ptr`) a esta clase interna dentro de la clase pública.
* Delegar todas las operaciones internas a este objeto `Impl`.

Esto permite:

* Ocultar completamente las dependencias de la implementación (incluyendo headers grandes o librerías externas).
* Minimizar recompilaciones: si solo cambia el `.cpp`, el archivo `.h` permanece intacto y las unidades que lo incluyen no necesitan recompilarse.
* Mejorar la encapsulación, evitando exponer detalles que no interesan al usuario de la clase.
* Reducir el tamaño de la interfaz visible y aumentar la coherencia del diseño.

## Estructura general del Pimpl idiom

```cpp
// Archivo MiClase.h
#pragma once
#include <memory>

class MiClase {
public:
    MiClase();
    ~MiClase();

    void metodoPublico();

    // No se exponen detalles internos
private:
    class Impl;                         // Declaración incompleta
    std::unique_ptr<Impl> pImpl;       // Puntero al detalle de implementación
};
```

```cpp
// Archivo MiClase.cpp
#include "MiClase.h"
#include <iostream>

// Definición completa de la clase Impl
class MiClase::Impl {
public:
    void metodoPrivado() {
        std::cout << "Implementación detallada\n";
    }
};

MiClase::MiClase() : pImpl(std::make_unique<Impl>()) {}

MiClase::~MiClase() = default;

void MiClase::metodoPublico() {
    pImpl->metodoPrivado();  // Delegación
}
```

Comparado con la separación tradicional Pimpl idiom:

* Oculta completamente la implementación de la clase.
* Reduce las dependencias en la interfaz al usar únicamente declaraciones incompletas (forward declarations), evitando así la inclusión directa de headers pesados y disminuyendo el acoplamiento entre módulos.
* Mejora significativamente los tiempos de compilación, ya que los cambios realizados en la implementación no afectan la interfaz pública ni provocan recompilaciones en los archivos que dependen de dicha interfaz.
* Mantiene una interfaz visible mucho más reducida, ya que oculta los detalles de implementación dentro de una clase interna, mostrando solo una declaración mínima en el encabezado.
* Reduce considerablemente el tamaño de la interfaz visible, exponiendo únicamente un puntero opaco y las declaraciones básicas, lo que facilita la comprensión y reduce la exposición innecesaria de detalles internos.
* Introduce una mayor complejidad en el código debido a la necesidad de escribir y mantener código adicional (boilerplate) para gestionar la clase interna oculta y el puntero que la referencia, aunque a cambio ofrece beneficios en encapsulamiento y tiempos de compilación.


## Ejemplo completo con Pimpl idiom

```cpp
// Archivo Vehiculo.h
#pragma once
#include <memory>
#include <string>

class Vehiculo {
public:
    Vehiculo(std::string modelo);
    ~Vehiculo();

    void mostrarInfo() const;

private:
    class Impl;
    std::unique_ptr<Impl> pImpl;
};
```

```cpp
// Archivo Vehiculo.cpp
#include "Vehiculo.h"
#include <iostream>

// Clase interna con implementación
class Vehiculo::Impl {
public:
    Impl(std::string modelo) : modelo_(std::move(modelo)) {}

    void mostrarInfo() const {
        std::cout << "Vehículo modelo: " << modelo_ << '\n';
    }

private:
    std::string modelo_;
};

// Implementación pública que delega
Vehiculo::Vehiculo(std::string modelo) : pImpl(std::make_unique<Impl>(std::move(modelo))) {}

Vehiculo::~Vehiculo() = default;

void Vehiculo::mostrarInfo() const {
    pImpl->mostrarInfo();
}
```

```cpp
// Archivo main.cpp
#include "Vehiculo.h"

int main() {
    Vehiculo v("Toyota Corolla");
    v.mostrarInfo();
}
```

* La **separación clásica** entre interfaz (`.h`) y detalles (`.cpp`) es una buena práctica que mejora la organización y encapsulamiento.
* El **Pimpl idiom** es una técnica avanzada para ocultar totalmente la implementación, reducir dependencias en el archivo de interfaz y acelerar compilaciones.
* Su uso es especialmente valioso en proyectos grandes o librerías que quieran preservar estabilidad de interfaz y disminuir tiempos de compilación.
* El coste es un poco más de complejidad en el código y una ligera sobrecarga en tiempo de ejecución por el uso del puntero y la indirección.

