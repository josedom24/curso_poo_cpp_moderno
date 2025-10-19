#include <iostream>

int main() {
    int* ptr = new int(10);
    delete ptr;  // el bloque ya no es válido

    // Error: acceso a memoria liberada
    *ptr = 5;  // comportamiento indefinido
    std::cout << "Valor: " << *ptr << "\n";  // lectura inválida

    return 0;
}
