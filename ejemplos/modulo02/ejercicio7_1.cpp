#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& n, int e)
        : nombre{n}, edad{e} {}  // inicialización directa

    void presentarse() const {
        std::cout << "Soy " << nombre << " y tengo " << edad << " años.\n";
    }
};

int main() {
    Persona p{"Ana", 30};
    p.presentarse();  // Soy Ana y tengo 30 años.
    return 0;
}
