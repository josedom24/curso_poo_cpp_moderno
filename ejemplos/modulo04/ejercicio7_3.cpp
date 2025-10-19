#include <iostream>

class Animal {
public:
    void hacerSonido() const {
        std::cout << "Sonido genérico de animal" << std::endl;
    }
};

class Perro : public Animal {
public:
    // Reescritura del método hacerSonido()
    void hacerSonido() const {
        std::cout << "Guau guau" << std::endl;
    }
};

int main() {
    Perro p;
    p.hacerSonido();  // Llama a la versión de Perro, no a la de Animal
    return 0;
}
