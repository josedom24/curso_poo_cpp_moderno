# Miembros de instancia: atributos y métodos

En C++, una clase está compuesta por **miembros**, que se dividen en dos grandes categorías:

* **Miembros de datos (atributos):** variables que representan el estado de cada objeto.
* **Funciones miembro (métodos):** funciones que representan el comportamiento de los objetos.

Se llaman *miembros de instancia* porque cada objeto creado a partir de una clase tiene su **propio conjunto de atributos**, pero puede invocar los mismos métodos sobre sus propios datos.

Esto permite que:

* Cada objeto tenga un estado independiente.
* Un mismo método actúe de forma diferente según los atributos del objeto.
* Se logre encapsulación, uno de los principios básicos de la POO.

## Atributos

Los atributos son variables definidas dentro de una clase. Cada objeto tendrá copias propias de esos atributos.

Ejemplo conceptual:

```
class Persona {
    std::string nombre;
    int edad;
};
```

* Cada objeto de tipo `Persona` tendrá su propio `nombre` y `edad`.
* Aunque todos los objetos comparten la misma estructura, sus datos son independientes.

## Métodos

Los métodos son funciones que pueden acceder y modificar los atributos del objeto. Se pueden declarar de dos formas:

1. **Declaración en la clase e implementación fuera de ella:**

   ```
   class Persona {
       void saludar(); // Declaración
   };

   void Persona::saludar() { /* implementación */ }
   ```

2. **Definición directa en la clase:**

   ```
   class Persona {
       void saludar() { /* implementación */ }
   };
   ```

En este caso, se convierten en funciones *inline* por defecto, lo que puede mejorar el rendimiento al evitar el coste de la llamada.


## Paso de parámetro y retorno en métodos

Los métodos, al ser funciones miembro, pueden recibir argumentos y retornar valores como cualquier función en C++. Existen varias formas de pasar parámetros, y cada una tiene implicaciones en rendimiento, seguridad y mutabilidad.

Paso de parámetros en métodos:

* **Por valor**

   ```cpp
   void setEdad(int nuevaEdad);
   ```

   * Se pasa una copia del argumento.
   * No afecta al valor original.
   * Puede ser costoso si el tipo de dato es complejo (como objetos grandes).

* **Por referencia**

   ```cpp
   void actualizarNombre(std::string& nuevoNombre);
   ```

   * El parámetro es un alias del argumento original.
   * Permite modificar el valor fuera del método.
   * Eficiente, pero debe usarse con cuidado si no se desea modificar el original.

* **Por referencia constante**

   ```cpp
   void mostrarNombre(const std::string& nombre) const;
   ```

   * Se pasa por referencia (evitando copia), pero **no se permite modificar** el valor dentro del método.
   * Es la forma recomendada para pasar objetos grandes cuando no se necesita modificarlos.

* **Por puntero**

   ```cpp
   void asignarPuntero(int* ptr);
   ```

   * Permite pasar la dirección de una variable.
   * Puede ser `nullptr`, por lo que requiere comprobaciones.
   * Útil para interfaces de bajo nivel o interoperabilidad con C.

Retorno de valores en métodos:

* **Por valor**

   ```cpp
   std::string obtenerNombre() const;
   ```

   * Se devuelve una copia del resultado.
   * Ideal para tipos simples o cuando se necesita un valor independiente.

* **Por referencia**

   ```cpp
   std::string& referenciaAlNombre();
   ```

   * Devuelve una referencia al miembro interno.
   * Permite modificar el valor directamente, pero puede exponer datos internos (violando encapsulamiento).

* **Por referencia constante**

   ```cpp
   const std::string& nombreConstante() const;
   ```

   * Devuelve una referencia de solo lectura.
   * Muy útil para objetos grandes que no se desea copiar, pero se quiere consultar.

Es conveniente:

* Usar **referencias constantes** para evitar copias innecesarias cuando no se requiere modificar.
* Reservar el paso **por puntero** solo para casos especiales o cuando se espera un valor nulo (`nullptr`).
* Al retornar referencias, asegurar que se refieren a datos **válidos y existentes**.


## Acceso implícito y puntero this

Dentro de un método, se puede acceder a los atributos de forma implícita (`nombre`) o explícita (`this->nombre`).

El puntero especial **`this`** apunta al objeto actual y se utiliza para:

* Diferenciar entre atributos y parámetros con el mismo nombre.
* Implementar *fluidez de métodos* (cuando un método devuelve `*this`).

## Ejemplo completo

```
#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    void presentarse() const {
        std::cout << "Hola, me llamo " << nombre
                  << " y tengo " << edad << " años.\n";
    }

    void cumplirAnios() {
        edad++;
    }

    void cambiarNombre(const std::string& nombre) {
        this->nombre = nombre; // Diferencia entre parámetro y atributo
    }
};

int main() {
    Persona p;
    p.nombre = "Carlos";
    p.edad = 40;

    p.presentarse();       // Hola, me llamo Carlos y tengo 40 años.
    p.cumplirAnios();
    p.cambiarNombre("Carlos Alberto");
    p.presentarse();       // Hola, me llamo Carlos Alberto y tengo 41 años.

    return 0;
}
```

## Representación UML del ejemplo Persona

## Representación UML del ejemplo ampliado

![diagrama1](img/diagrama3.png)