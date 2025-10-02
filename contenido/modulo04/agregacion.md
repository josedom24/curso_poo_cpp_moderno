## Agregación entre clases

La agregación es un tipo particular de asociación en programación orientada a objetos que representa una relación débil y no exclusiva entre dos clases. En esta relación, una clase (denominada agregadora) mantiene una referencia o vínculo hacia otra clase (denominada agregada), pero no asume la propiedad ni el control exclusivo sobre el ciclo de vida del objeto agregado.

En otras palabras:

* El objeto agregado puede existir independientemente del objeto agregador.
* La agregación implica una relación de "tiene un" o "usa un", pero sin una dependencia estricta en la existencia.
* La destrucción del objeto agregador no conlleva necesariamente la destrucción del objeto agregado.
* La relación es estructuralmente más estable que una dependencia simple, ya que el objeto agregador conserva una referencia o vínculo durante su vida útil.

Esta relación es útil para modelar escenarios en los que un objeto está compuesto o utiliza a otro, pero sin poseerlo en exclusiva ni encargarse de su ciclo de vida. Un ejemplo clásico es un vehículo que tiene un motor: el motor puede existir antes, después o incluso compartirse entre distintos vehículos.

### Formas de implementar la agregación en C++ moderno

#### Uso de punteros crudos (raw pointers)

El agregador mantiene un puntero sin propiedad hacia el objeto agregado. Es responsabilidad del código externo garantizar que el objeto apuntado exista mientras se use.

```cpp
class Motor {
public:
    void arrancar() const {
        std::cout << "Motor arrancado.\n";
    }
};

class Vehiculo {
private:
    Motor* motor_;  // puntero crudo, no propietario
public:
    Vehiculo(Motor* motor) : motor_(motor) {}
    void encender() const {
        if (motor_) motor_->arrancar();
        else std::cout << "No hay motor asignado.\n";
    }
};
```

Ventajas:

* Simple y directo.
* Sin sobrecarga adicional.

Desventajas:

* Riesgo de punteros colgantes si el objeto agregado se destruye antes.
* No hay gestión automática de ciclo de vida.

#### Uso de referencias

El agregador recibe y almacena una referencia al objeto agregado, garantizando que siempre existe mientras el agregador está vivo.

```cpp
class Vehiculo {
private:
    Motor& motor_;  // referencia, no propietario
public:
    Vehiculo(Motor& motor) : motor_(motor) {}
    void encender() const {
        motor_.arrancar();
    }
};
```

Ventajas:

* La referencia siempre es válida y no puede ser nula.
* Claridad en que el agregador no es propietario.

Desventajas:

* La referencia debe inicializarse obligatoriamente en el constructor.
* No puede reasignarse a otro objeto una vez inicializada.

#### Uso de punteros inteligentes no propietarios (std::weak_ptr)

Cuando se trabaja con `std::shared_ptr`, la agregación puede representarse con `std::weak_ptr`, que mantiene una referencia débil sin afectar al conteo de referencias ni a la propiedad.

```cpp
#include <memory>

class Vehiculo {
private:
    std::weak_ptr<Motor> motor_;  // referencia débil, no propietaria
public:
    Vehiculo(std::shared_ptr<Motor> motor) : motor_(motor) {}
    void encender() const {
        if (auto motor_shared = motor_.lock()) {
            motor_shared->arrancar();
        } else {
            std::cout << "El motor ya no existe.\n";
        }
    }
};
```

Ventajas:

* Seguridad frente a punteros colgantes.
* Compatible con gestión automática de memoria.

Desventajas:

* Ligera sobrecarga.
* Requiere que el objeto agregado se gestione con `std::shared_ptr`.

### Ejemplo completo de agregación

```cpp
#include <iostream>
#include <string>

// Clase Motor
class Motor {
private:
    std::string tipo_;
public:
    Motor(const std::string& tipo) : tipo_(tipo) {}
    void arrancar() const {
        std::cout << "Motor tipo " << tipo_ << " arrancado.\n";
    }
    std::string obtenerTipo() const { return tipo_; }
};

// Clase Vehiculo que agrega Motor
class Vehiculo {
private:
    Motor* motor_;  // puntero crudo, no propietario
    std::string modelo_;
public:
    Vehiculo(const std::string& modelo, Motor* motor) : modelo_(modelo), motor_(motor) {}
    void encender() const {
        std::cout << "Vehículo modelo " << modelo_ << " arrancando motor...\n";
        if (motor_) motor_->arrancar();
        else std::cout << "No hay motor asignado.\n";
    }
};

int main() {
    Motor motorDiesel("Diésel");
    Vehiculo camion("Camión Volvo", &motorDiesel);

    camion.encender();

    std::cout << "El motor sigue existiendo tras uso del vehículo: " 
              << motorDiesel.obtenerTipo() << "\n";

    return 0;
}
```

Explicación del ejemplo:

* `Vehiculo` recibe un puntero crudo a un objeto `Motor`, pero no lo crea ni lo destruye.
* El motor es creado en `main` y puede existir independientemente del vehículo.
* El método `encender()` utiliza la relación de agregación para invocar `arrancar()` en el motor.
* Al finalizar, la destrucción del vehículo no afecta al motor, ya que no hay propiedad exclusiva.

