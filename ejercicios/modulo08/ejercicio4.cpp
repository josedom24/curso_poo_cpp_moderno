#include <iostream>
#include <vector>
#include <optional>

// Función que busca un número en el vector y devuelve un std::optional<int>
std::optional<int> buscar(const std::vector<int>& v, int objetivo) {
    // Recorremos el vector buscando el valor
    for (int valor : v) {
        if (valor == objetivo) {
            return valor;  // Si lo encuentra, devuelve el valor (estado ocupado)
        }
    }
    return std::nullopt;    // Si no lo encuentra, devuelve "sin valor"
}

int main() {
    std::vector<int> numeros = {3, 5, 7, 9};

    // Caso 1: el valor está presente en el vector
    std::optional<int> resultado1 = buscar(numeros, 5);

    if (resultado1.has_value()) {
        std::cout << "Valor encontrado: " << resultado1.value() << '\n';
    }

    // Caso 2: el valor no está presente
    std::optional<int> resultado2 = buscar(numeros, 10);

    // Usamos value_or() para proporcionar un valor por defecto si está vacío
    std::cout << "Resultado: " << resultado2.value_or(-1) << '\n';

    return 0;
}
