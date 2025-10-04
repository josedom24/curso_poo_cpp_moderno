#include <iostream>
#include <vector>
#include <utility>  // Para std::move

// Clase Buffer: gestiona un recurso (un vector de enteros)
// e ilustra la diferencia entre copia y movimiento.
class Buffer {
private:
    std::vector<int> datos;  // Recurso interno gestionado automáticamente

public:
    // Constructor por defecto
    Buffer() {
        std::cout << "Constructor por defecto\n";
    }

    // Constructor con lista de inicialización
    Buffer(std::initializer_list<int> valores) : datos(valores) {
        std::cout << "Constructor con lista de inicialización\n";
    }

    // Constructor de copia (duplica los datos)
    Buffer(const Buffer& otro) : datos(otro.datos) {
        std::cout << "Constructor de copia\n";
    }

    // Operador de asignación por copia (duplica los datos)
    Buffer& operator=(const Buffer& otro) {
        std::cout << "Asignación por copia\n";
        if (this != &otro) {  // Evitar autoasignación
            datos = otro.datos;
        }
        return *this;
    }

    // Constructor de movimiento (transfiere los datos)
    Buffer(Buffer&& otro) noexcept : datos(std::move(otro.datos)) {
        std::cout << "Constructor de movimiento\n";
    }

    // Operador de asignación por movimiento (transfiere los datos)
    Buffer& operator=(Buffer&& otro) noexcept {
        std::cout << "Asignación por movimiento\n";
        if (this != &otro) {  // Evitar autoasignación
            datos = std::move(otro.datos);
        }
        return *this;
    }

    // Método para mostrar el contenido del vector
    void mostrar() const {
        std::cout << "[ ";
        for (int v : datos) {
            std::cout << v << " ";
        }
        std::cout << "]\n";
    }
};

// Programa principal
int main() {
    std::cout << "== Creación inicial ==\n";
    Buffer b1{1, 2, 3, 4, 5};  // Constructor con lista de inicialización
    b1.mostrar();

    std::cout << "\n== Copia de objeto ==\n";
    Buffer b2 = b1;  // Constructor de copia
    b2.mostrar();

    std::cout << "\n== Asignación por copia ==\n";
    Buffer b3;
    b3 = b1;  // Operador de asignación por copia
    b3.mostrar();

    std::cout << "\n== Movimiento de objeto ==\n";
    Buffer b4 = std::move(b1);  // Constructor de movimiento
    b4.mostrar();

    std::cout << "\n== Asignación por movimiento ==\n";
    Buffer b5;
    b5 = std::move(b4);  // Operador de asignación por movimiento
    b5.mostrar();

    std::cout << "\n== Fin del programa ==\n";
    return 0;
}
