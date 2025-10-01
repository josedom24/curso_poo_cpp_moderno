# Ejercicios de programación orientada a objetos

## Ejercicio 1: Clase `Rectangulo`

Define una clase llamada `Rectangulo` que represente un rectángulo con los atributos `base` y `altura`. Ambos deben ser `double` y estar encapsulados como privados.

La clase debe incluir:

* Un **constructor** que reciba `base` y `altura` como parámetros.
* Un método `double area() const` que devuelva el área del rectángulo.
* Un método `double perimetro() const` que devuelva el perímetro.
* Métodos **setters y getters** para cada atributo.
* En el `main`, crea al menos dos objetos `Rectangulo` y muestra su área y perímetro.

## Ejercicio 2: Composición con clase `Empleado` y `Fecha`


Define dos clases:

1. `Fecha`: representa una fecha con `dia`, `mes` y `anio` (todos enteros).

   * Incluye un constructor con inicialización uniforme y un método `mostrar()` que imprima la fecha en formato `dd/mm/aaaa`.

2. `Empleado`: representa un empleado con `nombre` (string) y una fecha de incorporación (`Fecha`, como objeto miembro).

   * Incluye un constructor que reciba el nombre y una fecha.
   * Incluye un método `mostrar()` que muestre el nombre y la fecha de incorporación.
   * Incluye un **destructor** que imprima un mensaje indicando que el objeto se ha destruido.

En el `main`, crea un empleado y llama al método `mostrar()`.

Perfecto, aquí tienes el **Ejercicio 3** completamente reformulado con la **sugerencia adicional integrada**: un método virtual adicional que permite practicar **polimorfismo de comportamiento** mediante métodos que devuelven valores distintos según la clase derivada.

## Ejercicio 3: Herencia y Polimorfismo con clase `Curso`

Define una clase base llamada `Curso`, que represente un curso general. Esta clase debe contener:

* Un atributo `titulo` de tipo `std::string` (privado).
* Un constructor que inicialice el título mediante **inicialización uniforme**.
* Un método virtual `void describir() const` que imprima `"Curso general: [título]"`.
* Un método virtual `double costo() const` que devuelva un valor base, por ejemplo `0.0`.
* Un **destructor virtual**.

Después, define dos clases derivadas:

`CursoPresencial`

* Atributo adicional: `aula` (`std::string`).
* El método `describir()` debe imprimir:
  `"Curso presencial en aula [aula]: [título]"`.
* El método `costo()` debe devolver un valor fijo, por ejemplo, `200.0`.

`CursoEnLinea`

* Atributo adicional: `plataforma` (`std::string`).
* El método `describir()` debe imprimir:
  `"Curso en línea en [plataforma]: [título]"`.
* El método `costo()` debe devolver un valor distinto, por ejemplo, `100.0`.

Tienes que tener en cuenta:

* Usa **inicialización uniforme** en todos los constructores (`:` con llaves `{}`).
* Usa la palabra clave `override` para los métodos sobrescritos.
* Implementa un **destructor virtual** en la clase base para asegurar destrucción adecuada.
* Implementa una función auxiliar:

    ```cpp
    void mostrarInformacionCurso(const Curso& curso) {
        curso.describir();
        std::cout << "Costo: " << curso.costo() << " euros\n";
    }
    ```

En la función principal:

* Crea un `std::vector<std::unique_ptr<Curso>>`.
* Añade varios objetos `CursoPresencial` y `CursoEnLinea`.
* Recorre el vector llamando a `mostrarInformacionCurso()` con cada elemento.
* Observa cómo se comporta el polimorfismo al llamar a `describir()` y `costo()` a través de punteros a la clase base.

Ejemplo de salida esperada:

```
Curso presencial en aula B203: Programación C++
Costo: 200 euros
Curso en línea en Udemy: Introducción a Python
Costo: 100 euros
```

