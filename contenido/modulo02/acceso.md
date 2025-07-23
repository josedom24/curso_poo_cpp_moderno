# Encapsulamiento y modificadores de acceso (`public`, `private`, `protected`)

Uno de los pilares fundamentales de la programación orientada a objetos es el **encapsulamiento**, que consiste en **ocultar los detalles internos de una clase** y exponer únicamente lo necesario para su uso externo.
En C++, esto se logra utilizando **modificadores de acceso**, que determinan qué partes del programa pueden acceder a los miembros (atributos y métodos) de una clase.

El **encapsulamiento** permite:

* **Proteger el estado interno** del objeto de modificaciones indebidas.
* **Restringir el acceso directo** a los atributos.
* **Definir una interfaz pública clara**, mientras se ocultan los detalles de implementación.

Y sus ventajas son:

* Mayor seguridad del código.
* Menor acoplamiento entre clases.
* Mayor facilidad para cambiar la implementación sin afectar a los usuarios de la clase.

## Modificadores de acceso en C++

C++ define tres niveles de acceso para los miembros de una clase:


* `public`:
    1. **Accesible desde cualquier parte del programa**, incluida la clase, funciones externas y clases derivadas.
    2. Se utiliza para definir la **interfaz pública** de la clase: los métodos que otros pueden usar.
    3. No compromete la encapsulación **si se limita solo a lo necesario**.

    ```cpp
    class Ejemplo {
    public:
        int valor;
    };
    ```

* `private`:
    1. **Solo accesible dentro de la clase que lo declara**; ni funciones externas ni clases derivadas pueden usarlo.
    2. Ideal para **ocultar detalles de implementación** y proteger los datos internos.
    3. Permite mantener **invariantes de clase** al controlar completamente el acceso.

    ```cpp
    class Ejemplo {
    private:
        int secreto;
    };
    ```

* `protected`:
    1. Accesible **dentro de la clase y en sus clases derivadas**, pero **no desde fuera**.
    2. Útil cuando se desea **permitir herencia controlada**, donde las subclases pueden modificar ciertos elementos internos.
    3. No es visible para usuarios externos, por lo tanto, ayuda a mantener cierto nivel de encapsulamiento.

    ```cpp
    class Ejemplo {
    private:
        int secreto;
    };
    ```
## Buenas prácticas

* Los **atributos deben declararse como `private`** por defecto.
* Se debe exponer una **interfaz pública controlada** mediante métodos que validen o regulen el acceso a los datos internos.
* Los métodos `public` deben ser **coherentes y seguros**, protegiendo la invariancia del objeto. Es decir, no modifiquen los valores de los atributos que conviertan al bojeto en un estado no permitido.


## Ejemplo con encapsulamiento

A continuación, se presenta una clase `CuentaBancaria` que **oculta su saldo** y proporciona métodos públicos para operar sobre él:

```cpp
#include <iostream>
#include <string>

class CuentaBancaria {
private:
    std::string titular;
    double saldo;

public:
    CuentaBancaria(const std::string& nombre, double saldoInicial)
        : titular(nombre), saldo(saldoInicial) {}

    void depositar(double cantidad) {
        if (cantidad > 0) {
            saldo += cantidad;
        }
    }

    void retirar(double cantidad) {
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
        }
    }

    void mostrarInformacion() const {
        std::cout << "Titular: " << titular << ", Saldo: $" << saldo << "\n";
    }
};

int main() {
    CuentaBancaria cuenta("Luis", 1000.0);
    cuenta.mostrarInformacion();  // Titular: Luis, Saldo: $1000

    cuenta.depositar(250);
    cuenta.retirar(100);
    cuenta.mostrarInformacion();  // Titular: Luis, Saldo: $1150

    // cuenta.saldo = 0; // Error: 'saldo' es privado
}
```

* Los atributos `titular` y `saldo` se han declarado com privados. Sólo se pueden modificar por medio del uso de métodos.
* Hemos creado varios métodos que modifican el estado interno de cada objeto.
* En un objeto `CuentaBancaria` el saldo no puede ser negativo, los métodos públicos (como `retirar()`) deben garantizar que no se permita un saldo negativo, asegurando así la invarianza `saldo ≥ 0`.


## Representación UML del ejemplo

![diagrama2](img/diagrama2.png

