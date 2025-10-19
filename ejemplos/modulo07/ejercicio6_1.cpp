#include <functional>
#include <iostream>

class Calculadora {
public:
    using Operacion = std::function<int(int, int)>;

    explicit Calculadora(Operacion op) : operacion_(op) {}

    int ejecutar(int a, int b) const {
        return operacion_(a, b);
    }

private:
    Operacion operacion_;
};

int main() {
    Calculadora suma([](int a, int b) { return a + b; });
    Calculadora producto([](int a, int b) { return a * b; });

    std::cout << "5 + 3 = " << suma.ejecutar(5, 3) << "\n";
    std::cout << "5 * 3 = " << producto.ejecutar(5, 3) << "\n";
}
