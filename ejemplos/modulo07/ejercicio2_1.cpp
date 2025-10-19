#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>

// ---------------------------------------------------------
// Interfaz abstracta: define el contrato del comportamiento
// ---------------------------------------------------------
class EstrategiaOrdenamiento {
public:
    // Método virtual puro: cada clase derivada define su propio algoritmo
    virtual void ordenar(std::vector<int>& datos) = 0;

    // Destructor virtual para garantizar destrucción correcta
    virtual ~EstrategiaOrdenamiento() = default;
};

// ---------------------------------------------------------
// Clase que delega el comportamiento de ordenación
// ---------------------------------------------------------
class Ordenador {
private:
    std::unique_ptr<EstrategiaOrdenamiento> estrategia_; // Comportamiento inyectado

public:
    // Constructor: recibe la estrategia a utilizar
    explicit Ordenador(std::unique_ptr<EstrategiaOrdenamiento> estrategia)
        : estrategia_(std::move(estrategia)) {}

    // Método público que delega la tarea
    void ordenar(std::vector<int>& datos) {
        estrategia_->ordenar(datos); // Llamada polimórfica
    }
};

// ---------------------------------------------------------
// Implementaciones concretas de la interfaz
// ---------------------------------------------------------

// Estrategia 1: ordenamiento burbuja (ineficiente, pero ilustrativo)
class OrdenamientoBurbuja : public EstrategiaOrdenamiento {
public:
    void ordenar(std::vector<int>& datos) override {
        for (size_t i = 0; i < datos.size(); ++i) {
            for (size_t j = 0; j < datos.size() - 1; ++j) {
                if (datos[j] > datos[j + 1]) {
                    std::swap(datos[j], datos[j + 1]);
                }
            }
        }
        std::cout << "Ordenado con burbuja\n";
    }
};

// Estrategia 2: uso de std::sort (más eficiente)
class OrdenamientoRapido : public EstrategiaOrdenamiento {
public:
    void ordenar(std::vector<int>& datos) override {
        std::sort(datos.begin(), datos.end());
        std::cout << "Ordenado con std::sort\n";
    }
};

// ---------------------------------------------------------
// Programa principal: selección de comportamiento
// ---------------------------------------------------------
int main() {
    std::vector<int> datos = {5, 2, 8, 1, 4};

    // Primer ordenador usa la estrategia de burbuja
    Ordenador ordenador1(std::make_unique<OrdenamientoBurbuja>());
    ordenador1.ordenar(datos);

    std::cout << "Resultado: ";
    for (int n : datos)
        std::cout << n << " ";
    std::cout << "\n\n";

    // Segundo ordenador usa la estrategia rápida
    std::vector<int> otrosDatos = {9, 3, 7, 1, 6};
    Ordenador ordenador2(std::make_unique<OrdenamientoRapido>());
    ordenador2.ordenar(otrosDatos);

    std::cout << "Resultado: ";
    for (int n : otrosDatos)
        std::cout << n << " ";
    std::cout << "\n";

    return 0;
}
