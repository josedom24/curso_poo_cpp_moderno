#include <iostream>
#include <string>

class Monitor {
private:
    int& referencia;  // Referencia a una variable externa

public:
    Monitor(int& r) : referencia{r} {}

    void mostrarEstado(const std::string& nombre) const {
        std::cout << "Monitor [" << nombre << "]: valor = " << referencia << "\n";
    }

    void modificar(int nuevoValor) {
        referencia = nuevoValor;  // Cambia directamente la variable original
    }
};

int main() {
    int temperatura = 25;
    int presion = 1013;

    Monitor monitorTemp(temperatura);
    Monitor monitorPres(presion);

    monitorTemp.mostrarEstado("Temperatura");
    monitorPres.mostrarEstado("Presión");

    // Cambiar las variables externas afecta al monitor
    temperatura = 30;
    presion = 1008;

    monitorTemp.mostrarEstado("Temperatura");
    monitorPres.mostrarEstado("Presión");

    // Cambiar desde el monitor afecta a las variables externas
    monitorTemp.modificar(35);
    monitorPres.modificar(995);

    monitorTemp.mostrarEstado("Temperatura");
    monitorPres.mostrarEstado("Presión");

    std::cout << "Variable temperatura = " << temperatura << "\n";
    std::cout << "Variable presion = " << presion << "\n";

    return 0;
}
