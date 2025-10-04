#include <iostream>
#include <string>

// Clase Token: representa un identificador único.
// Su constructor es privado, lo que impide la creación directa de instancias.
class Token {
private:
    std::string valor;  // Valor interno del token

    // Constructor privado: solo accesible desde funciones amigas.
    explicit Token(const std::string& v) : valor(v) {}

    // Prohibimos la copia y la asignación para mantener unicidad.
    Token(const Token&) = delete;
    Token& operator=(const Token&) = delete;

public:
    // Método público para mostrar el valor del token.
    void mostrar() const {
        std::cout << "Token: " << valor << std::endl;
    }

    // Declaramos una función amiga que puede crear objetos Token.
    friend Token crearTokenSeguro();
};

// Función amiga: única vía autorizada para crear tokens válidos.
Token crearTokenSeguro() {
    // En un sistema real, aquí podría generarse un valor aleatorio o encriptado.
    return Token("ID-SECURE-001");
}

int main() {
    // Token t("ABC123"); // Error: constructor privado, no se puede instanciar directamente

    // Creación controlada del token mediante la función amiga.
    Token token = crearTokenSeguro();

    // Mostramos el valor del token.
    token.mostrar();

    // Token copia = token;  // Error: copia eliminada
    // Token otro;
    // otro = token;          // Error: asignación eliminada

    return 0;
}
