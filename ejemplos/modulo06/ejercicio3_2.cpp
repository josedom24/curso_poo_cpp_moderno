#include <iostream>
#include <memory>

// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0;     // Método virtual puro
    virtual ~Figura() = default;          // Destructor virtual
};

// Clase derivada
class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un Círculo\n";
    }
};

// Función que devuelve un objeto por valor (provoca object slicing)
Figura crearFiguraPorValor() {
    Circulo c;
    return c;  // Se produce "object slicing"
}

// Solución moderna: devolver por puntero inteligente
std::unique_ptr<Figura> crearFiguraPorPuntero() {
    return std::make_unique<Circulo>();
}

int main() {
    std::cout << "== Ejemplo con devolución por valor ==\n";
    Figura f = crearFiguraPorValor();
    f.dibujar();  // Error conceptual: no se llama a Circulo::dibujar()
                  // Se comporta como una Figura “recortada”

    std::cout << "\n== Ejemplo con devolución mediante puntero ==\n";
    auto figuraPtr = crearFiguraPorPuntero();
    figuraPtr->dibujar();  //  Llama correctamente a Circulo::dibujar()

    return 0;
}
