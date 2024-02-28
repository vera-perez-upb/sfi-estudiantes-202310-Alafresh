### Funciones Principales

1. **`processData(uint8_t *pData, uint8_t size, uint8_t *res)`:**
   - Esta función toma un puntero a un array de bytes (`pData`), su tamaño (`size`), y un puntero a un byte (`res`).
   - Calcula la suma de los valores de los bytes en `pData` después de restarles `0x30` (48 en decimal), que es el valor ASCII para '0'.
   - Almacena el resultado en la dirección apuntada por `res`.

2. **`task1()`:**
   - Implementa una máquina de estados finitos (FSM) con dos estados: `INIT` y `WAIT_DATA`.
   - En el estado `INIT`, inicializa la comunicación serie con una velocidad de 115200 baudios y cambia al estado `WAIT_DATA`.
   - En el estado `WAIT_DATA`, espera a que lleguen 5 bytes por el puerto serie.
     - Cuando se reciben 5 bytes, se llama a `processData` para calcular la suma de los valores de los bytes recibidos y se imprime el resultado por el puerto serie.

#### Variables Estáticas

1. `rxData`: Array estático de 5 bytes para almacenar los datos recibidos por el puerto serie.
2. `dataCounter`: Variable estática para rastrear el número de datos recibidos.

#### Preguntas Respondidas

1. **¿Por qué es necesario declarar `rxData` static?**
   - Es necesario declarar `rxData` como `static` para que mantenga su valor entre llamadas a la función `task1()`. Si `rxData` no fuera `static`, se crearía una nueva instancia de `rxData` cada vez que se llama a `task1()`, lo que resultaría en la pérdida de datos anteriores y un comportamiento impredecible en la función `task1()`.

2. **¿Se inicializa `dataCounter` a 0 cada vez que se ingresa a la función `loop()`?**
   - No, `dataCounter` no se inicializa a 0 cada vez que se ingresa a la función `loop()`. Debido a que `dataCounter` se declara como `static`, mantiene su valor entre llamadas a la función `task1()`. Esto es necesario para que `dataCounter` pueda rastrear el número de datos recibidos de forma continua.

3. **¿Por qué el nombre del arreglo corresponde a la dirección del primer elemento del arreglo?**
   - El nombre del arreglo en C/C++ se convierte automáticamente en un puntero al primer elemento del arreglo cuando se utiliza en una expresión. Por lo tanto, `rxData` es equivalente a `&rxData[0]`, que es la dirección de memoria del primer elemento del arreglo `rxData`.

4. **¿Por qué es necesaria la constante `0x30` en `(pData[i] - 0x30)`?**
   - La constante `0x30` se utiliza para convertir un carácter numérico ASCII en su valor numérico equivalente. En ASCII, los caracteres '0' a '9' tienen valores numéricos consecutivos a partir de `0x30`. Por lo tanto, al restar `0x30` de un carácter numérico ASCII, se obtiene su valor numérico real. Esto es útil cuando se procesan datos recibidos como caracteres ASCII y se necesita trabajar con sus valores numéricos.