#include <iostream>
#include <string>

class CuentaBancaria {
private:
    std::string titular;
    double saldo;

public:
    CuentaBancaria(const std::string& nombre, double saldoInicial)
        : titular{nombre}, saldo{saldoInicial} {}

    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
        }
    }

    void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
        }
    }

    void mostrarInformacion() const {
        std::cout << "Titular: " << titular
                  << ", Saldo: $" << saldo << "\n";
    }
};

int main() {
    CuentaBancaria cuenta("Luis", 1000.0);
    cuenta.mostrarInformacion();  // Titular: Luis, Saldo: $1000

    cuenta.depositar(250);
    cuenta.retirar(100);
    cuenta.mostrarInformacion();  // Titular: Luis, Saldo: $1150

    // cuenta.saldo = 0; // Error: 'saldo' es privado

    return 0;
}
