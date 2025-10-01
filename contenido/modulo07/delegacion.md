# Delegación de comportamiento mediante interfaces

Una de las formas más clásicas y efectivas de lograr comportamiento intercambiable en programación orientada a objetos es la **delegación mediante interfaces**. En este enfoque, una clase delega parte de su comportamiento a otro objeto que cumple una **interfaz abstracta**, lo que permite sustituir libremente su implementación sin modificar al cliente que la utiliza. Este principio se basa en el concepto de **programar contra interfaces, no contra implementaciones**.

Veamos el ejemplo de una interfaz en C++:

```cpp
class EstrategiaOrdenamiento {
public:
    virtual void ordenar(std::vector<int>& datos) = 0;
    virtual ~EstrategiaOrdenamiento() = default;
};
```

Esta clase define una interfaz para cualquier método de ordenación. No indica **cómo** se ordenan los datos, solo establece que cualquier clase que la implemente debe ofrecer ese comportamiento.

## Delegación de comportamiento

Ahora podemos definir una clase que **no conoce la implementación concreta** del comportamiento, sino que se comunica a través de la interfaz:

```cpp
class Ordenador {
private:
    std::unique_ptr<EstrategiaOrdenamiento> estrategia_;

public:
    Ordenador(std::unique_ptr<EstrategiaOrdenamiento> estrategia)
        : estrategia_(std::move(estrategia)) {}

    void ordenar(std::vector<int>& datos) {
        estrategia_->ordenar(datos);
    }

};
```

La clase `Ordenador` **no realiza la ordenación por sí misma**, sino que la delega al objeto que implementa la interfaz `EstrategiaOrdenamiento`.

## Implementaciones concretas

A continuación, se pueden definir diferentes formas de ordenación que implementan la misma interfaz:

```cpp
class OrdenamientoBurbuja : public EstrategiaOrdenamiento {
public:
    void ordenar(std::vector<int>& datos) override {
        for (size_t i = 0; i < datos.size(); ++i) {
            for (size_t j = 0; j < datos.size() - 1; ++j) {
                if (datos[j] > datos[j + 1]) {
                    std::swap(datos[j], datos[j + 1]);
                }
            }
        }
    }
};

class OrdenamientoRapido : public EstrategiaOrdenamiento {
public:
    void ordenar(std::vector<int>& datos) override {
        std::sort(datos.begin(), datos.end()); // Implementación eficiente
    }
};
```

## Uso en código cliente

El cliente puede ahora elegir libremente el método de ordenación sin modificar la clase `Ordenador`:

```cpp
std::vector<int> datos = {5, 2, 8, 1};

Ordenador ordenador1(std::make_unique<OrdenamientoBurbuja>());
ordenador1.ordenar(datos);

Ordenador ordenador2(std::make_unique<OrdenamientoRapido>());
ordenador2.ordenar(datos);
```

## Ventajas de este enfoque

* **Bajo acoplamiento**: la clase que usa el comportamiento no depende de detalles de implementación.
* **Reutilización**: los distintos métodos pueden utilizarse en diferentes contextos.
* **Extensibilidad**: se pueden añadir nuevas implementaciones sin modificar el código existente.
* **Facilidad para pruebas**: permite inyectar versiones simuladas o controladas del comportamiento.

## Limitaciones

* Requiere crear una jerarquía de clases, lo cual puede aumentar la complejidad en sistemas simples.
* La interfaz debe mantenerse estable, lo que exige un diseño cuidadoso desde el principio.
* Puede resultar excesivo si solo se requiere cambiar el comportamiento de forma puntual.

