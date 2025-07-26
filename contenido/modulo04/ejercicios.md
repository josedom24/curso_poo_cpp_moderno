## Ejercicio propuesto

Modelar una clase `Computadora` que contenga un `Procesador` y una `Pantalla`. El `Procesador` debe ser parte integral de la computadora (composición), mientras que la `Pantalla` puede ser compartida entre varias computadoras (agregación).

* La clase `Computadora` debe **poseer un `Procesador`** (composición).
* La clase `Computadora` debe **usar una `Pantalla` compartida** (agregación).
* Deben demostrarse la relación de dependencia en el ciclo de vida (el procesador muere con la computadora, pero la pantalla puede vivir aparte).


```cpp
#include <iostream>
#include <memory>
#include <string>

// Clase Procesador (Composición)
class Procesador {
public:
    Procesador(std::string modelo) : modelo_(modelo) {
        std::cout << "Procesador " << modelo_ << " construido.\n";
    }

    ~Procesador() {
        std::cout << "Procesador " << modelo_ << " destruido.\n";
    }

    void info() const {
        std::cout << "Procesador: " << modelo_ << '\n';
    }

private:
    std::string modelo_;
};

// Clase Pantalla (Agregación)
class Pantalla {
public:
    Pantalla(std::string tipo) : tipo_(tipo) {
        std::cout << "Pantalla " << tipo_ << " construida.\n";
    }

    ~Pantalla() {
        std::cout << "Pantalla " << tipo_ << " destruida.\n";
    }

    void mostrar() const {
        std::cout << "Pantalla: " << tipo_ << '\n';
    }

private:
    std::string tipo_;
};

// Clase Computadora (compone Procesador y agrega Pantalla)
class Computadora {
public:
    Computadora(std::string marca, std::string modeloProcesador, std::shared_ptr<Pantalla> pantalla)
        : marca_(marca), procesador_(modeloProcesador), pantalla_(pantalla) {
        std::cout << "Computadora " << marca_ << " construida.\n";
    }

    ~Computadora() {
        std::cout << "Computadora " << marca_ << " destruida.\n";
    }

    void mostrarComponentes() const {
        std::cout << "Computadora: " << marca_ << '\n';
        procesador_.info();          // parte de la composición
        pantalla_->mostrar();        // parte agregada (compartida)
    }

private:
    std::string marca_;
    Procesador procesador_;             // composición: creado y destruido junto a Computadora
    std::shared_ptr<Pantalla> pantalla_; // agregación: compartido, gestionado por fuera
};
```

---

### Uso y demostración

```cpp
int main() {
    std::shared_ptr<Pantalla> pantallaCompartida = std::make_shared<Pantalla>("LED 24''");

    {
        Computadora pc1("Dell", "Intel i7", pantallaCompartida);
        Computadora pc2("HP", "AMD Ryzen 5", pantallaCompartida);

        std::cout << "\nComponentes de PC1:\n";
        pc1.mostrarComponentes();

        std::cout << "\nComponentes de PC2:\n";
        pc2.mostrarComponentes();
    } // pc1 y pc2 se destruyen, pero pantalla sigue viva hasta que el shared_ptr muere

    std::cout << "Fin del programa.\n";
    return 0;
}
```

---

### Salida esperada (resumida)

```
Pantalla LED 24'' construida.
Procesador Intel i7 construido.
Computadora Dell construida.
Procesador AMD Ryzen 5 construido.
Computadora HP construida.

Componentes de PC1:
Computadora: Dell
Procesador: Intel i7
Pantalla: LED 24''

Componentes de PC2:
Computadora: HP
Procesador: AMD Ryzen 5
Pantalla: LED 24''

Computadora HP destruida.
Procesador AMD Ryzen 5 destruido.
Computadora Dell destruida.
Procesador Intel i7 destruido.
Pantalla LED 24'' destruida.
Fin del programa.
```

---

### Conclusión

Este ejemplo permite observar claramente:

* Cómo los objetos de tipo `Procesador` son **parte integral** de la clase `Computadora` (composición): viven y mueren con ella.
* Cómo una `Pantalla` puede ser **compartida** entre múltiples instancias de `Computadora` (agregación), y su ciclo de vida es **gestionado externamente** mediante `std::shared_ptr`.

¿Te gustaría que continúe con el siguiente punto: **Asociaciones entre objetos y responsabilidades**?
