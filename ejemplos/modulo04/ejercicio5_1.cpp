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
