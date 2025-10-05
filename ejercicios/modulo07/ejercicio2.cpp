#include <iostream>
#include <vector>
#include <functional>

// Función genérica que recibe una operación sobre cada elemento del vector
void procesarDatos(const std::vector<int>& datos,
                   const std::function<void(int)>& operacion) {
    for (int valor : datos)
        operacion(valor); // Se aplica el comportamiento inyectado
}

int main() {
    std::vector<int> numeros = {1, 2, 3, 4, 5};

    // Lambda que duplica el valor y lo muestra
    auto duplicar = [](int x) {
        std::cout << x << " duplicado: " << x * 2 << '\n';
    };

    // Lambda que filtra y muestra solo los pares
    auto filtrarPares = [](int x) {
        if (x % 2 == 0)
            std::cout << "Número par: " << x << '\n';
    };

    std::cout << "=== Aplicando duplicar ===\n";
    procesarDatos(numeros, duplicar);

    std::cout << "\n=== Aplicando filtro de pares ===\n";
    procesarDatos(numeros, filtrarPares);
}
