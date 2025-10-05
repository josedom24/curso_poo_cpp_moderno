# Manejo de eventos genéricos mediante `std::variant` y `std::visit`

Hasta ahora, el sistema está formado por una jerarquía de clases (`Dispositivo`, `Sensor`, `Actuador`) gestionadas por la clase `Controlador`.
Cada tipo de dispositivo tiene su comportamiento específico, implementado mediante **herencia** y **métodos virtuales**.

En este apartado introduciremos una alternativa **moderna y flexible** para manejar información diversa: los **eventos genéricos** representados con `std::variant` y procesados con `std::visit`.

Esta técnica permite **unificar distintos tipos de datos** en una sola variable, garantizando seguridad de tipo en tiempo de compilación, sin necesidad de una jerarquía de clases adicional.

## Objetivo

Modelar distintos **eventos del sistema** —como lecturas de sensores, errores o acciones ejecutadas— mediante un único tipo genérico (`Evento`) que pueda contener uno de varios tipos concretos.

Posteriormente, todos estos eventos se procesarán de forma centralizada mediante `std::visit`.

## Definición de eventos

Creamos una cabecera llamada `Eventos.h` que define los posibles tipos de evento y su manejo.

```cpp
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
```

* Se definen **tres estructuras simples** que modelan distintos eventos del sistema: `EventoLectura`, `EventoError` y `EventoAccion`.
* `using Evento = std::variant<...>` crea un tipo genérico que puede contener cualquiera de esos tres.
* `std::visit()` aplica una función a la variante, ejecutando la acción adecuada según el tipo almacenado.
* La lambda `[](const auto& ev)` es **genérica**: el compilador deduce automáticamente el tipo (`EventoLectura`, `EventoError`, etc.) y ejecuta el bloque correspondiente.
* El uso de `if constexpr` garantiza que solo el bloque correspondiente al tipo real del evento se compile.


## Integración con el sistema

Podemos usar estos eventos para **registrar o notificar lo que ocurre** al interactuar con los sensores y actuadores definidos en los apartados anteriores.

Por ejemplo, podemos registrar los eventos generados por el controlador en el archivo `main.cpp`:

```cpp
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
```

* Se añade un **vector de eventos** que almacena los sucesos ocurridos durante la ejecución.
* Los **sensores** generan:
  * `EventoLectura` si la lectura es exitosa.
  * `EventoError` si falla.
* Los **actuadores** ejecutan lambdas que **emiten un `EventoAccion`** al ser activados.
* Finalmente, el sistema recorre el vector `eventos` y llama a `procesarEvento()` para mostrar los resultados.


