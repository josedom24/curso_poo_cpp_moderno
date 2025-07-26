# Sobrecarga de operadores

En C++, los **operadores** como `+`, `-`, `==`, `<`, entre otros, pueden **sobrecargarse** para que funcionen con objetos definidos por el programador. Esto permite que los objetos se comporten de manera intuitiva y natural cuando se combinan con estos operadores, como ocurre con los tipos integrados.

La sobrecarga de operadores es especialmente útil en clases que representan **valores numéricos, geométricos, temporales, cadenas, unidades físicas**, etc.

La **sobrecarga de un operador** consiste en **definir una función con una sintaxis especial** que indica cómo debe comportarse el operador cuando se utiliza con objetos de una clase.

Por ejemplo, para que el operador `+` funcione con objetos de tipo `Punto2D`, se puede definir:

```cpp
Punto2D operator+(const Punto2D& a, const Punto2D& b);
```

## Sobrecarga como función miembro vs función libre

Se puede utilizar una **función miembro**:

* Se usa cuando el operando izquierdo es el propio objeto (`this`).
* Se define dentro de la clase.

```cpp
class Punto {
public:
    int _x, _y;  // Usando guion bajo en los atributos para diferenciarlos

    Punto(int x, int y) : _x(x), _y(y) {}  // Los parámetros sin guion bajo, para evitar confusión

    Punto operator+(const Punto& otro) const {
        return Punto(_x + otro._x, _y + otro._y);  // Se suman los atributos correctos
    }
};
```

También lo podemos utilizar con una **función fuera de la clase**:

* Se usa cuando se desea permitir simetría, es decir, para funcionar de la misma manera independientemente de cuál de los operandos es el primero o el segundo,  o cuando el operando izquierdo no es de la clase.
* Puede ser función amiga (`friend`) si necesita acceso a miembros privados.

```cpp
class Punto {
private:
    int _x, _y;  // Atributos con guion bajo

public:
    Punto(int x_, int y_) : _x(x_), _y(y_) {}  // Parametros con guion bajo

    int getX() const { return _x; }
    int getY() const { return _y; }

    friend Punto operator+(const Punto& a, const Punto& b);
};

Punto operator+(const Punto& a, const Punto& b) {
    return Punto(a._x + b._x, a._y + b._y);  // Usando los atributos con guion bajo
}
```


## Ejemplo: clase `Fraccion`

¡Entendido! Aquí tienes el programa basado en la clase `Punto` usando guiones bajos para los atributos y sobrecargando todos los operadores aritméticos (`+`, `-`, `*`, `/`), los operadores `==` y `!=`, y el operador de inserción en flujo `<<`, todo en un solo programa.

### Programa en C++ con la clase `Punto`

```cpp
#include <iostream>

class Punto {
private:
    int _x, _y;  // Atributos con guion bajo

public:
    // Constructor
    Punto(int x_, int y_) : _x(x_), _y(y_) {}

    // Sobrecarga del operador +
    Punto operator+(const Punto& otro) const {
        return Punto(_x + otro._x, _y + otro._y);
    }

    // Sobrecarga del operador -
    Punto operator-(const Punto& otro) const {
        return Punto(_x - otro._x, _y - otro._y);
    }

    // Sobrecarga del operador *
    Punto operator*(int scalar) const {
        return Punto(_x * scalar, _y * scalar);
    }

    // Sobrecarga del operador /
    Punto operator/(int scalar) const {
        if (scalar == 0) {
            throw std::invalid_argument("División por cero");
        }
        return Punto(_x / scalar, _y / scalar);
    }

    // Sobrecarga del operador ==
    bool operator==(const Punto& otro) const {
        return (_x == otro._x && _y == otro._y);
    }

    // Sobrecarga del operador !=
    bool operator!=(const Punto& otro) const {
        return !(*this == otro);  // Utiliza el operador == ya sobrecargado
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
        os << "(" << p._x << ", " << p._y << ")";
        return os;
    }
};

int main() {
    // Creación de objetos de la clase Punto
    Punto p1(3, 4);
    Punto p2(1, 2);

    // Operaciones aritméticas
    Punto suma = p1 + p2;
    Punto resta = p1 - p2;
    Punto multiplicacion = p1 * 2; // Multiplicación por un escalar
    Punto division = p1 / 2;       // División por un escalar

    // Comparaciones
    if (p1 == p2) {
        std::cout << "p1 es igual a p2\n";
    } else {
        std::cout << "p1 no es igual a p2\n";
    }

    if (p1 != p2) {
        std::cout << "p1 es diferente de p2\n";
    }

    // Mostrar resultados
    std::cout << "Suma: " << suma << "\n";
    std::cout << "Resta: " << resta << "\n";
    std::cout << "Multiplicación: " << multiplicacion << "\n";
    std::cout << "División: " << division << "\n";

    return 0;
}
```


* **Operadores sobrecargados**:
   * **Suma**: `operator+` toma dos objetos `Punto` y devuelve un nuevo `Punto` con la suma de las coordenadas.
   * **Resta**: `operator-` toma dos objetos `Punto` y devuelve un nuevo `Punto` con la resta de las coordenadas.
   * **Multiplicación por escalar**: `operator*` multiplica las coordenadas de un `Punto` por un valor escalar.
   * **División por escalar**: `operator/` divide las coordenadas de un `Punto` por un valor escalar. Se incluye un control para evitar la división por cero.
   * **Igualdad**: `operator==` compara dos objetos `Punto` y devuelve `true` si ambos tienen las mismas coordenadas.
   * **Desigualdad**: `operator!=` devuelve `true` si los objetos `Punto` no son iguales.
   * **Operador de inserción en flujo (`<<`)**: Este operador imprime un objeto `Punto` en formato `(x, y)`.

