# Constructores, destructores y métodos constantes

Un **constructor** es un método especial de la clase que se invoca automáticamente al crear un objeto. Su propósito es **inicializar** el estado del objeto, es decir, asignar valores iniciales a sus atributos. Tipos:

* **Constructor por defecto**: Se utiliza cuando se desea crear un objeto sin proporcionar valores explícitos. Si no se define, el compilador lo genera automáticamente, aunque es buena práctica definirlo explícitamente y garantizar que los atributos tengan valores iniciales seguros, usando **inicialización uniforme**. En C++ moderno, se recomienda utilizar **listas de inicialización uniforme**, que garantizan inicializaciones consistentes, seguras y evitan conversiones implícitas no deseadas. La sintaxis de **listas de inicialización uniforme** es:

    ```cpp
    Clase() : miembro1{valor1}, miembro2{valor2} {
    // cuerpo del constructor (opcional)
    }
    ```

    Veamos un ejemplo:

    ```cpp
    class Punto {
    private:
        int x;
        int y;

    public:
        // Constructor por defecto con inicialización uniforme
        Punto() : x{0}, y{0} {}
    };
    ```

* **Constructor con parámetros**: Permite crear un objeto inicializando sus atributos con valores proporcionados al momento de la creación.

    ```cpp
    class Punto {
    private:
        int x;
        int y;

    public:
        // Constructor con parámetros e inicialización uniforme
        Punto(int valorX, int valorY) : x{valorX}, y{valorY} {}
    };
    ```

* Con la **sobrecarga de constructores**, una clase en C++ puede tener tanto un constructor por defecto como varios constructores con parámetros. Hay que tener en cuenta que los constructores tienes que tener un número o tipos de datos de parámetros distinto.
* Si defines constructores con parámetros y no defines un constructor por defecto, este no será generado automáticamente, y si lo necesitas, debes escribirlo manualmente.

## Uso de `explicit` en constructores

La palabra clave `explicit` se utiliza para prevenir conversiones implícitas automáticas al llamar a un constructor con un solo parámetro. Veamos un ejemplo:

```cpp
#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor explícito (evita conversión implícita desde std::string)
    explicit Persona(const std::string& nombre) 
        : nombre(nombre), edad(0) {}

    void mostrar() const {
        std::cout << "Nombre: " << nombre << ", Edad: " << edad << std::endl;
    }
};

int main() {
    Persona p1("Carlos");  // OK: llamada directa

    // Persona p2 = "Ana"; // Error: conversión implícita no permitida por 'explicit'

    p1.mostrar();

    return 0;
}
```

* Sin `explicit`, podrías escribir `Persona p2 = "Ana";` y compilaría, haciendo una conversión implícita de `std::string` a `Persona`.
* Con `explicit`, ese tipo de conversión está prohibida. Solo se permite `Persona p("texto")`, es decir, llamada directa al constructor.

## Destructor: concepto y cuándo se ejecuta

Un **destructor** es un método especial que se ejecuta automáticamente cuando un objeto:

* Sale de su ámbito de vida (final de un bloque de código).
* Es eliminado explícitamente mediante `delete`.
* Es destruido por un contenedor o estructura de datos.

El destructor permite liberar recursos que el objeto haya gestionado, como memoria dinámica, archivos abiertos o conexiones. La sintaxis es:


```cpp
class Ejemplo {
public:
    ~Ejemplo() {
        std::cout << "Destructor invocado" << std::endl;
    }
};
```

Si no se define, el compilador genera uno por defecto. Sin embargo, es fundamental definirlo cuando se gestionan recursos manualmente.
En ocasiones se recomienda definirlo expresamente. En este caso, le estamos diciendo al compilador que genere automáticamente el destructor por defecto para una clase. La sintaxis para realizar esta declaración sería:

```cpp
~Clase() = default;
```

## Métodos constantes (`const`) y objetos constantes

Un método puede declararse como **const**, lo que indica que:

* No modifica los atributos del objeto.
* Solo puede invocar otros métodos que también sean `const`.
* Proporciona mayor seguridad y claridad en el diseño de clases.

Un objeto puede declararse como **const**, lo que implica que:

* Solo se pueden invocar en él métodos constantes.
* No se pueden modificar sus atributos.

Ejemplo:

```cpp
class Persona {
private:
    std::string nombre;

public:
    Persona(const std::string& n) : nombre{n} {}

    // Método constante: no puede modificar el objeto
    std::string getNombre() const {
        return nombre;
    }
};
int main()
{
    const Persona p{"Luis"};
    std::cout << p.getNombre() << std::endl; // Correcto
    // p.setNombre("Pedro"); // Error: no se puede modificar un objeto constante
```
}

Es recomendable marca todos los métodos que no modifican el estado del objeto como **const**.


## Introducción al puntero `this`

Dentro de los métodos de una clase, `this` es un puntero especial que apunta al objeto actual que invocó el método. Se usa para:

* Diferenciar entre atributos y parámetros con el mismo nombre.
* Permitir encadenamiento de métodos que devuelven una referencia al propio objeto.

Ejemplo:

```cpp
#include <iostream>
#include <string>

class Persona {
private:
    std::string nombre;

public:
    // Constructor con inicialización uniforme
    Persona(std::string nombre) : nombre{nombre} {}

    // Setter que usa 'this' y permite encadenamiento
    Persona& setNombre(const std::string& nombre) {
        this->nombre = nombre;
        return *this;
    }

    // Método para mostrar el estado del objeto
    void mostrar() const {
        std::cout << "Nombre: " << nombre << std::endl;
    }
};

int main() {
    Persona p{"Carlos"};
    p.mostrar();

    // Encadenamiento de métodos usando return *this
    p.setNombre("Laura").mostrar();

    return 0;
}
```

Como hemos visto en ocasiones anteriores, utilizamos el operador `->`para que el puntero `this` pueda acceder a los atributos del objeto.

## Ejemplo final

```cpp
#include <iostream>
#include <string>

class Coche {
private:
    std::string marca;
    std::string modelo;
    int anio;

public:
    // Constructor por defecto con inicialización uniforme
    Coche() : marca{"Desconocida"}, modelo{"Desconocido"}, anio{0} {}

    // Constructor con parámetros e inicialización uniforme
    explicit Coche(const std::string& m, const std::string& mod, int a)
        : marca{m}, modelo{mod}, anio{a} {}

    // Destructor
    ~Coche() {
        std::cout << "Coche destruido: " << marca << " " << modelo << std::endl;
    }

    // Método constante
    std::string getMarca() const {
        return marca;
    }

    // Setter con uso de this y encadenamiento
    Coche& setMarca(const std::string& marca) {
        this->marca = marca;
        return *this;
    }

    // Mostrar información
    void mostrar() const {
        std::cout << "Marca: " << marca << ", Modelo: " << modelo << ", Año: " << anio << std::endl;
    }
};

int main() {
    Coche c1{};  // Inicialización uniforme por defecto
    c1.mostrar();

    Coche c2{"Toyota", "Corolla", 2020};
    c2.mostrar();

    c2.setMarca("Honda").mostrar();  // Encadenamiento de métodos

    const Coche c3{"Ford", "Fiesta", 2018};
    std::cout << "Marca (objeto constante): " << c3.getMarca() << std::endl;

    return 0;
}
```
