#include <iostream>

class Figura {
public:
    virtual void dibujar() const = 0;
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

// Función incorrecta: devuelve referencia a un objeto local
Figura& crearFigura() {
    Circulo c;  // Objeto local (vida limitada al ámbito de la función)
    return c;   // Se devuelve una referencia a un objeto que será destruido
}

int main() {
    Figura& f = crearFigura();  // La referencia queda colgante
    f.dibujar();                // Comportamiento indefinido
}
