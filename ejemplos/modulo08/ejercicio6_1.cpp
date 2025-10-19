#include <iostream>
#include <variant>

int main() {
    // Un std::variant que puede contener un int o un float
    std::variant<int, float> valor;

    valor = 10;      // Contiene un int
    std::cout << "Valor entero: " << std::get<int>(valor) << '\n';

    valor = 3.14f;   // Ahora contiene un float
    std::cout << "Valor flotante: " << std::get<float>(valor) << '\n';

    return 0;
}
