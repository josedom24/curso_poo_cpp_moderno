#include <iostream>
#include <string>

class Documento {
public:
    Documento(std::string texto) : texto_(texto) {}
    std::string obtenerTexto() const { return texto_; }

private:
    std::string texto_;
};

class Impresora {
public:
    // Dependencia puntual: recibe un Documento solo para imprimirlo
    void imprimir(const Documento& doc) const {
        std::cout << "Imprimiendo: " << doc.obtenerTexto() << "\n";
    }
};

int main() {
    Documento d("Informe mensual");
    Impresora impresora;
    impresora.imprimir(d); // relación de dependencia
    return 0;
}
