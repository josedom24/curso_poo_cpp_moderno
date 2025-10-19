#include <iostream>
#include <memory>
#include <string>

class Usuario {
    std::string nombre;
public:
    explicit Usuario(std::string n) : nombre(std::move(n)) {}
    void saludar() const {
        std::cout << "Hola, soy " << nombre << '\n';
    }
};

int main() {
    auto u1 = std::make_shared<Usuario>("Ana");
    auto u2 = u1;  // Ambos comparten el mismo objeto

    u1->saludar();
    u2->saludar();

    std::cout << "Número de referencias: " << u1.use_count() << '\n';

    return 0; // El objeto se destruye cuando el contador llega a cero
}
