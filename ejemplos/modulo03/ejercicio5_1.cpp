#include <iostream>
#include <memory>

class Dispositivo {
public:
    void encender() const {
        std::cout << "Dispositivo encendido\n";
    }
    void apagar() const {
        std::cout << "Dispositivo apagado\n";
    }
};

int main() {
    // Creación de un objeto dinámico de tipo Dispositivo
    std::unique_ptr<Dispositivo> d = std::make_unique<Dispositivo>();

    // Acceso a métodos mediante ->
    d->encender();
    d->apagar();

    // No es necesario liberar memoria manualmente
    return 0; // d se destruye y libera automáticamente el objeto
}
