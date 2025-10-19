#include <iostream>
#include <vector>
#include <algorithm>

class Ordenador {
public:
    void ordenar(std::vector<int>& datos) {
        // Algoritmo de ordenación fijo (burbuja)
        for (size_t i = 0; i < datos.size(); ++i) {
            for (size_t j = 0; j < datos.size() - 1; ++j) {
                if (datos[j] > datos[j + 1]) {
                    std::swap(datos[j], datos[j + 1]);
                }
            }
        }
    }
};

int main() {
    std::vector<int> datos = {5, 2, 9, 1, 7};
    Ordenador ordenador;
    ordenador.ordenar(datos);

    for (int n : datos)
        std::cout << n << " ";
}
