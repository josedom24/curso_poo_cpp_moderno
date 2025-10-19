#include <iostream>
#include <vector>

class Buffer {
private:
    std::vector<int> datos;  // Contenedor gestionado automáticamente

public:
    // Constructor por defecto
    Buffer() = default;

    // Constructor con datos iniciales
    Buffer(std::initializer_list<int> lista) : datos(lista) {}

    // Constructor de copia
    Buffer(const Buffer& other) : datos(other.datos) {
        std::cout << "Constructor de copia\n";
    }

    // Operador de asignación por copia
    Buffer& operator=(const Buffer& other) {
        if (this != &other) { // Evitar autoasignación
            datos = other.datos;
            std::cout << "Asignación por copia\n";
        }
        return *this;
    }

    void mostrar() const {
        for (int v : datos) std::cout << v << " ";
        std::cout << "\n";
    }
};

int main() {
    Buffer b1{1, 2, 3};
    Buffer b2 = b1;   // Llama al constructor de copia
    Buffer b3;
    b3 = b1;          // Llama al operador de asignación por copia

    b1.mostrar();
    b2.mostrar();
    b3.mostrar();
}
