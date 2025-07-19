# Curso de Introducción a C++ Moderno

1. Fundamentos de la programación

    * [¿Qué es un lenguaje de programación?](contenido/modulo01/introduccion.md)
    * [Introducción a C++ moderno](contenido/modulo01/cpp.md)
    * [Instalación de un entorno de desarrollo para C++](contenido/modulo01/instalacion.md)
    * [Estructura de un programa en C++](contenido/modulo01/estructura.md)
    * [Cómo compilar y ejecutar programas](contenido/modulo01/compilacion.md)

2.  Tipos de datos básicos

    * [Tipos de datos fundamentales](contenido/modulo02/tipos.md)
    * [Tipos de datos carácter y booleano](contenido/modulo02/caracter_bool.md)
    * [Tipos de datos numéricos y operaciones aritméticas](contenido/modulo02/numeros.md)
    * [Declaración e inicialización de variables](contenido/modulo02/variables.md)
    * [Declaración e inicialización de constantes](contenido/modulo02/constantes.md)
    * [Conversión de tipos de datos](contenido/modulo02/casting.md)
    * [Introducción a las cadenas de caracteres](contenido/modulo02/cadenas.md)
    * [Conversión de cadenas de caracteres](contenido/modulo02/casting_cadenas.md)
    * [Entrada y salida estándar](contenido/modulo02/entrada_salida.md)
    * [Ejercicios estructura secuencial](contenido/modulo02/secuencial.md)

3. Control de flujo

    * [Operadores relacionales y lógicos](contenido/modulo03/operadores.md)
    * [Estructuras alternativas: if](contenido/modulo03/if.md)
    * [Estructuras alternativas: switch](contenido/modulo03/switch.md)
    * [Ejercicios estructuras alternativas](contenido/modulo03/alternativa.md)
    * [Estructuras repetitivas: while](contenido/modulo03/while.md)
    * [Estructuras repetitivas: do-while](contenido/modulo03/dowhile.md)
    * [Estructuras repetitivas: for](contenido/modulo03/for.md)
    * [Uso específico de variables: contadores, acumuladores e indicadores](contenido/modulo03/variables.md)
    * [Ejercicios estructuras repetitivas](contenido/modulo03/repetitiva.md)

4. Gestión de recursos

    * [Introducción a la gestión de recursos](contenido/modulo04/introduccion.md)
    * [Gestión manual de memoria](contenido/modulo04/memoria.md)
    * [Gestión de memoria con punteros](contenido/modulo04/punteros.md)
    * [Gestión de memoria con referencias](contenido/modulo04/referencias.md)
    * [Propiedad de recursos y patrón RAII](contenido/modulo04/raii.md)
    * [Gestión de memoria con punteros inteligentes](contenido/modulo04/propiedad.md)

5. Programación estructurada

    * [Introducción a la programación estructurada y uso de funciones](contenido/modulo05/funciones.md)
    * [Paso de argumentos a funciones](contenido/modulo05/argumentos.md)
    * [Valores de retorno de una función](contenido/modulo05/retorno.md)
    * [Ámbito y duración de las variables en funciones](contenido/modulo05/ambito.md)
    * [Tipos de funciones: constexpr, inline, lambda y recursivas](contenido/modulo05/tipos.md)
    * [Ejercicios con funciones](contenido/modulo05/ejercicios.md)

6. Tipos de datos compuestos

    * [Tipos definidos por el usuario: `enum class`](contenido/modulo06/enum.md)
    * [Tipos definidos por el usuario: `struct`](contenido/modulo06/struct.md)
    * [Cadenas de caracteres: `std::string`](contenido/modulo06/string.md)
    * [Arreglos: `std::array`](contenido/modulo06/array.md)
    * [Vectores: `std::vector`](contenido/modulo06/vector.md)
    * [Listas: `std::list`](contenido/modulo06/list.md)
    * [Mapas: `std::map` y `std::unordered_map`](contenido/modulo06/map.md)
    * [Algoritmos de la Biblioteca Estándar de C++](contenido/modulo06/algoritmos.md)
    * [Ejercicios con `std::string`](contenido/modulo06/ejercicios_string.md)
    * [Ejercicios con `std::array`](contenido/modulo06/ejercicios_array.md)
    * [Ejercicios con `std::vector`](contenido/modulo06/ejercicios_vector.md)
    * [Ejercicios con `std::list`](contenido/modulo06/ejercicios_list.md)
    * [Ejercicios con `std::map` y `std::unordered_map`](contenido/modulo06/ejercicios_map.md)
    

