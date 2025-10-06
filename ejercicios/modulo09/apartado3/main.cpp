#include "Controlador.h"
#include <ctime>

int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Inicializa el generador aleatorio

    Controlador controlador;

    // --- Registro de dispositivos ---
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de temperatura"));
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de humedad"));

    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Ventilador", [] { std::cout << "Ventilador encendido\n"; }));

    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Alarma", [] { std::cout << "Alarma activada\n"; }));

    // --- Operaciones principales ---
    controlador.mostrarDispositivos();
    controlador.leerSensores();
    controlador.activarActuadores();

    return 0;
}