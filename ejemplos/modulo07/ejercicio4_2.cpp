#include <iostream>
#include <functional>

class Procesador {
public:
    void setOperacion(std::function<int(int, int)> op) {
        operacion_ = op;
    }

    int procesar(int a, int b) const {
        return operacion_(a, b);
    }

private:
    std::function<int(int, int)> operacion_;
};

int main() {
    Procesador p;

    // Configurar la operación de multiplicar
    p.setOperacion([](int x, int y) { return x * y; });
    std::cout << "Multiplicación: " << p.procesar(4, 5) << "\n";

    // Cambiar el comportamiento dinámicamente
    p.setOperacion([](int x, int y) { return x + y; });
    std::cout << "Suma: " << p.procesar(4, 5) << "\n";
}
