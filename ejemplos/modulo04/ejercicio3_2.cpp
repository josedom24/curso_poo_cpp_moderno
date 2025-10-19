#include <iostream>
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
    Pedido(int id, const Cliente& cliente) : id_(id), cliente_(cliente) {}

    void mostrar() const {
        std::cout << "Pedido " << id_ << " para cliente " 
                  << cliente_.obtenerNombre() << "\n";
    }

private:
    int id_;
    const Cliente& cliente_; // asociación obligatoria, no propietaria
};

int main() {
    Cliente c("María");
    Pedido p(789, c);
    p.mostrar();
    return 0;
}
