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
