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

// Función que devuelve la interfaz
std::unique_ptr<Forma> crearForma(bool esCirculo) {
    if (esCirculo)
        return std::make_unique<Circulo>();
    else
        return std::make_unique<Rectangulo>();
}

int main() {
    auto forma1 = crearForma(true);   // Crea un círculo
    auto forma2 = crearForma(false);  // Crea un rectángulo

    forma1->dibujar();  // Llamada polimórfica: Circulo::dibujar()
    forma2->dibujar();  // Llamada polimórfica: Rectangulo::dibujar()
}
