# Asociaciones entre clases

En programación orientada a objetos, una **asociación** es una relación estructural entre dos clases en la que una clase mantiene un vínculo hacia otra. Esta relación es más estable y duradera que una dependencia puntual, ya que la clase asociada se convierte en parte del estado de la clase que la contiene.

Las asociaciones pueden ser:

* **Unidireccionales**: solo una clase conoce a la otra.
* **Bidireccionales**: ambas clases se conocen mutuamente.

Ejemplos de asociaciones típicas:

* Un pedido tiene un cliente.
* Un alumno pertenece a una clase.
* Un coche tiene un conductor.

## Asociación mediante punteros sin propiedad

Una clase puede almacenar un puntero a otra sin ser dueña de su ciclo de vida.

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
            std::cout << "Pedido " << id_ << " para cliente " 
                      << cliente_->obtenerNombre() << "\n";
        } else {
            std::cout << "Pedido " << id_ << " sin cliente asignado\n";
        }
    }

private:
    int id_;
    Cliente* cliente_; // asociación no propietaria
};

int main() {
    Cliente c("Ana");
    Pedido p(123, &c);
    p.mostrar();
    return 0;
}
```

En este caso:

* `Pedido` guarda un puntero a `Cliente`, pero **no lo gestiona**.
* El ciclo de vida del cliente está gestionado fuera.
* Es una asociación débil y no propietaria.

## Asociación mediante punteros inteligentes (`std::shared_ptr`)

Cuando se quiere compartir la propiedad del objeto asociado, se usan punteros inteligentes con conteo de referencias.

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
    Pedido(int id, std::shared_ptr<Cliente> cliente) 
        : id_(id), cliente_(std::move(cliente)) {}

    void mostrar() const {
        if (cliente_) {
            std::cout << "Pedido " << id_ << " para cliente " 
                      << cliente_->obtenerNombre() << "\n";
        }
    }

private:
    int id_;
    std::shared_ptr<Cliente> cliente_; // asociación compartida
};

int main() {
    auto c = std::make_shared<Cliente>("Luis");
    Pedido p(456, c);
    p.mostrar();

    // Tanto 'c' como 'p' comparten la propiedad del cliente
    return 0;
}
```

En este caso:

* `Pedido` y el puntero `c` comparten el mismo cliente.
* El objeto `Cliente` se destruye cuando ya no queda ninguna referencia.
* Es una asociación propietaria compartida.

## Asociación mediante referencias

Si la asociación es obligatoria y se garantiza que el objeto asociado siempre existirá, puede usarse una referencia.

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
        std::cout << "Pedido " << id_ << " para cliente " 
                  << cliente_.obtenerNombre() << "\n";
    }

private:
    int id_;
    const Cliente& cliente_; // asociación obligatoria, no propietaria
};

int main() {
    Cliente c("María");
    Pedido p(789, c);
    p.mostrar();
    return 0;
}
```

Aquí:

* `Pedido` mantiene una referencia a un `Cliente`.
* Se garantiza que no sea nula.
* No hay propiedad ni gestión del ciclo de vida.

## Asociaciones especiales: agregación y composición

La agregación y la composición son casos específicos de asociación:

* **Agregación**: el objeto contenido puede existir independientemente.
* **Composición**: el objeto contenido depende totalmente del contenedor.

Se estudiarán con más detalle en los apartados siguientes.

