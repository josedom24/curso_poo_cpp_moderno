#include <iostream>
#include <vector>
#include <optional>

// Busca un número en un vector y devuelve un std::optional<int>
std::optional<int> buscar(const std::vector<int>& datos, int objetivo) {
    for (int valor : datos) {
        if (valor == objetivo)
            return valor;          // Valor encontrado
    }
    return std::nullopt;           // Sin valor
}

int main() {
    std::vector<int> numeros = {3, 5, 7, 9};

    auto resultado = buscar(numeros, 5);

    if (resultado) {
        std::cout << "Encontrado: " << *resultado << '\n';
    }

    std::cout << "Valor o -1: " << resultado.value_or(-1) << '\n';

    auto resultado2 = buscar(numeros, 100);
    if (!resultado2) {
        std::cout << "No encontrado.\n";
    }

    std::cout << "Resultado2 con valor por defecto: "
              << resultado2.value_or(-1) << '\n';
}
