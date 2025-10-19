#include <iostream>

class Sumar {
public:
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    Sumar sumar;
    std::cout << "Resultado: " << sumar(3, 4) << '\n';  // 7
}
