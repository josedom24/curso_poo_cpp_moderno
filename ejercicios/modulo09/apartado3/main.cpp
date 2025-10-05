#include "Controlador.h"
#include <ctime>

int main() {
    std::srand(static_cast<unsigned>(std::time(nullptr))); // Inicializa el generador aleatorio

    Controlador controlador;

    // Registro de dispositivos
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de temperatura"));
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de humedad"));

    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Ventilador", [] { std::cout << "Ventilador encendido\n"; }));

    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Alarma", [] { std::cout << "Alarma activada\n"; }));

    controlador.mostrarDispositivos();
    controlador.leerSensores();
    controlador.activarActuadores();

    return 0;
}
