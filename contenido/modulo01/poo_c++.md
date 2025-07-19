# Definición de clases y creación de objetos

Una **clase** en C++ se define mediante la palabra clave `class`, seguida del nombre de la clase y un bloque de llaves `{}` que contiene la declaración de atributos (variables miembro) y métodos (funciones miembro).

```cpp
class NombreDeLaClase {
    // Sección de atributos y métodos
};
```

## Atributos (variables miembro) y métodos (funciones miembro)

Dentro de una clase se definen:

* **Atributos**: Variables que almacenan el estado o las propiedades de los objetos.
* **Métodos**: Funciones que definen el comportamiento o las operaciones que los objetos pueden realizar.

Veamos un ejemplo:

```cpp
class Rectangulo {
private:
    double base;
    double altura;

public:
    // Método para inicializar los atributos
    void establecerDimensiones(double b, double h) {
        base = b;
        altura = h;
    }

    // Método para calcular el área
    double calcularArea() const {
        return base * altura;
    }
};
```

En este ejemplo:

* `base` y `altura` son **atributos privados**.
* Los métodos `establecerDimensiones` y `calcularArea` son **públicos** y permiten manipular el estado del objeto y realizar cálculos.

Los **modificadores de acceso** determinan la visibilidad de los atributos y métodos de la clase. Los más utilizados son:

* `public`: Los miembros declarados como `public` son accesibles desde cualquier parte del programa.
* `private`: Los miembros declarados como `private` solo son accesibles desde dentro de la propia clase. Se utilizan para proteger el estado interno del objeto.

Ejemplo:

```cpp
class Ejemplo {
private:
    int datoPrivado; // Solo accesible dentro de la clase

public:
    void metodoPublico() {
        // Puede acceder a datoPrivado
    }
};
```

Por convención y buenas prácticas, se recomienda:

* Declarar los atributos como `private` para proteger el estado del objeto.
* Proporcionar métodos públicos controlados (getters y setters) para acceder o modificar los atributos si es necesario.
* Terminar el nombre de los atributos con guión bajo `_`. Esto permite diferenciar claramente atributos de variables locales o parámetros y evitar colisiones de nombres.

## Creación e inicialización de objetos

Una vez definida la clase, se pueden crear **objetos** que son instancias concretas de esa clase. La sintaxis para crear objetos es:

```cpp
NombreDeLaClase nombreDelObjeto;
```

Los objetos se pueden inicializar mediante:

* **Asignación directa a los atributos públicos** (poco recomendable por falta de encapsulamiento).
* **Métodos específicos** diseñados para establecer el estado del objeto (preferible).
* **Constructores**, que se verán en detalle en apartados posteriores.

Ejemplo:

```cpp
int main() {
    Rectangulo r1;
    r1.establecerDimensiones(5.0, 3.0);

    std::cout << "Área del rectángulo: " << r1.calcularArea() << std::endl;

    return 0;
}
```

En este caso:

* Se crea un objeto `r1` de tipo `Rectangulo`.
* Se llama al método `establecerDimensiones` para inicializar sus atributos.
* Se utiliza el método `calcularArea` para obtener el resultado.

## Introducción de getters y setters

El **encapsulamiento** es un principio fundamental de la POO que consiste en proteger los atributos internos de los objetos, permitiendo su acceso o modificación únicamente a través de métodos públicos controlados, conocidos como **getters** (métodos que permiten el valor de los atributos) y **setters** (métodos que permiten modificar los atributos).



```cpp
class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Setter para el nombre
    void setNombre(const std::string& n) {
        nombre = n;
    }

    // Getter para el nombre
    std::string getNombre() const {
        return nombre;
    }

    // Setter para la edad
    void setEdad(int e) {
        if (e >= 0) {
            edad = e;
        }
    }

    // Getter para la edad
    int getEdad() const {
        return edad;
    }
};

int main() {
    Persona p1;
    p1.setNombre("Laura");
    p1.setEdad(28);

    std::cout << "Nombre: " << p1.getNombre() << ", Edad: " << p1.getEdad() << std::endl;

    return 0;
}
```
Los getters y setters:

* Permiten controlar cómo se accede o modifica el estado del objeto.
* Facilitan la validación de datos antes de modificar atributos (como en el caso de la edad).
* Mejoran la seguridad y robustez del código.
* Mantienen el principio de encapsulamiento.

## Ejemplo completo: Clase `Coche`

```cpp
#include <iostream>
#include <string>

class Coche {
private:
    std::string marca;
    std::string modelo;
    int anio;

public:
    // Setter para la marca
    void setMarca(const std::string& m) {
        marca = m;
    }

    // Getter para la marca
    std::string getMarca() const {
        return marca;
    }

    // Setter para el modelo
    void setModelo(const std::string& mod) {
        modelo = mod;
    }

    // Getter para el modelo
    std::string getModelo() const {
        return modelo;
    }

    // Setter para el año (con validación)
    void setAnio(int a) {
        if (a > 1885) { // Primer automóvil se inventó alrededor de 1886
            anio = a;
        } else {
            std::cout << "Año no válido. Debe ser mayor a 1885." << std::endl;
        }
    }

    // Getter para el año
    int getAnio() const {
        return anio;
    }

    // Método para mostrar la información del coche
    void mostrarInformacion() const {
        std::cout << "Marca: " << marca 
                  << ", Modelo: " << modelo 
                  << ", Año: " << anio << std::endl;
    }
};

int main() {
    Coche coche1;

    // Inicialización de los atributos usando setters
    coche1.setMarca("Toyota");
    coche1.setModelo("Corolla");
    coche1.setAnio(2020);

    // Mostrar información usando un método
    coche1.mostrarInformacion();

    // Ejemplo de uso de getters
    std::cout << "La marca del coche es: " << coche1.getMarca() << std::endl;

    return 0;
}
```

* La clase `Coche` encapsula tres atributos privados: `marca`, `modelo` y `anio`.
* Se proporcionan métodos públicos (`set` y `get`) para controlar el acceso y modificación de esos atributos.
* El método `setAnio` incluye una validación para evitar valores inválidos.
* El método `mostrarInformacion` imprime el estado del objeto de forma legible.
* En la función `main`, se crea un objeto `coche1`, se inicializa mediante setters y se accede a su información.

