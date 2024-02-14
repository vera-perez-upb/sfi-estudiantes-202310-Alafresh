# Máquinas de Estados

## ¿Qué es una máquina de estado?

Una máquina de estado es un modelo de comportamiento compuesto por un conjunto finito de estados, transiciones entre esos estados y acciones. Es una forma de organizar el comportamiento de un sistema para responder a eventos o condiciones de manera predecible y controlada. Cada estado representa una situación específica, y las transiciones definen cómo el sistema cambia de un estado a otro en respuesta a eventos externos.

## ¿En qué tipo de problemas se utilizan las máquinas de estado?

Las máquinas de estados se utilizan en una variedad de problemas y aplicaciones, incluyendo:

1. **Sistemas de control**: Para controlar el comportamiento de máquinas, robots o dispositivos electrónicos en sistemas embebidos, robótica y automatización.
2. **Interfaces de usuario**: Para gestionar el flujo de una aplicación o sitio web, controlando la navegación entre diferentes pantallas o menús.
3. **Protocolos de comunicación**: En redes y telecomunicaciones, para manejar las diferentes etapas de una comunicación entre dispositivos o sistemas.
4. **Juegos**: Para controlar el estado del juego, como menús, juego activo, pausas y pantallas de fin de juego.
5. **Análisis de texto**: En procesamiento de lenguaje natural, para analizar y procesar texto según patrones o reglas definidas.
6. **Electrónica digital**: En el diseño de circuitos digitales y sistemas lógicos, para controlar secuencias de operaciones o estados de un circuito.
7. **Automatización de procesos**: En la gestión de procesos empresariales o flujos de trabajo, para definir y controlar las diferentes etapas de un proceso.

### ¿Cómo se ejecuta este programa?

Este programa se ejecuta en un microcontrolador compatible con Raspberry pico. Se carga el código en el microcontrolador utilizando el entorno de desarrollo de Arduino (IDE) y se ejecuta automáticamente. La función `setup()` se ejecuta una vez al inicio para inicializar el sistema, y luego la función `loop()` se ejecuta repetidamente, permitiendo que la máquina de estados revise y cambie de estado según sea necesario.

### ¿Pudiste ver este mensaje: `Serial.print("Task1States::WAIT_TIMEOUT\n");`? ¿Por qué crees que ocurre esto?

Este mensaje se imprime cuando el programa cambia al estado `Task1States::WAIT_TIMEOUT`. Esto ocurre durante la primera ejecución de la función `task1()` cuando el estado inicial `Task1States::INIT` realiza sus acciones, como iniciar la comunicación serial y establecer el tiempo inicial, y luego cambia al estado `WAIT_TIMEOUT`. El mensaje indica que el sistema ha completado su inicialización y ahora está esperando que transcurra el intervalo de tiempo especificado.

### ¿Cuántas veces se ejecuta el código en el case `Task1States::INIT`?

El código en el case `Task1States::INIT` se ejecuta una sola vez. Esto se debe a que una vez que se completan las acciones en este estado, el estado de la tarea cambia a `Task1States::WAIT_TIMEOUT`, y en las siguientes ejecuciones de la función `task1()`, el sistema ya no entrará en el case `Task1States::INIT`.
