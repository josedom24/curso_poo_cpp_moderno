#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor
    Persona(const std::string& n, int e) : nombre{n}, edad{e} {}

    // Método constante: no modifica el estado del objeto
    void presentarse() const {
        std::cout << "Hola, soy " << nombre << " y tengo " << edad << " años.\n";
    }

    // Método no constante: permite modificar el atributo
    void setNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }
};

int main() {
    Persona p1("Carlos", 30);  // Objeto normal
    p1.presentarse();           // OK
    p1.setNombre("Carlos Alberto");
    p1.presentarse();           // Se modificó el nombre

    const Persona p2("Lucía", 25);  // Objeto constante
    p2.presentarse();                // OK: método const
    // p2.setNombre("Ana");          // Error: no se puede modificar un objeto const

    return 0;
}
