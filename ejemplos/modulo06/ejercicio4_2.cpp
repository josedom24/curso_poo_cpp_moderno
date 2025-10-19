#include <iostream>
#include <memory>

// Interfaz base
class Forma {
public:
    virtual void dibujar() const = 0;
    virtual ~Forma() = default;
};

// Implementaciones concretas
class Circulo : public Forma {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

class Rectangulo : public Forma {
public:
    void dibujar() const override {
        std::cout << "Dibujando un rectángulo\n";
    }
};

// Función que devuelve una interfaz compartida
std::shared_ptr<Forma> crearForma(bool esCirculo) {
    if (esCirculo)
        return std::make_shared<Circulo>();
    else
        return std::make_shared<Rectangulo>();
}

int main() {
    auto forma1 = crearForma(true);   // Círculo
    auto forma2 = crearForma(false);  // Rectángulo

    // Dos punteros compartiendo el mismo objeto
    auto formaCompartida = forma1;

    forma1->dibujar();  // Circulo
    forma2->dibujar();  // Rectangulo

    std::cout << "Referencias compartidas al círculo: "
              << forma1.use_count() << "\n";
}
