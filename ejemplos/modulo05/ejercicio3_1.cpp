#include <iostream>
#include <string>

// Clase Token que restringe su creación
class Token {
private:
    std::string valor;

    // Constructor privado: no accesible desde fuera
    Token(const std::string& v) : valor(v) {}

public:
    void mostrar() const {
        std::cout << "Token: " << valor << '\n';
    }

    // Función amiga que puede construir objetos Token
    friend Token crearTokenSeguro();
};

// Función amiga que tiene acceso al constructor privado
Token crearTokenSeguro() {
    // Aquí podríamos generar un valor aleatorio o validar datos
    return Token("ABC123");
}

int main() {
    // Token t("XYZ"); // Error: el constructor es privado
    Token t = crearTokenSeguro();  // Creación controlada
    t.mostrar();
}
