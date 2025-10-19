#include <iostream>
#include <vector>
#include <algorithm>

// Función plantilla genérica para imprimir un vector
template <typename T>
void imprimir(const std::vector<T>& v) {
    for (const T& val : v)
        std::cout << val << " ";
    std::cout << '\n';
}

int main() {
    // Contenedor genérico
    std::vector<int> numeros = {4, 2, 8, 1};

    // Algoritmo genérico: ordena la secuencia
    std::sort(numeros.begin(), numeros.end());

    // Iteradores y función plantilla
    imprimir(numeros); // Salida: 1 2 4 8

    return 0;
}
