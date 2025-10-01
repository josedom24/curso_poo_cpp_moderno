# Uso de `std::function` para encapsular comportamiento configurable

En C++ moderno, `std::function` es un componente de la biblioteca estándar que permite **almacenar, copiar y ejecutar cualquier objeto invocable**, como funciones, lambdas, punteros a funciones o functores. Actúa como un contenedor polimórfico para comportamientos, lo que permite pasar funciones como argumentos o configurarlas dinámicamente, **sin necesidad de conocer su tipo exacto en tiempo de compilación**.

Este mecanismo proporciona una forma de **abstracción de comportamiento más flexible** que las interfaces tradicionales o las plantillas, permitiendo desacoplar componentes de sus dependencias funcionales de forma dinámica y uniforme.

`std::function` es una plantilla de clase definida en `<functional>` que representa cualquier objeto que se pueda invocar con una determinada firma.

La sintaxis general es:

```cpp
std::function<tipo_retorno(parámetros)>
```

Por ejemplo:

```cpp
std::function<bool(int, int)> comparador;
```

Este objeto puede almacenar cualquier lambda, función o clase con `operator()` que reciba dos `int` y devuelva `bool`.

## Ventajas de `std::function`

* **Homogeneidad**: permite tratar por igual a funciones, lambdas y objetos con `operator()`.
* **Flexibilidad en tiempo de ejecución**: se puede cambiar el comportamiento dinámicamente.
* **Desacoplamiento**: evita depender de clases concretas o plantillas, permitiendo interfaces limpias.
* **Interoperabilidad**: facilita la interacción entre componentes que aceptan comportamientos como parámetros.

## Ejemplo básico: selección dinámica de comportamiento

```cpp
#include <iostream>
#include <functional>

void ejecutarOperacion(int a, int b, std::function<int(int, int)> operacion) {
    std::cout << "Resultado: " << operacion(a, b) << '\n';
}

int main() {
    auto suma = [](int x, int y) { return x + y; };
    auto resta = [](int x, int y) { return x - y; };

    ejecutarOperacion(5, 3, suma);   // Resultado: 8
    ejecutarOperacion(5, 3, resta);  // Resultado: 2
}
```

* Se incluye la librería `<functional>`, que permite usar `std::function` para encapsular funciones, lambdas o funtores con una firma específica.
* Se define la función `ejecutarOperacion` que recibe tres parámetros:
  * Dos enteros `a` y `b`.
  * Un objeto `operacion` de tipo `std::function<int(int, int)>`, es decir, cualquier función que reciba dos `int` y devuelva un `int`.
* Dentro de `ejecutarOperacion`, se llama a `operacion(a, b)` y se imprime el resultado.
* En `main()` se definen dos lambdas:
  * `suma`, que recibe dos enteros y devuelve su suma.
  * `resta`, que recibe dos enteros y devuelve su resta.
* Se llama a `ejecutarOperacion` con los valores `5` y `3` usando la lambda `suma`, por lo que se imprime `Resultado: 8`.
* Se llama a `ejecutarOperacion` con los mismos valores pero usando la lambda `resta`, por lo que se imprime `Resultado: 2`.

Este ejemplo muestra cómo usar `std::function` para pasar comportamiento intercambiable (en este caso, operaciones matemáticas) a una función, facilitando la flexibilidad y el desacoplamiento del código.

## Almacenamiento de comportamientos

`std::function` puede ser miembro de una clase para **almacenar una estrategia configurable**:

```cpp
class Procesador {
public:
    void setOperacion(std::function<int(int, int)> op) {
        operacion_ = op;
    }

    int procesar(int a, int b) const {
        return operacion_(a, b);
    }

private:
    std::function<int(int, int)> operacion_;
};

int main () {
    Procesador p;
    p.setOperacion([](int x, int y) { return x * y; });
    std::cout << p.procesar(4, 5); // 20
}
```

* Se define la clase `Procesador`, que permite almacenar y usar una operación matemática configurable.
* La clase tiene un método público `setOperacion` que recibe un objeto de tipo `std::function<int(int, int)>`. Esto significa que puede recibir cualquier función, lambda o functor que tome dos `int` y devuelva un `int`.
* Dentro de la clase, el objeto recibido se guarda en el miembro privado `operacion_`.
* El método `procesar` recibe dos enteros `a` y `b` y devuelve el resultado de aplicar la operación almacenada (`operacion_(a, b)`).
* En la función `main`:
  * Se crea una instancia `p` de la clase `Procesador`.
  * Se llama a `setOperacion` pasando una lambda que multiplica dos enteros.
  * Se llama a `p.procesar(4, 5)`, que ejecuta la lambda almacenada con los argumentos 4 y 5, devolviendo 20.
  * Finalmente, se imprime el resultado `20`.

Este ejemplo ilustra cómo encapsular comportamiento intercambiable en un objeto mediante `std::function`, facilitando la composición flexible y la inyección de lógica sin necesidad de herencia o interfaces explícitas.

## Uso común: registrar callbacks

Un **callback** es una función que se pasa como argumento a otra función u objeto, para que se llame más adelante —normalmente como respuesta a un evento o condición.

Registrar callbacks significa **asociar una función (o comportamiento)** que será llamada automáticamente **cuando ocurra un evento o condición específica**.

En otras palabras, cuando “registras un callback”, estás diciendo: *"Cuando ocurra X, ejecuta esta función que te paso ahora."*


Veamos a un ejemplo: imagina un botón gráfico. No sabes qué debe hacer ese botón exactamente, pero quieres que quien lo use decida. Entonces tú le permites que “registre un callback” así:

```cpp
#include <iostream>
#include <functional>

class Boton {
public:
    void registrarAlPulsar(std::function<void()> f) {
        callback = f;  // Aquí se registra el callback
    }

    void pulsar() {
        if (callback) callback();  // Aquí se invoca
    }

private:
    std::function<void()> callback;
};


int main() {
    Boton b;

    b.registrarAlPulsar([] {
        std::cout << "¡Botón pulsado!\n";
    });

    b.pulsar();  // Resultado: ¡Botón pulsado!
}
```

Se encapsula el comportamiento de la acción del botón usando una lambda pasada a través de `std::function`. Esto permite que el código que define el botón no dependa del comportamiento específico al pulsarlo.

Esto es muy útil:

* Permite **desacoplar** la lógica: el objeto que registra el callback no necesita saber qué hará el callback.
* Permite **comportamiento configurable**: diferentes partes del código pueden registrar funciones distintas según la necesidad.
* Es una técnica base en **programación orientada a eventos**, **interfaces gráficas**, **librerías reutilizables**, etc.
