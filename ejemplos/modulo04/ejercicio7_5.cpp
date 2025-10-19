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

class Derivada : public Base {
public:
    using Base::f; // Reexpone las sobrecargas de la base

    void f(const std::string& texto) {
        std::cout << "Derivada::f(std::string): " << texto << "\n";
    }
};

int main() {
    Derivada d;

    d.f("Hola");   // Llama a Derivada::f(std::string)
    d.f(10);       // Llama a Base::f(int)
    d.f(3.14);     // Llama a Base::f(double)

    return 0;
}
