#include <iostream>
#include <memory>
#include <vector>

// Clase base abstracta que representa un Animal genérico
class Animal {
public:
    // Método virtual: cada animal define su propio sonido
    virtual void hacerSonido() const {
        std::cout << "El animal emite un sonido genérico." << std::endl;
    }

    // Destructor virtual: asegura destrucción completa al usar punteros base
    virtual ~Animal() = default;
};

// Clase derivada: León
class Leon : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Ruge el león." << std::endl;
    }
};

// Clase derivada: Elefante
class Elefante : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Barrita el elefante." << std::endl;
    }
};

// Clase derivada: Mono
class Mono : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Chilla el mono." << std::endl;
    }
};

int main() {
    // Vector que almacena punteros inteligentes a la clase base Animal
    std::vector<std::unique_ptr<Animal>> zoologico;

    // Insertamos distintos animales (cada uno es un tipo derivado)
    zoologico.push_back(std::make_unique<Leon>());
    zoologico.push_back(std::make_unique<Elefante>());
    zoologico.push_back(std::make_unique<Mono>());

    // Recorremos el vector e invocamos el método polimórfico
    std::cout << "=== Sonidos del zoológico ===\n";
    for (const auto& animal : zoologico) {
        animal->hacerSonido();  // Se llama al método correcto según el tipo real
    }

    return 0;
}
