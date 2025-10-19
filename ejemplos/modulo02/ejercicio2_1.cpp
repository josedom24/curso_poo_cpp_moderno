#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor: inicializa los atributos de la clase
    Persona(const std::string& n, int e)
        : nombre(n), edad(e) {}

    // Método que muestra la información del objeto (sin modificarlo)
    void presentarse() const {
        std::cout << "Hola, me llamo " << nombre
                  << " y tengo " << edad << " años.\n";
    }

    // Método que incrementa la edad (paso de parámetro por valor)
    void cumplirAnios(int anios) {
        edad += anios;
    }

    // Método que modifica el nombre (paso por referencia constante)
    void cambiarNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    // Método que devuelve una copia del nombre (retorno por valor)
    std::string obtenerNombre() const {
        return nombre;
    }

    // Método que devuelve una referencia constante (sin copiar ni modificar)
    const std::string& nombreConstante() const {
        return nombre;
    }
};

int main() {
    Persona p("Ana", 30);

    p.presentarse();                   // Hola, me llamo Ana y tengo 30 años.
    p.cumplirAnios(1);                 // Paso por valor
    p.cambiarNombre("Ana López");      // Paso por referencia constante

    std::string copia = p.obtenerNombre();      // Retorno por valor
    const std::string& ref = p.nombreConstante(); // Retorno por referencia const

    std::cout << "Nombre copiado: " << copia << '\n';
    std::cout << "Referencia const: " << ref << '\n';

    p.presentarse(); // Hola, me llamo Ana López y tengo 31 años.
}
