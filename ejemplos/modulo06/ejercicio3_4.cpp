#include <iostream>

class Figura {
public:
    virtual void dibujar() const = 0;
    virtual ~Figura() = default;
};

class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un círculo\n";
    }
};

// Función que devuelve un puntero crudo
Figura* crearFigura() {
    return new Circulo();  // El cliente es responsable de liberar la memoria
}

int main() {
    Figura* f1 = crearFigura();   // Se crea dinámicamente un Circulo
    f1->dibujar();                // Llamada polimórfica correcta

    //  Si el cliente olvida liberar la memoria:
    // delete f1;  // ← Debería hacerse, pero si se omite hay fuga de memoria

    //  Si se hace delete dos veces por error:
    delete f1;
    // delete f1;  // ← Doble liberación: comportamiento indefinido
}
