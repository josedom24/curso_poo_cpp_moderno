#include <iostream>
#include <string>

class Cadena {
private:
    std::string texto;

public:
    // Método fluido: retorna una referencia al propio objeto
    Cadena& agregar(const std::string& s) {
        texto += s;
        return *this;
    }

    void imprimir() const {
        std::cout << texto << "\n";
    }
};

int main() {
    Cadena c;
    // Encadenamiento fluido
    c.agregar("Hola, ").agregar("mundo").agregar("!");
    c.imprimir();  // Imprime: Hola, mundo!
}
