#include <iostream>
#include <functional>
#include <cmath>

// Clase que encapsula un comportamiento inyectable
class Calculadora {
public:
    using Operacion = std::function<int(int, int)>;

    explicit Calculadora(Operacion op) : operacion_(std::move(op)) {}

    int calcular(int a, int b) const {
        return operacion_(a, b);
    }

private:
    Operacion operacion_;
};

// Functor con estado opcional: calcula potencias
class Potencia {
public:
    int operator()(int base, int exponente) const {
        return static_cast<int>(std::pow(base, exponente));
    }
};

int main() {
    // Lambdas como comportamientos inyectables
    auto sumar = [](int a, int b) { return a + b; };
    auto maximo = [](int a, int b) { return (a > b) ? a : b; };

    // Functor
    Potencia potencia;

    // Inyección de comportamiento mediante composición
    Calculadora calcSuma(sumar);
    Calculadora calcMax(maximo);
    Calculadora calcPot(potencia);

    std::cout << "5 + 3 = " << calcSuma.calcular(5, 3) << '\n';
    std::cout << "Máximo de (5, 3) = " << calcMax.calcular(5, 3) << '\n';
    std::cout << "5 ^ 3 = " << calcPot.calcular(5, 3) << '\n';
}
