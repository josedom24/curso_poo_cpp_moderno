#include <iostream>
#include <string>
#include <utility>

class ConexionBD {
private:
    std::string nombre;
    bool activa = false;

    // Constructor privado
    ConexionBD(std::string n) : nombre(std::move(n)), activa(true) {
        std::cout << "Conexión establecida con " << nombre << "\n";
    }

public:
    // Prohibir copia
    ConexionBD(const ConexionBD&) = delete;
    ConexionBD& operator=(const ConexionBD&) = delete;

    // Permitir movimiento
    ConexionBD(ConexionBD&& other) noexcept
        : nombre(std::move(other.nombre)), activa(other.activa) {
        other.activa = false;
        std::cout << "Conexión movida a nuevo objeto\n";
    }

    ConexionBD& operator=(ConexionBD&& other) noexcept {
        if (this != &other) {
            cerrar();
            nombre = std::move(other.nombre);
            activa = other.activa;
            other.activa = false;
            std::cout << "Conexión transferida mediante asignación por movimiento\n";
        }
        return *this;
    }

    ~ConexionBD() {
        cerrar();
    }

    void cerrar() {
        if (activa) {
            std::cout << "Cerrando conexión con " << nombre << "\n";
            activa = false;
        }
    }

    void conectar() const {
        if (activa)
            std::cout << "Conectado a " << nombre << "\n";
        else
            std::cout << "Conexión inactiva\n";
    }

    bool estaConectada() const { return activa; }

    // Función estática de creación controlada
    static ConexionBD crearConexion(const std::string& nombreBD) {
        return ConexionBD(nombreBD);
    }
};

int main() {
    ConexionBD c1 = ConexionBD::crearConexion("BaseDeDatosPrincipal");

    c1.conectar();

    // Transferencia de propiedad mediante movimiento
    ConexionBD c2 = std::move(c1);

    c1.conectar(); // Conexión inactiva
    c2.conectar(); // Activa

    return 0;
}