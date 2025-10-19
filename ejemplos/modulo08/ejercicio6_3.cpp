#include <iostream>
#include <variant>
#include <string>
#include <vector>

// Tipo variante que puede contener uno de varios tipos
using Evento = std::variant<int, std::string, double>;

// Visitor con sobrecarga de funciones
class ProcesadorEvento {
public:
    void operator()(int codigo) const {
        std::cout << "Código de control recibido: " << codigo << '\n';
    }

    void operator()(const std::string& mensaje) const {
        std::cout << "Mensaje recibido: \"" << mensaje << "\"\n";
    }

    void operator()(double lectura) const {
        std::cout << "Lectura de sensor: " << lectura << " unidades\n";
    }
};

int main() {
    std::vector<Evento> eventos = {
        42,
        std::string("Arranque del sistema"),
        23.7,
        std::string("Advertencia: temperatura alta"),
        0,
        18.2
    };

    // Procesar cada evento según su tipo
    for (const auto& evento : eventos) {
        std::visit(ProcesadorEvento{}, evento);
    }

    return 0;
}
