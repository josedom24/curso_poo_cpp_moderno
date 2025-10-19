#include <iostream>
#include <string>

// Clase base
class Animal {
private:
    std::string nombre;

public:
    Animal(const std::string& n) : nombre{n} {}

    void mostrarNombre() const {
        std::cout << "Nombre: " << nombre << std::endl;
    }
};

// Clase derivada
class Perro : public Animal {
private:
    std::string raza;

public:
    Perro(const std::string& n, const std::string& r)
        : Animal{n}, raza{r} {}

    void mostrar() const {
        mostrarNombre();  // Método heredado de Animal
        std::cout << "Raza: " << raza << std::endl;
    }
};

int main() {
    Perro p("Toby", "Labrador");
    p.mostrar();
    return 0;
}
