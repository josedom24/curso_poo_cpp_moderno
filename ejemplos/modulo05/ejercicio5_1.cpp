#include <iostream>
#include <stdexcept>

class Punto {
private:
    int _x, _y;

public:
    Punto(int x, int y) : _x(x), _y(y) {}

    // Sobrecarga de la suma (+)
    Punto operator+(const Punto& otro) const {
        return Punto(_x + otro._x, _y + otro._y);
    }

    // Sobrecarga de la resta (-)
    Punto operator-(const Punto& otro) const {
        return Punto(_x - otro._x, _y - otro._y);
    }

    // Multiplicación por escalar (*)
    Punto operator*(int escalar) const {
        return Punto(_x * escalar, _y * escalar);
    }

    // División por escalar (/)
    Punto operator/(int escalar) const {
        if (escalar == 0) {
            throw std::invalid_argument("División por cero");
        }
        return Punto(_x / escalar, _y / escalar);
    }

    // Comparación de igualdad (==)
    bool operator==(const Punto& otro) const {
        return _x == otro._x && _y == otro._y;
    }

    // Comparación de desigualdad (!=)
    bool operator!=(const Punto& otro) const {
        return !(*this == otro);
    }

    // Operador de salida (<<) – debe ser función externa
    friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
        os << "(" << p._x << ", " << p._y << ")";
        return os;
    }
};

int main() {
    Punto p1(3, 4);
    Punto p2(1, 2);

    Punto suma = p1 + p2;
    Punto resta = p1 - p2;
    Punto multiplicacion = p1 * 2;
    Punto division = p1 / 2;

    std::cout << "Suma: " << suma << "\n";
    std::cout << "Resta: " << resta << "\n";
    std::cout << "Multiplicación: " << multiplicacion << "\n";
    std::cout << "División: " << division << "\n";

    if (p1 != p2) {
        std::cout << "p1 y p2 son diferentes\n";
    }
}
