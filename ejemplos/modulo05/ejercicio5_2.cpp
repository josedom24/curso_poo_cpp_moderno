#include <iostream>

class Incrementador {
private:
    int valor;

public:
    Incrementador(int v) : valor(v) {}

    int operator()(int x) const {
        return x + valor;
    }
};

int main() {
    Incrementador inc(5);
    std::cout << inc(10) << "\n";  // Llama a inc.operator()(10): imprime 15
}