7. Programación orientada a objeto/

    * [Introducción a la Programación Orientada a Objetos](contenido/modulo07/introduccion.md)
    * [Definición de clases y creación de objetos](contenido/modulo07/poo_c++.md)
    * [Atributos estáticos de clase](contenido/modulo07/estatico.md)
    * [Constructores, destructores y métodos constantes](contenido/modulo07/constructor.md)
    * [Composición de Objetos](contenido/modulo07/composicion.md)
    * [Herencia y polimorfismo](contenido/modulo07/herencia.md)
    * [Ejercicios de programación orientada a objetos](contenido/modulo07/ejercicios.md)


8. Excepciones y trabajo con archivos
    * [Introducción a las excepciones](contenido/modulo08/excepciones.md)
    * [Introducción al trabajo con archivos](contenido/modulo08/archivos.md)
    * [Apertura, lectura y escritura de archivos](contenido/modulo08/operaciones.md)
    * [Ejercicios con archivos](contenido/modulo08/ejercicios.md)

---

# Curso de patrones de diseño con C++

1. Principios SOLID y patrones de diseño
    * SOLID: Principios de diseño orientado a objetos
    * ¿Qué son los patrones de diseño?
    * Patrones de diseño con C++ moderno

2. Funciones avanzadas y abstracción de comportamiento

    * [Uso de lambdas para comportamiento flexible](contenido/modulo2/lambda.md)
    * [`std::function` para callbacks o comportamientos configurables](contenido/modulo2/function.md)
    * [Clases functoras y lambdas como objetos de primera clase](contenido/modulo2/functor.md)
    * [Ejercicios sobre abstracción de comportamiento](contenido/modulo2/ejercicios.md)
    * [Plantilla de clase: `std::optional`](contenido/modulo2/plantilla.md)
    * Uso de std::variant y std::visit para patrones de diseño

3. Profundización en POO y diseño de interfaces

    * [Ampliación de constructores: control de creación y copia de objetos](contenido/modulo3/constructor.md)
    * [Clases abstractas y métodos virtuales](contenido/modulo3/constructor.md)
    * [Interfaces puras y uso correcto de `override`](contenido/modulo3/abstracta.md)
    * [Uso de `override` y `final`](contenido/modulo3/override.md)
    * [Devolución de interfaces mediante punteros inteligentes](contenido/modulo3/devolucion.md)
    * [Separación entre interfaz y detalle de implementación](contenido/modulo3/separacion.md)
    * [Fluidez de métodos](contenido/modulo3/fluidez.md)
    * [Ejercicios sobre profundización de POO](contenido/modulo3/ejercicios.md)

4. Gestión avanzado de recursos 

    * [Semántica de copia y movimiento](contenido/modulo4/move.md)
    * [Uso práctico de `std::unique_ptr` y `std::shared_ptr` en clases](contenido/modulo4/small_pointer.md)
    * [Clonación de objetos: copias superficiales y profundas](contenido/modulo4/clonacion.md)
    * [Composición de objetos con punteros inteligentes](contenido/modulo4/composicion.md)


5. Patrones Creacionales

    * [Singleton](contenido/modulo5/singleton.md)
    * [Factory Method](contenido/modulo5/factory_method.md)
    * [Abstract Factory](contenido/modulo5/abstract_factory.md)
    * [Builder](contenido/modulo5/builder.md)
    * [Prototype](contenido/modulo5/prototype.md)

6. Patrones Estructurales

    * [Adapter](contenido/modulo6/adapter.md)
    * [Decorator](contenido/modulo6/decorator.md)
    * Composite
    * Facade
    * Bridge
    * Proxy

