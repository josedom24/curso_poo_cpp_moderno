#ifndef EVENTOS_H
#define EVENTOS_H

#include <string>
#include <variant>
#include <iostream>

// ---------------------------------------------------------------------------
// Tipos de eventos concretos
// ---------------------------------------------------------------------------

// Representa una lectura válida de un sensor
struct EventoLectura {
    std::string nombre;
    double valor;
};

// Representa un fallo al leer un sensor
struct EventoError {
    std::string nombre;
};

// Representa la activación de un actuador
struct EventoAccion {
    std::string nombre;
};

// ---------------------------------------------------------------------------
// Tipo variante que puede contener cualquiera de los eventos anteriores
// ---------------------------------------------------------------------------
using Evento = std::variant<EventoLectura, EventoError, EventoAccion>;

// ---------------------------------------------------------------------------
// Función que procesa eventos genéricos mediante std::visit
// ---------------------------------------------------------------------------
inline void procesarEvento(const Evento& e) {
    std::visit([](const auto& ev) {
        using T = std::decay_t<decltype(ev)>;

        if constexpr (std::is_same_v<T, EventoLectura>) {
            std::cout << "[Lectura] " << ev.nombre << ": " << ev.valor << '\n';
        }
        else if constexpr (std::is_same_v<T, EventoError>) {
            std::cout << "[Error] Fallo en " << ev.nombre << '\n';
        }
        else if constexpr (std::is_same_v<T, EventoAccion>) {
            std::cout << "[Acción] " << ev.nombre << " ejecutado\n";
        }
    }, e);
}

#endif // EVENTOS_H
