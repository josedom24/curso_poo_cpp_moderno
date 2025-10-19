#include <iostream>

class Ejemplo {
private:
    std::string nombre;

public:
    // Constructor: se ejecuta al crear el objeto
    Ejemplo(const std::string& n) : nombre{n} {
        std::cout << "Constructor: " << nombre << " creado.\n";
    }

    // Destructor: se ejecuta automáticamente al destruir el objeto
    ~Ejemplo() {
        std::cout << "Destructor: " << nombre << " destruido.\n";
    }
};

int main() {
    std::cout << "Inicio del programa.\n";

    Ejemplo a("Objeto A"); // Se construye automáticamente
    {
        Ejemplo b("Objeto B"); // Se construye dentro de un bloque
        std::cout << "Dentro del bloque.\n";
    } // b sale de ámbito: se invoca su destructor aquí

    std::cout << "Fin del programa.\n";
    return 0; // Al finalizar main, se destruye 'a'
}
