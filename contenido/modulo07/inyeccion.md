# Inyección de comportamiento: composición flexible de lógica

Una de las maneras más efectivas de diseñar sistemas modulares y adaptables es **inyectar el comportamiento** desde el exterior, en lugar de codificarlo directamente dentro de las clases. Esta técnica permite construir componentes más generales, reutilizables y fáciles de probar.

En lugar de decidir “cómo” se hace algo dentro de una clase, podemos **delegar esa decisión al cliente** de la clase, quien proporciona la lógica en forma de objeto, función o lambda.


## Composición flexible en lugar de herencia rígida

El enfoque tradicional orientado a objetos muchas veces se basa en herencia para modificar el comportamiento. Sin embargo, la **composición flexible** es una alternativa más desacoplada: permite modificar el comportamiento de una clase **sin necesidad de subclases**, simplemente pasándole un componente que encapsule la lógica deseada.

Veamos un ejemplo de una calculadora con operación inyectada. Consideremos una clase `Calculadora` que puede ejecutar diferentes operaciones, pero no sabe cómo se realiza cada una. En lugar de definir múltiples subclases para sumar, restar, etc., permitimos **inyectar la operación** como una función.

```cpp
#include <functional>
#include <iostream>

class Calculadora {
public:
    using Operacion = std::function<int(int, int)>;

    Calculadora(Operacion op) : operacion_(op) {}

    int ejecutar(int a, int b) const {
        return operacion_(a, b);
    }

private:
    Operacion operacion_;
};

int main() {
    Calculadora suma([](int a, int b) { return a + b; });
    Calculadora producto([](int a, int b) { return a * b; });

    std::cout << "5 + 3 = " << suma.ejecutar(5, 3) << "\n";
    std::cout << "5 * 3 = " << producto.ejecutar(5, 3) << "\n";
}
```

* **`Operacion` como alias de `std::function`**: Se define con `using` un tipo general que puede almacenar cualquier operación binaria entera (suma, resta, multiplicación, etc.). Esto permite **inyectar lógicas diversas** sin cambiar la clase.
* **Constructor con inyección de comportamiento**:  En lugar de codificar internamente cómo se realiza una operación, `Calculadora` recibe esa lógica desde fuera. Esta es la esencia de la **composición flexible**: la clase **no implementa la operación**, solo la ejecuta.
* **Método `ejecutar` como delegación pura**: `Calculadora` delega completamente el comportamiento a lo que se le haya inyectado. Esto hace que la clase sea **altamente reutilizable** con distintas funciones.
* **Inyección mediante lambdas**: En `main`, se crean dos objetos `Calculadora` con distintos comportamientos (suma y producto), usando lambdas. Así se evita crear subclases como `CalculadoraSuma`, `CalculadoraProducto`, etc.
* **Cambiar comportamiento ≠ cambiar clase**: Se logra reutilización simplemente inyectando una nueva lambda.  Este enfoque permite **adaptar el comportamiento sin modificar o extender la clase original**.

## Ventajas de este enfoque

* **Flexibilidad**: podemos definir nuevos comportamientos sin tocar el código de `Calculadora`.
* **Bajo acoplamiento**: `Calculadora` no depende de una jerarquía de clases ni de implementaciones concretas.
* **Fácil prueba**: podemos inyectar funciones de prueba (mocks) para verificar el funcionamiento.

