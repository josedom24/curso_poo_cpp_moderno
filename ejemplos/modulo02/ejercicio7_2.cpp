#include <iostream>

class Punto {
private:
    const double x_;
    const double y_;

public:
    // Constructor con lista de inicialización
    Punto(double x, double y) : x_{x}, y_{y} {}

    // Método constante para mostrar el punto
    void mostrar() const {
        std::cout << "Punto(" << x_ << ", " << y_ << ")\n";
    }
};

int main() {
    Punto p1{1.5, 2.5};   // Se inicializan los miembros const
    Punto p2{0.0, -3.7};

    p1.mostrar();  // Punto(1.5, 2.5)
    p2.mostrar();  // Punto(0, -3.7)

    return 0;
}
