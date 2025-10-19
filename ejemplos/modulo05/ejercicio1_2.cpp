#include <iostream>
#include <vector>
#include <memory>

// Copia superficial: comparte el mismo recurso
class ContenedorSuperficial {
public:
    std::vector<int>* datos;  // No posee la memoria

    ContenedorSuperficial(std::vector<int>* ptr) : datos(ptr) {}

    void mostrar() const {
        for (int i : *datos) std::cout << i << " ";
        std::cout << "\n";
    }
};

// Copia profunda: mantiene su propia copia de los datos
class ContenedorProfundo {
public:
    std::vector<int> datos;

    ContenedorProfundo(const std::vector<int>& v) : datos(v) {}

    void mostrar() const {
        for (int i : datos) std::cout << i << " ";
        std::cout << "\n";
    }
};

int main() {
    std::vector<int> base1 = {1, 2, 3};
    std::vector<int> base2 = {1, 2, 3};

    std::cout << "== Copia superficial ==\n";
    ContenedorSuperficial s1(&base1);
    ContenedorSuperficial s2 = s1; // Copia superficial: comparten el puntero
    base1[1] = 99;

    s1.mostrar(); // 1 99 3
    s2.mostrar(); // 1 99 3 (comparten el mismo vector)

    std::cout << "\n== Copia profunda ==\n";
    ContenedorProfundo p1(base2);
    ContenedorProfundo p2 = p1; // Copia profunda: copia independiente
    base2[1] = 42;

    p1.mostrar(); // 1 2 3
    p2.mostrar(); // 1 2 3 (no se ve afectado)
}
