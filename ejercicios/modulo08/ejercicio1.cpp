#include <iostream>
#include <string>

// Definición de una clase plantilla con un parámetro de tipo genérico T
template <typename T>
class Caja {
private:
    T valor;  // Atributo que almacena el contenido de tipo T

public:
    // Método para establecer el valor
    void setValor(const T& v) {
        valor = v;
    }

    // Método para obtener el valor almacenado
    T getValor() const {
        return valor;
    }

    // Método que muestra el contenido por consola
    void mostrar() const {
        std::cout << "Valor: " << valor << '\n';
    }
};

int main() {
    // Instanciamos la plantilla con el tipo int
    Caja<int> cajaEnteros;
    cajaEnteros.setValor(42);
    cajaEnteros.mostrar();  // Muestra: Valor: 42

    // Instanciamos la plantilla con el tipo std::string
    Caja<std::string> cajaTexto;
    cajaTexto.setValor("Plantillas en C++");
    cajaTexto.mostrar();    // Muestra: Valor: Plantillas en C++

    return 0;
}
