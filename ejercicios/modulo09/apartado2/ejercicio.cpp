#include <iostream>
#include <string>
#include <optional>
#include <functional>
#include <memory>
#include <vector>
#include <cstdlib>
#include <ctime>

// ---------------------------------------------------------------------------
// Clase base abstracta: Dispositivo
// ---------------------------------------------------------------------------
class Dispositivo {
protected:
    std::string nombre;  // Nombre común a todos los dispositivos

public:
    explicit Dispositivo(std::string n) : nombre(std::move(n)) {}
    virtual ~Dispositivo() = default; // Destructor virtual para herencia segura

    // Método virtual puro: cada tipo de dispositivo definirá su comportamiento
    virtual void mostrarInfo() const = 0;
};

// ---------------------------------------------------------------------------
// Clase derivada: Sensor
// Representa un dispositivo que realiza lecturas, que pueden fallar.
// ---------------------------------------------------------------------------
class Sensor : public Dispositivo {
public:
    using Lectura = std::optional<double>;  // Valor leído o std::nullopt

    explicit Sensor(const std::string& n) : Dispositivo(n) {}

    // Simula una lectura: devuelve un número o falla aleatoriamente
    Lectura leer() const {
        double valor = rand() % 100;
        if (valor < 90)     // 90% de éxito
            return valor;
        else
            return std::nullopt;  // Lectura fallida
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
    std::function<void()> accion;  // Función inyectada que define su comportamiento

public:
    Actuador(const std::string& n, std::function<void()> a)
        : Dispositivo(n), accion(std::move(a)) {}

    // Ejecuta la acción si está definida
    void activar() const {
        if (accion)
            accion();
    }

    void mostrarInfo() const override {
        std::cout << "Actuador: " << nombre << '\n';
    }
};

// ---------------------------------------------------------------------------
// Programa principal: demostración del polimorfismo dinámico
// ---------------------------------------------------------------------------
int main() {
    srand(static_cast<unsigned>(time(nullptr))); // Inicializa el generador aleatorio

    // Contenedor de punteros inteligentes a dispositivos
    std::vector<std::unique_ptr<Dispositivo>> dispositivos;

    // Creación de sensores
    dispositivos.push_back(std::make_unique<Sensor>("Temperatura"));
    dispositivos.push_back(std::make_unique<Sensor>("Humedad"));

    // Creación de un actuador con una acción lambda
    dispositivos.push_back(std::make_unique<Actuador>(
        "Alarma", []() { std::cout << "¡Alarma activada!\n"; }));

    // Procesamiento de los dispositivos
    for (const auto& d : dispositivos) {
        d->mostrarInfo();

        // Intentamos identificar el tipo concreto del dispositivo
        if (auto s = dynamic_cast<Sensor*>(d.get())) {
            auto lectura = s->leer();
            if (lectura)
                std::cout << " Lectura: " << *lectura << '\n';
            else
                std::cout << " Error de lectura.\n";
        }
        else if (auto a = dynamic_cast<Actuador*>(d.get())) {
            a->activar();
        }
    }

    return 0; // Todos los objetos se destruyen automáticamente
}
