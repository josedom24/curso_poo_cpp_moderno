#include <iostream>
#include <memory>
#include <vector>

// Clase base abstracta: Instrumento
// Define la interfaz común para todos los instrumentos.
class Instrumento {
public:
    // Método virtual puro: obliga a las clases derivadas a implementarlo
    virtual void tocar() const = 0;

    // Destructor virtual: asegura destrucción correcta en herencia polimórfica
    virtual ~Instrumento() = default;
};

// Clase derivada: Guitarra
class Guitarra : public Instrumento {
public:
    void tocar() const override {
        std::cout << "Rasgueando la guitarra." << std::endl;
    }
};

// Clase derivada: Piano
class Piano : public Instrumento {
public:
    void tocar() const override {
        std::cout << "Tocando el piano." << std::endl;
    }
};

// Clase derivada: Bateria
class Bateria : public Instrumento {
public:
    void tocar() const override {
        std::cout << "Golpeando la batería." << std::endl;
    }
};

int main() {
    // Vector de punteros inteligentes a la clase base Instrumento.
    // std::unique_ptr garantiza gestión automática de memoria.
    std::vector<std::unique_ptr<Instrumento>> orquesta;

    // Añadimos distintos instrumentos (construcción directa usando make_unique)
    orquesta.push_back(std::make_unique<Guitarra>());
    orquesta.push_back(std::make_unique<Piano>());
    orquesta.push_back(std::make_unique<Bateria>());

    // Invocamos el método tocar() polimórficamente
    for (const auto& instrumento : orquesta) {
        instrumento->tocar();  // Se llama al método correspondiente según el tipo real
    }

    return 0;
}
