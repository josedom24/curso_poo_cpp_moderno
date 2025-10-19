#include <iostream>

int main() {
    int* ptr = new int;   // Reserva espacio para un entero en el heap
    *ptr = 42;            // Uso de la memoria
    std::cout << "Valor: " << *ptr << "\n";

    delete ptr;           // Liberación manual
    return 0;
}
