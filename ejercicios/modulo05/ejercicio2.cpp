#include <iostream>

class Punto2D {
private:
    double x;
    double y;

public:
    // Constructor con valores iniciales
    Punto2D(double x_, double y_) : x(x_), y(y_) {}

    // Sobrecarga del operador + (suma de dos puntos)
    Punto2D operator+(const Punto2D& otro) const {
        return Punto2D(x + otro.x, y + otro.y);
    }

    // Sobrecarga del operador - (resta de dos puntos)
    Punto2D operator-(const Punto2D& otro) const {
        return Punto2D(x - otro.x, y - otro.y);
    }

    // Sobrecarga del operador == (comparación de igualdad)
    bool operator==(const Punto2D& otro) const {
        return (x == otro.x && y == otro.y);
    }

    // Sobrecarga del operador << (impresión en flujo)
    // Este operador debe ser externo, ya que el flujo (std::cout) está a la izquierda de la expresión.
    // Se declara como función amiga para acceder a los miembros privados.
    friend std::ostream& operator<<(std::ostream& os, const Punto2D& p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

int main() {
    Punto2D p1(3.0, 4.0);
    Punto2D p2(1.0, 2.0);

    // Uso de los operadores sobrecargados
    Punto2D suma = p1 + p2;
    Punto2D resta = p1 - p2;

    // Comparación
    if (p1 == p2)
        std::cout << "Los puntos son iguales.\n";
    else
        std::cout << "Los puntos son diferentes.\n";

    // Impresión usando operador <<
    std::cout << "p1: " << p1 << "\n";
    std::cout << "p2: " << p2 << "\n";
    std::cout << "Suma: " << suma << "\n";
    std::cout << "Resta: " << resta << "\n";

    return 0;
}
