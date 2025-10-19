#include <iostream>
#include <string>

// Clase base general
class Animal {
public:
    virtual void hacerSonido() const {
        std::cout << "Sonido genérico de animal\n";
    }

    // Destructor virtual recomendado en jerarquías
    virtual ~Animal() = default;
};

// Clase Perro que hereda de Animal
class Perro : public Animal {
public:
    // Redefinimos el método virtual y lo marcamos como final
    // Esto significa que ninguna clase derivada de Perro podrá sobrescribirlo
    void hacerSonido() const final override {
        std::cout << "Guau guau\n";
    }
};

// Clase derivada de Perro (para demostrar el error si intentamos sobrescribir)
class PerroEspecial : public Perro {
public:
    // Si descomentamos este método, el compilador dará error
    /*
    void hacerSonido() const override {
        std::cout << "Guau especial\n";
    }
    */
};

// Clase Gato declarada como final: no puede tener clases derivadas
class Gato final : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Miau miau\n";
    }
};

// Si intentamos heredar de Gato, el compilador también dará error
/*
class GatoSiames : public Gato {
};
*/

int main() {
    Perro p;
    Gato g;

    Animal* a1 = &p;
    Animal* a2 = &g;

    a1->hacerSonido();  // Llama a Perro::hacerSonido -> "Guau guau"
    a2->hacerSonido();  // Llama a Gato::hacerSonido  -> "Miau miau"

    return 0;
}
