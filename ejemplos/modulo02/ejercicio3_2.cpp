#include <iostream>

class Caja {
private:
    double ancho;

public:
    Caja(double a) : ancho{a} {}

    friend void mostrarAncho(const Caja& c);  //Función amiga
};

void mostrarAncho(const Caja& c) {
    std::cout << "Ancho de la caja: " << c.ancho << '\n'; // Accede a un atributo privado
}

int main() {
    Caja c(3.5);
    mostrarAncho(c);
    return 0;
}
