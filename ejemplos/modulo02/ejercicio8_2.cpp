#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Getters: devuelven por referencia const para evitar copias
    const std::string& getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    // Setters con validación
    void setNombre(const std::string& nuevoNombre) { nombre = nuevoNombre; }

    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 0) {
            edad = nuevaEdad;
        }
    }
};

int main() {
    Persona p;
    p.setNombre("Lucía");
    p.setEdad(28);

    std::cout << p.getNombre() << " tiene " << p.getEdad() << " años.\n";

    return 0;
}
