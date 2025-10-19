#include <iostream>
#include <string>

class Persona {
public:
    // Atributos públicos
    std::string nombre;
    int edad;

    // Método público
    void saludar() {
        std::cout << "Hola, me llamo " << nombre
                  << " y tengo " << edad << " años.\n";
    }
};

int main() {
    Persona p1;
    p1.nombre = "Ana";
    p1.edad = 30;

    Persona p2;
    p2.nombre = "Luis";
    p2.edad = 25;

    p1.saludar();  // Hola, me llamo Ana y tengo 30 años.
    p2.saludar();  // Hola, me llamo Luis y tengo 25 años.

    return 0;
}
