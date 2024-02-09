# README para el Código de Parpadeo del LED

Este código está diseñado para microcontroladores Arduino y tiene como propósito principal hacer parpadear el LED integrado en la placa a intervalos de 100 milisegundos.

## Descripción General

El programa se divide en dos funciones principales: `setup()` y `loop()`.

### `setup()`

Esta función se ejecuta una sola vez al comenzar el programa. Su propósito es configurar el pin del LED integrado como salida (`OUTPUT`). Esto permite controlar el LED para encenderlo y apagarlo.

### `loop()`

Esta función se ejecuta en un bucle infinito tras la inicialización por `setup()`. Su tarea es hacer parpadear el LED a intervalos regulares de 100 milisegundos. Utiliza variables estáticas y la función `millis()` para controlar el tiempo y el estado del LED.

## Variables Estáticas

- `static uint32_t previousTime = 0;`: Almacena el último momento (en milisegundos) en que el LED cambió de estado. Al ser estática, mantiene su valor entre las llamadas a `loop()`, permitiendo calcular el intervalo de tiempo transcurrido.

- `static bool ledState = true;`: Lleva el registro del estado actual del LED (encendido con `true`, apagado con `false`). Al ser una variable estática, su valor se preserva entre las iteraciones de `loop()`, facilitando el cambio de estado del LED.

## Funcionamiento

1. **Obtención del Tiempo Actual:** Con `millis()`, se obtiene el tiempo actual en milisegundos desde que el programa comenzó.
2. **Cálculo del Intervalo:** Se verifica si han transcurrido más de 100 milisegundos desde la última vez que el LED cambió de estado.
3. **Actualización de Estado:** Si ha pasado el intervalo, se actualiza `previousTime`, se invierte el estado del LED (`ledState`), y se aplica este cambio con `digitalWrite()`.

## Propósito de las Variables Estáticas

Las variables estáticas como `previousTime` y `ledState` son fundamentales en este código. Permiten retener información entre las sucesivas llamadas a la función `loop()` sin reiniciar sus valores. Esto es crucial para:
- Medir intervalos de tiempo entre eventos (parpadeo del LED).
- Mantener el estado actual del LED para poder invertirlo en cada ciclo.

Este enfoque facilita el control preciso del comportamiento del programa sin la necesidad de variables globales o externas, optimizando el uso de la memoria y la legibilidad del código.