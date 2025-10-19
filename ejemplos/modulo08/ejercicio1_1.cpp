#include <iostream>
#include <string>

// Definición de una clase plantilla con un parámetro de tipo T
template <typename T>
class Contenedor {
private:
    T valor;  // Atributo genérico del tipo T

public:
    void setValor(const T& v) { valor = v; }  // Asigna el valor
    T getValor() const { return valor; }      // Devuelve el valor almacenado
};

int main() {
    // Instanciación con tipo int
    Contenedor<int> entero;
    entero.setValor(42);
    std::cout << "Valor entero: " << entero.getValor() << "\n";

    // Instanciación con tipo std::string
    Contenedor<std::string> texto;
    texto.setValor("Hola mundo");
    std::cout << "Valor de texto: " << texto.getValor() << "\n";

    return 0;
}
