#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& n, int e) : nombre{n}, edad{e} {}

    void mostrar() const {
        std::cout << nombre << " (" << edad << " años)\n";
    }
};

int main() {
    Persona p1("Ana", 30);          // Inicialización tradicional
    Persona p2{"Luis", 25};         // Inicialización uniforme (recomendada)
    Persona p3 = Persona("Eva", 40); // Inicialización por copia

    p1.mostrar();
    p2.mostrar();
    p3.mostrar();

    return 0;
}
