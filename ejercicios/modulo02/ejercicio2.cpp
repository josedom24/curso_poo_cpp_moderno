#include <iostream>
#include <string>

class CuentaBancaria {
private:
    // Atributos privados: principio de encapsulamiento
    std::string titular; 
    double saldo;

public:
    // Constructor por defecto delegante:
    // En lugar de repetir lógica, delega en el constructor parametrizado.
    // Así se evita duplicación de código y se mantiene coherencia en la inicialización.
    CuentaBancaria() : CuentaBancaria("Desconocido", 0.0) {}

    // Constructor con un parámetro delegante:
    // Si solo se pasa el nombre, delega en el constructor principal asignando saldo = 0.0
    CuentaBancaria(const std::string& nombre) : CuentaBancaria(nombre, 0.0) {}

    // Constructor principal (con dos parámetros):
    // Inicializa los atributos usando lista de inicialización
    CuentaBancaria(const std::string& nombre, double saldoInicial)
        : titular{nombre}, saldo{saldoInicial} {
        if (saldoInicial < 0) {
            std::cerr << "Error: el saldo inicial no puede ser negativo.\n";
            saldo = 0.0;
        }
    }

    // Método para depositar dinero
    // Aplica validación para evitar cantidades inválidas
    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
        }
    }

    // Método para retirar dinero
    // Asegura la invarianza: no se puede retirar más que el saldo disponible
    void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
        }
    }

    // Método constante para mostrar información
    // Se marca como const porque no modifica el estado del objeto
    void mostrar() const {
        std::cout << "Titular: " << titular
                  << ", Saldo: $" << saldo << "\n";
    }
};

int main() {
    // Uso del constructor por defecto (delegante)
    CuentaBancaria c1;
    c1.mostrar();

    // Uso del constructor con un parámetro (delegante)
    CuentaBancaria c2("Ana");
    c2.mostrar();

    // Uso del constructor principal con dos parámetros
    CuentaBancaria c3("Luis", 1000.0);
    c3.mostrar();

    // Operaciones sobre la cuenta
    c3.depositar(250.0);   // Deposita 250
    c3.retirar(100.0);     // Retira 100
    c3.mostrar();

    return 0; // Al salir de main, los objetos se destruyen automáticamente (RAII)
}
