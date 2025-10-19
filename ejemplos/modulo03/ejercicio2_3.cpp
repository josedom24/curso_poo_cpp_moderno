#include <iostream>

int main() {
    int* array = new int[100]; // Reserva un array de 100 enteros en el heap

    array[0] = 10; // Uso del array
    array[99] = 50;

    std::cout << "Primer elemento: " << array[0] 
              << ", Último: " << array[99] << "\n";

    delete[] array; // Liberación de memoria del array
    return 0;
}
