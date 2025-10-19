#include <iostream>
#include <vector>

template <typename Accion>
class Procesador {
public:
    explicit Procesador(Accion accion) : accion_(accion) {}

    void ejecutar(const std::vector<int>& datos) const {
        for (int valor : datos)
            accion_(valor);  // Inyección de comportamiento
    }

private:
    Accion accion_;
};

class Mostrar {
public:
    void operator()(int x) const {
        std::cout << "Valor: " << x << '\n';
    }
};

class Cuadrado {
public:
    void operator()(int x) const {
        std::cout << x << "² = " << x * x << '\n';
    }
};

int main() {
    std::vector<int> numeros = {1, 2, 3};

    Procesador<Mostrar> p1(Mostrar{});
    Procesador<Cuadrado> p2(Cuadrado{});

    p1.ejecutar(numeros);
    p2.ejecutar(numeros);
}
