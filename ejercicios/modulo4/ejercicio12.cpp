#include <iostream>
#include <string>

// Clase Profesor: representa a un docente que existe de manera independiente
// y que puede impartir uno o varios cursos.
class Profesor {
private:
    std::string nombre_;  // Nombre del profesor

public:
    // Constructor para inicializar el nombre
    Profesor(const std::string& nombre) : nombre_(nombre) {}

    // Método que simula que el profesor da una clase
    void darClase() const {
        std::cout << "El profesor " << nombre_ << " está dando clase." << std::endl;
    }

    // Método de acceso al nombre (getter)
    std::string getNombre() const {
        return nombre_;
    }
};

// Clase Curso: representa un curso en la universidad.
// Tiene un título y un puntero a un Profesor.
// Aquí se establece una relación de ASOCIACIÓN unidireccional:
// el Curso conoce a su Profesor, pero no lo posee ni gestiona su vida.
class Curso {
private:
    std::string titulo_;   // Título del curso
    Profesor* profesor_;   // Asociación: referencia a un Profesor (no propietario)

public:
    // Constructor: recibe el título del curso y un puntero al profesor
    Curso(const std::string& titulo, Profesor* profesor)
        : titulo_(titulo), profesor_(profesor) {}

    // Método que muestra la información del curso y del profesor asociado
    void mostrarInfo() const {
        if (profesor_) {
            std::cout << "Curso: " << titulo_
                      << " | Profesor responsable: " << profesor_->getNombre()
                      << std::endl;
        } else {
            std::cout << "Curso: " << titulo_
                      << " | Profesor no asignado." << std::endl;
        }
    }
};

int main() {
    // Se crea un profesor de manera independiente
    Profesor prof("Dr. García");

    // Se crea un curso y se asocia con el profesor existente.
    // El Curso no es dueño del Profesor: el profesor sigue existiendo aunque el curso desaparezca.
    Curso curso("Programación en C++", &prof);

    // Mostrar la información del curso junto con el profesor asociado
    curso.mostrarInfo();

    // El profesor puede seguir existiendo fuera del curso
    prof.darClase();

    return 0;
}
