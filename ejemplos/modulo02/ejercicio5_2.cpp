#include <iostream>

class Entero {
private:
    int valor;

public:
    // Constructor con un único parámetro
    // 'explicit' evita conversiones implícitas no deseadas
    explicit Entero(int v) : valor{v} {}

    int getValor() const { return valor; }
};

// Función que recibe un objeto Entero
void mostrar(const Entero& e) {
    std::cout << "Valor: " << e.getValor() << '\n';
}

int main() {
    Entero e1(10);  // Correcto: construcción explícita
    mostrar(e1);

    // Entero e2 = 20;     // Error: conversión implícita prohibida por 'explicit'
    // mostrar(30);        // Error: no se convierte int → Entero automáticamente

    mostrar(Entero(30));   // Correcto: conversión explícita

    return 0;
}