7. Patrones de Comportamiento

    * Strategy (usando plantillas y polimorfismo moderno)
    * Observer (con `std::function` y lambdas como callbacks)
    * Command
    * Template Method (esqueleto de un algoritmo dejando pasos a subclases)
    * Iterator (introduciendo ranges de C++20 si se desea)
    * Visitor
    * State
    * Memento (opcional)
    * Chain of Responsibility (opcional)
    
8. Proyecto final

---

# POO

Aquí tienes un índice detallado y estructurado para tu **curso de Programación Orientada a Objetos en C++ moderno**, con bloques temáticos y clases individuales. Se han reorganizado y enriquecido los contenidos que ya tienes, y se han añadido conceptos clave para un enfoque moderno, completo y progresivo del paradigma orientado a objetos.

---

## 🧠 Curso de Programación Orientada a Objetos en C++ Moderno

---

### 1. Fundamentos de la Programación Orientada a Objetos

* Introducción a la Programación Orientada a Objetos
* Clases y objetos en C++ moderno
* Miembros de instancia: atributos y métodos
* Encapsulamiento y modificadores de acceso (`public`, `private`, `protected`)
* Atributos y métodos estáticos

---

### 2. Diseño básico de clases

* Constructores, destructores y métodos constantes
* Inicialización de atributos con listas de inicialización
* Métodos getter y setter: motivación, sintaxis y buenas prácticas
* Sobrecarga de operadores aritméticos y de comparación
* Fluidez de métodos (`return *this`)
* Composición de objetos

---
### 2 bis. Introducción al modelado con UML

* ¿Qué es UML y por qué es útil en programación orientada a objetos?
* Diagramas de clases UML: clases, atributos, métodos, visibilidad
* Representación de relaciones: asociación, agregación, composición
* Herencia y clases abstractas en UML
* De clases a código: cómo convertir diagramas UML en C++
* Ejercicios prácticos: dibujar y analizar diagramas UML simples
---


### 3. Relaciones entre clases

* Agregación y composición: diferencias y ejemplos
* Asociaciones entre objetos y responsabilidades
* Introducción a la herencia: clases base y derivadas
* Herencia y polimorfismo en C++
* Conversiones implícitas y punteros base
* El papel del `virtual` y el uso correcto de `override`
* Finalización de métodos y clases con `final`
---

### 4. Interfaces y diseño polimórfico

* Clases abstractas y métodos virtuales puros
* Interfaces puras y su implementación
* Devolución de interfaces mediante punteros inteligentes
* Separación entre interfaz y detalle de implementación
* Diseño orientado a contratos y principios de responsabilidad

---

### 5. Gestión avanzada de objetos

* Semántica de copia y movimiento: constructor de copia, constructor de movimiento, operadores de asignación
* Copias superficiales vs. profundas y su implicación en clases
* Clonación de objetos mediante interfaces (`clone`)
* Composición de objetos con punteros inteligentes
* Uso práctico de `std::unique_ptr` y `std::shared_ptr` en clases

---

### 6. Plantillas de clases y programación genérica

* Introducción a las plantillas de clases
* Clases genéricas con uno o varios parámetros de tipo
* Uso de plantillas para reutilización de código
* Especialización de clases plantilla
* Interacción con la STL desde la perspectiva de plantillas
- Clases functoras y uso de `operator()`
* Ventajas y precauciones en el uso de plantillas

---

### 7. Principios de diseño orientado a objetos

* Abstracción, encapsulamiento, herencia y polimorfismo en profundidad
* Introducción a los principios SOLID
* Cohesión, acoplamiento y reutilización
* Diseño de clases orientado al cambio y la extensión
* Buenas prácticas en el diseño de APIs orientadas a objetos

---

### 8. Ejercicios y mini-proyectos orientados a objetos

* Ejercicios integradores de modelado de clases
* Ejercicios de herencia, polimorfismo y composición
* Ejercicios de clonación, RAII y punteros inteligentes
* Implementación de jerarquías de clases reutilizables
* Mini-proyecto: sistema de gestión de biblioteca / inventario / juego simple por consola

---

