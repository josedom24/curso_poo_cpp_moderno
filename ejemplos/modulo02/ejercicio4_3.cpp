#include <iostream>
#include <string>

class Archivo {
private:
    std::string nombre;

public:
    // Constructor por defecto: generado automáticamente
    Archivo() = default;

    // Constructor con parámetro
    Archivo(const std::string& n) : nombre{n} {}

    // Destructor automático
    ~Archivo() = default;

    // Método para mostrar información
    void mostrar() const {
        std::cout << "Archivo: " << nombre << '\n';
    }

    // Ejemplo: prohibimos la creación de objetos con un número
    Archivo(int) = delete;
};

int main() {
    Archivo a1("datos.txt"); // OK
    a1.mostrar();

    Archivo a2;              // OK: usa el constructor por defecto
    // Archivo a3(42);       // Error: constructor eliminado (=delete)

    return 0;
}
