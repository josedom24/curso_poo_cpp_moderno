#include <iostream>
#include <string>
#include <vector>

// Clase Jugador: representa a un jugador del club deportivo.
// Los jugadores existen de manera independiente a los equipos.
class Jugador {
private:
    std::string nombre_;  // Nombre del jugador

public:
    // Constructor que inicializa el nombre del jugador
    Jugador(const std::string& nombre) : nombre_(nombre) {}

    // Método que simula que el jugador participa en un partido
    void jugar() const {
        std::cout << "El jugador " << nombre_ << " está jugando." << std::endl;
    }

    // Getter para obtener el nombre
    std::string getNombre() const {
        return nombre_;
    }
};

// Clase Equipo: representa un equipo del club deportivo.
// Tiene un nombre y mantiene una lista de punteros a jugadores.
// Aquí hay una relación de AGREGACIÓN: el Equipo usa jugadores,
// pero no los posee ni controla su ciclo de vida.
class Equipo {
private:
    std::string nombre_;                 // Nombre del equipo
    std::vector<Jugador*> jugadores_;    // Lista de jugadores asociados (no propietarios)

public:
    // Constructor para inicializar el nombre del equipo
    Equipo(const std::string& nombre) : nombre_(nombre) {}

    // Método para agregar un jugador al equipo
    void agregarJugador(Jugador* jugador) {
        jugadores_.push_back(jugador);
    }

    // Método para mostrar los jugadores del equipo
    void mostrarEquipo() const {
        std::cout << "Equipo: " << nombre_ << std::endl;
        if (jugadores_.empty()) {
            std::cout << "  No hay jugadores en este equipo." << std::endl;
        } else {
            for (const auto& jugador : jugadores_) {
                std::cout << "  Jugador: " << jugador->getNombre() << std::endl;
            }
        }
    }
};

int main() {
    // Se crean jugadores independientes que existen aunque no estén en un equipo
    Jugador j1("Carlos");
    Jugador j2("María");
    Jugador j3("Ana");

    // Se crea un equipo y se agregan jugadores
    Equipo equipo1("Tigres");
    equipo1.agregarJugador(&j1);
    equipo1.agregarJugador(&j2);

    // Se crea otro equipo que comparte jugadores
    Equipo equipo2("Leones");
    equipo2.agregarJugador(&j2);
    equipo2.agregarJugador(&j3);

    // Mostrar información de los equipos
    equipo1.mostrarEquipo();
    equipo2.mostrarEquipo();

    // Los jugadores existen fuera de los equipos: siguen siendo válidos
    j1.jugar();
    j3.jugar();

    return 0;
}
