#include <algorithm>
#include <vector>
#include <iostream>

class EsPar {
public:
    bool operator()(int valor) const {
        return valor % 2 == 0;
    }
};

int main() {
    std::vector<int> datos = {1, 2, 3, 4, 5};

    // Usamos el functor como criterio de búsqueda
    auto it = std::find_if(datos.begin(), datos.end(), EsPar{});

    if (it != datos.end())
        std::cout << "Primer número par: " << *it << '\n';
}
