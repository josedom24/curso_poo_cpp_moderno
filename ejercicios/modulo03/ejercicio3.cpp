#include <iostream>
#include <memory>   // std::shared_ptr, std::make_shared

// Clase que simula un recurso compartido
class RecursoCompartido {
public:
    // Constructor: simula la adquisición del recurso
    RecursoCompartido() {
        std::cout << "Recurso compartido creado.\n";
    }

    // Destructor: simula la liberación del recurso
    ~RecursoCompartido() {
        std::cout << "Recurso compartido liberado.\n";
    }

    // Método que representa el uso del recurso
    void usar() const {
        std::cout << "Usando el recurso compartido.\n";
    }
};

int main() {
    std::cout << "Inicio del programa\n";

    // Creación de un recurso compartido
    std::shared_ptr<RecursoCompartido> sp1 = std::make_shared<RecursoCompartido>();

    {
        // Se crea una nueva copia compartida
        std::shared_ptr<RecursoCompartido> sp2 = sp1;

        std::cout << "Número de propietarios actuales: " << sp1.use_count() << '\n';

        // Ambos punteros pueden acceder al recurso
        sp1->usar();
        sp2->usar();

        std::cout << "Saliendo del bloque interno...\n";
    } // sp2 se destruye: el contador de referencias disminuye

    std::cout << "Número de propietarios tras el bloque: " << sp1.use_count() << '\n';

    std::cout << "Fin del programa\n";
    return 0;
} // sp1 se destruye, el contador llega a 0, se libera el recurso
