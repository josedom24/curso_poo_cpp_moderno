#include <iostream>
#include <string>

// Definición de la clase plantilla con dos parámetros de tipo genérico
template <typename T1, typename T2>
class Par {
private:
    T1 primero;  // Primer valor de tipo T1
    T2 segundo;  // Segundo valor de tipo T2

public:
    // Constructor que inicializa ambos valores
    Par(const T1& a, const T2& b)
        : primero(a), segundo(b) {}

    // Métodos para obtener los valores
    T1 getPrimero() const {
        return primero;
    }

    T2 getSegundo() const {
        return segundo;
    }

    // Método para mostrar ambos valores por consola
    void mostrar() const {
        std::cout << "Par: (" << primero << ", " << segundo << ")\n";
    }
};

int main() {
    // Instancia con tipos diferentes: int y std::string
    Par<int, std::string> p1(1, "uno");
    p1.mostrar();  // Muestra: Par: (1, uno)

    // Instancia con tipos distintos: double y char
    Par<double, char> p2(3.14, 'π');
    p2.mostrar();  // Muestra: Par: (3.14, π)

    return 0;
}
