#include <iostream>

class Punto {
private:
    int x;
    int y;

public:
    // Constructor por defecto con lista de inicialización
    Punto() : x{0}, y{0} {}

    // Constructor parametrizado con lista de inicialización
    Punto(int valorX, int valorY) : x{valorX}, y{valorY} {}

    // Método constante para mostrar el estado del objeto
    void mostrar() const {
        std::cout << "Punto(" << x << ", " << y << ")\n";
    }
};

int main() {
    Punto p1;            // Se usa el constructor por defecto
    Punto p2{3, 4};      // Se usa el constructor parametrizado

    p1.mostrar();        // Punto(0, 0)
    p2.mostrar();        // Punto(3, 4)

    return 0;
}
