#include <iostream>
#include <string>

class Contador {
private:
    static int totalObjetos;             // no const: debe definirse fuera
    static const int version = 1;        // const + integral: puede definirse aquí
    static const double PI;              // const + no integral: definir fuera
    static const std::string nombreClase; // const + no integral: definir fuera

public:
    Contador() {
        ++totalObjetos;
    }

    static int getTotalObjetos() {
        return totalObjetos;
    }

    static void mostrarInfo() {
        std::cout << "Clase: " << nombreClase << "\n";
        std::cout << "Versión: " << version << "\n";
        std::cout << "Valor de PI: " << PI << "\n";
    }
};

// Definiciones de los atributos estáticos
int Contador::totalObjetos = 0;
const double Contador::PI = 3.14159;
const std::string Contador::nombreClase = "Contador";

int main() {
    Contador a, b, c;
    Contador::mostrarInfo();
    std::cout << "Total de objetos creados: "
              << Contador::getTotalObjetos() << "\n";  // 3
}
