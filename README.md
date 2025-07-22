# Curso de Programación Orientada a Objetos con C++ moderno

1. Fundamentos de la Programación Orientada a Objetos

    * [¿Qué es la programación orientada a objetos?](contenido/modulo01/poo.md)
    * [Los pilares de la programación orientada a objetos](contenido/modulo01/pilares.md)
    * [La programación orientada a objetos en C++ moderno](contenido/modulo01/cpp.md)
    

2. Programación orientada a objetos en C++ moderno

    * Clases y objetos
    * Miembros de instancia: atributos y métodos
    * Encapsulamiento y modificadores de acceso (`public`, `private`, `protected`)
    * Constructores, destructores y métodos constantes
    * Inicialización de atributos con listas de inicialización
    * Métodos getter y setter: motivación, sintaxis y buenas prácticas
    * Sobrecarga de operadores aritméticos y de comparación
    * Atributos y métodos estáticos
    * Fluidez de métodos (`return   *this`)

3. Relaciones entre clases

    * Agregación y composición: diferencias y ejemplos
    * Asociaciones entre objetos y responsabilidades
    * Introducción a la herencia: clases base y derivadas
    * Herencia y polimorfismo en C++
    * Conversiones implícitas y punteros base
    * El papel del `virtual` y el uso correcto de `override`
    * Finalización de métodos y clases con `final`

4. Gestión avanzada de objetos

    * Uso de punteros inteligentes en la gestión de memoria dinámica
    * Semántica de copia y movimiento: constructor de copia, constructor de movimiento, operadores de asignación
    * Copias superficiales vs. profundas y su implicación en clases
    * Clonación de objetos mediante interfaces (`clone`)
    * Composición de objetos con punteros inteligentes
    * Uso práctico de `std::unique_ptr` y `std::shared_ptr` en clases

5. Interfaces y diseño polimórfico

    * Clases abstractas y métodos virtuales puros
    * Interfaces puras y su implementación
    * Devolución de interfaces mediante punteros inteligentes
    * Separación entre interfaz y detalle de implementación (Pimpl idiom)
    * Diseño orientado a contratos y principios de responsabilidad

6. Abstracción de comportamiento y composición flexible

    * Motivación: comportamiento intercambiable y bajo acoplamiento
    * Delegación de comportamiento mediante interfaces
    * Representación de acciones con lambdas (funciones anónimas)
    * Uso de std::function para encapsular comportamiento configurable
    * Functores (objetos invocables) y clases con operator()
    * Inyección de comportamiento: composición y estrategia
    * Comparación entre interfaces, lambdas, functores y std::function
    * Buenas prácticas para desacoplar lógica y facilitar pruebas
 
7. Plantillas de clases y programación genérica

    * Introducción a las plantillas de clases
    * Clases genéricas con uno o varios parámetros de tipo
    * Uso de plantillas para reutilización de código
    * Especialización de clases plantilla
    * Interacción con la STL desde la perspectiva de plantillas
    * Ventajas y precauciones en el uso de plantillas
    * [Plantilla de clase: `std::optional`](contenido/modulo07/optional.md)
    * Uso de `std::variant` y `std::visit` para patrones de diseño

8. Principios de diseño orientado a objetos

    * Abstracción, encapsulamiento, herencia y polimorfismo en profundidad
    * Introducción a los principios SOLID
    * Cohesión, acoplamiento y reutilización
    * Diseño de clases orientado al cambio y la extensión
    * Buenas prácticas en el diseño de APIs orientadas a objetos

9. Ejercicios y mini-proyectos orientados a objetos

    * Ejercicios integradores de modelado de clases
    * Ejercicios de herencia, polimorfismo y composición
    * Ejercicios de clonación, RAII y punteros inteligentes
    * Implementación de jerarquías de clases reutilizables
    * Mini-proyecto: sistema de gestión de biblioteca / inventario / juego simple por consola

