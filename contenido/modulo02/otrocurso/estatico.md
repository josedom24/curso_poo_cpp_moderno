# Atributos estáticos de clases

En programación orientada a objetos, cada instancia de una clase suele tener sus propios atributos (miembros de datos), lo que permite que cada objeto mantenga su propio estado. Sin embargo, en ciertos casos, es necesario disponer de información **compartida por todas las instancias** de una clase. Para ello, C++ proporciona los **miembros estáticos**.

## ¿Qué es un atributo estático?

Un **atributo estático** es un miembro de una clase que **pertenece a la clase en sí**, y no a las instancias individuales. Esto significa que:

* Existe una sola copia compartida por todas las instancias.
* Puede accederse sin necesidad de crear un objeto (usando el nombre de la clase).

La declaración de un atributo estático se realiza dentro de la clase. Su definición (y posible inicialización) debe hacerse fuera de la clase, en un archivo fuente `.cpp` o tras la clase si está en un solo archivo.

```cpp
class Contador {
private:
    static int totalObjetos;

public:
    Contador() {
        ++totalObjetos;
    }

    static int obtenerTotal() {
        return totalObjetos;
    }
};

// Definición del atributo estático
int Contador::totalObjetos = 0;
```

##  Acceso a miembros estáticos

Los miembros estáticos pueden ser accedidos:

* A través del nombre de la clase: `Contador::obtenerTotal()`
* A través de una instancia (aunque no es lo más recomendable): `obj.obtenerTotal()`

```cpp
int main() {
    Contador a;
    Contador b;
    std::cout << "Total de objetos: " << Contador::obtenerTotal() << '\n';
}
```


## Ejemplo práctico: ID automático por objeto

Supongamos que deseamos que cada objeto creado reciba un identificador único incremental:

```cpp
#include <iostream>

class Usuario {
private:
    static int siguienteId;
    int id;

public:
    Usuario() : id(siguienteId++) {}

    int obtenerId() const {
        return id;
    }

    static int totalUsuarios() {
        return siguienteId;
    }
};

// Inicialización del atributo estático
int Usuario::siguienteId = 1;

int main() {
    Usuario u1;
    Usuario u2;
    Usuario u3;

    std::cout << "ID u1: " << u1.obtenerId() << '\n';
    std::cout << "ID u2: " << u2.obtenerId() << '\n';
    std::cout << "ID u3: " << u3.obtenerId() << '\n';
    std::cout << "Total creados: " << Usuario::totalUsuarios() - 1 << '\n';
}
```

## Instancia estática dentro de un método de una clase

Una **instancia estática dentro de un método (sea estático o no)** es una variable local que **se inicializa una única vez**, y conserva su valor entre llamadas. Esto se usa, por ejemplo, para implementar **estado persistente privado**. Veamos un ejemplo:

```cpp
class Herramienta {
public:
    int siguienteNumero() const {
        static int numero = 0; // se inicializa solo una vez
        return ++numero;
    }
};

int main() {
    Herramienta h1, h2;
    std::cout << h1.siguienteNumero() << '\n'; // 1
    std::cout << h2.siguienteNumero() << '\n'; // 2
    std::cout << h1.siguienteNumero() << '\n'; // 3
}
```
