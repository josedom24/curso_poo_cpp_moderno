#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    void presentarse() const {
        std::cout << "Hola, me llamo " << nombre
                  << " y tengo " << edad << " años.\n";
    }

    void cumplirAnios() {
        edad++;
    }

    void cambiarNombre(const std::string& nombre) {
        this->nombre = nombre; // Diferencia entre parámetro y atributo
    }
};

int main() {
    Persona p;
    p.nombre = "Carlos";
    p.edad = 40;

    p.presentarse();       // Hola, me llamo Carlos y tengo 40 años.
    p.cumplirAnios();
    p.cambiarNombre("Carlos Alberto");
    p.presentarse();       // Hola, me llamo Carlos Alberto y tengo 41 años.
}
