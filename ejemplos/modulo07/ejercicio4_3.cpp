#include <iostream>
#include <functional>

class Boton {
private:
    std::function<void()> callback_;
public:
    void registrarAlPulsar(std::function<void()> f) {
        callback_ = f;
    }

    void pulsar() {
        if (callback_) callback_();
    }
};

int main() {
    Boton b;

    b.registrarAlPulsar([] {
        std::cout << "¡Botón pulsado!\n";
    });

    b.pulsar(); // Imprime: ¡Botón pulsado!
}
