#include <iostream>
#include <string>

// Clase base: Empleado
// Contiene los atributos y comportamientos comunes a todos los empleados.
class Empleado {
protected:
    std::string nombre;  // Atributo común

public:
    // Constructor que inicializa el nombre
    Empleado(const std::string& n) : nombre(n) {}

    // Método que muestra la información básica del empleado
    void mostrarInfo() const {
        std::cout << "Empleado: " << nombre << std::endl;
    }
};

// Clase derivada: Programador
// Hereda de Empleado y añade un atributo específico: lenguaje.
class Programador : public Empleado {
private:
    std::string lenguaje;

public:
    // Constructor: inicializa el nombre (de la base) y el lenguaje
    Programador(const std::string& n, const std::string& l)
        : Empleado(n), lenguaje(l) {}

    // Método que redefine la información mostrada
    void mostrarInfo() const {
        std::cout << "Programador: " << nombre
                  << " | Lenguaje principal: " << lenguaje << std::endl;
    }
};

// Clase derivada: Disenador
// Hereda de Empleado y añade un atributo específico: herramienta.
class Disenador : public Empleado {
private:
    std::string herramienta;

public:
    // Constructor: inicializa el nombre (de la base) y la herramienta
    Disenador(const std::string& n, const std::string& h)
        : Empleado(n), herramienta(h) {}

    // Método que redefine la información mostrada
    void mostrarInfo() const {
        std::cout << "Diseñador: " << nombre
                  << " | Herramienta favorita: " << herramienta << std::endl;
    }
};

int main() {
    // Creamos un programador y un diseñador
    Programador prog("Laura", "C++");
    Disenador dis("Carlos", "Photoshop");

    // Mostramos la información de cada empleado
    prog.mostrarInfo();
    dis.mostrarInfo();

    return 0;
}
