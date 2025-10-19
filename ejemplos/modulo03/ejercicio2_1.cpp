#include <iostream>

void funcion() {
    int x = 5;   // Variable local en el stack
    std::cout << "x = " << x << "\n";
} // al salir de la función, x se libera automáticamente

int main() {
    funcion();
    return 0;
}
