#include <iostream>
#include <functional>

void ejecutarOperacion(int a, int b, std::function<int(int, int)> operacion) {
    std::cout << "Resultado: " << operacion(a, b) << '\n';
}

int main() {
    auto suma = [](int x, int y) { return x + y; };
    auto resta = [](int x, int y) { return x - y; };

    ejecutarOperacion(5, 3, suma);   // Resultado: 8
    ejecutarOperacion(5, 3, resta);  // Resultado: 2
}
