
// Definición de estados
enum class States {
  ONE_SECOND,
  TWO_SECONDS,
  THREE_SECONDS
};

// Estado inicial
States state = States::ONE_SECOND;

// Variable para almacenar la última vez que se envió un mensaje
unsigned long lastTime = 0;

// Intervalos de tiempo (en milisegundos)
const unsigned long oneSecond = 1000;
const unsigned long twoSeconds = 2000;
const unsigned long threeSeconds = 3000;

void setup() {
  // Iniciar comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Obtener el tiempo actual
  unsigned long currentTime = millis();

  // Máquina de estados
  switch (state) {
    case States::ONE_SECOND:
      if (currentTime - lastTime >= oneSecond) {
        Serial.println("1 segundo");
        lastTime = currentTime;
        state = States::TWO_SECONDS;
      }
      break;
    case States::TWO_SECONDS:
      if (currentTime - lastTime >= twoSeconds) {
        Serial.println("2 segundos");
        lastTime = currentTime;
        state = States::THREE_SECONDS;
      }
      break;
    case States::THREE_SECONDS:
      if (currentTime - lastTime >= threeSeconds) {
        Serial.println("3 segundos");
        lastTime = currentTime;
        state = States::ONE_SECOND;
      }
      break;
  }
}