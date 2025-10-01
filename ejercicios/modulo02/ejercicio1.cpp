#include <iostream>
#include <string>

class Rectangulo {
private:
    // Atributos privados (principio de encapsulamiento):
    // Cada objeto tiene su propia base y altura
    double base;
    double altura;

public:
    // Constructor con lista de inicialización:
    // Inicializa directamente los atributos en lugar de asignarlos luego.
    // Esto es más eficiente y obligatorio en casos como atributos const o referencias.
    Rectangulo(double b, double h) : base{b}, altura{h} {
        if (b < 0 || h < 0) {
            std::cerr << "Error: base y altura deben ser no negativas.\n";
            base = 0;
            altura = 0;
        }
    }

    // Getter de base (marcado como const porque no modifica el objeto)
    double getBase() const {
        return base;
    }

    // Setter de base con validación: protege la invariancia del objeto
    void setBase(double b) {
        if (b >= 0) {
            base = b;
        }
    }

    // Getter de altura
    double getAltura() const {
        return altura;
    }

    // Setter de altura con validación
    void setAltura(double h) {
        if (h >= 0) {
            altura = h;
        }
    }

    // Método de solo lectura: calcula el área
    double area() const {
        return base * altura;
    }

    // Método de solo lectura: calcula el perímetro
    double perimetro() const {
        return 2 * (base + altura);
    }

    // Método público que muestra el estado interno del objeto:
    // Accede a los atributos encapsulados a través de la propia clase
    void mostrar() const {
        std::cout << "Rectángulo [Base: " << base
                  << ", Altura: " << altura
                  << ", Área: " << area()
                  << ", Perímetro: " << perimetro() << "]\n";
    }
};

int main() {
    // Se crea un objeto usando el constructor parametrizado
    Rectangulo r1{5.0, 3.0};

    // Se accede a sus datos de forma controlada (principio de encapsulamiento)
    r1.mostrar();

    // Se usan los setters para modificar atributos con validación
    r1.setBase(7.0);
    r1.setAltura(4.0);

    std::cout << "Después de modificar dimensiones:\n";
    r1.mostrar();

    return 0; // El programa finaliza y el objeto r1 se destruye automáticamente (RAII)
}