## 🧭 Curso de Introducción a C++ Moderno (versión revisada)

---

### 1. Fundamentos de la programación

* ¿Qué es un lenguaje de programación?
* Introducción a C++ moderno
* Instalación de un entorno de desarrollo para C++
* Estructura de un programa en C++
* Cómo compilar y ejecutar programas

---

### 2. Tipos de datos básicos

* Tipos de datos fundamentales
* Tipos de datos carácter y booleano
* Tipos de datos numéricos y operaciones aritméticas
* Declaración e inicialización de variables
* Declaración e inicialización de constantes
* Conversión de tipos de datos
* Introducción a las cadenas de caracteres
* Conversión de cadenas de caracteres
* Entrada y salida estándar
* **Ejercicios: estructura secuencial**

---

### 3. Control de flujo

* Operadores relacionales y lógicos
* Estructuras alternativas: `if`
* Estructuras alternativas: `switch`
* **Ejercicios: estructuras alternativas**
* Estructuras repetitivas: `while`
* Estructuras repetitivas: `do-while`
* Estructuras repetitivas: `for`
* Uso específico de variables: contadores, acumuladores e indicadores
* **Ejercicios: estructuras repetitivas**

---

### 4. Gestión de recursos

* Introducción a la gestión de recursos
* Gestión manual de memoria
* Gestión de memoria con punteros
* Gestión de memoria con referencias
* Propiedad de recursos y patrón RAII
* Gestión de memoria con punteros inteligentes

---

### 5. Programación estructurada

* Introducción a la programación estructurada y uso de funciones
* Paso de argumentos a funciones
* Valores de retorno de una función
* Ámbito y duración de las variables en funciones
* Tipos de funciones: `constexpr`, `inline`, `lambda` y recursivas
* **Ejercicios con funciones**

---

### 6. Tipos de datos compuestos

* Tipos definidos por el usuario: `enum class`
* Tipos definidos por el usuario: `struct`
* Cadenas de caracteres: `std::string`
* Arreglos: `std::array`
* Vectores: `std::vector`
* Listas: `std::list`
* Mapas: `std::map` y `std::unordered_map`
* Algoritmos de la Biblioteca Estándar de C++
* **Introducción a clases y objetos**

  * ¿Qué es una clase? ¿Qué es un objeto?
  * Declaración y uso de clases simples
  * Miembros públicos y privados
  * Constructores por defecto y acceso a atributos
* **Ejercicios: clases básicas**
* **Ejercicios con `std::string`**
* **Ejercicios con `std::array`**
* **Ejercicios con `std::vector`**
* **Ejercicios con `std::list`**
* **Ejercicios con `std::map` y `std::unordered_map`**

---

### 7. Funciones avanzadas y abstracción de comportamiento

* Introducción al paso de funciones como parámetros
* Uso de lambdas para comportamiento flexible
* Captura de variables en lambdas (`[=]`, `[&]`, `[this]`)
* `std::function` para callbacks o comportamientos configurables
* Aplicaciones prácticas: filtros, predicados, transformaciones
* Introducción al concepto de estrategia: cambiar comportamiento sin cambiar estructura
* Comparación práctica: funciones normales vs. lambdas vs. `std::function`
* **Ejercicios sobre abstracción de comportamiento**

---

### 8. Introducción a las plantillas

* ¿Qué es la programación genérica?
* Plantillas de funciones: sintaxis y deducción de tipos
* Ejemplos típicos (`max`, `swap`, `print`)
* Uso de funciones genéricas con contenedores STL
* Ventajas y limitaciones básicas
* **Ejercicios con plantillas de función**

---

### 9. Excepciones y trabajo con archivos

* Introducción a las excepciones
* Manejo de errores y uso de `try`, `catch`, `throw`
* Introducción al trabajo con archivos
* Apertura, lectura y escritura de archivos con `fstream`
* **Ejercicios con archivos**

---

### 10. Buenas prácticas y depuración básica

* Errores comunes de compilación y ejecución
* Uso de mensajes de depuración (`std::cerr`, `assert`)
* Estilo de código y legibilidad
* Organización del código en archivos (`.h` y `.cpp`)
* Introducción al uso del depurador (IDE o `gdb` básico)


