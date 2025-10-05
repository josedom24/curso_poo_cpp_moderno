#include <iostream>
#include <memory>
#include <string>

// Interfaz que define el contrato de impresión
class EstrategiaImpresion {
public:
    virtual void imprimir(const std::string& texto) const = 0;
    virtual ~EstrategiaImpresion() = default;
};

// Implementación concreta: impresión por consola
class ImpresionConsola : public EstrategiaImpresion {
public:
    void imprimir(const std::string& texto) const override {
        std::cout << "Imprimiendo en consola: " << texto << '\n';
    }
};

// Implementación concreta: simulación de impresión en archivo
class ImpresionArchivo : public EstrategiaImpresion {
public:
    void imprimir(const std::string& texto) const override {
        std::cout << "Guardando en archivo: " << texto << '\n';
    }
};

// Clase que delega el comportamiento en una estrategia inyectada
class Documento {
public:
    // El constructor recibe una estrategia concreta de impresión
    explicit Documento(std::unique_ptr<EstrategiaImpresion> estrategia)
        : estrategia_(std::move(estrategia)) {}

    // Método que delega la impresión en la estrategia configurada
    void procesar(const std::string& texto) const {
        estrategia_->imprimir(texto);
    }

private:
    std::unique_ptr<EstrategiaImpresion> estrategia_;
};

// Programa principal
int main() {
    // Documento que usa la estrategia de impresión por consola
    Documento docConsola(std::make_unique<ImpresionConsola>());
    docConsola.procesar("Hola desde consola");

    // Documento que usa la estrategia de impresión por archivo
    Documento docArchivo(std::make_unique<ImpresionArchivo>());
    docArchivo.procesar("Hola desde archivo");

    return 0;
}
