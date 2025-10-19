#include <iostream>
#include <optional>
#include <string>

int main() {
    // Declaración vacía: no contiene valor
    std::optional<std::string> mensaje;

    // Comprobar si contiene un valor
    if (!mensaje.has_value()) {
        std::cout << "Sin valor inicial.\n";
    }

    // Asignar un valor
    mensaje = "Hola mundo";

    // Comprobar valor usando operator bool()
    if (mensaje) {
        std::cout << "Valor asignado: " << *mensaje << '\n';
    }

    // Acceder al valor con value()
    std::cout << "Con value(): " << mensaje.value() << '\n';

    // Obtener valor con valor por defecto
    std::optional<std::string> otroMensaje;
    std::cout << "Valor o por defecto: " << otroMensaje.value_or("Vacío") << '\n';

    // Reiniciar (vaciar) el optional
    mensaje.reset();
    std::cout << "Tras reset(), has_value(): "
              << std::boolalpha << mensaje.has_value() << '\n';

    return 0;
}
