#include <iostream>
#include <typeinfo>

class Dispositivo {
public:
    virtual void info() const { std::cout << "Dispositivo genérico\n"; }
    virtual ~Dispositivo() = default;
};

class Camara : public Dispositivo {
public:
    void info() const override { std::cout << "Cámara de seguridad\n"; }
};

void procesar(Dispositivo& d) {
    try {
        Camara& c = dynamic_cast<Camara&>(d);
        c.info();
    } catch (const std::bad_cast& e) {
        std::cout << "Conversión fallida: " << e.what() << '\n';
    }
}

int main() {
    Camara cam;
    Dispositivo base;
    procesar(cam);   // Conversión válida
    procesar(base);  // Conversión inválida: lanza std::bad_cast
}
