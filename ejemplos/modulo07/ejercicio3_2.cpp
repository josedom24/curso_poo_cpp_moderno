#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> numeros = {1, 4, 7, 2, 9, 5};
    int umbral = 5;

    // Lambda que determina si un número es mayor que el umbral
    auto mayorQue = [umbral](int x) {
        return x > umbral;
    };

    // Lambda que determina si un número es menor que el umbral
    auto menorQue = [umbral](int x) {
        return x < umbral;
    };

    // Buscar el primer número mayor que el umbral
    auto it1 = std::find_if(numeros.begin(), numeros.end(), mayorQue);
    if (it1 != numeros.end())
        std::cout << "Primer número mayor que " << umbral << ": " << *it1 << "\n";

    // Buscar el primer número menor que el umbral
    auto it2 = std::find_if(numeros.begin(), numeros.end(), menorQue);
    if (it2 != numeros.end())
        std::cout << "Primer número menor que " << umbral << ": " << *it2 << "\n";
}
