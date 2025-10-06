# Análisis del diseño resultante y conclusiones finales del curso

Con la finalización del proyecto **Sistema de dispositivos inteligentes**, culmina también el recorrido formativo del **curso de Programación Orientada a Objetos con C++ moderno**.
En este último apartado reflexionaremos sobre el diseño construido, los principios aplicados y los conocimientos adquiridos a lo largo del curso.

## Análisis del diseño del proyecto

El sistema desarrollado integra de manera coherente los principales **conceptos y herramientas de la POO moderna en C++**, aplicándolos en un caso práctico completo.

### Arquitectura modular y clara

El proyecto se ha estructurado en módulos independientes y bien definidos:

| Módulo               | Responsabilidad principal                                                                  |
| -------------------- | ------------------------------------------------------------------------------------------ |
| **`Dispositivos.h`** | Define la jerarquía de clases (`Dispositivo`, `Sensor`, `Actuador`) y sus comportamientos. |
| **`Controlador.h`**  | Gestiona la colección de dispositivos y coordina sus acciones.                             |
| **`Eventos.h`**      | Modela la información heterogénea del sistema mediante `std::variant` y `std::visit`.      |
| **`main.cpp`**       | Integra los componentes y ofrece una interfaz interactiva (menú).                          |

Esta organización refleja la **separación de responsabilidades**, facilitando la comprensión, el mantenimiento y la extensión del sistema.

### Polimorfismo dinámico y estático

El proyecto ilustra **dos formas complementarias de polimorfismo** en C++ moderno:

* **Polimorfismo dinámico (en tiempo de ejecución):**
  Implementado mediante herencia y punteros a clase base (`Dispositivo`).
  Permite que el controlador trate sensores y actuadores de forma uniforme.

* **Polimorfismo estático (en tiempo de compilación):**
  Logrado con `std::variant` y `std::visit` en el manejo de eventos.
  Sustituye jerarquías innecesarias por una representación genérica, manteniendo seguridad de tipos.

Este equilibrio muestra cómo C++ moderno combina **orientación a objetos y programación genérica** para lograr flexibilidad y eficiencia.

### Gestión segura de recursos

La utilización de **punteros inteligentes** (`std::unique_ptr`, `std::shared_ptr`) garantiza una **gestión automática y segura de memoria**, eliminando fugas y errores comunes asociados al uso de `new` y `delete`.
El patrón **RAII (Resource Acquisition Is Initialization)** se aplica de forma natural en todas las clases, reforzando la fiabilidad del sistema.

### Inyección de comportamiento y composición

Los **actuadores** utilizan `std::function` y **lambdas** para definir acciones en tiempo de ejecución.
Esta técnica ejemplifica la **inyección de comportamiento mediante composición**, un enfoque más flexible y extensible que la herencia tradicional.
Permite configurar el sistema sin modificar las clases, cumpliendo con el principio de diseño **abierto a la extensión y cerrado a la modificación**.

### Uso de características modernas de C++

A lo largo del proyecto se han empleado múltiples herramientas del C++ contemporáneo:

| Herramienta moderna                   | Aplicación                                                 |
| ------------------------------------- | ---------------------------------------------------------- |
| `std::unique_ptr` / `std::shared_ptr` | Gestión automática de memoria y propiedad de recursos.     |
| `std::optional`                       | Representación segura de lecturas fallidas.                |
| `std::function` y lambdas             | Definición dinámica de comportamientos.                    |
| `std::variant` y `std::visit`         | Manejo de eventos heterogéneos sin jerarquías adicionales. |
| Inicialización en lista y `explicit`  | Mejora de la seguridad y legibilidad del código.           |

Estas características reflejan el **paradigma moderno de C++**, centrado en la seguridad, expresividad y control.

## Conclusión general del curso

A través del desarrollo de este proyecto, el estudiante ha recorrido todas las etapas de la **programación orientada a objetos en C++ moderno**, desde sus fundamentos hasta la aplicación práctica de técnicas avanzadas.

### Logros de aprendizaje

Al completar el curso, el estudiante habrá adquirido:

1. **Comprensión profunda de los pilares de la POO**: encapsulación, herencia, polimorfismo y abstracción.
2. **Capacidad para diseñar jerarquías de clases coherentes** y aplicar composición e inyección de dependencias.
3. **Competencia en la gestión de recursos y memoria** usando RAII y punteros inteligentes.
4. **Conocimiento de técnicas modernas de C++**: `std::optional`, `std::variant`, `std::function`, lambdas, y plantillas genéricas.
5. **Dominio de prácticas de diseño** orientadas a la mantenibilidad y extensibilidad del software.

