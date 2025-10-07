#include <iostream>
#include <vector>
#include <string>
#include <utility>

class Imagen {
private:
    std::string id;
    std::vector<int> pixeles;

public:
    Imagen(std::string nombre, size_t tam)
        : id(std::move(nombre)), pixeles(tam, 0) {
        std::cout << "Creando imagen " << id << " con " << tam << " píxeles\n";
    }

    // Constructor de copia
    Imagen(const Imagen& other)
        : id(other.id + "_copia"), pixeles(other.pixeles) {
        std::cout << "Copiando imagen " << other.id << " → " << id << "\n";
    }

    // Operador de asignación por copia
    Imagen& operator=(const Imagen& other) {
        if (this != &other) {
            id = other.id + "_asignada";
            pixeles = other.pixeles;
            std::cout << "Asignando por copia desde " << other.id << "\n";
        }
        return *this;
    }

    // Constructor de movimiento
    Imagen(Imagen&& other) noexcept
        : id(std::move(other.id)), pixeles(std::move(other.pixeles)) {
        std::cout << "Moviendo imagen " << id << "\n";
    }

    // Operador de asignación por movimiento
    Imagen& operator=(Imagen&& other) noexcept {
        if (this != &other) {
            id = std::move(other.id);
            pixeles = std::move(other.pixeles);
            std::cout << "Asignando por movimiento a " << id << "\n";
        }
        return *this;
    }

    void mostrar() const {
        std::cout << id << " (" << pixeles.size() << " píxeles)\n";
    }
};

int main() {
    Imagen img1("foto_original", 5'000'000);
    Imagen img2 = img1;                // Constructor de copia
    Imagen img3 = std::move(img1);     // Constructor de movimiento

    Imagen img4("imagen_extra", 3'000'000);
    img4 = img2;                       // Asignación por copia
    img4 = std::move(img3);            // Asignación por movimiento

    std::cout << "\nEstado final:\n";
    img1.mostrar();
    img2.mostrar();
    img3.mostrar();
    img4.mostrar();
}