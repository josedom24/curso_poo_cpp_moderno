#include <iostream>
#include <memory>  // std::unique_ptr, std::make_unique
#include <vector>
#include <cmath>   // std::pow, std::sqrt

// Clase base abstracta: representa una figura geométrica genérica
class Figura {
public:
    // Método virtual puro para clonar el objeto (patrón Prototype)
    virtual std::unique_ptr<Figura> clone() const = 0;

    // Método virtual para mostrar la información de la figura
    virtual void mostrar() const = 0;

    // Destructor virtual para asegurar destrucción correcta en jerarquías
    virtual ~Figura() = default;
};

// Clase derivada: Círculo
class Circulo : public Figura {
private:
    double radio;

public:
    // Constructor explícito
    explicit Circulo(double r) : radio(r) {}

    // Implementación del método clone()
    std::unique_ptr<Figura> clone() const override {
        // Crea una copia profunda del objeto actual
        return std::make_unique<Circulo>(*this);
    }

    // Método para mostrar la información del círculo
    void mostrar() const override {
        std::cout << "Círculo de radio " << radio
                  << " — Área: " << M_PI * std::pow(radio, 2) << '\n';
    }
};

// Clase derivada: Rectángulo
class Rectangulo : public Figura {
private:
    double ancho;
    double alto;

public:
    // Constructor explícito
    Rectangulo(double a, double b) : ancho(a), alto(b) {}

    // Implementación del método clone()
    std::unique_ptr<Figura> clone() const override {
        // Crea una copia profunda del objeto actual
        return std::make_unique<Rectangulo>(*this);
    }

    // Método para mostrar la información del rectángulo
    void mostrar() const override {
        std::cout << "Rectángulo de " << ancho << " x " << alto
                  << " — Área: " << ancho * alto << '\n';
    }
};

int main() {
    // Vector de figuras (polimórfico)
    std::vector<std::unique_ptr<Figura>> figuras;

    // Agregamos diferentes tipos de figuras
    figuras.push_back(std::make_unique<Circulo>(3.5));
    figuras.push_back(std::make_unique<Rectangulo>(4.0, 6.0));

    std::cout << "=== Figuras originales ===\n";
    for (const auto& f : figuras) {
        f->mostrar();
    }

    // Clonamos las figuras sin conocer su tipo concreto
    std::vector<std::unique_ptr<Figura>> clones;
    for (const auto& f : figuras) {
        clones.push_back(f->clone());
    }

    std::cout << "\n=== Figuras clonadas ===\n";
    for (const auto& f : clones) {
        f->mostrar();
    }

    return 0;
}
