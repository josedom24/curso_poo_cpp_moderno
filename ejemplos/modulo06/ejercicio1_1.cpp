#include <iostream>
#include <memory>
#include <vector>

// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0;  // Método virtual puro
    virtual ~Figura() = default;       // Destructor virtual
};

// Clases derivadas concretas
class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

class Rectangulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un rectángulo\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Figura>> figuras;

    figuras.push_back(std::make_unique<Circulo>());
    figuras.push_back(std::make_unique<Rectangulo>());

    for (const auto& figura : figuras)
        figura->dibujar();  // Llamada polimórfica
}
