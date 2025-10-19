#include <iostream>
#include <memory>
#include <string>

class Cliente {
public:
    Cliente(std::string nombre) : nombre_(std::move(nombre)) {}
    std::string obtenerNombre() const { return nombre_; }
private:
    std::string nombre_;
};

class Pedido {
public:
    Pedido(int id, std::shared_ptr<Cliente> cliente) 
        : id_(id), cliente_(std::move(cliente)) {}

    void mostrar() const {
        if (cliente_) {
            std::cout << "Pedido " << id_ << " para cliente " 
                      << cliente_->obtenerNombre() << "\n";
        }
    }

private:
    int id_;
    std::shared_ptr<Cliente> cliente_; // asociación compartida
};

int main() {
    auto c = std::make_shared<Cliente>("Luis");
    Pedido p(456, c);
    p.mostrar();

    // Tanto 'c' como 'p' comparten la propiedad del cliente
    return 0;
}
