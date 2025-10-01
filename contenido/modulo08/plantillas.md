# Introducción a las plantillas de clases

En el desarrollo de software, es frecuente la necesidad de definir clases que operan sobre diferentes tipos de datos. Una solución inicial podría ser crear múltiples versiones de una misma clase, una por cada tipo requerido. Sin embargo, este enfoque conlleva una considerable duplicación de código, lo cual incrementa los costos de mantenimiento y disminuye la claridad del diseño.

La **programación genérica** en C++ proporciona un mecanismo eficiente para resolver este problema mediante **plantillas (templates)**. Una plantilla permite definir estructuras de datos y algoritmos en términos de **tipos genéricos**, de modo que el compilador pueda generar automáticamente las versiones concretas según se necesiten.

## Definición de una plantilla de clase

Una **plantilla de clase** es una especificación paramétrica de una clase, que emplea uno o más parámetros de tipo. Estos parámetros actúan como marcadores de posición para tipos concretos que se instanciarán posteriormente.

La sintaxis general para definir una plantilla de clase con un único parámetro de tipo es la siguiente:

```cpp
template <typename T>
class Contenedor {
private:
    T valor;
public:
    void setValor(const T& v) {
        valor = v;
    }

    T getValor() const {
        return valor;
    }
};
```

En este ejemplo, la clase `Contenedor` es una plantilla que opera sobre un tipo genérico `T`. El tipo real se determina en el momento de la instanciación.

## Instanciación de plantillas de clase

Una vez definida la plantilla, se pueden crear instancias de la clase con distintos tipos:

```cpp
Contenedor<int> entero;
entero.setValor(42);

Contenedor<std::string> texto;
texto.setValor("Hola mundo");
```

En cada caso, el compilador genera automáticamente una versión especializada de la clase `Contenedor`, adaptada al tipo concreto (`int`, `std::string`, etc.).


## Características de las plantillas de clase

* **Generación automática**: el compilador genera el código específico según el tipo utilizado.
* **Verificación en tiempo de compilación**: las operaciones con tipos se validan durante la compilación, garantizando seguridad de tipo.
* **Separación de interfaz y tipo concreto**: permite definir algoritmos y estructuras abstractas independientes del tipo de dato.
* **Comparación con sobrecarga y herencia**: a diferencia de la sobrecarga de funciones o del uso de jerarquías de herencia, las plantillas permiten reutilizar código sin sacrificar rendimiento. Además, no introducen la sobrecarga que conlleva el uso de punteros o referencias polimórficas, ya que todo se resuelve en tiempo de compilación.
* Las plantillas se definen normalmente en archivos de encabezado (`.h` o `.hpp`), ya que el compilador necesita conocer su definición completa al momento de instanciarlas.

## Ejemplo completo

```cpp
#include <iostream>
#include <string>

template <typename T>
class Caja {
private:
    T contenido;
public:
    void setContenido(const T& valor) { contenido = valor; }
    T getContenido() const { return contenido; }
};

int main() {
    Caja<int> cajaEntera;
    cajaEntera.setContenido(10);
    std::cout << "Entero: " << cajaEntera.getContenido() << "\n";

    Caja<std::string> cajaTexto;
    cajaTexto.setContenido("Texto genérico");
    std::cout << "Texto: " << cajaTexto.getContenido() << "\n";

    return 0;
}
```

