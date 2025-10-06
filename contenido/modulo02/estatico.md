# Atributos y métodos estáticos

En C++, los miembros de una clase pueden ser **estáticos**, lo que significa que **pertenecen a la clase en sí**, y no a instancias individuales. Un **atributo estático** mantiene un único valor compartido por todos los objetos de la clase, y un **método estático** puede llamarse sin necesidad de crear una instancia.

Los miembros estáticos son útiles para representar información común a todos los objetos, o para definir funciones auxiliares relacionadas con la clase, pero que no dependen de un objeto en particular.

Los miembros estáticos pueden ser accedidos:

* A través del nombre de la clase: `Contador::obtenerTotal()`
* A través de una instancia (aunque no es lo más recomendable): `obj.obtenerTotal()`

## Atributo estático

Los atributos estáticos se declaran dentro de la clase con la palabra clave static, pero deben **definirse fuera** de ella cuando no son constantes o cuando su tipo no es un **tipo primitivo entero** (como `int` o `char`). Ejemplo:

```cpp
#include <iostream>
#include <string>

class Contador {
private:
    static int totalObjetos;             // no const → debe definirse fuera
    static const int version = 1;        // const + integral → puede definirse aquí
    static const double PI;              // const + no integral → definir fuera
    static const std::string nombreClase; // const + no integral → definir fuera

public:
    Contador() {
        ++totalObjetos;
    }

    static int getTotalObjetos() {
        return totalObjetos;
    }

    static void mostrarInfo() {
        std::cout << "Clase: " << nombreClase << "\n";
        std::cout << "Versión: " << version << "\n";
        std::cout << "Valor de PI: " << PI << "\n";
    }
};

// Definiciones de los atributos estáticos
int Contador::totalObjetos = 0;
const double Contador::PI = 3.14159;
const std::string Contador::nombreClase = "Contador";

int main() {
    Contador a, b, c;
    Contador::mostrarInfo();
    std::cout << "Total de objetos creados: "
              << Contador::getTotalObjetos() << "\n";  // 3
}
```
Este ejemplo muestra la diferencia entre los tipos de atributos estáticos:

* Los **constantes de tipo integral** pueden inicializarse directamente dentro de la clase.
* Los **no constantes** o los **no integrales** (como `double` o `std::string`) deben definirse **fuera de la clase**, incluso si son `const`.


## Métodos estáticos

Un método estático **no tiene acceso al puntero `this`**, por lo que **no puede acceder directamente a miembros no estáticos**. Solo puede usar otros métodos estáticos, atributos estáticos o parámetros que reciba.
Un **método estático** puede usarse incluso sin crear ningún objeto, y es ideal para operaciones **independientes del estado de una instancia** (como funciones utilitarias o contadores globales).


Ejemplo:

```cpp
#include <iostream>
#include <string>

class Calculadora {
private:
    // Atributo estático: compartido por todas las instancias
    static int totalOperaciones;

    // Atributo no estático: pertenece a cada objeto
    std::string nombreUsuario;

public:
    // Constructor: asigna un nombre al usuario
    Calculadora(const std::string& nombre) : nombreUsuario(nombre) {}

    // Método estático: no tiene puntero 'this'
    // No puede acceder a 'nombreUsuario' (miembro no estático)
    static int suma(int a, int b) {
        ++totalOperaciones;  // ✅ puede acceder a miembros estáticos
        return a + b;
    }

    static int resta(int a, int b) {
        ++totalOperaciones;
        return a - b;
    }

    static int getTotalOperaciones() {
        return totalOperaciones;
    }

    // Método no estático: puede acceder tanto a miembros normales como estáticos
    void mostrarResumen() const {
        std::cout << "Usuario: " << nombreUsuario << "\n";
        std::cout << "Total de operaciones realizadas: "
                  << totalOperaciones << "\n";
    }
};

// Definición del atributo estático (una sola copia para toda la clase)
int Calculadora::totalOperaciones = 0;

int main() {
    // Los métodos estáticos pueden llamarse sin crear objetos
    std::cout << "Suma: " << Calculadora::suma(3, 4) << "\n";    // 7
    std::cout << "Resta: " << Calculadora::resta(10, 2) << "\n"; // 8

    // Creamos dos objetos de Calculadora con distintos usuarios
    Calculadora c1("Ana");
    Calculadora c2("Luis");

    // Ambos comparten el mismo atributo estático totalOperaciones
    std::cout << "\nTotal de operaciones (vía clase): "
              << Calculadora::getTotalOperaciones() << "\n";

    // Cada objeto tiene su propio 'nombreUsuario'
    std::cout << "\nResumen individual:\n";
    c1.mostrarResumen();
    c2.mostrarResumen();

    // No se puede hacer esto dentro de un método estático:
    // nombreUsuario = "nuevo";  // Error: 'this' no existe en métodos estáticos
}
```
* **Atributo estático**: Solo existe **una copia compartida** por todas las instancias. Se define **fuera** de la clase.
* **Método estático**: No depende de un objeto concreto. Se invoca usando `Clase::metodo()`.
* **Sin puntero `this`**: Dentro de un método estático **no hay `this`**, por tanto **no se puede acceder a miembros no estáticos** ni llamar a métodos no estáticos.
* **Acceso desde instancias**: Aunque se puede llamar a un método estático usando un objeto (`obj.metodo()`), no tiene relación con ese objeto en particular.


