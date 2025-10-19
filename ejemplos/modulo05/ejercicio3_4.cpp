#include <iostream>
#include <utility>

class RecursoControlado {
public:
    RecursoControlado() { std::cout << "Creado\n"; }
    ~RecursoControlado() { std::cout << "Destruido\n"; }

    // No copiable
    RecursoControlado(const RecursoControlado&) = delete;
    RecursoControlado& operator=(const RecursoControlado&) = delete;

    // Movible
    RecursoControlado(RecursoControlado&&) noexcept {
        std::cout << "Movido (constructor)\n";
    }

    RecursoControlado& operator=(RecursoControlado&&) noexcept {
        std::cout << "Movido (asignación)\n";
        return *this;
    }
};

int main() {
    RecursoControlado a;
    RecursoControlado b = std::move(a); // movimiento permitido
    // RecursoControlado c = b;         // Error: copia prohibida
}
