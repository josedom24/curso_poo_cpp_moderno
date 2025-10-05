#include <iostream>
#include <memory>   // std::unique_ptr, std::make_unique

// Clase simple que simula un sensor
class Sensor {
public:
    // Constructor: simula la activación del sensor
    Sensor() {
        std::cout << "Sensor activado.\n";
    }

    // Destructor: simula la liberación del sensor
    ~Sensor() {
        std::cout << "Sensor desactivado.\n";
    }

    // Método que simula una lectura del sensor
    void leer() const {
        std::cout << "Lectura del sensor: 42\n";
    }
};

int main() {
    std::cout << "Inicio del programa\n";

    // Creación de un puntero inteligente con propiedad exclusiva
    std::unique_ptr<Sensor> ptr1 = std::make_unique<Sensor>();

    // Uso del objeto a través del puntero
    ptr1->leer();

    // Transferencia de propiedad usando std::move
    std::unique_ptr<Sensor> ptr2 = std::move(ptr1);

    // Comprobamos si el primer puntero aún posee el recurso
    if (!ptr1) {
        std::cout << "ptr1 ya no posee el recurso.\n";
    }

    // El puntero ptr2 sigue siendo el propietario
    ptr2->leer();

    std::cout << "Fin del programa\n";
    return 0;
} // Aquí se destruye ptr2 y se libera el recurso automáticamente
