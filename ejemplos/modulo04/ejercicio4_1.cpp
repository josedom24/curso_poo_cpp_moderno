#include <iostream>

// Clase Motor
class Motor {
public:
    void arrancar() const {
        std::cout << "Motor arrancado.\n";
    }
};

// Clase Vehiculo que agrega Motor mediante referencia
class Vehiculo {
private:
    Motor& motor_;  // referencia, no propietario
public:
    // El constructor obliga a recibir una referencia válida a Motor
    Vehiculo(Motor& motor) : motor_(motor) {}

    void encender() const {
        motor_.arrancar();
    }
};

int main() {
    Motor motorPrincipal;      // Motor creado de forma independiente
    Vehiculo coche(motorPrincipal); // Vehículo con referencia al motor

    coche.encender();          // El coche utiliza el motor para arrancar

    return 0;
}
