# Ejercicios sobre conceptos avanzados de programación orientada a objetos

## Ejercicio 1: Control de creación de objetos

Un sistema de seguridad quiere generar identificadores únicos (`Token`) que no puedan ser creados libremente por cualquier parte del programa, solo mediante una función controlada. Implementa la clase `Token` con constructor privado y una función `crearTokenSeguro()` que devuelva un token válido.
Prohíbe además la copia de objetos `Token`.

## Ejercicio 2: Sobrecarga de operadores

Crea una clase `Punto2D` que represente un punto en el plano. Implementa la sobrecarga de operadores para:

* `+` (suma de dos puntos).
* `-` (resta de dos puntos).
* `==` (comparación de igualdad).
* `<<` (impresión en flujo en formato `(x, y)`).

## Ejercicio 3: Fluidez de métodos

Queremos diseñar una clase que permita construir y configurar un **pedido en línea** (por ejemplo, de una tienda digital) de forma **fluida y legible**.

Crea una clase `Pedido` que permita encadenar métodos para configurar distintos aspectos del pedido:

* `setCliente(const std::string&)`: establece el nombre del cliente.
* `addProducto(const std::string&, double)`: añade un producto con su precio.
* `aplicarDescuento(double)`: aplica un porcentaje de descuento al total.
* `mostrarResumen()`: muestra el resumen del pedido: cliente, productos, subtotal, descuento y total final.

El método `mostrarResumen()` debe cerrar el encadenamiento.

El programa principal deberá construir un pedido mediante llamadas encadenadas que simulen un flujo natural, por ejemplo:

```cpp
pedido.setCliente("Ana")
      .addProducto("Portátil", 1200.0)
      .addProducto("Ratón", 25.0)
      .aplicarDescuento(10.0)
      .mostrarResumen();
```

## Ejercicio 4: Clonación de objetos

Crea una jerarquía de clases clonables:

* Una clase abstracta `Figura` con un método virtual `clone()`.
* Dos clases derivadas (`Circulo` y `Rectangulo`) que implementen la clonación profunda. 
    * La clase `Circulo` tendrá un atributo `radio` de tipo `double`. 
    * La clase `Rectangulo` tendrá dos atributos, `ancho` y `alto` también de tipo `double`.
    * Las dos clases tendrán un método `mostrar()` que imprimirán los atributos y las áreas de las figuras.

Permite duplicar objetos desde punteros a `Figura` sin conocer el tipo concreto.

## Ejercicio 5: Semántica de copia y movimiento

Implementa una clase `Buffer` que gestione un vector de enteros. Define explícitamente:

* Constructor de copia y operador de asignación por copia.
* Constructor de movimiento y operador de asignación por movimiento.

Prueba en `main()` la diferencia entre copiar y mover objetos para observar qué operaciones se ejecutan.


