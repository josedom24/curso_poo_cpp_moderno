#include "Controlador.h"
#include "Eventos.h"
#include <vector>
#include <ctime>

void mostrarMenu() {
    std::cout << "\n===== Sistema de Dispositivos Inteligentes =====\n";
    std::cout << "1. Mostrar dispositivos registrados\n";
    std::cout << "2. Leer sensores\n";
    std::cout << "3. Activar actuadores\n";
    std::cout << "4. Procesar eventos\n";
    std::cout << "0. Salir\n";
    std::cout << "Seleccione una opción: ";
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    Controlador controlador;
    std::vector<Evento> eventos; // Registro de sucesos del sistema

    // --- Registro inicial de dispositivos ---
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de temperatura"));
    controlador.agregarDispositivo(std::make_unique<Sensor>("Sensor de humedad"));

    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Ventilador", [&eventos] {
            std::cout << "Ventilador encendido\n";
            eventos.push_back(EventoAccion{"Ventilador"});
        }));

    controlador.agregarDispositivo(std::make_unique<Actuador>(
        "Alarma", [&eventos] {
            std::cout << "Alarma activada\n";
            eventos.push_back(EventoAccion{"Alarma"});
        }));

    int opcion = -1;
    do {
        mostrarMenu();
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                controlador.mostrarDispositivos();
                break;

            case 2:
                std::cout << "\n--- Lectura de sensores ---\n";
                for (const auto& d : controlador.getDispositivos()) {
                    if (auto s = dynamic_cast<Sensor*>(d.get())) {
                        auto lectura = s->leer();
                        if (lectura)
                            eventos.push_back(EventoLectura{s->getNombre(), *lectura});
                        else
                            eventos.push_back(EventoError{s->getNombre()});
                    }
                }
                break;

            case 3:
                std::cout << "\n--- Activación de actuadores ---\n";
                controlador.activarActuadores();
                break;

            case 4:
                std::cout << "\n--- Procesamiento de eventos ---\n";
                for (const auto& e : eventos)
                    procesarEvento(e);
                break;

            case 0:
                std::cout << "Saliendo del sistema...\n";
                break;

            default:
                std::cout << "Opción no válida.\n";
                break;
        }

    } while (opcion != 0);

    return 0;
}
