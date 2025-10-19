#include <iostream>
#include <string>

class Mensaje {
private:
    std::string texto_;

public:
    // Constructor para inicializar el texto del mensaje
    Mensaje(const std::string& texto) : texto_(texto) {}

    // Sobrecarga de métodos mostrar()

    // Versión sin parámetros
    void mostrar() const {
        std::cout << "Mensaje: " << texto_ << std::endl;
    }

    // Versión con parámetro entero: repite el mensaje varias veces
    void mostrar(int veces) const {
        for (int i = 0; i < veces; ++i) {
            std::cout << "Mensaje (" << i + 1 << "): " << texto_ << std::endl;
        }
    }

    // Versión con parámetro string: añade un prefijo al mensaje
    void mostrar(const std::string& prefijo) const {
        std::cout << prefijo << ": " << texto_ << std::endl;
    }
};

int main() {
    Mensaje m("Hola mundo");

    m.mostrar();                   // Llama a la versión sin parámetros
    m.mostrar(3);                   // Llama a la versión con un entero
    m.mostrar("Aviso importante");  // Llama a la versión con un string

    return 0;
}
