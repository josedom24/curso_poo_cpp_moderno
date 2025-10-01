# Especialización de plantillas de clase

Una de las características más poderosas de las plantillas en C++ es la posibilidad de **especializar su comportamiento para ciertos tipos concretos**. Esta técnica, conocida como **especialización de plantillas**, permite modificar o redefinir la implementación de una clase plantilla cuando se utiliza con tipos específicos, sin afectar su comportamiento general.

La especialización es útil cuando:

* Se desea optimizar una implementación para un tipo concreto.
* Se requiere alterar el comportamiento para tipos que tienen propiedades particulares (por ejemplo, punteros o cadenas de texto).
* Es necesario aplicar restricciones o validaciones específicas a ciertos tipos.

## Especialización total

La **especialización total** se produce cuando se define una versión específica de la plantilla para un conjunto exacto de tipos. En este caso, se proporciona una implementación completamente distinta que se utilizará **solo cuando se usen esos tipos concretos**.

```cpp
template <typename T>
class Caja {
public:
    void mostrar() {
        std::cout << "Tipo genérico\n";
    }
};

// Especialización total para std::string
template <>
class Caja<std::string> {
public:
    void mostrar() {
        std::cout << "Tipo cadena de texto\n";
    }
};

int main() {
    Caja<int> a;
    a.mostrar();            // Imprime: Tipo genérico

    Caja<std::string> b;
    b.mostrar();            // Imprime: Tipo cadena de texto
]
```

* La clase `Caja` tiene una implementación general y una versión especializada para el tipo `std::string`.
* La usamos cuando queremos un comportamiento completamente diferente **para un conjunto exacto de tipos**.

## Especialización parcial

La **especialización parcial** permite modificar el comportamiento de la plantilla **para un subconjunto de casos**, pero **sin fijar todos los parámetros**. Es decir, puedes especializar **algunos** de los parámetros de la plantilla, dejando otros genéricos.

Veamos un ejemplo donde hacemos especialización para punteros:

```cpp
template <typename T>
class Contenedor {
public:
    void imprimir(const T& valor) {
        std::cout << "Valor: " << valor << '\n';
    }
};

// Especialización parcial para punteros
template <typename T>
class Contenedor<T*> {
public:
    void imprimir(T* valor) {
        if (valor)
            std::cout << "Puntero a: " << *valor << '\n';
        else
            std::cout << "Puntero nulo\n";
    }
};

int main() {

    Contenedor<int> c1;
    c1.imprimir(42);            // Valor: 42

    int x = 99;
    Contenedor<int*> c2;
    c2.imprimir(&x);            // Puntero a: 99
}
```

Veamos otro ejemplo donde hacemos una especialización para un tipo concreto de uno de los parámetros de tipos:

```cpp
template <typename T1, typename T2>
class MiClase {
public:
    void metodo() {
        std::cout << "Plantilla general\n";
    }
};

// Especialización parcial cuando T1 es int (y T2 es cualquiera)
template <typename T2>
class MiClase<int, T2> {
public:
    void metodo() {
        std::cout << "Especialización parcial: T1 = int\n";
    }
};

int main() {
    MiClase<double, double> obj1;
    obj1.metodo(); // Imprime: Plantilla general

    MiClase<int, char> obj2;
    obj2.metodo(); // Imprime: Especialización parcial: T1 = int
}
```

* La usamos cuando queremos adaptar el comportamiento según **parte del patrón de tipos**, sin fijar completamente todos los argumentos.

## Ejemplo completo

```cpp
#include <iostream>
#include <string>

template <typename T>
class Caja {
private:
    T valor;
public:
    Caja(const T& v) : valor(v) {}
    void mostrar() const {
        std::cout << "Contenido genérico: " << valor << '\n';
    }
};

// Especialización total para std::string
template <>
class Caja<std::string> {
private:
    std::string valor;
public:
    Caja(const std::string& v) : valor(v) {}
    void mostrar() const {
        std::cout << "Texto: \"" << valor << "\"\n";
    }
};

int main() {
    Caja<int> a(100);
    a.mostrar();    // Contenido genérico: 100

    Caja<std::string> b("Hola");
    b.mostrar();    // Texto: "Hola"

    return 0;
}
```


## Especialización y herencia

Las clases plantilla especializadas pueden heredar de la plantilla base, permitiendo la reutilización de parte de la implementación original y su extensión para tipos concretos:

```cpp
template <typename T>
class Base {
public:
    void operar() {
        std::cout << "Operación genérica\n";
    }
};

template <>
class Base<bool> : public Base<void> {
public:
    void operar() {
        std::cout << "Operación especializada para bool\n";
    }
};
```

Este patrón es útil para extender o modificar comportamientos sin sacrificar la reutilización.

Veamos un ejemplo donde construimos un procesador de datos con especialización para `bool`:

```cpp
#include <iostream>

// Plantilla base genérica
template <typename T>
class Procesador {
public:
    void procesar(const T& valor) {
        std::cout << "Procesando valor genérico: " << valor << '\n';
    }

    void log() {
        std::cout << "Log genérico\n";
    }
};

// Especialización total para bool que hereda de una instancia concreta
template <>
class Procesador<bool> : public Procesador<void> {
public:
    void procesar(const bool& valor) {
        std::cout << "Procesando booleano: " << std::boolalpha << valor << '\n';
    }
};

// Plantilla base instanciada para void (usada como base común)
template <>
class Procesador<void> {
public:
    void log() {
        std::cout << "Log común (reutilizado en especialización)\n";
    }
};

int main() {
    Procesador<int> p1;
    p1.procesar(42);      // Procesando valor genérico: 42
    p1.log();             // Log genérico

    Procesador<bool> p2;
    p2.procesar(true);    // Procesando booleano: true
    p2.log();             // Log común (reutilizado en especialización)
}
```

* `Procesador<T>` es la clase plantilla general que implementa un método `procesar` para cualquier tipo `T`.
* Se define una **especialización total** para `bool` que proporciona su propia lógica de `procesar`, pero **reutiliza el método `log()`** heredándolo desde `Procesador<void>`.
* `Procesador<void>` actúa como una **base común** para especializaciones que quieran compartir una parte del comportamiento general.

