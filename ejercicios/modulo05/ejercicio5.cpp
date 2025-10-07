#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // Para std::setprecision
#include <utility>  // Para std::pair

// Clase que representa un pedido de compra
class Pedido {
private:
    std::string cliente;
    std::vector<std::pair<std::string, double>> productos;
    double descuento = 0.0;  // Porcentaje de descuento (0-100)

public:
    // Método para establecer el cliente
    Pedido& setCliente(const std::string& nombre) {
        cliente = nombre;
        return *this; // Devuelve una referencia al objeto actual
    }

    // Método para añadir un producto al pedido
    Pedido& addProducto(const std::string& nombre, double precio) {
        productos.emplace_back(nombre, precio);
        return *this;
    }

    // Método para aplicar un porcentaje de descuento
    Pedido& aplicarDescuento(double porcentaje) {
        descuento = porcentaje;
        return *this;
    }

    // Método final que imprime un resumen del pedido
    void mostrarResumen() const {
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "=== Resumen del pedido ===\n";
        std::cout << "Cliente: " << cliente << "\n\n";
        std::cout << "Productos:\n";

        double subtotal = 0.0;
        for (const auto& [nombre, precio] : productos) {
            std::cout << "  - " << nombre << ": " << precio << " €\n";
            subtotal += precio;
        }

        double total = subtotal * (1 - descuento / 100.0);

        std::cout << "\nSubtotal: " << subtotal << " €\n";
        std::cout << "Descuento: " << descuento << "%\n";
        std::cout << "Total final: " << total << " €\n";
        std::cout << "===========================\n";
    }
};

int main() {
    Pedido pedido;

    // Encadenamiento de métodos (fluidez)
    pedido.setCliente("Ana Pérez")
          .addProducto("Portátil", 1200.0)
          .addProducto("Ratón inalámbrico", 25.0)
          .addProducto("Teclado mecánico", 80.0)
          .aplicarDescuento(10.0)
          .mostrarResumen();

    return 0;
}
