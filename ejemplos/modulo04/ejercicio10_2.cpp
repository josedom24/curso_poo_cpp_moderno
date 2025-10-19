#include <iostream>
#include <vector>
#include <memory>

class Animal {
public:
    virtual void hacerSonido() const = 0;
    virtual ~Animal() = default; // Destructor virtual
};

class Perro : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Guau\n";
    }
};

class Gato : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Miau\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Animal>> animales;

    animales.push_back(std::make_unique<Perro>());
    animales.push_back(std::make_unique<Gato>());

    for (const auto& animal : animales) {
        animal->hacerSonido(); // Se resuelve dinámicamente
    }

    return 0;
}
