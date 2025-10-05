#include <iostream>
#include <memory>
#include <string>

// -----------------------------------------------------------
// Interfaz pura: define el contrato común
// -----------------------------------------------------------
class DispositivoAudio {
public:
    // Método virtual puro: toda clase derivada debe implementarlo
    virtual void emitirSonido() const = 0;

    // Destructor virtual: garantiza destrucción correcta
    virtual ~DispositivoAudio() = default;
};

// -----------------------------------------------------------
// Clase concreta: Altavoz
// -----------------------------------------------------------
class Altavoz : public DispositivoAudio {
public:
    void emitirSonido() const override {
        std::cout << "Emitiendo sonido por altavoz" << std::endl;
    }
};

// -----------------------------------------------------------
// Clase concreta: Auriculares
// -----------------------------------------------------------
class Auriculares : public DispositivoAudio {
public:
    void emitirSonido() const override {
        std::cout << "Emitiendo sonido por auriculares" << std::endl;
    }
};

// -----------------------------------------------------------
// Función que devuelve una interfaz polimórfica
// -----------------------------------------------------------
// Crea dinámicamente el tipo de dispositivo solicitado
// y lo devuelve como puntero a la interfaz base.
//
// El cliente no necesita conocer las clases concretas:
// solo trabaja con DispositivoAudio.
//
std::unique_ptr<DispositivoAudio> crearDispositivo(const std::string& tipo) {
    if (tipo == "altavoz")
        return std::make_unique<Altavoz>();
    else if (tipo == "auriculares")
        return std::make_unique<Auriculares>();
    else {
        std::cout << "Tipo de dispositivo no reconocido.\n";
        return nullptr;
    }
}

// -----------------------------------------------------------
// Función principal
// -----------------------------------------------------------
int main() {
    std::cout << "Introduce tipo de dispositivo (altavoz / auriculares): ";
    std::string tipo;
    std::cin >> tipo;

    // La función devuelve una interfaz, no una clase concreta
    auto dispositivo = crearDispositivo(tipo);

    if (dispositivo) {
        // Llamada polimórfica: se ejecuta el método de la clase real
        dispositivo->emitirSonido();
    } else {
        std::cout << "No se pudo crear el dispositivo." << std::endl;
    }

    // No se necesita liberar memoria manualmente.
    // std::unique_ptr se encarga de la destrucción automática (RAII).
    return 0;
}
