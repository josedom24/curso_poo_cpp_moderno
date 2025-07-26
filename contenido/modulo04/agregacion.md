# Agregación entre clases

La **agregación** es un tipo particular de asociación en programación orientada a objetos que representa una relación **débil y no exclusiva** entre dos clases. En esta relación, una clase (denominada *agregadora*) mantiene una referencia o vínculo hacia otra clase (denominada *agregada*), pero **no asume la propiedad ni el control exclusivo sobre el ciclo de vida del objeto agregado**.

En otras palabras:

* El objeto agregado puede existir independientemente del objeto agregador.
* La agregación implica una relación de "tiene un" o "usa un" pero sin una dependencia estricta en la existencia.
* La destrucción del objeto agregador **no conlleva necesariamente** la destrucción del objeto agregado.
* La relación es estructuralmente más estable que una dependencia simple, ya que el objeto agregador conserva una referencia o vínculo durante su vida útil.

Esta relación es útil para modelar escenarios en los que un objeto está compuesto o utiliza a otro, pero sin poseerlo en exclusiva ni encargarse de su ciclo de vida. Por ejemplo, un vehículo puede *tener un* motor, pero dicho motor puede existir y ser compartido en otras circunstancias o instancias.

## Formas de implementar la agregación en C++ moderno

En C++ moderno, la agregación puede implementarse de distintas maneras, según el grado de control sobre el ciclo de vida del objeto agregado y las necesidades de seguridad y eficiencia. A continuación, se describen las formas más habituales:

### Uso de punteros crudos (`Raw pointers`)

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

**Ventajas:**

* Simple y directo.
* Sin sobrecarga adicional.

**Desventajas:**

* Riesgo de punteros colgantes o acceso inválido si el objeto agregado se destruye.
* No hay gestión automática del ciclo de vida.

### Uso de referencias

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

**Ventajas:**

* Garantiza que la referencia es válida (no nula).
* Claridad en la propiedad: el agregador no posee el objeto.

**Desventajas:**

* La referencia debe inicializarse obligatoriamente en el constructor.
* No puede cambiar la referencia durante la vida del objeto (a menos que se use puntero).

### Uso de punteros inteligentes no propietarios (`std::weak_ptr`)

Cuando se usa un sistema de gestión automática de memoria con `std::shared_ptr`, la agregación puede representarse con un `std::weak_ptr` que mantiene una referencia débil sin afectar el conteo de referencias ni la propiedad.

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

**Ventajas:**

* Seguridad frente a punteros colgantes.
* Claridad en la no propiedad.
* Compatible con gestión automática de memoria.

**Desventajas:**

* Ligera complejidad y sobrecarga.
* Requiere que el objeto agregado sea gestionado por `std::shared_ptr`.


## Ejemplo completo de agregación: Vehículo y Motor

A continuación se presenta un ejemplo completo de la relación de agregación entre un `Vehiculo` y un `Motor` usando punteros crudos, la forma más común y didáctica para ilustrar el concepto.

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

    // El motorDiesel existe independientemente del Vehiculo
    std::cout << "El motor sigue existiendo tras uso del vehículo: " << motorDiesel.obtenerTipo() << "\n";

    return 0;
}
```

* El `Vehiculo` recibe un puntero crudo a un objeto `Motor`, que no crea ni destruye. Esto refleja que `Vehiculo` **no es dueño** del motor.
* El motor es creado en `main` y puede existir independientemente, pudiendo ser reutilizado o compartido con otros vehículos.
* El método `encender` usa la agregación para llamar al método `arrancar` del motor, mostrando la colaboración entre ambos objetos.
* Al finalizar, la destrucción del vehículo no afecta al motor, ya que no hay propiedad ni ciclo de vida compartido.

## Diagrama UML

![agrgación](img/agragacion.png)

* Se muestra con una **línea con diamante blanco** en el lado del objeto agregador (contenedor) y una flecha apuntando hacia el objeto agregado (componente).
* El **diamante indica la agregación**, pero no propiedad.
* Se representan relaciones **entre clases**, no entre instancias concretas.
* La notación puede incluir **multiplicidad** en los extremos (ej. `1`, `0..*`), aunque puede omitirse si el contexto es claro.
