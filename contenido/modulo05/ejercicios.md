# Ejercicios sobre conceptos avanzados de programación orientada a objetos

## Ejercicio 1: Control de creación de objetos

**Enunciado**
Un sistema de seguridad quiere generar identificadores únicos (`Token`) que no puedan ser creados libremente por cualquier parte del programa, solo mediante una función controlada. Implementa la clase `Token` con constructor privado y una función `crearTokenSeguro()` que devuelva un token válido.
Prohíbe además la copia de objetos `Token`.

**Diagrama UML (yUML)**

```
[Token|-valor:string; -Token(valor:string); +mostrar():void]
```

## Ejercicio 2: Sobrecarga de operadores

**Enunciado**
Crea una clase `Punto2D` que represente un punto en el plano. Implementa la sobrecarga de operadores para:

* `+` (suma de dos puntos).
* `-` (resta de dos puntos).
* `==` (comparación de igualdad).
* `<<` (impresión en flujo en formato `(x, y)`).

**Diagrama UML (yUML)**

```
[Punto2D|-x:int; -y:int; +Punto2D(x:int, y:int); +operator+(otro:Punto2D):Punto2D; 
+operator-(otro:Punto2D):Punto2D; +operator==(otro:Punto2D):bool; +mostrar():void]
```

## Ejercicio 3: Fluidez de métodos

**Enunciado**
Diseña una clase `Conexion` que permita configurar la conexión a un servidor de manera fluida, encadenando llamadas a métodos como `setHost`, `setPuerto` y `usarSSL`.
Al final, implementa un método `conectar()` que muestre la configuración utilizada.

**Diagrama UML (yUML)**

```
[Conexion|-host:string; -puerto:int; -segura:bool; +setHost(h:string):Conexion&; 
+setPuerto(p:int):Conexion&; +usarSSL(s:bool):Conexion&; +conectar():void]
```

## Ejercicio 4: Clonación de objetos

**Enunciado**
Crea una jerarquía de clases clonables:

* Una clase abstracta `Figura` con un método virtual `clone()`.
* Dos clases derivadas (`Circulo` y `Rectangulo`) que implementen la clonación profunda.

Permite duplicar objetos desde punteros a `Figura` sin conocer el tipo concreto.

**Diagrama UML (yUML)**

```
[Figura|+clone():Figura*; {abstract}]^-[Circulo|-radio:double; +clone():Figura*]
[Figura]^-[Rectangulo|-ancho:double; -alto:double; +clone():Figura*]
```

## Ejercicio 5: Semántica de copia y movimiento

**Enunciado**
Implementa una clase `Buffer` que gestione un vector de enteros. Define explícitamente:

* Constructor de copia y operador de asignación por copia.
* Constructor de movimiento y operador de asignación por movimiento.

Prueba en `main()` la diferencia entre copiar y mover objetos para observar qué operaciones se ejecutan.

**Diagrama UML (yUML)**

```
[Buffer|-datos:vector<int>; +Buffer(); +Buffer(lista:{int}); 
+Buffer(const Buffer&); +operator=(const Buffer&):Buffer&; 
+Buffer(Buffer&&); +operator=(Buffer&&):Buffer&; +mostrar():void]
```

