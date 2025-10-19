#include <iostream>
#include <memory>

// Clase Motor
class Motor {
public:
    void arrancar() const {
        std::cout << "Motor arrancado.\n";
    }
};

// Clase Vehiculo que agrega Motor mediante weak_ptr (no propietario)
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

int main() {
    std::shared_ptr<Motor> motor = std::make_shared<Motor>();

    Vehiculo coche(motor);   // El vehículo observa el motor (no lo posee)
    coche.encender();        // Motor arrancado
    motor.reset();           // Liberamos el motor explícitamente
    coche.encender();        // El motor ya no existe

    return 0;
}
