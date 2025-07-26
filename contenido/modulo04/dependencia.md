# Dependencia entre clases
La **dependencia** es la relación más débil entre clases. Se da cuando una clase **usa otra de forma puntual**, normalmente como parte de la implementación de uno o más métodos, **sin conservarla** como parte de su estado.

En otras palabras, una clase **depende** de otra si necesita conocerla para cumplir una tarea, pero **no es dueña de ella**, ni la contiene ni la almacena.

## Características principales

* Representa una relación **temporal** y **local**.
* Se describe como una relación de tipo **"usa"**.
* No hay propiedad ni ciclo de vida compartido.
* La clase dependiente **puede dejar de depender** de la otra sin alterar su estructura interna.
* Es común que un cambio en la clase usada **afecte** a la clase dependiente.

## Formas de implementar una dependencia en C++ moderno

En C++ moderno, las dependencias suelen manifestarse de varias formas dentro de métodos o funciones:

### Uso como parámetro por referencia o por valor

La forma más común de dependencia es **recibir un objeto como argumento** en un método:

```cpp
void usar(Objeto o);         // por valor (puede implicar copia o movimiento)
void usar(const Objeto& o);  // por referencia constante (lectura)
void usar(Objeto& o);        // por referencia modificable
```

Esta es la forma más habitual y recomendada para expresar dependencia puntual sin acoplamiento fuerte.


Ejemplo:

```cpp
#include <iostream>
#include <string>

class Documento {
public:
    Documento(std::string texto) : texto_(texto) {}

    std::string obtenerTexto() const { return texto_; }

private:
    std::string texto_;
};

class Impresora {
public:
    void imprimir(const Documento& doc) const {
        std::cout << "Imprimiendo: " << doc.obtenerTexto() << '\n';
    }
};

int main() {
    Documento d("Informe mensual");
    Impresora impresora;
    impresora.imprimir(d);  // dependencia puntual
}
```
* `Impresora` depende de `Documento`, pero solo dentro del método `imprimir`.
* No hay atributo de tipo `Documento` en la clase.
* El uso de `const Documento&` es eficiente y seguro.

### Uso local dentro de un método (creación local)

Otra forma de dependencia es cuando una clase **crea un objeto localmente** para usarlo temporalmente:

```cpp
void metodo() {
    Objeto obj;
    obj.hacerAlgo();
}
```

Aquí, la dependencia está totalmente encapsulada dentro del método. Veamos un ejemplo:

```cpp
#include <iostream>
#include <string>

class Documento {
public:
    Documento(std::string texto) : texto_(texto) {}

    std::string obtenerTexto() const { return texto_; }

private:
    std::string texto_;
};

class Impresora {
public:
    void imprimir(const Documento& doc) const {
        std::cout << "Imprimiendo: " << doc.obtenerTexto() << '\n';
    }
};

class Aplicacion {
public:
    void generarYImprimir() const {
        Documento doc("Acta de la reunión");
        Impresora impresora;
        impresora.imprimir(doc);
    }
};

int main() {
    Aplicacion app;
    app.generarYImprimir();  // La dependencia se resuelve dentro del método
    return 0;
}
```

* `Aplicacion` no almacena ni mantiene referencias ni punteros a `Documento` ni a `Impresora`.
* Dentro del método `generarYImprimir`, se **crea un objeto `Documento` local** y un **objeto `Impresora` local**.
* Se imprime el documento inmediatamente después de crearlo.

Esta es una **dependencia por creación local**, porque:

* La clase `Aplicacion` **usa** las clases `Documento` e `Impresora`, pero **no tiene una relación permanente** con ellas.
* Las instancias de `Documento` e `Impresora` **viven únicamente dentro del método**.
* Cuando el método termina, los objetos locales se destruyen automáticamente.


### Uso mediante punteros o punteros inteligentes temporales

En situaciones donde el objeto puede no existir, o cuando se usa durante poco tiempo:

```cpp
void imprimir(const Objeto* ptr);                // puntero crudo
void imprimir(std::shared_ptr<Objeto> ptr);      // puntero inteligente (temporal)
```

Esta forma de dependencia puede usarse cuando la relación es opcional o efímera. Ejemplo:

```cpp
#include <iostream>
#include <memory>   // Para std::shared_ptr
#include <string>

class Documento {
public:
    Documento(std::string texto) : texto_(std::move(texto)) {
        std::cout << "Documento creado: " << texto_ << '\n';
    }
    ~Documento() {
        std::cout << "Documento destruido: " << texto_ << '\n';
    }

    std::string obtenerTexto() const {
        return texto_;
    }

private:
    std::string texto_;
};

class Impresora {
public:
    // Dependencia mediante puntero inteligente temporal
    void imprimir(std::shared_ptr<Documento> doc) const {
        if (doc) {
            std::cout << "Imprimiendo documento: " << doc->obtenerTexto() << '\n';
        } else {
            std::cout << "No hay documento para imprimir.\n";
        }
    }
};

class Aplicacion {
public:
    void ejecutar() const {
        // Se crea un shared_ptr temporal para el documento
        auto doc = std::make_shared<Documento>("Reporte trimestral");

        // Se pasa el shared_ptr temporal a la función imprimir (dependencia puntual)
        Impresora impresora;
        impresora.imprimir(doc);

        // Después de imprimir, doc sigue existiendo aquí, pero Aplicacion no es dueño exclusivo
        // doc se destruye automáticamente cuando todas las shared_ptr que lo apuntan desaparecen
    }
};

int main() {
    Aplicacion app;
    app.ejecutar();

    std::cout << "Fin de main\n";
    return 0;
}
```
* La clase `Impresora` **depende temporalmente** de `Documento` a través del método `imprimir`, que recibe un `std::shared_ptr<Documento>`.
* No conserva ni almacena el documento; solo lo usa mientras dura la llamada (dependencia efímera).
* La clase `Aplicacion` crea el `Documento` dentro del método `ejecutar()` mediante un `std::shared_ptr` temporal, que pasa directamente al método `imprimir`.
* Como `shared_ptr` es un puntero inteligente, el control del ciclo de vida es compartido: mientras exista al menos un puntero a ese recurso, este no se libera.
* Cuando el método `ejecutar` termina, `doc` se destruye (si no hay más copias), liberando el recurso.
* `Aplicacion` no tiene relación permanente con `Documento` ni con `Impresora`, solo los usa puntualmente.
* Esta forma permite que `Impresora` use un recurso que puede o no existir y sin acoplarse a su ciclo de vida.


