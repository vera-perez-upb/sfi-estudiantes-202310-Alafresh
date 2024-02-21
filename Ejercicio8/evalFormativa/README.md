# Ejemplo de Máquina de Estados con Raspberry Pi Pico

Este proyecto es un ejemplo simple de cómo implementar una máquina de estados en Raspberry Pi Pico. El programa alterna entre tres estados, cada uno correspondiente a un intervalo de tiempo diferente. En cada estado, el Pico envía un mensaje a través del puerto serial indicando el número de segundos correspondiente al estado actual.

## Estados

La máquina de estados tiene tres estados definidos:

- `ONE_SECOND`: En este estado, el Pico espera un segundo antes de cambiar al siguiente estado.
- `TWO_SECONDS`: En este estado, el Pico espera dos segundos antes de cambiar al siguiente estado.
- `THREE_SECONDS`: En este estado, el Pico espera tres segundos antes de volver al primer estado.

## Eventos

Los eventos en este programa son los intervalos de tiempo transcurridos. Cada vez que el tiempo actual menos el último tiempo registrado alcanza o supera el intervalo definido para el estado actual, se produce un evento que desencadena el cambio de estado.

## Acciones

Las acciones en este programa son:

- Enviar un mensaje a través del puerto serial indicando el número de segundos correspondiente al estado actual.
- Actualizar el estado de la máquina de estados.
- Actualizar la variable `lastTime` con el tiempo actual para marcar el inicio de un nuevo intervalo.

## Cómo funciona

El programa utiliza la función `millis()` para obtener el tiempo transcurrido desde que el Pico se inició. Se utiliza una variable `lastTime` para almacenar la última vez que se envió un mensaje. En cada iteración del bucle principal (`loop`), el programa verifica si ha transcurrido el tiempo necesario para cambiar de estado. Si es así, realiza las acciones correspondientes y actualiza el estado y la variable `lastTime`.

## Uso

Para utilizar este ejemplo, simplemente carga el código en tu Raspberry Pi Pico y abre el monitor serial de tu IDE.