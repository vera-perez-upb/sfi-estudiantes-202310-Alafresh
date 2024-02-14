void task1()
{
  // Definición de estados y variable de estado*` 
  enum class Task1States {
    INIT,
    WAIT_TIMEOUT
    };
    // mantiene el estado actual de la tarea.
  static Task1States task1State = Task1States::INIT;

  // Variable que almacena la última vez que se realizó una acción, se usa para controlar el tiempo entre acciones.
  static uint32_t lastTime = 0;

  // intervalo de tiempo (en milisegundos) entre acciones, en este caso, 1000 ms o 1 segundo.
  constexpr uint32_t INTERVAL = 1000;

    // maneja los diferentes estados de la tarea.
    switch (task1State)
    {
      // Se inicializa la comunicacion serial, se actualiza la variable lastime con el tiempo actual
      // se cambia el estado de wait_timeout y se imprime un mensaje con su estado
      case Task1States::INIT:
      {
        // Acciones:  
        Serial.begin(115200);
        // Garantiza los valores iniciales para el siguiente estado.       
        lastTime = millis();
        task1State = Task1States::WAIT_TIMEOUT;
        Serial.print("Task1States::WAIT_TIMEOUT**\n**");
        break;
      }
      // se espera que haya pasado un intervalo de tiempo se actualiza lastTIme y se imprime el estado actual
      case Task1States::WAIT_TIMEOUT:
      {
        uint32_t currentTime = millis();
        // Evento       
        if ((currentTime - lastTime) >= INTERVAL)
        {
          // Acciones:
          lastTime = currentTime;
          Serial.print(currentTime);
          Serial.print('\n');
        }
        break;
      }
      default:
      {
        Serial.println("Error");
      }
    }
}

void setup()
{
    task1();
}

void loop()
{
    task1();
}