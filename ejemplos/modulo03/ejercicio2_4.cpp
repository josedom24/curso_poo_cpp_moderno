#include <iostream>

int main() {
    int* ptr = new int(10);  // reserva dinámica

    // Error: se pierde la referencia al bloque reservado
    ptr = nullptr;

    // El bloque original sigue existiendo en memoria, pero ya no es accesible
    std::cout << "Fuga de memoria: el entero reservado nunca se libera.\n";

    return 0;
}
