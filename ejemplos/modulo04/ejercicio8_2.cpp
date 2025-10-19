#include <iostream>
#include <string>

class Animal {
public:
    virtual void hablar() const {
        std::cout << "El animal emite un sonido." << std::endl;
    }

    virtual ~Animal() = default; // Destructor virtual recomendado
};

class Perro : public Animal {
public:
    void hablar() const override {
        std::cout << "El perro ladra." << std::endl;
    }
};

class Gato : public Animal {
public:
    void hablar() const override {
        std::cout << "El gato maúlla." << std::endl;
    }
};

void hacerHablar(const Animal& a) {
    a.hablar();
}

int main() {
    Perro p{};
    Gato g{};

    hacerHablar(p);  // "El perro ladra."
    hacerHablar(g);  // "El gato maúlla."

    Animal* ptr = new Perro{};
    ptr->hablar();   // "El perro ladra."
    delete ptr;

    return 0;
}
