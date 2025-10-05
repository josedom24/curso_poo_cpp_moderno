#ifndef DISPOSITIVOS_H
#define DISPOSITIVOS_H

#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include <cstdlib>

// ---------------------------------------------------------------------------
// Clase base abstracta: Dispositivo
// ---------------------------------------------------------------------------
class Dispositivo {
protected:
    std::string nombre;

public:
    explicit Dispositivo(std::string n) : nombre(std::move(n)) {}
    virtual ~Dispositivo() = default;

    virtual void mostrarInfo() const = 0;
    const std::string& getNombre() const { return nombre; }
};

// ---------------------------------------------------------------------------
// Clase derivada: Sensor
// Representa un dispositivo que realiza lecturas (pueden fallar).
// ---------------------------------------------------------------------------
class Sensor : public Dispositivo {
public:
    using Lectura = std::optional<double>;

    explicit Sensor(const std::string& n) : Dispositivo(n) {}

    Lectura leer() const {
        double valor = rand() % 100;
        if (valor < 90)  // 90% de éxito
            return valor;
        else
            return std::nullopt;
    }

    void mostrarInfo() const override {
        std::cout << "Sensor: " << nombre << '\n';
    }
};

// ---------------------------------------------------------------------------
// Clase derivada: Actuador
// Representa un dispositivo que ejecuta una acción configurable.
// ---------------------------------------------------------------------------
class Actuador : public Dispositivo {
    std::function<void()> accion;

public:
    Actuador(const std::string& n, std::function<void()> a)
        : Dispositivo(n), accion(std::move(a)) {}

    void activar() const {
        if (accion)
            accion();
    }

    void mostrarInfo() const override {
        std::cout << "Actuador: " << nombre << '\n';
    }
};

#endif // DISPOSITIVOS_H
