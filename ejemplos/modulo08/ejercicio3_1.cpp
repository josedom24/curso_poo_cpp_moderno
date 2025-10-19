#include <iostream>
#include <string>

// Versión genérica
template <typename T>
class Caja {
public:
    void mostrar(const T& valor) const {
        std::cout << "Contenido genérico: " << valor << '\n';
    }
};

// Especialización total para std::string
template <>
class Caja<std::string> {
public:
    void mostrar(const std::string& valor) const {
        std::cout << "Texto: \"" << valor << "\"\n";
    }
};

int main() {
    Caja<int> c1;
    c1.mostrar(42);              // Contenido genérico: 42

    Caja<std::string> c2;
    c2.mostrar("Hola mundo");    // Texto: "Hola mundo"

    return 0;
}
