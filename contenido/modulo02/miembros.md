# Miembros de instancia: atributos y métodos

En C++, una **clase** está compuesta por **miembros**, que se dividen en dos grandes categorías:

* **Miembros de datos (atributos)**: variables asociadas a cada objeto, que representan su **estado**.
* **Funciones miembro (métodos)**: funciones asociadas a cada objeto, que representan su **comportamiento**.

Estos elementos se conocen como **miembros de instancia** porque cada objeto creado a partir de una clase tiene su **propio conjunto de atributos** y puede invocar los **mismos métodos**, operando sobre sus propios datos. Los miembros de instancias:

* Permiten que cada objeto tenga su **estado propio**.
* Hacen posible que un mismo método pueda **actuar sobre distintos objetos**, dependiendo de sus atributos.
* Constituyen la **base de la encapsulación**, un principio fundamental de la POO.

## Atributos: miembros de datos

Los atributos son variables definidas dentro de una clase que **almacenan información específica de cada objeto**. Veamos un ejemplo:

```cpp
class Persona {
public:
    std::string nombre;
    int edad;
};
```

Cada objeto de tipo `Persona` tendrá su propio `nombre` y `edad`.

```cpp
Persona p1;
p1.nombre = "Ana";
p1.edad = 30;

Persona p2;
p2.nombre = "Luis";
p2.edad = 25;
```

Aunque ambos objetos comparten la misma estructura (la clase), sus datos son **independientes**.

## Métodos: funciones miembro

Los métodos son funciones que pueden acceder y manipular los atributos del objeto al que pertenecen. Los métodos se pueden declarar:

* Dentro de la clase e implementarse fuera de ella:

    ```cpp
    class Persona {
    public:
        std::string nombre;
        int edad;

        void saludar();  // declaración
    };

    // implementación
    void Persona::saludar() {
        std::cout << "Hola, soy " << nombre << " y tengo " << edad << " años.\n";
    }
    ```

* Directamente dentro de la clase. Esto los convierte en funciones `inline` por defecto, es decir, el compilador puede insertar el código del método directamente en los lugares donde se invoque, es una **recomendación**, si se hace el código será más efiiciente porque nos ahorramos el coste de la llamada a la función.

    ```cpp
    class Persona {
    public:
        std::string nombre;
        int edad;

        void saludar() {
            std::cout << "Hola, soy " << nombre << " y tengo " << edad << " años.\n";
        }
    };
    ```

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


## Acceso implícito a los atributos

Dentro de un método, se puede acceder directamente a los atributos sin usar prefijos:

```cpp
void Persona::saludar() {
    std::cout << nombre;  // se entiende que es this->nombre
}
```

Internamente, C++ utiliza un puntero especial llamado `this`, que apunta al objeto actual. Por lo tanto, las siguientes expresiones son equivalentes:

```cpp
nombre           // acceso implícito
this->nombre     // acceso explícito
```


## Ejemplo completo

```cpp
#include <iostream>
#include <string>

class Persona {
public:
    std::string nombre;
    int edad;

    void presentarse() {
        std::cout << "Hola, me llamo " << nombre << " y tengo " << edad << " años.\n";
    }

    void cumplirAnios() {
        edad++;
    }
};

int main() {
    Persona p;
    p.nombre = "Carlos";
    p.edad = 40;

    p.presentarse();  // Hola, me llamo Carlos y tengo 40 años.
    p.cumplirAnios();
    p.presentarse();  // Hola, me llamo Carlos y tengo 41 años.
}
```
