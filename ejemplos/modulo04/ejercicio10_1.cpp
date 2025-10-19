#include <iostream>

class Base {};
class Derivada : public Base {};

int main() {
    Derivada d;

    Base* pBase = &d;  // Conversión implícita de Derivada* a Base*
    Base& rBase = d;   // Conversión implícita de Derivada& a Base&

    std::cout << "Conversiones implícitas realizadas correctamente.\n";
    return 0;
}
