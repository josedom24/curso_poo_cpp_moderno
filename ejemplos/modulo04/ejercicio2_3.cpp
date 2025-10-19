#include <iostream>
#include <memory>
#include <string>

class Documento {
public:
    Documento(std::string texto) : texto_(std::move(texto)) {
        std::cout << "Documento creado: " << texto_ << "\n";
    }
    ~Documento() {
        std::cout << "Documento destruido: " << texto_ << "\n";
    }
    std::string obtenerTexto() const { return texto_; }

private:
    std::string texto_;
};

class Impresora {
public:
    // Dependencia temporal con shared_ptr
    void imprimir(std::shared_ptr<Documento> doc) const {
        if (doc) {
            std::cout << "Imprimiendo documento: " << doc->obtenerTexto() << "\n";
        }
    }
};

class Aplicacion {
public:
    void ejecutar() const {
        auto doc = std::make_shared<Documento>("Reporte trimestral");
        Impresora impresora;
        impresora.imprimir(doc); // dependencia puntual
    }
};

int main() {
    Aplicacion app;
    app.ejecutar();
    std::cout << "Fin de main\n";
    return 0;
}
