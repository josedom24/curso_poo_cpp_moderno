#include <iostream>
#include <variant>

int main() {
    std::variant<int, std::string> dato = "Hola";

    std::visit([](auto&& valor) {
        std::cout << "Valor: " << valor << '\n';
    }, dato);
}
