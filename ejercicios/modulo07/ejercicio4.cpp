#include <iostream>
#include <vector>
#include <functional>

// Functor con estado interno
class Multiplicador {
public:
    explicit Multiplicador(int factor) : factor_(factor) {}

    int operator()(int valor) const {
        return valor * factor_;
    }

private:
    int factor_;
};

// Función genérica que aplica una operación a cada elemento
void aplicarOperacion(const std::vector<int>& datos,
                      const std::function<int(int)>& operacion) {
    for (int x : datos)
        std::cout << operacion(x) << " ";
    std::cout << '\n';
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 4};

    Multiplicador por2(2);
    Multiplicador por10(10);

    // Lambda sin estado: eleva al cuadrado
    auto cuadrado = [](int x) { return x * x; };

    std::cout << "Multiplicar por 2: ";
    aplicarOperacion(numeros, por2); // Usa functor con estado

    std::cout << "Multiplicar por 10: ";
    aplicarOperacion(numeros, por10); // Usa otro functor con distinto estado

    std::cout << "Elevar al cuadrado: ";
    aplicarOperacion(numeros, cuadrado); // Usa lambda sin estado
}
