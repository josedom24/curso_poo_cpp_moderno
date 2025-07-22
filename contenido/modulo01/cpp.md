# La programación orientada a objetos en C++ moderno


C++ es un lenguaje multiparadigma, pero históricamente ha sido uno de los principales representantes de la **programación orientada a objetos (POO)**. A lo largo de su evolución, desde su creación como extensión de C en los años 80 hasta los estándares modernos como C++11, C++14, C++17, C++20 y C++23, el lenguaje ha incorporado características poderosas que no solo fortalecen el paradigma orientado a objetos, sino que también introducen mejoras significativas en legibilidad, seguridad, rendimiento y expresividad.

## Fundamentos de la POO en C++

En C++, los elementos clave del paradigma orientado a objetos están completamente integrados en el lenguaje:

* **Clases y Objetos**: Una **clase** en C++ define una estructura de datos que encapsula **atributos** (miembros de datos) y **comportamientos** (métodos o funciones miembro). Un **objeto** es una instancia de una clase.

    En C++ moderno, además de las clases tradicionales, se puede usar:

    * **Constructores delegados**: En C++, los **constructores** son funciones especiales que se utilizan para **inicializar objetos** de una clase en el momento en que se crean. Permiten asignar valores iniciales a los atributos y establecer un estado válido para el objeto desde el comienzo. En versiones anteriores del lenguaje, era común tener varios constructores que repetían parte de la lógica de inicialización, lo cual dificultaba el mantenimiento. Con la llegada de **C++11**, se introdujeron los **constructores delegados**, una mejora que permite a un constructor **llamar a otro constructor de la misma clase** para reutilizar su lógica. Esto permite **centralizar la inicialización** y **evitar la duplicación de código**, haciendo el diseño más limpio, coherente y fácil de mantener.
     para evitar duplicación de código.
    * La **inicialización uniforme** (o *uniform initialization*) introducida en **C++11** unifica y simplifica la forma de inicializar variables y objetos utilizando llaves `{}` en lugar de paréntesis o el operador de asignación. Este enfoque elimina ambigüedades entre distintos tipos de inicialización y mejora la legibilidad del código. Con la inicialización uniforme, se pueden inicializar atributos, objetos, arrays, listas y estructuras de manera consistente, además de permitir la inicialización de miembros con valores por defecto. También es más segura, ya que impide conversiones implícitas peligrosas, lo que favorece un código más robusto y predecible.
    * En C++ moderno (a partir de C++11), **es posible asignar valores por defecto directamente a los miembros de datos** en la propia declaración dentro de la clase. Esta característica permite simplificar la escritura de constructores, ya que no es necesario inicializar manualmente todos los atributos en cada constructor si ya tienen un valor predeterminado. 

* **Encapsulación**: C++ permite controlar el acceso a los miembros de una clase mediante los **modificadores de acceso**:

    * `private`: Solo accesible dentro de la clase.
    * `protected`: Accesible en la clase y en sus derivadas.
    * `public`: Accesible desde cualquier parte.

    En C++ moderno, también se pueden usar:

    * Los métodos `getter` y `setter` en C++ sirven para acceder y modificar de forma segura los atributos privados de una clase, respetando el principio de encapsulación. En C++ moderno, suelen definirse **en línea** dentro de la clase para que el compilador pueda optimizarlos mejor y mejorar el rendimiento. Además, declararlos como `constexpr` permite que, cuando sea posible, se evalúen en tiempo de compilación, haciendo el código más eficiente.
    * La **inicialización directa de miembros privados mediante listas de inicialización** es una práctica que consiste en asignar valores a los atributos de una clase directamente en la lista de inicialización del constructor, antes de que el cuerpo del constructor se ejecute. Esto permite inicializar los miembros de forma eficiente, especialmente para tipos complejos o constantes, ya que evita la creación de objetos temporales o la asignación posterior dentro del cuerpo del constructor. 

* **Abstracción**: C++ proporciona abstracción a través de:

    * **Clases abstractas** son aquellas que contienen al menos un método virtual puro y no pueden instanciarse directamente, sirviendo como base para otras clases.
    * **Interfaces** que se simulan mediante clases que solo tienen métodos virtuales puros y no contienen datos, definiendo un contrato que las clases derivadas deben implementar.
    * **Funciones virtuales**, métodos que permiten que las clases derivadas redefinan su comportamiento, habilitando el polimorfismo en tiempo de ejecución.

    Con C++ moderno, se puede mejorar la abstracción utilizando:

    * `override` y `final` se usan para indicar explícitamente que un método redefine uno virtual de la clase base o que no puede ser redefinido, mejorando la claridad y evitando errores.
    * `=default` y `=delete` permiten controlar si se generan automáticamente ciertas funciones especiales (como constructores o operadores) o si se prohíbe su uso.
    * Las clases `struct` en C++ son tipos ligeros cuya diferencia principal con `class` es que sus miembros son públicos por defecto, facilitando estructuras de datos simples.

## Herencia y jerarquías de clases en C++

C++ permite la creación de **jerarquías de clases** mediante herencia, tanto **simple** como **múltiple**. Las clases derivadas heredan atributos y métodos de las clases base.

