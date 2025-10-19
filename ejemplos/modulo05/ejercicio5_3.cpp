#include <iostream>

struct FuncionBase {
    virtual int operator()(int x) const {
        return x;  // identidad
    }
    virtual ~FuncionBase() = default;
};

struct FuncionDoble : FuncionBase {
    int operator()(int x) const override {
        return x * 2;
    }
};

void ejecutarFuncion(const FuncionBase& f, int valor) {
    std::cout << f(valor) << "\n";
}

int main() {
    FuncionDoble doble;
    ejecutarFuncion(doble, 5);  // Imprime 10
}
