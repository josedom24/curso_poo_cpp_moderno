#include <iostream>
#include <string>

class Base {
public:
    void f(int x) {
        std::cout << "Base::f(int): " << x << "\n";
    }

    void f(double x) {
        std::cout << "Base::f(double): " << x << "\n";
    }
};

// Clase derivada que oculta las funciones f() de Base
class Derivada : public Base {
public:
    void f(const std::string& texto) {
        std::cout << "Derivada::f(std::string): " << texto << "\n";
    }
};

int main() {
    Derivada d;

    // Solo se puede llamar a la versión de Derivada
    d.f("Hola");        // Correcto
    // d.f(10);         // Error: las versiones de Base están ocultas
    // d.f(3.14);       // Error: también están ocultas

    return 0;
}
