#include <iostream>
#include <string>

class ConexionBD {
private:
    std::string cadenaConexion;

public:
    // Solo existe este constructor: requiere un string
    explicit ConexionBD(const std::string& conexion) : cadenaConexion{conexion} {}

    void conectar() const {
        std::cout << "Conectando a la base de datos en: " << cadenaConexion << "\n";
    }
};

class Aplicacion {
private:
    ConexionBD conexion;  // Composición: la aplicación TIENE una conexión

public:
    // Obligatoriamente inicializamos 'conexion' en la lista
    Aplicacion(const std::string& cadena) : conexion{cadena} {}

    void iniciar() const {
        conexion.conectar();
        std::cout << "Aplicación iniciada.\n";
    }
};

int main() {
    Aplicacion app{"Servidor=127.0.0.1;Puerto=5432;BD=ventas"};
    app.iniciar();

    return 0;
}