---

# Curso de Introducción a C++ Moderno

1. Fundamentos de la programación
    * ¿Qué es un lenguaje de programación?
    * Introducción a C++ moderno
    * Instalación de un entorno de desarrollo para C++
    * Estructura de un programa en C++
    * Cómo compilar y ejecutar programas

2. Tipos de datos básicos
    * Tipos de datos fundamentales
    * Tipos de datos carácter y booleano
    * Tipos de datos numéricos y operaciones aritméticas
    * Declaración e inicialización de variables
    * Declaración e inicialización de constantes
    * Conversión de tipos de datos
    * Introducción a las cadenas de caracteres
    * Conversión de cadenas de caracteres
    * Entrada y salida estándar
    * Ejercicios estructura secuencial
     
3. Control de flujo
    * Operadores relacionales y lógicos
    * Estructuras alternativas: if
    * Estructuras alternativas: switch
    * Ejercicios estructuras alternativas
    * Estructuras repetitivas: while
    * Estructuras repetitivas: do-while
    * Estructuras repetitivas: for
    * Uso específico de variables: contadores, acumuladores e indicadores
    * Ejercicios estructuras repetitivas

4. Gestión de recursos
    * Introducción a la gestión de recursos
    * Gestión manual de memoria
    * Gestión de memoria con punteros
    * Gestión de memoria con referencias
    * Propiedad de recursos y patrón RAII
    * Gestión de memoria con punteros inteligentes

5. Programación estructurada
    * Introducción a la programación estructurada y uso de funciones
    * Paso de argumentos a funciones
    * Valores de retorno de una función
    * Ámbito y duración de las variables en funciones
    * Tipos de funciones: constexpr, inline, lambda y recursivas
    * Ejercicios con funciones

6. Tipos de datos compuestos
    * Tipos definidos por el usuario: enum class
    * Tipos definidos por el usuario: struct
    * Tipos definidos por el usuario: clases y objetos
    * Cadenas de caracteres: std::string
    * Arreglos: std::array
    * Vectores: std::vector
    * Listas: std::list
    * Mapas: std::map y std::unordered_map
    * Algoritmos de la Biblioteca Estándar de C++
    * Ejercicios con std::string
    * Ejercicios con std::array
    * Ejercicios con std::vector
    * Ejercicios con std::list
    * Ejercicios con std::map y std::unordered_map

7. Funciones avanzadas y abstracción de comportamiento

    * Introducción al paso de funciones como parámetros
    * Uso de lambdas para comportamiento flexible
    * Captura de variables en lambdas (`[=]`,` [&]`, `[this]`)
    * `std::function` para callbacks o comportamientos configurables
    * Aplicaciones prácticas: filtros, predicados, transformaciones
    * Introducción al concepto de estrategia: cambiar comportamiento sin cambiar estructura
    * Comparación práctica: funciones normales vs. lambdas vs. `std::function`
    * Ejercicios sobre abstracción de comportamiento

8. Introducción a las plantillas

    ¿Qué es la programación genérica?
    Plantillas de funciones: sintaxis y deducción de tipos
    Ejemplos típicos (`max`, `swap`, `print`)
    Uso de funciones genéricas con contenedores STL
    Ventajas y limitaciones básicas
    Ejercicios con plantillas de función

9. Excepciones y trabajo con archivos
    * Introducción a las excepciones
    * Manejo de errores y uso de `try`, `catch`, `throw`
    * Introducción al trabajo con archivos
    * Apertura, lectura y escritura de archivos
    * Ejercicios con archivos

# Curso de Programación Orientada a Objetos con C++ moderno

1. Fundamentos de la Programación Orientada a Objetos

    * Introducción a la Programación Orientada a Objetos
    * Clases y objetos en C++ moderno
    * Miembros de instancia: atributos y métodos
    * Encapsulamiento y modificadores de acceso (`public`, `private`, `protected`)
    * Atributos y métodos estáticos

