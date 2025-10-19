#include <iostream>
#include <memory>
#include <vector>

// Clase base con clonación virtual
class Clonable {
public:
    virtual std::unique_ptr<Clonable> clone() const = 0;
    virtual void mostrar() const = 0;
    virtual ~Clonable() = default;
};

// Clase derivada A
class DerivadoA : public Clonable {
private:
    int dato;

public:
    DerivadoA(int d) : dato(d) {}

    std::unique_ptr<Clonable> clone() const override {
        return std::make_unique<DerivadoA>(*this);  // Copia profunda
    }

    void mostrar() const override {
        std::cout << "DerivadoA: " << dato << "\n";
    }
};

// Clase derivada B
class DerivadoB : public Clonable {
private:
    std::vector<int> datos;

public:
    DerivadoB(const std::vector<int>& v) : datos(v) {}

    std::unique_ptr<Clonable> clone() const override {
        return std::make_unique<DerivadoB>(*this);  // Copia profunda
    }

    void mostrar() const override {
        std::cout << "DerivadoB: ";
        for (int n : datos) std::cout << n << " ";
        std::cout << "\n";
    }
};

int main() {
    std::unique_ptr<Clonable> a = std::make_unique<DerivadoA>(42);
    std::unique_ptr<Clonable> b = std::make_unique<DerivadoB>(std::vector<int>{1, 2, 3});

    auto clonA = a->clone();
    auto clonB = b->clone();

    a->mostrar();
    clonA->mostrar();

    b->mostrar();
    clonB->mostrar();
}
