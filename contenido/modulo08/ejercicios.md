# Ejercicios sobre programación genérica

## Ejercicio 1: Clase plantilla básica

Crea una clase plantilla `Caja<T>` que permita almacenar un valor de tipo genérico.

1. Define una plantilla de clase con un único parámetro de tipo `T`.
2. La clase debe incluir:

   * un atributo privado `valor` de tipo `T`;
   * un método `setValor(const T&)` para asignar el valor;
   * un método `getValor()` que devuelva el valor;
   * un método `mostrar()` que imprima el contenido de la caja.
3. Comprueba su funcionamiento con diferentes tipos de datos.

## Ejercicio 2: Clase plantilla con varios parámetros

Implementa una clase genérica `Par<T1, T2>` que almacene dos valores de tipos posiblemente distintos.

1. La clase debe tener dos atributos: `primero` (tipo `T1`) y `segundo` (tipo `T2`).
2. Debe incluir:

   * un constructor que reciba ambos valores;
   * métodos `getPrimero()` y `getSegundo()`;
   * un método `mostrar()` que imprima ambos valores.
3. Instancia la clase con combinaciones de tipos distintos para comprobar su funcionamiento.


## Ejercicio 3: Especialización de plantillas

Implementa una clase plantilla `Contenedor<T>` con una especialización total para el tipo `std::string`.

1. Define la versión genérica con un método `mostrar()` que imprima `"Tipo genérico"`.
2. Crea una especialización total para `std::string` que imprima `"Tipo texto"`.
3. Comprueba el comportamiento con instancias de distintos tipos.


## Ejercicio 4: Uso de `std::optional`

Crea una función que busque un número dentro de un `std::vector<int>` utilizando `std::optional` para representar la posibilidad de que no se encuentre el valor.

1. Define la función:

   ```cpp
   std::optional<int> buscar(const std::vector<int>& v, int objetivo);
   ```
2. Si el número está en el vector, devuelve su valor; si no, devuelve `std::nullopt`.
3. En `main()`, usa `value_or()` para imprimir el resultado o un valor por defecto cuando el `optional` esté vacío.


## Ejercicio 5: Uso de `std::variant` y `std::visit`

Diseña un programa que procese datos heterogéneos usando `std::variant` y `std::visit`.

1. Define un tipo `using Dato = std::variant<int, std::string, double>;`.
2. Crea un `std::vector<Dato>` con distintos tipos de valores.
3. Usa `std::visit()` con una lambda genérica para imprimir el contenido.
4. (Opcional) Implementa una clase *visitor* con sobrecarga de `operator()` para manejar cada tipo de forma diferente.

