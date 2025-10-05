#include <iostream>

// Clase que gestiona automáticamente un recurso de memoria dinámica
class Recurso {
private:
    int* ptr;  // Puntero al entero almacenado en memoria dinámica

public:
    // Constructor: adquiere el recurso (reserva memoria)
    Recurso(int valor = 0) {
        ptr = new int(valor); // Reserva memoria e inicializa con 'valor'
        std::cout << "Recurso adquirido. Valor inicial: " << *ptr << '\n';
    }

    // Destructor: libera el recurso automáticamente
    ~Recurso() {
        delete ptr; // Libera la memoria reservada
        std::cout << "Recurso liberado.\n";
    }

    // Método para establecer un nuevo valor
    void setValor(int valor) {
        *ptr = valor;
    }

    // Método para obtener el valor actual
    int getValor() const {
        return *ptr;
    }

    // Método para mostrar el valor
    void mostrar() const {
        std::cout << "Valor actual: " << *ptr << '\n';
    }
};

int main() {
    std::cout << "Inicio del bloque RAII\n";

    {
        // Se crea un objeto Recurso dentro de un bloque local
        Recurso r(42);      // Constructor reserva memoria
        r.mostrar();         // Muestra el valor actual

        r.setValor(100);     // Modifica el valor
        r.mostrar();         // Muestra el nuevo valor
    } // Al salir del bloque, se llama automáticamente al destructor

    std::cout << "Fin del bloque RAII\n";
    return 0;
}
