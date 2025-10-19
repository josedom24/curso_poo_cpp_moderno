#include <iostream>
#include <optional>

// Función que puede devolver un número o ningún valor
std::optional<int> obtenerNumero(bool exito) {
    if (exito)
        return 42;           // Valor presente
    else
        return std::nullopt; // Sin valor
}

int main() {
    // Caso 1: la función devuelve un valor
    std::optional<int> resultado1 = obtenerNumero(true);

    if (resultado1.has_value()) {
        std::cout << "Valor encontrado: " << resultado1.value() << '\n';
    }

    // También puede usarse directamente como condición lógica
    if (resultado1) {
        std::cout << "Acceso con *resultado1: " << *resultado1 << '\n';
    }

    // Caso 2: la función no devuelve valor
    std::optional<int> resultado2 = obtenerNumero(false);

    // Usar value_or() para obtener un valor por defecto
    int numero = resultado2.value_or(0);
    std::cout << "Valor devuelto o 0 por defecto: " << numero << '\n';

    // Comprobar si está vacío
    if (!resultado2) {
        std::cout << "Sin valor en resultado2.\n";
    }

    return 0;
}
