#include <iostream>

class Base {
public:
    virtual void funcion() {
        std::cout << "Función base\n";
    }
    virtual ~Base() = default; // Destructor virtual
};

class Derivada : public Base {
public:
    void funcion() override {
        std::cout << "Función derivada\n";
    }
};

int main() {
    Base* b = new Derivada();
    b->funcion();  // Llama a la versión de Derivada
    delete b;
}
