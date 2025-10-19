template <typename T>
class Contenedor {
public:
    void imprimir(const T& valor) const {
        std::cout << "Valor: " << valor << '\n';
    }
};

// Especialización parcial para punteros
template <typename T>
class Contenedor<T*> {
public:
    void imprimir(const T* valor) const {
        if (valor)
            std::cout << "Puntero a: " << *valor << '\n';
        else
            std::cout << "Puntero nulo\n";
    }
};
