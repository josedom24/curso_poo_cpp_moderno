# Atributos y métodos estáticos

En C++, los miembros de una clase pueden ser **estáticos**, lo que significa que pertenecen a la **clase en sí** y no a objetos individuales.

* Un **atributo estático** mantiene un único valor compartido por todas las instancias.
* Un **método estático** puede llamarse sin necesidad de crear un objeto de la clase.

Son útiles cuando:

* Se necesita información común a todos los objetos.
* Se definen funciones auxiliares relacionadas con la clase, pero que no dependen de una instancia concreta.

## Acceso a miembros estáticos

Los miembros estáticos se pueden acceder de dos formas:

* A través del nombre de la clase: `Clase::miembro` (recomendado).
* A través de un objeto de la clase (posible, pero menos claro).

## Atributo estático

Un atributo se declara como `static` dentro de la clase. Si no es `inline` o `constexpr`, debe definirse fuera de la clase.

```cpp
#include <iostream>

class Contador {
private:
    static int totalObjetos; // Declaración

public:
    Contador() { ++totalObjetos; }

    static int getTotalObjetos() { return totalObjetos; }
};

// Definición obligatoria fuera de la clase
int Contador::totalObjetos = 0;

int main() {
    Contador a, b, c;
    std::cout << "Total objetos: " << Contador::getTotalObjetos() << "\n"; // 3
    return 0;
}
```

## Métodos estáticos

Un método estático **no tiene acceso al puntero `this`**, por lo que no puede usar miembros no estáticos. Puede acceder a:

* otros métodos estáticos,
* atributos estáticos,
* parámetros que reciba.

```cpp
#include <iostream>

class Calculadora {
public:
    static int suma(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << Calculadora::suma(3, 4) << "\n"; // 7
    return 0;
}
```

## Instancia estática dentro de un método

Una **variable local estática** dentro de un método se inicializa solo la primera vez que se ejecuta, y mantiene su valor entre llamadas.

```cpp
#include <iostream>

class Herramienta {
public:
    int siguienteNumero() const {
        static int numero = 0; // persiste entre llamadas
        return ++numero;
    }
};

int main() {
    Herramienta h1, h2;
    std::cout << h1.siguienteNumero() << '\n'; // 1
    std::cout << h2.siguienteNumero() << '\n'; // 2
    std::cout << h1.siguienteNumero() << '\n'; // 3
    return 0;
}
```

## Consideraciones importantes

* Los miembros estáticos existen incluso si no se han creado objetos.
* Si no son `inline` o `constexpr`, deben definirse **una sola vez fuera de la clase**.
* Los métodos estáticos no pueden ser virtuales.

