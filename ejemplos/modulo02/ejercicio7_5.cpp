#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona() : Persona("Desconocido", 0) {}   // constructor delegante
    Persona(const std::string& n) : Persona(n, 0) {} // constructor delegante
    Persona(const std::string& n, int e) : nombre{n}, edad{e} {} // inicialización directa

    void mostrar() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << "\n";
    }
};

int main() {
    Persona p1;               // Usa el constructor delegante por defecto
    Persona p2{"José"};       // Usa el constructor delegante con un parámetro
    Persona p3{"María", 25};  // Usa el constructor con dos parámetros

    p1.mostrar();  // Nombre: Desconocido, Edad: 0
    p2.mostrar();  // Nombre: José, Edad: 0
    p3.mostrar();  // Nombre: María, Edad: 25

    return 0;
}
