#include <iostream>
#include <string>

// Clase Notificador: representa un servicio externo
// que sabe cómo enviar mensajes. La Biblioteca solo lo usará de forma puntual.
class Notificador {
private:
    std::string mensaje_;  // Atributo que guarda el texto del mensaje

public:
    // Constructor: inicializa el mensaje que se va a enviar
    Notificador(const std::string& mensaje) : mensaje_(mensaje) {}

    // Método que envía el mensaje
    void enviarMensaje() const {
        std::cout << "Enviando notificación: " << mensaje_ << std::endl;
    }
};

// Clase Biblioteca: no almacena un Notificador como atributo,
// simplemente lo utiliza dentro del método avisarRetraso.
// Esto es lo que define una relación de DEPENDENCIA.
class Biblioteca {
public:
    // Método que genera un mensaje de retraso y lo envía usando un Notificador
    void avisarRetraso(const std::string& usuario, const std::string& libro) const {
        // Se construye el texto del aviso
        std::string texto = "El usuario " + usuario +
                            " tiene retraso en la devolución del libro: " + libro;

        // Se crea un objeto Notificador local y se usa de manera puntual.
        // La Biblioteca depende de Notificador, pero no lo posee ni lo guarda.
        Notificador notificador(texto);
        notificador.enviarMensaje();
    }
};

int main() {
    Biblioteca biblio;

    // Aquí la Biblioteca usa Notificador solo durante la ejecución de avisarRetraso.
    // No hay relación permanente entre ellas, solo una dependencia temporal.
    biblio.avisarRetraso("Ana Pérez", "Cien años de soledad");

    return 0;
}
