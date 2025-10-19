#include <iostream>

// Clase base
class Base {
public:
    void funcionBase() {
        std::cout << "Función de la clase base" << std::endl;
    }
};

// Clase derivada
class Derivada : public Base {
public:
    void funcionDerivada() {
        std::cout << "Función específica de la clase derivada" << std::endl;
    }
};

int main() {
    Derivada obj;
    obj.funcionBase();     // Método heredado de Base
    obj.funcionDerivada(); // Método propio de Derivada
    return 0;
}
