#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    // Constructor con inicialización uniforme
    Persona(const std::string& n, int e) : nombre{n}, edad{e} {}

    // Método para saludar (no modifica el estado)
    void saludar() const {
        std::cout << "Hola, soy " << nombre
                  << " y tengo " << edad << " años.\n";
    }

    // Método para actualizar la edad
    void cumplirAnios() {
        edad++;
    }
};

int main() {
    Persona p1("Claudia", 28);  // Inicialización tradicional
    Persona p2{"Carlos", 35};   // Inicialización uniforme
    
    p1.saludar();       // Hola, soy Claudia y tengo 28 años.
    p1.cumplirAnios();
    p1.saludar();       // Hola, soy Claudia y tengo 29 años.

    p1.saludar();       // Hola, soy Carlos y tengo 35 años.

    return 0;
}
