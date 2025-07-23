# Constructores, destructores y métodos constantes

En C++, la creación, uso y destrucción de objetos es controlada mediante **constructores**, **destructores** y **métodos constantes**. Estos mecanismos garantizan que los objetos se inicialicen correctamente, liberen recursos cuando ya no se necesiten y permitan el uso seguro de funciones que no alteran su estado.

## Constructores

Un **constructor** es una función especial cuyo nombre coincide con el de la clase y que **no tiene tipo de retorno**. Se ejecuta automáticamente al crear un objeto y se utiliza para inicializar sus atributos.

Tipos de constructores:

* **Constructor por defecto**: no recibe argumentos.
* **Constructor parametrizado**: recibe argumentos para inicializar atributos.
* **Constructor delegante**: llama a otro constructor de la misma clase (se tratarán en otra sección).
* **Constructores especiales**: como el de copia y el de movimiento (se tratarán en otra sección).

Veamos un ejemplo:

```cpp
class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Constructor por defecto
    Persona() {
        nombre = "Desconocido";
        edad = 0;
    }

    // Constructor parametrizado
    Persona(const std::string& n, int e) {
        nombre = n;
        edad = e;
    }

    void presentarse() const {
        std::cout << "Soy " << nombre << " y tengo " << edad << " años.\n";
    }
};

```
* **Constructor por defecto**: Se utiliza cuando se desea crear un objeto sin proporcionar valores explícitos. Si no se define, el compilador lo genera automáticamente, aunque es buena práctica definirlo explícitamente y garantizar que los atributos tengan valores iniciales seguros
* Con la **sobrecarga de constructores**, una clase en C++ puede tener tanto un constructor por defecto como varios constructores con parámetros. Hay que tener en cuenta que los constructores tienes que tener un número o tipos de datos de parámetros distinto.
* Si defines constructores con parámetros y no defines un constructor por defecto, este no será generado automáticamente, y si lo necesitas, debes escribirlo manualmente.

## El modificador `explicit`

En C++, un constructor que recibe **un solo parámetro** puede usarse para convertir automáticamente (**de forma implícita**) un valor de ese tipo al tipo de la clase. Esto a veces puede causar errores difíciles de detectar.
Para evitar esas conversiones implícitas, se usa el modificador `explicit`, que obliga a que la conversión sea explícita (es decir, que el programador la indique claramente).

Veamos un ejemplo `explicit` (conversión implícita permitida):

```cpp
#include <iostream>

class Entero {
public:
    int valor;

    // Constructor sin 'explicit' y sin lista de inicialización
    Entero(int v) {
        valor = v;
    }

    void mostrar() const {
        std::cout << "Valor: " << valor << "\n";
    }
};

void imprimir(Entero e) {
    e.mostrar();
}

int main() {
    imprimir(5);  // Se convierte implícitamente a Entero(5)
    return 0;
}

```

* La función `imprimir` recibe un objeto `Entero`.
* Cuando llamamos `imprimir(5);`, C++ **convierte implícitamente** el entero `5` a un objeto `Entero` usando el constructor `Entero(int v)`.
* Esto puede ser conveniente, pero también puede generar errores si no es lo que queremos.

Veamos ahora un ejemplo con `explicit` (conversión implícita prohibida):

```cpp
#include <iostream>

class Entero {
public:
    int valor;

    // Constructor con 'explicit' y sin lista de inicialización
    explicit Entero(int v) {
        valor = v;
    }

    void mostrar() const {
        std::cout << "Valor: " << valor << "\n";
    }
};

void imprimir(Entero e) {
    e.mostrar();
}

int main() {
    // imprimir(5);  // Error: conversión implícita no permitida

    imprimir(Entero(5));  // Correcto: conversión explícita

    return 0;
}

```

* Al marcar el constructor con `explicit`, la llamada `imprimir(5);` genera un error de compilación porque la conversión implícita está prohibida.
* En su lugar, debemos crear explícitamente el objeto: `imprimir(Entero(5));`.


## Destructor

El **destructor** es una función especial que se ejecuta automáticamente cuando un objeto se destruye. Su propósito principal es **liberar recursos** (memoria, archivos, conexiones, etc.). Su sintaxis es:

```cpp
~NombreDeClase();
```

Un destructor  se ejecuta automáticamente cuando un objeto:

* Sale de su ámbito de vida (final de un bloque de código).
* Es eliminado explícitamente mediante delete.
* Es destruido por un contenedor o estructura de datos.


Veamos un ejemplo:

```cpp
class Persona {
public:
    Persona() {
        std::cout << "Creando persona\n";
    }

    ~Persona() {
        std::cout << "Destruyendo persona\n";
    }
};
```

Si no se define, el compilador genera uno por defecto. Sin embargo, es fundamental definirlo cuando se gestionan recursos manualmente. En ocasiones se recomienda definirlo expresamente.

## Métodos constantes y objetoos constantes

Un método puede declararse como const, lo que indica que:

* No modifica los atributos del objeto.
* Solo puede invocar otros métodos que también sean const.
* Proporciona mayor seguridad y claridad en el diseño de clases.

Un objeto puede declararse como const, lo que implica que:

* Solo se pueden invocar en él métodos constantes.
* No se pueden modificar sus atributos.




```cpp
class Persona {
private:
    std::string nombre;

public:
    Persona(const std::string& n) {
        nombre = n
    }

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

Es recomendable marca todos los métodos que no modifican el estado del objeto como `const`. Que beneficios tenemos con el uso de `const`:

* Mejora la claridad del diseño.
* Aumenta la seguridad: garantiza que no se alterará el estado del objeto.
* Permite el uso en contextos donde solo se permite lectura.


## Uso de `=default` y `=delete`

C++ permite controlar si ciertas funciones especiales (constructores, destructores, operadores, etc.) se deben **generadas automáticamente** (`=default`) o se deben **prohibir explícitamente** (`=delete`).

* `=default`: Se utiliza para pedir al compilador que genere una implementación por defecto.

    ```cpp
    class Persona {
    public:
        Persona() = default;  // Usa el constructor por defecto generado por el compilador
        ~Persona() = default; // Destructor por defecto
    };
    ```

* `=delete`: Se utiliza para **evitar** que una función especial pueda ser usada.

    ```cpp
    class Persona {
    public:
        Persona() = default;
         Persona(const std::string& n) = delete; // Se prohíbe el uso de constructor que recibe solo el nombre
    };
    ```

