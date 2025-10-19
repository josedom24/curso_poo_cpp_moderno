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
    void imprimir(const Documento& doc) const {
        std::cout << "Imprimiendo: " << doc.obtenerTexto() << "\n";
    }
};

class Aplicacion {
public:
    void generarYImprimir() const {
        Documento doc("Acta de la reunión"); // creado localmente
        Impresora impresora;                 // creado localmente
        impresora.imprimir(doc);             // uso inmediato
    }
};

int main() {
    Aplicacion app;
    app.generarYImprimir();
    return 0;
}
