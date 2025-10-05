#ifndef CONTROLADOR_H
#define CONTROLADOR_H

#include "Dispositivos.h"
#include <vector>
#include <memory>

class Controlador {
private:
    std::vector<std::unique_ptr<Dispositivo>> dispositivos;

public:
    // Agrega un nuevo dispositivo
    void agregarDispositivo(std::unique_ptr<Dispositivo> d) {
        dispositivos.push_back(std::move(d));
    }

    // Muestra información de todos los dispositivos
    void mostrarDispositivos() const {
        std::cout << "\n--- Dispositivos registrados ---\n";
        for (const auto& d : dispositivos) {
            d->mostrarInfo();
        }
    }

    // Lee todos los sensores
    void leerSensores() const {
        std::cout << "\n--- Lectura de sensores ---\n";
        for (const auto& d : dispositivos) {
            if (auto s = dynamic_cast<Sensor*>(d.get())) {
                auto lectura = s->leer();
                if (lectura)
                    std::cout << s->getNombre() << ": " << *lectura << '\n';
                else
                    std::cout << s->getNombre() << ": error de lectura\n";
            }
        }
    }

    // Activa todos los actuadores
    void activarActuadores() const {
        std::cout << "\n--- Activación de actuadores ---\n";
        for (const auto& d : dispositivos) {
            if (auto a = dynamic_cast<Actuador*>(d.get())) {
                a->activar();
            }
        }
    }
};

#endif // CONTROLADOR_H
