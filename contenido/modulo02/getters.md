#  Métodos getter y setter
En diseño orientado a objetos, los atributos de una clase suelen declararse como `private` o `protected` para cumplir con el principio de **encapsulamiento**, impidiendo el acceso directo desde fuera de la clase.

Para permitir el acceso controlado a estos atributos, se emplean los métodos conocidos como:

* **Getters**: permiten **consultar** el valor de un atributo.
* **Setters**: permiten **modificar** el valor de un atributo, validando si es necesario.

## ¿Por qué no exponer los atributos como públicos?

Aunque sería más simple hacer los atributos públicos, esto **rompería el encapsulamiento**, exponiendo el estado interno del objeto sin ningún tipo de control ni validación. Por ejemplo:

```cpp
class Persona {
public:
    std::string nombre;
    int edad;
};
```

Cualquier parte del programa podría hacer:

```cpp
persona.edad = -99;  // Edad inválida
```

Esto es problemático porque **no hay garantía de integridad** del estado del objeto.

## Uso de getters y setters

Declarando los atributos como `private` y exponiendo funciones públicas de acceso y modificación, se protege el estado interno de la clase. Veamos un ejemplo:


```cpp
class Persona {
private:
    std::string nombre;
    int edad;

public:
    // Getter
    std::string getNombre() const {
        return nombre;
    }

    int getEdad() const {
        return edad;
    }

    // Setter
    void setNombre(const std::string& nuevoNombre) {
        nombre = nuevoNombre;
    }

    void setEdad(int nuevaEdad) {
        if (nuevaEdad >= 0) {
            edad = nuevaEdad;
        }
    }
};

int main() {
    Persona p;
    p.setNombre("Lucía");
    p.setEdad(28);

    std::cout << p.getNombre() << " tiene " << p.getEdad() << " años.\n";
}

```

El uso de este tipo de métodos nos proporcionan las siguientes ventajas:

* Añadir validación,
* Registrar cambios (logs),
* Lanzar excepciones,
* Aplicar lógica de negocio.

Como buenas prácticas podemos apuntar:
* Los *getters* deben marcarse como `const` si no modifican el estado del objeto.
* Usar pasar por referencia `const` para evitar copias costosas. Esto evita una copia innecesaria cuando el tipo es complejo.
* Usar validación en los setters, para permitir proteger la clase de estados inválidos.
* Evitar setters innecesarios. No todo atributo necesita un setter. Si un atributo no debe cambiarse luego de inicializarse (por ejemplo, un identificador único), simplemente **no se proporciona el setter**.

