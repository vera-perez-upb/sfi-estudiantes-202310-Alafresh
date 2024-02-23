# Uso de Punteros en C++

Este repositorio contiene un ejemplo simple de cómo utilizar punteros en un programa de Arduino. En el código (`task1()`), muestra cómo declarar, definir e interactuar con punteros en el contexto de una tarea que implica la recepción de datos por el puerto serial.

## Contenido

- [Uso de Punteros](#uso-de-punteros)
- [Funcionamiento del Código](#funcionamiento-del-código)
- [Instrucciones de Uso](#instrucciones-de-uso)

## Uso de Punteros

### ¿Cómo se declara un puntero?

Un puntero se declara especificando el tipo de datos al que apunta y el asterisco (*) antes del nombre de la variable. Por ejemplo:

```cpp
int *puntero;
```

### ¿Cómo se define un puntero? (cómo se inicializa)

Un puntero se puede inicializar asignándole la dirección de una variable o utilizando el operador de dirección (&) seguido del nombre de la variable. Por ejemplo:

```cpp
int variable = 5;
int *puntero = &variable;
```

### ¿Cómo se obtiene la dirección de una variable?

Se obtiene la dirección de una variable utilizando el operador de dirección (&) seguido del nombre de la variable. Por ejemplo:

```cpp
int variable = 5;
int *puntero = &variable;
```

### ¿Cómo se puede leer el contenido de una variable por medio de un puntero?

Se puede leer el contenido de una variable accediendo al valor al que apunta el puntero utilizando el operador de indirección (*). Por ejemplo:

```cpp
int variable = 5;
int *puntero = &variable;
int contenido = *puntero; // contenido ahora es igual a 5
```

### ¿Cómo se puede escribir el contenido de una variable por medio de un puntero?

Se puede escribir el contenido de una variable accediendo al valor al que apunta el puntero y asignándole un nuevo valor. Por ejemplo:

```cpp
int variable = 5;
int *puntero = &variable;
*puntero = 10; // Ahora variable tendrá el valor de 10
```

## Funcionamiento del Código

El código proporcionado (`task1()`) muestra un ejemplo de cómo utilizar punteros en Arduino en una tarea que implica la recepción de datos por el puerto serial. La función `task1()` se ejecuta en un bucle (`loop()`) y realiza las siguientes operaciones:

1. Inicializa el puerto serial en una velocidad de 115200.
2. Espera la recepción de datos por el puerto serial.
3. Cuando se reciben datos, lee un valor del puerto serial, almacena su dirección en un puntero, imprime el contenido de la variable utilizando ese puntero, establece el valor de la variable a 10 utilizando ese puntero y luego lo imprime nuevamente.

## Instrucciones de Uso

1. Conecta tu placa Arduino o Rasberry al puerto serie de tu computadora.
2. Carga el código en tu placa Arduino o Rasberry utilizando el IDE de Arduino.
3. Abre el monitor serie para ver la salida.
4. Envía datos al puerto serie para observar cómo el programa interactúa con ellos.