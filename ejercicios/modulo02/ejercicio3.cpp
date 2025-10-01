#include <iostream>
#include <string>

class Empleado {
private:
    // Atributos privados: principio de encapsulamiento
    std::string nombre;
    double salario;

    // Atributo estático: compartido por TODAS las instancias
    // Representa el total de empleados creados
    inline static int totalEmpleados = 0;  
    // Con C++17 usamos 'inline static' para evitar la definición fuera de la clase

public:
    // Constructor parametrizado con lista de inicialización
    Empleado(const std::string& n, double s) 
        : nombre{n}, salario{s} {
        if (s < 0) {
            std::cerr << "Error: el salario no puede ser negativo.\n";
            salario = 0.0;
        }
        ++totalEmpleados; // Cada vez que se crea un objeto, el contador aumenta
    }

    // Getter del nombre (const porque no modifica el estado)
    const std::string& getNombre() const {
        return nombre;
    }

    // Getter del salario (const)
    double getSalario() const {
        return salario;
    }

    // Setter con validación: evita asignar un salario negativo
    void setSalario(double nuevoSalario) {
        if (nuevoSalario >= 0) {
            salario = nuevoSalario;
        }
    }

    // Método estático: no depende de un objeto, accede a atributo estático
    static int getTotalEmpleados() {
        return totalEmpleados;
    }

    // Método para mostrar información del empleado
    void mostrar() const {
        std::cout << "Empleado: " << nombre 
                  << ", Salario: $" << salario << "\n";
    }
};

int main() {
    // Se crean objetos de la clase Empleado
    Empleado e1("Ana", 1200.0);
    Empleado e2("Luis", 1500.0);

    e1.mostrar();
    e2.mostrar();

    // Modificación controlada del salario (usando setter con validación)
    e1.setSalario(1300.0);
    e1.mostrar();

    // Llamada a un método estático: no necesita un objeto
    std::cout << "Total de empleados creados: " 
              << Empleado::getTotalEmpleados() << "\n";

    return 0; // Al finalizar, los objetos se destruyen automáticamente (RAII)
}
