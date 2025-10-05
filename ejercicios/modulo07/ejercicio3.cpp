#include <iostream>
#include <functional>

class Procesador {
public:
    // Establece una operación configurable
    void setOperacion(std::function<int(int, int)> op) {
        operacion_ = op;
    }

    // Ejecuta la operación configurada
    int ejecutar(int a, int b) const {
        if (!operacion_) {
            std::cerr << "Error: No se ha configurado una operación.\n";
            return 0;
        }
        return operacion_(a, b);
    }

private:
    std::function<int(int, int)> operacion_; // Comportamiento inyectable
};

int main() {
    Procesador p;

    // Inyección de comportamiento con distintas lambdas
    p.setOperacion([](int x, int y) { return x + y; });
    std::cout << "Suma: " << p.ejecutar(4, 5) << "\n";

    p.setOperacion([](int x, int y) { return x * y; });
    std::cout << "Producto: " << p.ejecutar(4, 5) << "\n";

    p.setOperacion([](int x, int y) { return (x > y) ? x : y; });
    std::cout << "Mayor: " << p.ejecutar(4, 5) << "\n";
}
