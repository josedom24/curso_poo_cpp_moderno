class Persona {
public:
    std::string nombre;
    int edad;
};

int main() {
    Persona persona;
    persona.edad = -99; // Estado inválido
    return 0;
}
