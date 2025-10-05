#include "Controlador.h"
#include "Eventos.h"
#include <vector>
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Controlador controlador;
    std::vector<Evento> eventos; // Almacena los eventos generados

    // --- Registro de dispositivos ---
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de temperatura"));
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de humedad"));
    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Ventilador", [&eventos] {
            eventos.push_back(EventoAccion{"Ventilador"});
        }));
    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Alarma", [&eventos] {
            eventos.push_back(EventoAccion{"Alarma"});
        }));

    // --- Simulación de lecturas ---
    std::cout << "\n--- Lecturas de sensores ---\n";
    for (const auto& d : controlador.getDispositivos()) {
        if (auto s = dynamic_cast<Sensor*>(d.get())) {
            auto lectura = s->leer();
            if (lectura)
                eventos.push_back(EventoLectura{s->getNombre(), *lectura});
            else
                eventos.push_back(EventoError{s->getNombre()});
        }
    }

    // --- Procesamiento de eventos ---
    std::cout << "\n--- Procesamiento de eventos ---\n";
    for (const auto& e : eventos)
        procesarEvento(e);

    return 0;
}
