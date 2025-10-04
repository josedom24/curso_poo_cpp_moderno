#include <iostream>
#include <string>
#include <vector>

// Clase Habitacion: representa una parte integral de una casa.
// Una habitación no existe por sí misma, siempre está dentro de una Casa.
class Habitacion {
private:
    std::string tipo_;  // Tipo de la habitación (ej. "Dormitorio", "Cocina")

public:
    // Constructor que inicializa el tipo de la habitación
    Habitacion(const std::string& tipo) : tipo_(tipo) {}

    // Método que muestra la información de la habitación
    void mostrar() const {
        std::cout << "Habitación: " << tipo_ << std::endl;
    }
};

// Clase Casa: representa una vivienda que contiene habitaciones.
// Aquí se establece una relación de COMPOSICIÓN:
// las habitaciones forman parte de la casa y dependen totalmente de su vida.
class Casa {
private:
    std::string direccion_;                // Dirección de la casa
    std::vector<Habitacion> habitaciones_; // Habitaciones como parte integral (por valor)

public:
    // Constructor que inicializa la dirección
    Casa(const std::string& direccion) : direccion_(direccion) {}

    // Método para agregar una habitación a la casa
    void agregarHabitacion(const std::string& tipo) {
        habitaciones_.emplace_back(tipo);  // Se construye directamente dentro de la casa
    }

    // Método para mostrar la información de la casa y sus habitaciones
    void mostrarCasa() const {
        std::cout << "Casa en: " << direccion_ << std::endl;
        if (habitaciones_.empty()) {
            std::cout << "  No tiene habitaciones registradas." << std::endl;
        } else {
            for (const auto& hab : habitaciones_) {
                std::cout << "  ";
                hab.mostrar();
            }
        }
    }
};

int main() {
    // Se crea una casa en una dirección específica
    Casa casa("Calle Mayor 123");

    // Se agregan habitaciones: cada una pertenece exclusivamente a la casa
    casa.agregarHabitacion("Dormitorio");
    casa.agregarHabitacion("Cocina");
    casa.agregarHabitacion("Baño");

    // Mostrar información de la casa y de sus habitaciones
    casa.mostrarCasa();

    // Cuando la casa se destruye, también lo hacen sus habitaciones
    return 0;
}
