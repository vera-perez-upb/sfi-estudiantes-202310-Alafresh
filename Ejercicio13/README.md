### README

Este código implementa una tarea (`task1`) en el IDE de arduino utilizando el lenguaje de programación C++. 

#### Funciones Principales

1. **`changeVar(uint32_t *pdata)`:**
   - Esta función toma un puntero a un entero sin signo de 32 bits (`uint32_t`) como argumento.
   - Asigna el valor 10 a la variable a la que apunta el puntero `pdata`.

2. **`printVar(uint32_t value)`:**
   - Esta función toma un entero sin signo de 32 bits (`uint32_t`) como argumento.
   - Imprime el valor de la variable `value` en el puerto serie de Arduino.

#### Tarea (`task1`)

1. **Enumeración de Estados (`Task1States`):**
   - Define dos estados para la tarea `task1`: `INIT` y `WAIT_DATA`.

2. **Variables Estáticas:**
   - `task1State`: Almacena el estado actual de la tarea `task1`.
   - `rxData`: Almacena los datos recibidos por el puerto serie.
   - `dataCounter`: Contador para rastrear el número de datos recibidos.

3. **Máquina de Estados Finits (FSM):**
   - La tarea `task1` implementa una FSM con dos estados: `INIT` y `WAIT_DATA`.
   - En el estado `INIT`, inicializa la comunicación serie con una velocidad de 115200 baudios y cambia al estado `WAIT_DATA`.
   - En el estado `WAIT_DATA`, espera a que lleguen datos por el puerto serie.
     - Cuando se reciben datos, se almacenan en `rxData` y se incrementa `dataCounter`.
     - Si se reciben 5 datos, se llama a `changeVar` para cambiar el valor de una variable y luego se imprime el valor antes y después del cambio utilizando `printVar`.
     - Después de procesar los datos, `dataCounter` se restablece a 0.

#### Configuración y Bucle Principal

- En la función `setup()`, se llama a `task1()` una vez para inicializar la tarea.
- En la función `loop()`, se llama a `task1()` repetidamente para ejecutar la FSM en un bucle infinito.
