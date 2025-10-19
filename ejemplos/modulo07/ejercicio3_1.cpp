#include <iostream>
#include <vector>
#include <algorithm> // std::sort

int main() {
    std::vector<int> numeros = {5, 2, 8, 1, 4};

    // Orden ascendente (criterio por defecto)
    std::sort(numeros.begin(), numeros.end());

    std::cout << "Ascendente: ";
    for (int n : numeros) std::cout << n << " ";
    std::cout << "\n";

    // Orden descendente (criterio definido por una lambda)
    std::sort(numeros.begin(), numeros.end(), [](int a, int b) {
        return a > b;  // Devuelve true si 'a' debe ir antes que 'b'
    });

    std::cout << "Descendente: ";
    for (int n : numeros) std::cout << n << " ";
    std::cout << "\n";
}