2. Diseño básico de clases

    * Constructores, destructores y métodos constantes
    * Inicialización de atributos con listas de inicialización
    * Métodos getter y setter: motivación, sintaxis y buenas prácticas
    * Sobrecarga de operadores aritméticos y de comparación
    * Fluidez de métodos (`return   *this`)
    * Composición de objetos

3. Introducción al modelado con UML

    * ¿Qué es UML y por qué es útil en programación orientada a objetos?
    * Diagramas de clases UML: clases, atributos, métodos, visibilidad
    * Representación de relaciones: asociación, agregación, composición
    * Herencia y clases abstractas en UML
    * De clases a código: cómo convertir diagramas UML en C++
    * Ejercicios prácticos: dibujar y analizar diagramas UML simples

4. Relaciones entre clases

    * Agregación y composición: diferencias y ejemplos
    * Asociaciones entre objetos y responsabilidades
    * Introducción a la herencia: clases base y derivadas
    * Herencia y polimorfismo en C++
    * Conversiones implícitas y punteros base
    * El papel del `virtual` y el uso correcto de `override`
    * Finalización de métodos y clases con `final`

5. Interfaces y diseño polimórfico

    * Clases abstractas y métodos virtuales puros
    * Interfaces puras y su implementación
    * Devolución de interfaces mediante punteros inteligentes
    * Separación entre interfaz y detalle de implementación
    * Diseño orientado a contratos y principios de responsabilidad

6. Gestión avanzada de objetos

    * Semántica de copia y movimiento: constructor de copia, constructor de movimiento, operadores de asignación
    * Copias superficiales vs. profundas y su implicación en clases
    * Clonación de objetos mediante interfaces (`clone`)
    * Composición de objetos con punteros inteligentes
    * Uso práctico de `std::unique_ptr` y `std::shared_ptr` en clases

7. Plantillas de clases y programación genérica

    * Introducción a las plantillas de clases
    * Clases genéricas con uno o varios parámetros de tipo
    * Uso de plantillas para reutilización de código
    * Especialización de clases plantilla
    * Interacción con la STL desde la perspectiva de plantillas
    * Clases functoras y uso de `operator()`
    * Ventajas y precauciones en el uso de plantillas

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

# Curso de patrones de diseño con C++ moderno

1. Principios SOLID y patrones de diseño
    * SOLID: Principios de diseño orientado a objetos
    * ¿Qué son los patrones de diseño?
    * Patrones de diseño con C++ moderno

2. Patrones Creacionales

    * Patrón Singleton
    * Ejemplo de patrón Singleton con C++
    * Patrón Factory Method
    * Ejemplo de patrón Factory Method con C++
    * Patrón Abstract Factory
    * Ejemplo de patrón Abstract Factory con C++
    * Patrón Builder
    * Ejemplo de patrón Builder con C++
    * Patrón Prototype
    * Ejemplo de patrón Prototype con C++

3. Patrones Estructurales

    * Patrón Adapter
    * Ejemplo de patrón Adapter con C++
    * Patrón Decorator
    * Ejemplo de patrón Decorator con C++
    * Patrón Composite
    * Ejemplo de patrón Composite con C++
    * Patrón Facade
    * Ejemplo de patrón Facade con C++
    * Patrón Bridge
    * Ejemplo de patrón Bridge con C++
    * Patrón Proxy
    * Ejemplo de patrón Proxy con C++

4. Patrones de Comportamiento

    * Patrón Strategy
    * Ejemplo de patrón Strategy con C++
    * Patrón Observer
    * Ejemplo de patrón Observer con C++
    * Patrón Command
    * Ejemplo de patrón Command con C++
    * Patrón Template Method
    * Ejemplo de patrón Template Method con C++
    * Patrón Iterator
    * Ejemplo de patrón Iterator con C++
    * Patrón Visitor
    * Ejemplo de patrón Visitor con C++
    * Patrón State
    * Ejemplo de patrón State con C++
    * Patrón Memento
    * Ejemplo de patrón Memento con C++
    * Patrón Chain of Responsibility
    * Ejemplo de patrón Chain of Responsibility con C++
    
5. Proyecto final