# Ejercicios sobre abstracción de comportamiento

## Ejercicio 1: Delegación de comportamiento mediante interfaces

Crea una interfaz `EstrategiaImpresion` con un método virtual puro `imprimir(const std::string&)`.

1. Implementa dos clases concretas:

   * `ImpresionConsola` — muestra el mensaje por consola.
   * `ImpresionArchivo` — muestra `"Guardando en archivo: [mensaje]"`.
2. Crea una clase `Documento` que contenga un puntero inteligente a `EstrategiaImpresion` y un método `procesar(const std::string&)` que delegue la acción en la estrategia.
3. En `main()`, crea un `Documento` con cada estrategia y llama a `procesar("Hola mundo")`.
4. Comprueba que el comportamiento cambia sin modificar `Documento`.


## Ejercicio 2: Uso de lambdas para comportamiento intercambiable

1. Crea un vector de enteros `{5, 2, 8, 1, 4}`.
2. Usa `std::sort` con una **lambda** para ordenarlo de forma ascendente.
3. Ordénalo nuevamente de forma descendente usando otra lambda distinta.
4. Muestra los resultados por consola tras cada ordenación.
5. Reflexiona: ¿cómo cambia el comportamiento de la misma función (`std::sort`) según la lambda usada?


## Ejercicio 3: Encapsulación de comportamiento con `std::function`

1. Escribe una función `ejecutarOperacion(int a, int b, std::function<int(int,int)> op)` que imprima el resultado de aplicar `op(a, b)`.
2. En `main()`, define tres lambdas: `suma`, `resta` y `multiplicacion`.
3. Llama a `ejecutarOperacion()` pasando cada una de ellas.
4. Observa cómo `std::function` permite cambiar el comportamiento sin modificar la función principal.


## Ejercicio 4: Functores con estado interno

1. Define una clase `Contador` con un atributo privado `int incremento_`.
2. Implementa `operator()(int valor)` que devuelva `valor + incremento_`.
3. En `main()`, crea dos objetos:

   * Uno con incremento 1 (simula un contador que avanza de uno en uno).
   * Otro con incremento 10.
4. Aplica ambos a un conjunto de valores (por ejemplo, `{0, 5, 10}`) y muestra los resultados.
5. Reflexiona: ¿por qué un functor es útil cuando se necesita mantener estado?


## Ejercicio 5: Inyección de comportamiento mediante composición

Crea una clase `Calculadora` que permita **inyectar operaciones** aritméticas:

1. Define un alias `Operacion` como `std::function<int(int,int)>`.
2. Implementa un constructor que reciba una `Operacion` y un método `ejecutar(int, int)` que la use.
3. En `main()`, crea tres instancias:

   * Una con lambda de suma.
   * Otra con lambda de resta.
   * Otra con lambda de multiplicación.
4. Muestra los resultados de `ejecutar(6, 2)` para cada calculadora.
5. Reflexiona: ¿por qué esta técnica es más flexible que crear subclases como `CalculadoraSuma`?

