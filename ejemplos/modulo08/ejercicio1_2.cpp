#include <iostream>
#include <string>

// Definición de la plantilla
template <typename T>
class Caja {
private:
    T contenido;  // Tipo genérico

public:
    void setContenido(const T& valor) { contenido = valor; }
    T getContenido() const { return contenido; }
};

int main() {
    // Instanciación con int
    Caja<int> cajaEntera;
    cajaEntera.setContenido(10);
    std::cout << "Entero: " << cajaEntera.getContenido() << "\n";

    // Instanciación con std::string
    Caja<std::string> cajaTexto;
    cajaTexto.setContenido("Texto genérico");
    std::cout << "Texto: " << cajaTexto.getContenido() << "\n";

    return 0;
}