* **Herencia Simple**: Permite extender una clase base agregando o modificando funcionalidades.

    ```cpp
    class Animal {
    public:
        void hacerSonido() {
            // Sonido genérico
            std::cout << "Sonido de animal" << std::endl;
        }
    };
    
    class Perro : public Animal {
    public:
        void hacerSonido() {
            // Sonido específico de perro
            std::cout << "Guau guau" << std::endl;
        }
    };
    ```
    * `Animal` es la clase base que tiene un método `hacerSonido()` con una implementación genérica.
    * `Perro` es una clase derivada que **hereda** de `Animal` con `public`.
    * La clase `Perro` **sobrescribe** el método `hacerSonido()` para dar un comportamiento específico (el ladrido).
    * La herencia simple permite que `Perro` reutilice o modifique el comportamiento de `Animal`.
    * Cuando se llama a `hacerSonido()` en un objeto `Perro`, se ejecuta la versión específica del perro.

* **Herencia Múltiple**: C++ permite que una clase derive de más de una clase base, lo cual puede ser útil, pero debe usarse con precaución para evitar ambigüedades.

```cpp
class Electrico {
public:
    void cargarBateria();
};

class Vehiculo {
public:
    void arrancar();
};

class CocheElectrico : public Vehiculo, public Electrico {
    // Combina funcionalidades
};
```

* `Electrico` es una clase que define el método `cargarBateria()`, relacionado con la carga eléctrica.
* `Vehiculo` es otra clase que define el método `arrancar()`, relacionado con el funcionamiento general del vehículo.
* `CocheElectrico` hereda **simultáneamente** de `Vehiculo` y de `Electrico`, combinando ambas funcionalidades en un solo objeto.
* La herencia múltiple permite que `CocheElectrico` tenga tanto el comportamiento de un vehículo convencional (`arrancar()`) como el de un vehículo eléctrico (`cargarBateria()`).
* En herencia múltiple, las ambigüedades ocurren cuando dos o más clases base tienen métodos o atributos con el mismo nombre, y el compilador no sabe cuál usar. Para resolverlo, se debe especificar explícitamente la clase base a la que pertenece el miembro mediante el operador de resolución de ámbito.

## Polimorfismo en C++

C++ implementa dos formas principales de polimorfismo:

* **Polimorfismo en tiempo de compilación** (estático): En este método se incluyen los siguientes mecanismos:

    * **Sobrecarga de funciones**: múltiples funciones con el mismo nombre pero diferentes parámetros.
    * **Sobrecarga de operadores**: redefinición del comportamiento de operadores para tipos definidos por el usuario.
    * **Plantillas (templates)**: permiten escribir código genérico reutilizable.

* **Polimorfismo en tiempo de ejecución** (dinámico): permite que un mismo puntero o referencia a una clase base ejecute métodos diferentes según el tipo real del objeto en tiempo de ejecución. Se logra mediante el uso de:

    * **Punteros o referencias a clases base**, que pueden referirse a objetos de cualquier clase derivada.
    * Las funciones que se desean redefinir en las clases derivadas se declaran como **`virtual`**, indicando que la llamada debe resolverse dinámicamente.
    * Esto garantiza que, aunque se use una referencia o puntero a la clase base, se ejecute la versión correcta del método correspondiente a la clase derivada.
    * La palabra clave **`override`** se utiliza para indicar explícitamente que un método redefine uno virtual de la clase base, mejorando la claridad y ayudando a detectar errores en tiempo de compilación.
    * En conjunto, estas características permiten crear código más flexible y extensible mediante polimorfismo dinámico.

## Recursos modernos para la programación orientada a objetos en C++

* **Smart Pointers (`std::unique_ptr`, `std::shared_ptr`)**: Los **punteros inteligentes** nos proporcionan un manejo seguro y automático de memoria dinámica. Facilitan la gestión de objetos sin fugas de memoria.

    Ejemplo:

    ```cpp
    std::unique_ptr<Coche> coche = std::make_unique<Coche>();
    ```

    * **Gestión automática de memoria:** El puntero inteligente `std::unique_ptr` libera automáticamente la memoria del objeto `Coche` cuando deja de usarse, evitando fugas de memoria.
    * **Propiedad única:** `std::unique_ptr` garantiza que solo exista un propietario del objeto, lo que previene problemas de acceso concurrente o eliminación accidental desde múltiples lugares.
    * **Seguridad ante excepciones:** Al gestionar la memoria automáticamente, los punteros inteligentes evitan pérdidas de recursos incluso si ocurren excepciones en el código.
    * **Código más limpio y seguro:** No es necesario llamar manualmente a `delete`, lo que reduce errores humanos y hace el código más legible.
    * **Facilita el uso del polimorfismo:** Puede almacenar objetos derivados en punteros a clases base sin perder el control de la memoria.
    * En el ejemplo, `std::make_unique<Coche>()` crea y asigna un nuevo objeto `Coche` a un `std::unique_ptr`, asegurando que la gestión de memoria sea automática y eficiente.


* **`std::optional`, `std::variant`, `std::any`**: Son **plantillas genéricas** de tipo **contenedor**, que facilitan la construcción de objetos que pueden representar diferentes tipos o estados.

    * `std::optional` permite retornar objetos que podrían no existir.
    * `std::variant` modela objetos con múltiples posibles tipos.
    * `std::any` permite almacenar cualquier tipo.

