# Ejercicios sobre conceptos avanzados de programación orientada a objetos

## Ejercicio 1: Copia y movimiento de objetos

Diseña una clase `Imagen` que simule la gestión de un recurso gráfico en memoria.
Cada objeto `Imagen` contendrá un identificador y un vector de píxeles (simulado con `std::vector<int>`).

Implementa:

* **Constructor con tamaño e identificador**, que reserve un número dado de píxeles.
* **Constructor de copia** y **operador de asignación por copia**, que dupliquen la imagen.
* **Constructor de movimiento** y **operador de asignación por movimiento**, que transfieran los píxeles de una imagen a otra usando `std::move`.
* Un método `mostrar()` que imprima el identificador y el tamaño actual del vector de píxeles.

En `main()`, crea y mueve imágenes para observar qué operaciones se ejecutan.

Perfecto 👍
Tu intuición es correcta: **los ejercicios están muy bien diseñados** y solo necesitan **reordenarse** para seguir la secuencia lógica del nuevo orden de apartados del módulo.

Recordemos el nuevo orden didáctico del módulo 5:

1. Copia de objetos: superficiales y profundas
2. Movimiento de objetos
3. Control de creación, copia y movimiento de objetos
4. Clonación de objetos
5. Sobrecarga de operadores
6. Fluidez de métodos

Por tanto, los ejercicios deben reflejar esa progresión conceptual.

Aquí te dejo el **orden actualizado y coherente**, sin cambiar los enunciados ni las temáticas (solo los títulos y numeración):

Perfecto ✅
Siguiendo tu línea didáctica, aquí tienes un **nuevo Ejercicio 2** con una **temática diferente**, pero que sigue enseñando el mismo concepto: **controlar la creación, copia y movimiento de objetos**.

He elegido un contexto realista y comprensible: **gestión de una conexión de base de datos**.
La clase `ConexionBD` representa un recurso que **no puede duplicarse**, pero puede **moverse** (transferir la conexión).

---

## Ejercicio 2: Control de creación, copia y movimiento

Diseña una clase `ConexionBD` que represente una conexión a una base de datos.
Por razones de seguridad y gestión de recursos:

* No debe poder **copiarse** (dos objetos no pueden compartir la misma conexión).
* Sí debe poder **moverse** (una conexión puede transferirse de un objeto a otro).
* Su **creación debe estar controlada** mediante una función estática o amiga.

1. La clase `ConexionBD` debe tener:

   * Un **constructor privado** que reciba el nombre de la base de datos.
   * Un método público `conectar()` que muestre un mensaje simulando la conexión.
   * Un método `cerrar()` que indique el cierre de la conexión.
   * Un método `estaConectada()` que devuelva `true` o `false`.
   * Una **función estática** `crearConexion(const std::string&)` que devuelva un objeto `ConexionBD` válido.

2. Control del ciclo de vida:

   * Prohíbe la **copia** con `= delete`.
   * Permite el **movimiento** (`= default` o implementación manual).
   * Muestra por consola mensajes cuando se construye, mueve o destruye el objeto.


## Ejercicio 3: Clonación de objetos

Crea una jerarquía de clases clonables:

* Una clase abstracta `Figura` con un método virtual `clone()`.
* Dos clases derivadas (`Circulo` y `Rectangulo`) que implementen la clonación profunda.

  * `Circulo` tendrá un atributo `radio` de tipo `double`.
  * `Rectangulo` tendrá atributos `ancho` y `alto` de tipo `double`.
  * Ambas clases tendrán un método `mostrar()` que imprima los atributos y el área.

Permite duplicar objetos desde punteros a `Figura` sin conocer el tipo concreto.


## Ejercicio 4: Sobrecarga de operadores

Crea una clase `Punto2D` que represente un punto en el plano.
Implementa la sobrecarga de operadores para:

* `+` (suma de dos puntos).
* `-` (resta de dos puntos).
* `==` (comparación de igualdad).
* `<<` (impresión en flujo en formato `(x, y)`).


## Ejercicio 5: Fluidez de métodos

Diseña una clase `Pedido` que permita construir y configurar un **pedido en línea** de forma **fluida y legible**.

Implementa los métodos:

* `setCliente(const std::string&)`
* `addProducto(const std::string&, double)`
* `aplicarDescuento(double)`
* `mostrarResumen()`

El método `mostrarResumen()` debe cerrar el encadenamiento.

Ejemplo de uso:

```cpp
pedido.setCliente("Ana")
      .addProducto("Portátil", 1200.0)
      .addProducto("Ratón", 25.0)
      .aplicarDescuento(10.0)
      .mostrarResumen();
```
