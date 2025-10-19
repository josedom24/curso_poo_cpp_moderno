#include <iostream>
#include <memory>
#include <vector>

class Buffer {
private:
    std::vector<int> datos;

public:
    Buffer(std::initializer_list<int> lista) : datos(lista) {}

    // Método de clonación
    std::unique_ptr<Buffer> clone() const {
        return std::make_unique<Buffer>(*this);  // Copia profunda
    }

    void mostrar() const {
        for (int v : datos) std::cout << v << " ";
        std::cout << "\n";
    }
};

int main() {
    Buffer original{1, 2, 3};
    auto copia = original.clone();  // Clonación profunda

    std::cout << "Original: ";
    original.mostrar();
    std::cout << "Copia:    ";
    copia->mostrar();
}
