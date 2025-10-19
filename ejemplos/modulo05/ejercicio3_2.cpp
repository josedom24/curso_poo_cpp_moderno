#include <iostream>
#include <string>

// Clase Archivo que no permite ser copiada ni asignada
class Archivo {
public:
    // Constructor que simula abrir un archivo
    Archivo(const std::string& nombre) {
        std::cout << "Abriendo archivo: " << nombre << '\n';
    }

    // Se eliminan las operaciones de copia y asignación
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;
};

int main() {
    Archivo a("datos.txt");

    // Archivo b = a;   // Error: constructor de copia eliminado
    // Archivo c;
    // c = a;           // Error: operador de asignación eliminado
}
