#include <iostream>
#include <string>

class Coche {
private:
    std::string marca;
    std::string modelo;
    int anio;

public:
    // Constructor por defecto
    Coche() : marca{"Desconocida"}, modelo{"Desconocido"}, anio{0} {}

    // Constructor con parámetros (explicit evita conversiones implícitas)
    explicit Coche(const std::string& m, const std::string& mod, int a)
        : marca{m}, modelo{mod}, anio{a} {}

    // Destructor
    ~Coche() {
        std::cout << "Coche destruido: " << marca << " " << modelo << "\n";
    }

    // Método constante
    std::string getMarca() const {
        return marca;
    }

    // Setter con puntero this y encadenamiento
    Coche& setMarca(const std::string& marca) {
        this->marca = marca;
        return *this;
    }

    // Mostrar información
    void mostrar() const {
        std::cout << "Marca: " << marca
                  << ", Modelo: " << modelo
                  << ", Año: " << anio << "\n";
    }
};

int main() {
    Coche c1{};  // Constructor por defecto
    c1.mostrar();

    Coche c2{"Toyota", "Corolla", 2020};  // Constructor parametrizado
    c2.mostrar();

    c2.setMarca("Honda").mostrar();  // Encadenamiento con this

    const Coche c3{"Ford", "Fiesta", 2018};
    std::cout << "Marca (objeto const): " << c3.getMarca() << "\n";

    return 0;
}
