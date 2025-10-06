# Sobrecarga de operadores

En C++, los operadores como `+`, `-`, `==`, `<`, `<<`, entre otros, pueden sobrecargarse para que funcionen con objetos definidos por el programador.
Esto permite que los objetos se comporten de manera intuitiva y natural, de forma similar a los tipos integrados.

La sobrecarga de operadores es un ejemplo de **polimorfismo estático**, ya que la resolución de qué función llamar se realiza en tiempo de compilación en función de los tipos de los operandos.

Este mecanismo es especialmente útil en clases que representan **valores numéricos, geométricos, cadenas, fechas, unidades físicas o estructuras matemáticas**, donde resulta natural sumar, restar o comparar objetos con operadores en lugar de con métodos.

## Ejemplo: clase `Punto`

Vamos a implementar una clase `Punto` que representa un punto en un plano 2D.
Queremos que se pueda **sumar y restar** con otros puntos, **multiplicar y dividir** por escalares, y **comparar** para saber si dos puntos son iguales o diferentes.

En lugar de escribir métodos como `p1.sumar(p2)`, sobrecargamos los operadores y escribimos `p1 + p2`, que resulta más claro y natural. Con esta implementación, trabajar con objetos `Punto` es tan natural como trabajar con enteros o flotantes.

```cpp
#include <iostream>
#include <stdexcept>

class Punto {
private:
    int _x, _y;

public:
    Punto(int x, int y) : _x(x), _y(y) {}

    // Sobrecarga de la suma (+)
    Punto operator+(const Punto& otro) const {
        return Punto(_x + otro._x, _y + otro._y);
    }

    // Sobrecarga de la resta (-)
    Punto operator-(const Punto& otro) const {
        return Punto(_x - otro._x, _y - otro._y);
    }

    // Multiplicación por escalar (*)
    Punto operator*(int escalar) const {
        return Punto(_x * escalar, _y * escalar);
    }

    // División por escalar (/)
    Punto operator/(int escalar) const {
        if (escalar == 0) {
            throw std::invalid_argument("División por cero");
        }
        return Punto(_x / escalar, _y / escalar);
    }

    // Comparación de igualdad (==)
    bool operator==(const Punto& otro) const {
        return _x == otro._x && _y == otro._y;
    }

    // Comparación de desigualdad (!=)
    bool operator!=(const Punto& otro) const {
        return !(*this == otro);
    }

    // Operador de salida (<<) – debe ser función externa
    friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
        os << "(" << p._x << ", " << p._y << ")";
        return os;
    }
};

int main() {
    Punto p1(3, 4);
    Punto p2(1, 2);

    Punto suma = p1 + p2;
    Punto resta = p1 - p2;
    Punto multiplicacion = p1 * 2;
    Punto division = p1 / 2;

    std::cout << "Suma: " << suma << "\n";
    std::cout << "Resta: " << resta << "\n";
    std::cout << "Multiplicación: " << multiplicacion << "\n";
    std::cout << "División: " << division << "\n";

    if (p1 != p2) {
        std::cout << "p1 y p2 son diferentes\n";
    }
}
```

* **`operator+` y `operator-`**: devuelven un nuevo punto con la suma o resta de las coordenadas.
* **`operator*` y `operator/`**: permiten escalar el punto. La división incluye un control de errores para evitar la división por cero.
* **`operator==` y `operator!=`**: comparan puntos para ver si son iguales o distintos.
* **`operator<<`**: imprime un punto en formato `(x, y)`; este operador debe ser externo porque el flujo de salida (`std::cout`) está a la izquierda de la expresión.


### El operador de inserción en flujo `<<`

En el ejemplo anterior, hemos definido la sobrecarga de `operator<<` como una **función externa** en lugar de un método miembro, utilizando la palabra calve `friend`.
Esto se debe a que, en una expresión como:

```cpp
std::cout << p;
```

el operando izquierdo es `std::cout` (un objeto de tipo `std::ostream`), y no un `Punto`.
En C++, cuando un operador se define como método miembro, el operando izquierdo debe ser siempre un objeto de esa clase.
Como no podemos modificar la clase `std::ostream` de la biblioteca estándar, debemos definir `operator<<` como **función externa**, que reciba:

* una referencia a `std::ostream` como primer parámetro (lado izquierdo),
* un objeto `Punto` como segundo parámetro (lado derecho).

De esta forma, el compilador sabe que al escribir `std::cout << p;` debe llamar a nuestra función sobrecargada:

```cpp
friend std::ostream& operator<<(std::ostream& os, const Punto& p) {
    os << "(" << p._x << ", " << p._y << ")";
    return os;
}
```

## El operador `operator()`: objetos invocables (functores)

Además de operadores aritméticos y de comparación, en C++ se puede sobrecargar el operador `()` (paréntesis).
Esto permite que un objeto se utilice **como si fuera una función**. Los objetos que implementan este operador se llaman **functores** u **objetos invocables**.

Esto es útil cuando queremos encapsular lógica que depende de un **estado interno** y poder reutilizarla como si fuera una función.

```cpp
#include <iostream>

class Incrementador {
private:
    int valor;

public:
    Incrementador(int v) : valor(v) {}

    int operator()(int x) const {
        return x + valor;
    }
};

int main() {
    Incrementador inc(5);
    std::cout << inc(10) << "\n";  // Llama a inc.operator()(10): imprime 15
}
```

En este ejemplo:

* `Incrementador` guarda un número `valor`.
* Al invocar el objeto con `inc(10)`, se ejecuta `operator()`, que devuelve `10 + valor`.
* Así podemos usar `Incrementador` en cualquier sitio donde se espere una función.

## Operadores virtuales

Hasta ahora hemos visto **polimorfismo estático**: el compilador decide qué función llamar según los tipos.
Pero los operadores también pueden participar en **polimorfismo dinámico** si se declaran como `virtual` en una clase base.

Esto permite que las clases derivadas redefinan el comportamiento del operador y que la decisión de qué código ejecutar se tome en tiempo de ejecución.

```cpp
#include <iostream>

struct FuncionBase {
    virtual int operator()(int x) const {
        return x;  // identidad
    }
    virtual ~FuncionBase() = default;
};

struct FuncionDoble : FuncionBase {
    int operator()(int x) const override {
        return x * 2;
    }
};

void ejecutarFuncion(const FuncionBase& f, int valor) {
    std::cout << f(valor) << "\n";
}

int main() {
    FuncionDoble doble;
    ejecutarFuncion(doble, 5);  // Imprime 10
}
```

* `FuncionBase` define `operator()` como virtual.
* `FuncionDoble` redefine el operador para multiplicar por dos.
* Al llamar `ejecutarFuncion(doble, 5)`, el parámetro es una referencia a `FuncionBase`, pero en tiempo de ejecución se invoca la versión redefinida en `FuncionDoble`.
