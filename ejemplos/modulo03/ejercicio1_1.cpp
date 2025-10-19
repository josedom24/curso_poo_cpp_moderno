#include <iostream>

int main() {
    int* ptr = new int;    // Reserva de memoria dinámica
    *ptr = 42;             // Uso de la memoria

    std::cout << "Valor: " << *ptr << "\n";

    delete ptr;            // Liberación manual de memoria

    return 0;
}
