# Atributos y métodos estáticos

En C++, los miembros de una clase pueden ser **estáticos**, lo que significa que **pertenecen a la clase en sí**, y no a instancias individuales. Un **atributo estático** mantiene un único valor compartido por todos los objetos de la clase, y un **método estático** puede llamarse sin necesidad de crear una instancia.

Los miembros estáticos son útiles para representar información común a todos los objetos, o para definir funciones auxiliares relacionadas con la clase, pero que no dependen de un objeto en particular.

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

## Atributo estático

Se declara con la palabra clave `static` dentro de la clase, pero debe **definirse fuera** de ella si es un atributo no `const` de tipo no integral:

```cpp
class Contador {
private:
    static int totalObjetos;

public:
    Contador() {
        ++totalObjetos;
    }

    static int getTotalObjetos() {
        return totalObjetos;
    }
};

// Definición del atributo estático
int Contador::totalObjetos = 0;

int main() {
    Contador a, b, c;
    std::cout << "Total objetos: " << Contador::getTotalObjetos() << "\n";  // 3
}
```

## Métodos estáticos

Un método estático **no tiene acceso al puntero `this`**, por lo que **no puede acceder directamente a miembros no estáticos**. Solo puede usar:

* otros métodos estáticos,
* atributos estáticos,
* parámetros que reciba.

Ejemplo:

```cpp
class Calculadora {
public:
    static int suma(int a, int b) {
        return a + b;
    }
};

int main() {
    std::cout << Calculadora::suma(3, 4) << "\n";  // 7
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


## Consideraciones importantes

* Los miembros estáticos **existen incluso si no se han creado instancias** de la clase.
* Un atributo estático **debe definirse exactamente una vez** fuera de la clase si no es `inline` o `constexpr`.
* Los métodos estáticos **no pueden ser virtuales**.
