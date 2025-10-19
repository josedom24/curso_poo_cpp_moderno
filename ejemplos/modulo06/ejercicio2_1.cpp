#include <iostream>
#include <memory>
#include <vector>

// Interfaz pura
class Dibujable {
public:
    virtual void dibujar() const = 0;   // Método virtual puro
    virtual ~Dibujable() = default;     // Destructor virtual
};

// Clases concretas que implementan la interfaz
class Circulo : public Dibujable {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

class Rectangulo : public Dibujable {
public:
    void dibujar() const override {
        std::cout << "Dibujando un rectángulo\n";
    }
};

// Función que trabaja con la interfaz
void renderizar(const std::vector<std::unique_ptr<Dibujable>>& objetos) {
    for (const auto& obj : objetos)
        obj->dibujar();  // Llamada polimórfica
}

int main() {
    std::vector<std::unique_ptr<Dibujable>> figuras;
    figuras.push_back(std::make_unique<Circulo>());
    figuras.push_back(std::make_unique<Rectangulo>());

    renderizar(figuras);
}
