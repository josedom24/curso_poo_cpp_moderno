
## Constructores delegados (C++11)




# Inicialización de atributos con listas de inicialización

En C++, los constructores permiten inicializar los atributos de una clase al momento de la creación del objeto. Una forma eficiente y preferida de hacerlo es mediante el uso de **listas de inicialización**.

La lista de inicialización ofrece varias ventajas sobre la asignación dentro del cuerpo del constructor, especialmente cuando se trabaja con **atributos constantes**, **referencias**, o **tipos sin constructor por defecto**. Además, es más eficiente y refleja mejor la intención de inicializar, no simplemente asignar.

Una **lista de inicialización** aparece después de los paréntesis del constructor y antes del cuerpo, utilizando el carácter `:` seguido de una lista separada por comas:

```cpp
Clase::Clase(tipo1 arg1, tipo2 arg2)
    : atributo1(arg1), atributo2(arg2) {
    // cuerpo del constructor (opcional)
}
```

Veamos un ejemplo:

```cpp
class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona(const std::string& n, int e)
        : nombre(n), edad(e) {}

    void presentarse() const {
        std::cout << "Soy " << nombre << " y tengo " << edad << " años.\n";
    }
};
```

Este constructor inicializa los atributos `nombre` y `edad` directamente desde la lista de inicialización. No se produce una construcción por defecto seguida de una asignación, sino una **construcción directa** y eficiente.


## ¿Por qué usar listas de inicialización?

* **Para inicializar miembros `const`**: Los miembros constantes deben **obligatoriamente** inicializarse en la lista de inicialización, ya que **no se pueden asignar** dentro del cuerpo del constructor.

    ```cpp
    class Punto {
    private:
        const double x_;
        const double y_;

    public:
        Punto(double x, double y)
            : x_(x), y_(y) {}
    };
    ```

    Es recomendable terminar el nombre de los atributos con guión bajo `_`. Esto permite diferenciar claramente atributos de variables locales o parámetros y evitar colisiones de nombres.

* **Para inicializar referencias**: Las referencias deben inicializarse en el momento de la construcción.

    ```cpp
    class Referencia {
    private:
        int& ref;

    public:
        Referencia(int& r)
            : ref(r) {}
    };
    ```

* **Para mejorar la eficiencia**: Inicializar un atributo directamente es más eficiente que crearlo con un valor por defecto y luego reasignarlo.

    ```cpp
    class Cadena {
    private:
        std::string texto;

    public:
        Cadena(const std::string& t)
            : texto(t) {} // mejor que texto = t; primero se construye 'texto' con su constructor por defecto y luego se asigna
    };
    ```

* **Para inicializar tipos que no tienen constructor por defecto**: Una razón fundamental para usar listas de inicialización en C++ es cuando se tiene que inicializar un miembro de tipo **sin constructor por defecto**. En estos casos, **no puedes asignarle un valor en el cuerpo del constructor**, porque **ya debe estar inicializado al entrar al cuerpo**.

    Esto ocurre normalmente cuando usamos **composición** (un atributo de una clase es un objeto de otra clase). En este caso, cuando el objeto de la otra clase **no tiene constructor por defecto** tenemos que usar la lista de inicialización , ya que El miembro debe estar **completamente inicializado antes de ejecutar el cuerpo del constructor**. Ejemplo:

    ```cpp
    class NoCopiable {
    public:
        NoCopiable(int) {}
        NoCopiable() = delete; // no hay constructor por defecto
    };

    class Contenedor {
    private:
        NoCopiable obj;

    public:
        Contenedor(int valor)
            : obj(valor) {}
    };
    ```



## Orden de inicialización

**Importante**: Los atributos se inicializan **en el orden en que se declaran en la clase**, **no** en el orden que aparecen en la lista de inicialización. Desordenarlos puede generar advertencias o errores sutiles.

```cpp
class Ejemplo {
private:
    int a;
    int b;

public:
    Ejemplo(int x, int y)
        : b(y), a(x) {}  // Primero se inicializa a, luego b
};
```

## Uso combinado con delegación

Las listas de inicialización pueden combinarse con **constructores delegados** para maximizar la reutilización del código de inicialización. Un **constructor delegante** permite que un constructor invoque a otro dentro de la misma clase. Esto mejora la coherencia de inicialización y evita duplicación de código.

Ejemplo:

```cpp
class Persona {
private:
    std::string nombre;
    int edad;

public:
    Persona()
        : Persona("Desconocido", 0) {}  // delegación

    Persona(const std::string& n)
        : Persona(n, 0) {}             // delegación

    Persona(const std::string& n, int e)
        : nombre(n), edad(e) {}        // inicialización directa
};
```

Podemos crear objero de la calse `Persona de diferente manera:

```cpp
Persona p1;
Persona p2("José");
Persona p2("María",25);
```