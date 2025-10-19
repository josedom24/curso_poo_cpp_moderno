#include <iostream>
#include <memory>

class Circulo {
public:
    void dibujar() const {
        std::cout << "Dibujando un círculo\n";
    }
};

class Rectangulo {
public:
    void dibujar() const {
        std::cout << "Dibujando un rectángulo\n";
    }
};

// Funciones que devuelven tipos concretos
std::unique_ptr<Circulo> crearCirculo() {
    return std::make_unique<Circulo>();
}

std::unique_ptr<Rectangulo> crearRectangulo() {
    return std::make_unique<Rectangulo>();
}

int main() {
    auto c = crearCirculo();
    auto r = crearRectangulo();

    c->dibujar();
    r->dibujar();
}