## Instancia estática dentro de un método de una clase

Perfecto 👍
Aquí tienes el apartado **redefinido** con una redacción más clara, un tono didáctico formal y un **ejemplo más completo y comentado** que muestra distintos usos y matices del concepto.

---

## Instancia estática dentro de un método de una clase

Una **instancia estática declarada dentro de un método** (ya sea el método estático o no estático) es una **variable local con duración estática**.
Esto significa que:

* **Se inicializa una única vez**, la primera vez que se ejecuta el flujo de control que la alcanza.
* **Conserva su valor entre llamadas sucesivas** al método, incluso aunque el método sea invocado desde distintos objetos.
* Su **ámbito sigue siendo local** al método: no puede accederse a ella desde fuera.

Este tipo de variable resulta muy útil para mantener **estado persistente interno** sin necesidad de usar un atributo de clase o de objeto, y sin exponer ese estado a otras partes del programa.

Veamos un ejemplo:

```cpp
#include <iostream>
#include <string>

class GeneradorID {
public:
    // Devuelve un identificador único creciente
    int siguienteID() const {
        static int contador = 0; // se inicializa una sola vez, la primera vez que se llama
        return ++contador;       // conserva su valor entre llamadas
    }
};

class Usuario {
private:
    int id;
    std::string nombre;

public:
    // Método estático para mostrar cuántos usuarios se han creado
    static void mostrarProximoID() {
        // Variable estática dentro de un método estático
        static int contadorPrevio = 0;
        ++contadorPrevio;
        std::cout << "Llamada #" << contadorPrevio
                  << " al método mostrarProximoID()\n";
    }

    Usuario(const std::string& n, GeneradorID& gen)
        : id(gen.siguienteID()), nombre(n) {}

    void mostrar() const {
        std::cout << "Usuario " << nombre << " -> ID: " << id << "\n";
    }
};

int main() {
    GeneradorID generador; // objeto que mantiene el contador interno (vía variable estática)
    Usuario::mostrarProximoID(); // llamada 1 al método estático
    Usuario::mostrarProximoID(); // llamada 2 al método estático

    Usuario u1("Ana", generador);
    Usuario u2("Luis", generador);
    Usuario u3("Marta", generador);

    std::cout << "\nListado de usuarios:\n";
    u1.mostrar();
    u2.mostrar();
    u3.mostrar();

    // Se puede volver a llamar: el estado interno persiste
    std::cout << "\nOtra llamada a mostrarProximoID():\n";
    Usuario::mostrarProximoID();
}
```

* `static int contador` dentro de `siguienteID()`: Es una **variable local estática**: se inicializa una sola vez y conserva su valor. Permite que todos los objetos `GeneradorID` compartan el mismo contador.
* `static int contadorPrevio` dentro de `mostrarProximoID()`: También es local estática, pero ahora dentro de un **método estático**. Mantiene el número de veces que el método ha sido invocado, sin depender de ningún objeto.
* `id` en `Usuario`: Es un atributo **no estático**, distinto para cada objeto. Se inicializa usando el valor persistente del generador.

