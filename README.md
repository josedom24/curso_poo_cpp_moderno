# Curso de Programación Orientada a Objetos con C++ moderno

1. Fundamentos de la Programación Orientada a Objetos

    * [¿Qué es la programación orientada a objetos?](contenido/modulo01/poo.md)
    * [Los pilares de la programación orientada a objetos](contenido/modulo01/pilares.md)

2. Fundamentos básicos de programación orientada a objetos

    * [Clases y objetos](contenido/modulo02/clases.md)
    * [Miembros de instancia: atributos y métodos](contenido/modulo02/miembros.md)
    * [Encapsulamiento y modificadores de acceso (`public`, `private`, `protected`)](contenido/modulo02/acceso.md)
    * [Constructores y destructores](contenido/modulo02/constructor.md)
    * [Inicialización de objetos](contenido/modulo02/objetos.md)
    * [Métodos y objetos constantes](contenido/modulo02/constantes.md)
    * [Inicialización de atributos con listas de inicialización](contenido/modulo02/inicializacion.md)
    * [Métodos getter y setter](contenido/modulo02/getters.md)
    * [Polimorfismo estático: sobrecarga de métodos](contenido/modulo02/sobrecarga.md)
    * [Atributos y métodos estáticos](contenido/modulo02/estatico.md)
    * [Ejercicios sobre clases y objetos](contenido/modulo02/ejercicios.md)
    
3. Gestión de memoria dinámica

    * [Introducción a la gestión de recursos en C++ moderno](contenido/modulo03/introduccion.md)
    * [Gestión manual de memoria dinámica](contenido/modulo03/memoria.md)
    * [Propiedad de recursos y patrón RAII](contenido/modulo03/raii.md)
    * [Gestión de memoria con punteros inteligentes](contenido/modulo03/inteligentes.md)
    * [Clases y punteros inteligentes](contenido/modulo03/clases.md)
    * [Ejercicios sobre gestión de memoria dinámica](contenido/modulo03/ejercicios.md)

4. Relaciones entre clases
    * [Introducción a las relaciones entre clases](contenido/modulo04/introduccion.md)
    * [Dependencia entre clases](contenido/modulo04/dependencia.md)
    * [Asociaciones entre clases](contenido/modulo04/asociacion.md)
    * [Agregación entre clases](contenido/modulo04/agregacion.md)
    * [Composición entre clases](contenido/modulo04/composicion.md)
    * [Ejercicios sobre relaciones de clases](contenido/modulo04/ejercicio1.md)
    * [Herencia: clases base y derivadas](contenido/modulo04/herencia.md)
    * [Herencia y polimorfismo dinámico](contenido/modulo04/polimorfismo.md)
    * [Conversión segura de tipos polimórficos con `dynamic_cast`](contenido/modulo04/cast.md)
    * [Conversiones implícitas y punteros base](contenido/modulo04/conversiones.md)
    * [Ejercicios sobre herencia y polimorfismo](contenido/modulo04/ejercicio2.md)

5. Fundamentos avanzados de programación orientada a objetos
    * [Copia de objetos: superficiales y profundas](contenido/modulo05/copy.md)
    * [Movimiento de objetos](contenido/modulo05/move.md)
    * [Control de creación, copia y movimiento de objetos](contenido/modulo05/creacion.md)
    * [Clonación de objetos](contenido/modulo05/clonacion.md)
    * [Sobrecarga de operadores](contenido/modulo05/operadores.md)
    * [Fluidez de métodos](contenido/modulo05/fluidez.md)
    * [Ejercicios sobre conceptos avanzados de programación orientada a objetos](contenido/modulo05/ejercicios.md)

6. Interfaces y diseño polimórfico

    * [Clases abstractas y métodos virtuales puros](contenido/modulo06/abstracta.md)
    * [Interfaces puras y diseño orientado a contratos](contenido/modulo06/interface.md)
    * [El problema de devolver tipos concretos y objetos polimórficos](contenido/modulo06/concretos.md)
    * [Devolución de interfaces mediante punteros inteligentes](contenido/modulo06/devolucion.md)
    * [Ejercicios sobre interfaces y diseño polimórfico](contenido/modulo06/ejercicios.md)

7. Abstracción del comportamiento

    * [Comportamiento intercambiable y bajo acoplamiento](contenido/modulo07/comportamiento.md)
    * [Delegación de comportamiento mediante interfaces](contenido/modulo07/delegacion.md)
    * [Representación de acciones con funciones lambdas](contenido/modulo07/lambda.md)
    * [Uso de `std::function` para encapsular comportamiento configurable](contenido/modulo07/function.md)
    * [Functores y clases con `operator()`](contenido/modulo07/functor.md)
    * [Inyección de comportamiento mediante composición](contenido/modulo07/composicion.md)
    * [Ejercicios sobre abstracción de comportamiento](contenido/modulo07/ejercicios.md)
    
8. Plantillas de clases y programación genérica

    * [Introducción a las plantillas de clases](contenido/modulo08/plantillas.md)
    * [Clases genéricas con uno o varios parámetros de tipo](contenido/modulo08/parametros.md)
    * [Especialización de plantillas de clase](contenido/modulo08/especializacion.md)
    * [Las plantillas de clase y la STL](contenido/modulo08/stl.md)
    * [Plantilla de clase: `std::optional`](contenido/modulo07/optional.md)
    * [Plantillas de clase:`std::variant` y `std::visit`](contenido/modulo08/variant.md)
    * [Ejercicios sobre programación genérica](contenido/modulo08/ejercicios.md)

9. Proyecto final: Sistema de dispositivos inteligentes

    * [Planteamiento general del proyecto](contenido/modulo09/planteamiento.md)
    * [Clases base y derivadas: diseño de la jerarquía de dispositivos](contenido/modulo09/jerarquia.md)
    * [Implementación del controlador del sistema](contenido/modulo09/controlador.md)
    * [Manejo de eventos genéricos mediante std::variant y std::visit](contenido/modulo09/eventos.md)
    * [Integración en un programa principal](contenido/modulo09/main.md)
    * [Análisis del diseño resultante y conclusiones finales del curso](contenido/modulo09/end.md)