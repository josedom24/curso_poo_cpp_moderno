#include <iostream>

int main() {
    int* ptr = new int(10);  // reserva memoria
    delete ptr;               // primera liberación

    // Error: segunda liberación del mismo bloque
    delete ptr;  // comportamiento indefinido

    std::cout << "Este mensaje podría no mostrarse correctamente.\n";
    return 0;
}
