#include <iostream>
#include <memory>
#include <vector>

// -----------------------------------------------------------
// Clase base abstracta: define la interfaz común
// -----------------------------------------------------------
class Reproductor {
public:
    // Método virtual puro: todas las clases derivadas deben implementarlo
    virtual void reproducir() const = 0;

    // Destructor virtual: garantiza la destrucción correcta
    // al eliminar objetos derivados a través de un puntero base.
    virtual ~Reproductor() = default;
};

// -----------------------------------------------------------
// Clase concreta: Reproductor de audio
// -----------------------------------------------------------
class ReproductorAudio : public Reproductor {
public:
    void reproducir() const override {
        std::cout << "Reproduciendo audio..." << std::endl;
    }
};

// -----------------------------------------------------------
// Clase concreta: Reproductor de video
// -----------------------------------------------------------
class ReproductorVideo : public Reproductor {
public:
    void reproducir() const override {
        std::cout << "Reproduciendo video..." << std::endl;
    }
};

// -----------------------------------------------------------
// Función principal
// -----------------------------------------------------------
int main() {
    // Creamos un vector de punteros inteligentes a Reproductor
    // Cada elemento puede apuntar a un objeto de cualquier clase derivada.
    std::vector<std::unique_ptr<Reproductor>> dispositivos;

    // Insertamos diferentes tipos de reproductores
    dispositivos.push_back(std::make_unique<ReproductorAudio>());
    dispositivos.push_back(std::make_unique<ReproductorVideo>());

    // Recorremos el vector y reproducimos cada dispositivo
    // La llamada se resuelve en tiempo de ejecución (polimorfismo dinámico)
    for (const auto& d : dispositivos) {
        d->reproducir();
    }

    // Los objetos se destruyen automáticamente al salir del ámbito.
    // Gracias a std::unique_ptr, no es necesario liberar memoria manualmente.
    return 0;
}
