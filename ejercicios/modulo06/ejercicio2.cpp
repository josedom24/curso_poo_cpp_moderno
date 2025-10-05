#include <iostream>
#include <string>

// -----------------------------------------------------------
// Interfaz pura: define el contrato común
// -----------------------------------------------------------
class Notificador {
public:
    // Método virtual puro: las clases derivadas deben implementarlo
    virtual void enviarMensaje(const std::string& mensaje) const = 0;

    // Destructor virtual: necesario para liberar correctamente
    // los objetos derivados a través de punteros o referencias base
    virtual ~Notificador() = default;
};

// -----------------------------------------------------------
// Clase concreta: notificación por correo electrónico
// -----------------------------------------------------------
class NotificadorEmail : public Notificador {
public:
    void enviarMensaje(const std::string& mensaje) const override {
        std::cout << "Enviando correo: " << mensaje << std::endl;
    }
};

// -----------------------------------------------------------
// Clase concreta: notificación por SMS
// -----------------------------------------------------------
class NotificadorSMS : public Notificador {
public:
    void enviarMensaje(const std::string& mensaje) const override {
        std::cout << "Enviando SMS: " << mensaje << std::endl;
    }
};

// -----------------------------------------------------------
// Función que usa la interfaz, sin depender de implementaciones concretas
// -----------------------------------------------------------
void procesarEvento(const Notificador& n) {
    // La función no necesita saber si es un correo o un SMS
    n.enviarMensaje("Evento registrado");
}

// -----------------------------------------------------------
// Función principal
// -----------------------------------------------------------
int main() {
    NotificadorEmail email;
    NotificadorSMS sms;

    // La misma función trabaja con ambos tipos de notificador
    procesarEvento(email);  // Se llama a NotificadorEmail::enviarMensaje
    procesarEvento(sms);    // Se llama a NotificadorSMS::enviarMensaje

    return 0;
}
