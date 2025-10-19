#include <iostream>
#include <memory>

class Sensor {
public:
    virtual void leer() const = 0; // Necesario para que sea polimórfica
    virtual ~Sensor() = default;
};

class SensorTemperatura : public Sensor {
public:
    void leer() const override {
        std::cout << "Leyendo temperatura...\n";
    }
    void calibrar() const {
        std::cout << "Calibrando sensor de temperatura.\n";
    }
};

class SensorHumedad : public Sensor {
public:
    void leer() const override {
        std::cout << "Leyendo humedad...\n";
    }
};

int main() {
    std::unique_ptr<Sensor> sensor = std::make_unique<SensorTemperatura>();

    // Conversión segura desde base a derivada
    if (auto temp = dynamic_cast<SensorTemperatura*>(sensor.get())) {
        temp->leer();       // Correcto
        temp->calibrar();   // Acceso a métodos propios del derivado
    } else {
        std::cout << "El objeto no es un SensorTemperatura.\n";
    }

    return 0;
}
