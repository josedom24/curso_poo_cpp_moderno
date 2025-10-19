#include <iostream>
#include <string>

class Calculadora {
private:
    // Atributo estático: compartido por todas las instancias
    static int totalOperaciones;

    // Atributo no estático: pertenece a cada objeto
    std::string nombreUsuario;

public:
    // Constructor: asigna un nombre al usuario
    Calculadora(const std::string& nombre) : nombreUsuario(nombre) {}

    // Método estático: no tiene puntero 'this'
    // No puede acceder a 'nombreUsuario' (miembro no estático)
    static int suma(int a, int b) {
        ++totalOperaciones;  // puede acceder a miembros estáticos
        return a + b;
    }

    static int resta(int a, int b) {
        ++totalOperaciones;
        return a - b;
    }

    static int getTotalOperaciones() {
        return totalOperaciones;
    }

    // Método no estático: puede acceder tanto a miembros normales como estáticos
    void mostrarResumen() const {
        std::cout << "Usuario: " << nombreUsuario << "\n";
        std::cout << "Total de operaciones realizadas: "
                  << totalOperaciones << "\n";
    }
};

// Definición del atributo estático (una sola copia para toda la clase)
int Calculadora::totalOperaciones = 0;

int main() {
    // Los métodos estáticos pueden llamarse sin crear objetos
    std::cout << "Suma: " << Calculadora::suma(3, 4) << "\n";    // 7
    std::cout << "Resta: " << Calculadora::resta(10, 2) << "\n"; // 8

    // Creamos dos objetos de Calculadora con distintos usuarios
    Calculadora c1("Ana");
    Calculadora c2("Luis");

    // Ambos comparten el mismo atributo estático totalOperaciones
    std::cout << "\nTotal de operaciones (vía clase): "
              << Calculadora::getTotalOperaciones() << "\n";

    // Cada objeto tiene su propio 'nombreUsuario'
    std::cout << "\nResumen individual:\n";
    c1.mostrarResumen();
    c2.mostrarResumen();

    // No se puede hacer esto dentro de un método estático:
    // nombreUsuario = "nuevo";  // Error: 'this' no existe en métodos estáticos
}
