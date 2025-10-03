# Ejercicios sobre herencia y polimorfismo

## Ejercicio 1: Herencia básica

**Tema:** Clases base y derivadas con reutilización de código.

En una empresa, todos los empleados tienen un nombre y un método para mostrarlo. Los programadores, además, tienen un lenguaje principal, y los diseñadores, un programa de diseño favorito.

Crea las clases:

* `Empleado`, con atributo `nombre` y método `mostrarInfo()`.
* `Programador`, derivada de `Empleado`, con atributo `lenguaje` y método `mostrarInfo()`.
* `Disenador`, derivada de `Empleado`, con atributo `herramienta` y método `mostrarInfo()`.

Usa herencia para evitar duplicar el código relacionado con el nombre.

### UML

```yuml
[Empleado|-nombre:string; +mostrarInfo():void]
[Programador|-lenguaje:string; +mostrarInfo():void]^- [Empleado]
[Disenador|-herramienta:string; +mostrarInfo():void]^- [Empleado]
```

---

## Ejercicio 2: Polimorfismo dinámico

**Tema:** Funciones virtuales y `override`.

Queremos simular diferentes tipos de **instrumentos musicales**. Todos tienen un método `tocar()`, pero cada instrumento produce un sonido distinto.

Crea las clases:

* `Instrumento` (clase base abstracta), con método virtual puro `tocar()`.
* `Guitarra`, derivada de `Instrumento`, redefine `tocar()` para imprimir "Rasgueando la guitarra".
* `Piano`, derivada de `Instrumento`, redefine `tocar()` para imprimir "Tocando el piano".
* `Bateria`, derivada de `Instrumento`, redefine `tocar()` para imprimir "Golpeando la batería".

Escribe un programa que use un `std::vector<std::unique_ptr<Instrumento>>` para almacenar distintos instrumentos y llame a `tocar()` en cada uno, demostrando el polimorfismo dinámico.

### UML

```yuml
[Instrumento|+tocar():void]
[Guitarra|+tocar():void]^-.- [Instrumento]
[Piano|+tocar():void]^-.- [Instrumento]
[Bateria|+tocar():void]^-.- [Instrumento]
```

---

## Ejercicio 3: Conversión implícita y punteros base

**Tema:** Uso de punteros inteligentes y polimorfismo en colecciones.

En un zoológico queremos representar distintos animales, pero tratarlos de forma uniforme para poder listarlos y hacerlos emitir sonidos.

Crea las clases:

* `Animal` (clase base con método virtual `hacerSonido()` y destructor virtual).
* `Leon`, derivada de `Animal`, redefine `hacerSonido()` para imprimir "Ruge el león".
* `Elefante`, derivada de `Animal`, redefine `hacerSonido()` para imprimir "Barrita el elefante".
* `Mono`, derivada de `Animal`, redefine `hacerSonido()` para imprimir "Chilla el mono".

En el `main`, crea un `std::vector<std::unique_ptr<Animal>>` y almacena distintos animales. Recorre el vector y llama a `hacerSonido()` en cada uno para demostrar la conversión implícita de punteros derivados a base.

### UML

```yuml
[Animal|+hacerSonido():void; +~Animal()] 
[Leon|+hacerSonido():void]^-.- [Animal]
[Elefante|+hacerSonido():void]^-.- [Animal]
[Mono|+hacerSonido():void]^-.- [Animal]
```

