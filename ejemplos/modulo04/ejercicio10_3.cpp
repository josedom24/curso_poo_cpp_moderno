#include <iostream>
#include <memory>

class Animal {
public:
    virtual void sonido() const { std::cout << "Sonido genérico\n"; }
    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void sonido() const override { std::cout << "Guau\n"; }
};

int main() {
    std::unique_ptr<Perro> pPerro = std::make_unique<Perro>();

    // Conversión implícita de unique_ptr<Perro> a unique_ptr<Animal>
    std::unique_ptr<Animal> pAnimal = std::move(pPerro);

    pAnimal->sonido(); // "Guau"
    return 0;
}
