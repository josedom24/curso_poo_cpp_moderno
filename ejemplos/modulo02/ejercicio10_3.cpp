#include <iostream>
#include <string>

class GeneradorID {
public:
    // Devuelve un identificador único creciente
    int siguienteID() const {
        static int contador = 0; // se inicializa una sola vez, la primera vez que se llama
        return ++contador;       // conserva su valor entre llamadas
    }
};

class Usuario {
private:
    int id;
    std::string nombre;

public:
    // Método estático para mostrar cuántos usuarios se han creado
    static void mostrarProximoID() {
        // Variable estática dentro de un método estático
        static int contadorPrevio = 0;
        ++contadorPrevio;
        std::cout << "Llamada #" << contadorPrevio
                  << " al método mostrarProximoID()\n";
    }

    Usuario(const std::string& n, GeneradorID& gen)
        : id(gen.siguienteID()), nombre(n) {}

    void mostrar() const {
        std::cout << "Usuario " << nombre << " -> ID: " << id << "\n";
    }
};

int main() {
    GeneradorID generador; // objeto que mantiene el contador interno (vía variable estática)
    Usuario::mostrarProximoID(); // llamada 1 al método estático
    Usuario::mostrarProximoID(); // llamada 2 al método estático

    Usuario u1("Ana", generador);
    Usuario u2("Luis", generador);
    Usuario u3("Marta", generador);

    std::cout << "\nListado de usuarios:\n";
    u1.mostrar();
    u2.mostrar();
    u3.mostrar();

    // Se puede volver a llamar: el estado interno persiste
    std::cout << "\nOtra llamada a mostrarProximoID():\n";
    Usuario::mostrarProximoID();
}
