#include <iostream>
#include <string>

// Definición de una clase plantilla con dos tipos genéricos
template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;

public:
    Par(const T1& a, const T2& b) : primero(a), segundo(b) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }
};

int main() {
    // Instanciación con tipos distintos
    Par<int, std::string> p1(1, "uno");
    std::cout << "Par 1 -> " << p1.getPrimero() << ", " << p1.getSegundo() << '\n';

    Par<double, char> p2(3.14, 'π');
    std::cout << "Par 2 -> " << p2.getPrimero() << ", " << p2.getSegundo() << '\n';

    return 0;
}
