## Composición entre clases

La composición es un tipo fuerte de asociación en programación orientada a objetos que representa una relación de propiedad exclusiva entre dos clases. En esta relación, una clase (contenedora) posee completamente a otra clase (componente), siendo responsable directa tanto de su creación como de su destrucción.

Características principales:

* El objeto contenido no puede existir independientemente del contenedor.
* La destrucción del contenedor implica la destrucción automática de los objetos contenidos.
* Modela relaciones “parte-todo” estrictas.
* Es una relación estructural fuerte con ciclo de vida dependiente.

Ejemplo típico: un automóvil contiene un motor propio; si el automóvil desaparece, su motor también deja de existir.

### Composición por valor

El objeto contenido se declara como miembro de datos dentro de la clase contenedora. Su construcción y destrucción ocurren automáticamente junto con el contenedor.

```cpp
#include <iostream>

class Motor {
public:
    void arrancar() const {
        std::cout << "Motor arrancado.\n";
    }
};

class Vehiculo {
private:
    Motor motor_;  // composición por valor
public:
    Vehiculo() = default;

    void encender() const {
        motor_.arrancar();
    }
};

int main() {
    Vehiculo coche;
    coche.encender();

    return 0;
}
```

* Con atributo por valor `Motor motor_` el **vehículo siempre tiene un motor propio**, no puede existir sin él.
* La relación es **composición**: el `Vehiculo` es dueño del `Motor`.
* La **vida del motor** depende completamente del `Vehiculo`: se crea y destruye junto con él.
* Ventajas: Control total del ciclo de vida, sin punteros ni riesgos de memoria. Implementación sencilla.
* Desventajas:  El objeto siempre existe mientras exista el contenedor. No se puede compartir el objeto contenido.

### Composición con punteros inteligentes propietarios

Cuando la composición requiere inicialización dinámica, se puede usar `std::unique_ptr` para asegurar la propiedad exclusiva.

```cpp
#include <iostream>
#include <memory>

class Motor {
public:
    void arrancar() const {
        std::cout << "Motor arrancado.\n";
    }
};

class Vehiculo {
private:
    std::unique_ptr<Motor> motor_;  // propietario exclusivo
public:
    Vehiculo() : motor_(std::make_unique<Motor>()) {}

    void encender() const {
        motor_->arrancar();
    }
};

int main() {
    Vehiculo coche;
    coche.encender();

    return 0;
}
```

* Con `std::unique_ptr<Motor>` el **Vehiculo es dueño exclusivo del motor**, nadie más puede poseerlo.
* El motor se crea dinámicamente en el constructor con `std::make_unique<Motor>()`.
* La relación es **composición**: cuando el `Vehiculo` se destruye, el `Motor` también se destruye automáticamente.
* Uso de punteros inteligentes asegura **gestión segura de memoria** sin fugas.
* Ventajas: Permite inicialización dinámica. Mantiene propiedad exclusiva y gestión automática. Seguridad ante fugas de memoria.
* Desventajas: No se puede compartir el objeto contenido.

