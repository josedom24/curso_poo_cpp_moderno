# Asociaciones entre clases

En programación orientada a objetos, una **asociación** es una relación estructural entre dos clases en la que una clase mantiene una **referencia o vínculo** hacia otra. Esta relación es más estable y duradera que una dependencia puntual, ya que la clase asociada se convierte en parte del estado o contexto de la clase que la contiene.

Las asociaciones pueden ser:

* **Unidireccionales:** Solo una clase conoce a la otra.
* **Bidireccionales:** Ambas clases mantienen referencias mutuas.

La asociación se usa para modelar relaciones como:

* Un `Pedido` tiene un `Cliente`.
* Un `Alumno` pertenece a una `Clase`.
* Un `Coche` tiene un `Conductor`.



## Formas de implementar asociaciones en C++ moderno

### Asociación mediante punteros o referencias sin propiedad

Aquí la clase mantiene un puntero o referencia a otra clase, pero **no es dueña del objeto asociado**. Es una asociación débil, útil cuando el ciclo de vida es independiente o está gestionado externamente. Veamos un ejemplo:

```cpp
#include <iostream>
#include <string>

class Cliente {
public:
    Cliente(std::string nombre) : nombre_(std::move(nombre)) {}
    std::string obtenerNombre() const { return nombre_; }
private:
    std::string nombre_;
};

class Pedido {
public:
    Pedido(int id, Cliente* cliente) : id_(id), cliente_(cliente) {}

    void mostrar() const {
        if (cliente_) {
            std::cout << "Pedido " << id_ << " para cliente " << cliente_->obtenerNombre() << '\n';
        } else {
            std::cout << "Pedido " << id_ << " sin cliente asignado\n";
        }
    }

private:
    int id_;
    Cliente* cliente_;  // asociación (no propietaria)
};

int main() {
    Cliente c("Ana");
    Pedido p(123, &c);
    p.mostrar();
}
```

* `Pedido` almacena un puntero a `Cliente`, pero no gestiona su ciclo de vida.
* El puntero puede ser nulo o apuntar a un cliente válido.
* Asociación débil, no propietaria.

### Asociación mediante punteros inteligentes (`std::shared_ptr`)

Cuando queremos compartir la propiedad y asegurarnos que el objeto asociado viva mientras exista alguna referencia, usamos `std::shared_ptr`.

```cpp
#include <iostream>
#include <memory>
#include <string>

class Cliente {
public:
    Cliente(std::string nombre) : nombre_(std::move(nombre)) {}
    std::string obtenerNombre() const { return nombre_; }
private:
    std::string nombre_;
};

class Pedido {
public:
    Pedido(int id, std::shared_ptr<Cliente> cliente) : id_(id), cliente_(std::move(cliente)) {}

    void mostrar() const {
        if (cliente_) {
            std::cout << "Pedido " << id_ << " para cliente " << cliente_->obtenerNombre() << '\n';
        } else {
            std::cout << "Pedido " << id_ << " sin cliente asignado\n";
        }
    }

private:
    int id_;
    std::shared_ptr<Cliente> cliente_;  // asociación compartida y propietaria
};

int main() {
    auto c = std::make_shared<Cliente>("Luis");
    Pedido p(456, c);
    p.mostrar();

    // 'c' y 'p' comparten la propiedad del cliente.
}
```

* Aquí `Pedido` comparte la propiedad de `Cliente`.
* Mientras exista alguna referencia, el objeto no se destruye.
* Útil para asociaciones donde varias entidades usan el mismo objeto.

### Asociación mediante referencias (`&`)

Si la asociación es obligatoria y la clase asociada siempre existirá antes y después, puede usarse referencia, que garantiza no-null.

```cpp
#include <iostream>
#include <string>

class Cliente {
public:
    Cliente(std::string nombre) : nombre_(std::move(nombre)) {}
    std::string obtenerNombre() const { return nombre_; }
private:
    std::string nombre_;
};

class Pedido {
public:
    Pedido(int id, const Cliente& cliente) : id_(id), cliente_(cliente) {}

    void mostrar() const {
        std::cout << "Pedido " << id_ << " para cliente " << cliente_.obtenerNombre() << '\n';
    }

private:
    int id_;
    const Cliente& cliente_;  // asociación no propietaria obligatoria
};

int main() {
    Cliente c("María");
    Pedido p(789, c);
    p.mostrar();
}
```

* `Pedido` mantiene una referencia constante a un `Cliente`.
* No hay propiedad ni ciclo de vida asociado.
* Ideal cuando el objeto existe garantizadamente antes y después.

### Asociaciones mediante agregación y composición

En los próximos apartados estudiaremos dos nuevas relaciones en clases como son la **agregación** y la **composición**, que son otros modos de asociaciones.