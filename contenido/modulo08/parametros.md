Aquí tienes el desarrollo didáctico del apartado **"Clases genéricas con uno o varios parámetros de tipo"**, con un estilo formal, claro y adecuado para un curso de C++ moderno y programación orientada a objetos:

---

## 2. Clases Genéricas con Uno o Varios Parámetros de Tipo

### 2.1 Introducción

En el apartado anterior se introdujo la noción de plantillas de clases con un solo parámetro de tipo. Sin embargo, en muchas situaciones prácticas es necesario que una clase manipule simultáneamente objetos de distintos tipos. C++ permite extender el concepto de plantillas para incluir **múltiples parámetros de tipo**, proporcionando mayor flexibilidad y expresividad.

### 2.2 Sintaxis General

La definición de una plantilla de clase con varios parámetros de tipo sigue la siguiente forma:

```cpp
template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;
public:
    Par(const T1& a, const T2& b) : primero(a), segundo(b) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }
};
```

Aquí, la clase `Par` está parametrizada con dos tipos, `T1` y `T2`. Cada uno puede ser distinto e independiente.

### 2.3 Ejemplo de Uso

```cpp
Par<int, std::string> par1(1, "uno");
std::cout << par1.getPrimero() << ", " << par1.getSegundo() << std::endl;

Par<double, char> par2(3.14, 'π');
```

Este enfoque permite modelar pares heterogéneos de manera genérica, sin necesidad de definir múltiples versiones especializadas de la clase.

### 2.4 Comparación con `std::pair`

La STL (Standard Template Library) ya provee una clase plantilla genérica llamada `std::pair<T1, T2>`, que implementa precisamente esta idea. El objetivo de este apartado es comprender cómo se construye y usa una estructura equivalente desde cero, lo cual fortalece la comprensión del modelo de tipos en C++.

```cpp
std::pair<int, std::string> p = std::make_pair(2, "dos");
std::cout << p.first << ", " << p.second << std::endl;
```

Al crear estructuras propias, es posible agregar lógica adicional que `std::pair` no incluye, como validaciones o restricciones de tipo, lo que refuerza la utilidad de definir clases genéricas personalizadas.

### 2.5 Parámetros de Tipo por Valor

Además de tipos, las plantillas también pueden recibir valores constantes como parámetros. Por ejemplo:

```cpp
template <typename T, int N>
class Arreglo {
private:
    T datos[N];
public:
    T& operator[](int i) { return datos[i]; }
    const T& operator[](int i) const { return datos[i]; }
};
```

Este tipo de plantilla permite definir estructuras parametrizadas por tamaño en tiempo de compilación. Su uso es habitual en implementaciones de arrays estáticos o buffers con tamaño fijo.

### 2.6 Ventajas de Múltiples Parámetros de Plantilla

* Permiten representar relaciones entre tipos (por ejemplo, pares clave-valor).
* Fomentan la reutilización sin pérdida de tipo ni necesidad de conversiones.
* Incrementan la capacidad expresiva del lenguaje sin añadir complejidad en tiempo de ejecución.

---

### Ejemplo completo

```cpp
#include <iostream>
#include <string>

template <typename T1, typename T2>
class Par {
private:
    T1 primero;
    T2 segundo;
public:
    Par(const T1& a, const T2& b) : primero(a), segundo(b) {}

    T1 getPrimero() const { return primero; }
    T2 getSegundo() const { return segundo; }
};

int main() {
    Par<int, std::string> p(7, "siete");
    std::cout << "Primero: " << p.getPrimero() << "\n";
    std::cout << "Segundo: " << p.getSegundo() << "\n";

    return 0;
}
```

---

### 2.7 Conclusión

El uso de múltiples parámetros de tipo en plantillas de clases proporciona una herramienta poderosa para diseñar componentes más flexibles, reutilizables y expresivos. Esta capacidad es esencial en el diseño de estructuras de datos genéricas y se encuentra en la base de muchas clases fundamentales de la STL. Comprender su construcción y aplicación es clave para dominar la programación genérica en C++ moderno.

---

¿Deseas que incluya ahora una sección de ejercicios o actividades prácticas asociadas a este apartado?
