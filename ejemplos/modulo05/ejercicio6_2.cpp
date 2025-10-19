#include <iostream>
#include <string>

class Conexion {
private:
    std::string host;
    int puerto = 0;
    bool segura = false;

public:
    Conexion& setHost(const std::string& h) {
        host = h;
        return *this;
    }

    Conexion& setPuerto(int p) {
        puerto = p;
        return *this;
    }

    Conexion& usarSSL(bool s) {
        segura = s;
        return *this;
    }

    void conectar() const {
        std::cout << "Conectando a " << host << ":" << puerto
                  << (segura ? " con SSL\n" : " sin SSL\n");
    }
};

int main() {
    Conexion c;
    // Configuración fluida y expresiva
    c.setHost("localhost")
     .setPuerto(443)
     .usarSSL(true)
     .conectar();
}
