# Fluidez de métodos

En muchas ocasiones es necesario permitir la **encadenación de llamadas a métodos** sobre el mismo objeto. Esta técnica se denomina **fluidez de métodos** (*method chaining* en inglés), y se basa en que cada método **retorne una referencia al propio objeto** (`*this`).

Este estilo mejora la legibilidad del código y permite construir objetos o configurar estados de forma más natural y expresiva.

## Fundamento: `return *this`

En un método no estático, el puntero `this` apunta al objeto actual. Al hacer `return *this`, se devuelve una **referencia al propio objeto**, permitiendo que otras llamadas puedan encadenarse sobre él.

La sintaxis de este tipo de métodos es:

```cpp
Tipo& metodo(...args) {
    // ...acciones...
    return *this;
}
```

Para evitar copias innecesarias, se recomienda **retornar por referencia** (`Tipo&`) o por referencia constante (`const Tipo&`) si no se desea modificar más.


Veamos un ejemplo:

```cpp
class Cadena {
private:
    std::string texto;

public:
    Cadena& agregar(const std::string& s) {
        texto += s;
        return *this;
    }

    void imprimir() const {
        std::cout << texto << "\n";
    }
};

int main() {
    Cadena c;
    c.agregar("Hola, ").agregar("mundo").agregar("!");
    c.imprimir();  // Hola, mundo!
}
```


## Ejemplo práctico: Configuración encadenada

```cpp
class Conexion {
private:
    std::string host;
    int puerto = 0;
    bool segura = false;

public:
    Conexion& setHost(const std::string& h) {
        host = h;
        return *this;
    }

    Conexion& setPuerto(int p) {
        puerto = p;
        return *this;
    }

    Conexion& usarSSL(bool s) {
        segura = s;
        return *this;
    }

    void conectar() const {
        std::cout << "Conectando a " << host << ":" << puerto
                  << (segura ? " con SSL\n" : "\n");
    }
};

int main() {
    Conexion c;
    c.setHost("localhost")
     .setPuerto(443)
     .usarSSL(true)
     .conectar();
}
```

* La **fluidez de métodos** nos permite realizar las operaciones relacionadas expresadas en una única línea, lo que mejora la claridad del flujo y la construcción de objetos.
* Es importante retornar por **referencia** para evitar copias.
* Puede usarse con `const` si los métodos no modifican el estado:

