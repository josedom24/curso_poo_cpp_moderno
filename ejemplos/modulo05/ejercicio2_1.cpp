#include <iostream>
#include <vector>

class Buffer {
private:
    std::vector<int> datos;

public:
    // Constructor por defecto
    Buffer() = default;

    // Constructor con datos iniciales
    Buffer(std::initializer_list<int> lista) : datos(lista) {}

    // Constructor de movimiento
    Buffer(Buffer&& other) noexcept : datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento\n";
    }

    // Operador de asignación por movimiento
    Buffer& operator=(Buffer&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento\n";
        }
        return *this;
    }

    void mostrar() const {
        if (datos.empty())
            std::cout << "(vacío)\n";
        else {
            for (int v : datos) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    Buffer b1{1, 2, 3};
    Buffer b2 = std::move(b1); // Invoca el constructor de movimiento
    Buffer b3;
    b3 = std::move(b2);        // Invoca el operador de asignación por movimiento

    std::cout << "b1: "; b1.mostrar(); // Estado válido pero vacío
    std::cout << "b2: "; b2.mostrar(); // Estado válido pero vacío
    std::cout << "b3: "; b3.mostrar(); // Contiene los datos originales
}
