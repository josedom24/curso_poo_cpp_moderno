#include <iostream>
#include <variant>
#include <string>
#include <vector>

// Definimos un tipo variante que puede almacenar uno de varios tipos
using Dato = std::variant<int, std::string, double>;

int main() {
    // Creamos un vector con datos de diferentes tipos
    std::vector<Dato> datos = {
        42,
        std::string("Hola mundo"),
        3.14,
        std::string("C++ moderno"),
        7
    };

    // Recorremos el vector y aplicamos std::visit a cada elemento
    for (const auto& d : datos) {
        // Lambda genérica que imprime el valor independientemente de su tipo
        std::visit([](auto&& valor) {
            std::cout << "Valor: " << valor << '\n';
        }, d);
    }

    return 0;
}
