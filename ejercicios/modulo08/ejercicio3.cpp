#include <iostream>
#include <string>

// Plantilla general de la clase Contenedor
template <typename T>
class Contenedor {
public:
    // Método genérico para mostrar el tipo de contenido
    void mostrar() const {
        std::cout << "Tipo genérico\n";
    }
};

// Especialización total para el tipo std::string
template <>
class Contenedor<std::string> {
public:
    // Método especializado para cadenas de texto
    void mostrar() const {
        std::cout << "Tipo texto\n";
    }
};

int main() {
    // Instancia con un tipo genérico (int)
    Contenedor<int> c1;
    c1.mostrar();  // Muestra: Tipo genérico

    // Instancia con tipo std::string (usa la especialización)
    Contenedor<std::string> c2;
    c2.mostrar();  // Muestra: Tipo texto

    return 0;
}
