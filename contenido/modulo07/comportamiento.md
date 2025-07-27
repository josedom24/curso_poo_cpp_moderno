# Comportamiento intercambiable y bajo acoplamiento

Uno de los principios fundamentales del diseño de software orientado a objetos y de la programación modular en general es la **separación de responsabilidades**. Este principio sugiere que cada componente del sistema debe encargarse de una tarea específica, facilitando así su reutilización, mantenimiento y extensión. En este contexto, surge la necesidad de diseñar **componentes cuyo comportamiento pueda intercambiarse sin modificar su estructura interna**. Este enfoque no solo favorece la flexibilidad, sino que también conduce a un sistema más **robusto, extensible y fácilmente comprobable**.

## ¿Qué significa comportamiento intercambiable?

Decimos que un componente tiene **comportamiento intercambiable** cuando su lógica interna no está acoplada a una única implementación, sino que **puede delegar ciertas decisiones o acciones a otros componentes**. Así, diferentes comportamientos pueden ser seleccionados dinámicamente o inyectados en tiempo de ejecución, sin necesidad de modificar el componente principal.

Este enfoque es especialmente útil en los siguientes escenarios:

* Cuando se desea reutilizar una clase con distintos comportamientos en contextos variados.
* Cuando el algoritmo o comportamiento puede variar según la configuración del programa o el entorno de ejecución.
* Cuando se requiere probar unidades de código con comportamientos simulados (mocks) para facilitar pruebas unitarias.

## El problema del acoplamiento rígido

Una clase que implementa directamente todos sus comportamientos está **fuertemente acoplada** a ellos. Esto implica varias desventajas:

* **Dificultad para extender o modificar** el comportamiento sin alterar el código existente.
* **Falta de reutilización**, ya que la lógica está incrustada en la clase.
* **Mayor complejidad al probar**, porque no se puede aislar el comportamiento ni simularlo fácilmente.

Veamos un ejemplo:

```cpp
class Ordenador {
public:
    void ordenar(std::vector<int>& datos) {
        // Algoritmo de ordenación fijo (por ejemplo, burbuja)
        for (size_t i = 0; i < datos.size(); ++i) {
            for (size_t j = 0; j < datos.size() - 1; ++j) {
                if (datos[j] > datos[j + 1]) {
                    std::swap(datos[j], datos[j + 1]);
                }
            }
        }
    }
};
```

En este ejemplo, la clase `Ordenador` **no puede cambiar su estrategia de ordenación sin modificar su implementación interna**.

## Ventajas del bajo acoplamiento y la composición flexible

El diseño orientado al **bajo acoplamiento** y a la **composición flexible de comportamientos** permite separar la lógica de control del comportamiento específico, de modo que:

* **Los comportamientos se encapsulan** en entidades independientes.
* **La lógica principal permanece inalterada** al modificar o intercambiar comportamientos.
* **Se fomenta la reutilización y la extensibilidad**, facilitando la evolución del sistema.
* **Las pruebas unitarias son más sencillas**, gracias a la posibilidad de inyectar comportamientos simulados.

## Visión general de las soluciones

En C++ moderno, existen múltiples formas de lograr comportamiento intercambiable con bajo acoplamiento:

* Delegar el comportamiento a través de **interfaces abstractas**.
* Utilizar **lambdas** como funciones anónimas que encapsulan lógica específica.
* Aplicar **`std::function`** como contenedor de funciones genéricas y configurables.
* Definir **functores** como objetos con `operator()` para representar acciones o estrategias.
* Implementar **inyección de comportamiento** mediante composición.

Cada una de estas técnicas permite sustituir el comportamiento sin afectar la estructura de los componentes que lo utilizan.
