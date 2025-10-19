#include <iostream>

class Recurso {
public:
    Recurso() { std::cout << "Recurso adquirido\n"; }
    ~Recurso() { std::cout << "Recurso liberado\n"; }

    // Prohibimos copia y movimiento
    Recurso(const Recurso&) = delete;
    Recurso& operator=(const Recurso&) = delete;
    Recurso(Recurso&&) = delete;
    Recurso& operator=(Recurso&&) = delete;
};

int main() {
    Recurso r1;
    // Recurso r2 = r1;           // Error: copia prohibida
    // Recurso r3 = std::move(r1); // Error: movimiento prohibido
}
