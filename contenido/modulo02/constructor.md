# Constructores, destructores y métodos constantes

En C++, la creación, uso y destrucción de objetos se gestionan mediante **constructores**, **destructores** y **métodos constantes**. Estos mecanismos garantizan que los objetos:

* se **inicialicen correctamente**,
* liberen recursos cuando ya no se necesiten,
* y permitan operaciones seguras en objetos que no deben modificarse.

## Constructores

Un **constructor** es una función especial cuyo nombre coincide con el de la clase y que no tiene tipo de retorno. Se ejecuta automáticamente al crear un objeto.

Tipos:

* **Constructor por defecto:** no recibe argumentos.
* **Constructor parametrizado:** recibe valores para inicializar atributos.
* **Constructor delegante:** llama a otro constructor de la misma clase (se verá más adelante).
* **Constructores especiales:** como el de copia y el de movimiento (se estudiarán más adelante).

Aunque lo estudiaremos en profundidad en el siguiente apartado, hay que indicar que en C++ moderno, se recomienda usar **listas de inicialización uniforme (`{}`)** para inicializar los atributos:

```cpp
#include <iostream>

class Punto {
private:
    int x;
    int y;

public:
    // Constructor por defecto con lista de inicialización
    Punto() : x{0}, y{0} {}

    // Constructor parametrizado con lista de inicialización
    Punto(int valorX, int valorY) : x{valorX}, y{valorY} {}

    // Método constante para mostrar el estado del objeto
    void mostrar() const {
        std::cout << "Punto(" << x << ", " << y << ")\n";
    }
};

int main() {
    Punto p1;            // Se usa el constructor por defecto
    Punto p2{3, 4};      // Se usa el constructor parametrizado

    p1.mostrar();        // Punto(0, 0)
    p2.mostrar();        // Punto(3, 4)

    return 0;
}
```

Este programa demuestra que:

* El **constructor por defecto** inicializa `x` e `y` en `0`.
* El **constructor parametrizado** usa la lista de inicialización para asignar directamente los valores recibidos.
* La función `mostrar()` es **const** porque no modifica el estado del objeto.


### Uso de `explicit`

Si un constructor recibe un único parámetro, puede usarse como conversión implícita, lo que a veces causa errores. Para evitarlo se emplea la palabra clave **`explicit`**:

Aquí tienes un ejemplo completo y comentado que muestra el uso de `explicit` en un constructor:

```cpp
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
```

* `explicit` impide que el compilador convierta automáticamente un `int` en un `Entero`.
* Esto evita errores sutiles cuando una función espera un `Entero` y se pasa un `int` por descuido.
* Para crear el objeto, debe hacerse de forma **explícita**: `Entero(30)` o `Entero e(30);`.


## Destructor

Un **destructor** es una función especial que se ejecuta automáticamente cuando un objeto:

* sale de su ámbito,
* se elimina con `delete`,
* o es destruido dentro de un contenedor.

Su sintaxis es: `~NombreDeClase();`

Ejemplo:

```cpp
#include <iostream>

class Ejemplo {
private:
    std::string nombre;

public:
    // Constructor: se ejecuta al crear el objeto
    Ejemplo(const std::string& n) : nombre{n} {
        std::cout << "Constructor: " << nombre << " creado.\n";
    }

    // Destructor: se ejecuta automáticamente al destruir el objeto
    ~Ejemplo() {
        std::cout << "Destructor: " << nombre << " destruido.\n";
    }
};

int main() {
    std::cout << "Inicio del programa.\n";

    Ejemplo a("Objeto A"); // Se construye automáticamente
    {
        Ejemplo b("Objeto B"); // Se construye dentro de un bloque
        std::cout << "Dentro del bloque.\n";
    } // b sale de ámbito → se invoca su destructor aquí

    std::cout << "Fin del programa.\n";
    return 0; // Al finalizar main, se destruye 'a'
}
```

* El **constructor** se llama cuando se crea el objeto (`Ejemplo a("Objeto A");`).
* El **destructor (`~Ejemplo`)** se ejecuta automáticamente cuando el objeto sale de su ámbito.
* El orden de destrucción es **inverso al de creación**: el último objeto creado es el primero en destruirse.
* No es necesario invocar el destructor manualmente; el compilador lo hace por ti.
* Si no se define, el compilador genera uno por defecto. 


## Uso de `=default` y `=delete`

C++ permite controlar si ciertas funciones especiales (constructores, destructores, operadores, etc.) se deben **generar automáticamente** (`=default`) o se deben **prohibir explícitamente** (`=delete`).

Veamos un ejemplo:

Aquí tienes un **ejemplo completo** y comentado que muestra el uso de `=default` y `=delete`:

```cpp
#include <iostream>
#include <string>

class Archivo {
private:
    std::string nombre;

public:
    // Constructor por defecto: generado automáticamente
    Archivo() = default;

    // Constructor con parámetro
    Archivo(const std::string& n) : nombre{n} {}

    // Destructor generado automáticamente
    ~Archivo() = default;

    // Prohibimos la copia: un archivo no puede copiarse
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;

    // Método para mostrar información
    void mostrar() const {
        std::cout << "Archivo: " << nombre << '\n';
    }
};

int main() {
    Archivo a1("datos.txt");
    a1.mostrar();

    Archivo a2;            // Se usa el constructor por defecto (=default)
    // Archivo a3 = a1;    // Error: copia eliminada (=delete)
    // a2 = a1;            // Error: asignación eliminada (=delete)

    return 0;
}
```

* `=default` indica al compilador que genere automáticamente el **constructor por defecto** y el **destructor**.
* `=delete` desactiva la **copia** y la **asignación**, impidiendo duplicar objetos de esta clase.
* Este patrón es útil cuando los objetos **poseen recursos únicos** (como archivos o sockets) que **no deben copiarse**.
* El compilador marcará un **error en tiempo de compilación** si se intenta realizar una operación eliminada.

