#include <iostream>
#include <vector>
#include <algorithm>

// Clase genérica personalizada compatible con la STL
template <typename T>
class ContenedorSimple {
private:
    std::vector<T> elementos;
public:
    void agregar(const T& val) { elementos.push_back(val); }

    auto begin() { return elementos.begin(); }
    auto end() { return elementos.end(); }
    auto begin() const { return elementos.begin(); }
    auto end() const { return elementos.end(); }
};

int main() {
    ContenedorSimple<int> c;
    c.agregar(3);
    c.agregar(1);
    c.agregar(2);

    // Podemos usar algoritmos de la STL
    std::sort(c.begin(), c.end());

    // Iteración compatible con range-based for
    for (int v : c)
        std::cout << v << " ";

    // Salida: 1 2 3
}
