// Funcion que se llama antes de iniciar el programa sirve para configurar la placa segun su funcion
void setup() {
  // Configura el pin al que está conectado el LED integrado
  pinMode(LED_BUILTIN, OUTPUT);
}
// Esta función se ejecuta repetidamente en un bucle infinito después del setup
void loop() {
  // Define una variable estática almacena milisegundos en cual el led cambio de estado
  static uint32_t previousTime = 0;
  // lleva el registro del led true escendido false apagado
  static bool ledState = true;
  // la funcion millis() obtiene el tiempo actual en milisegundos desde que el programa comenzó a ejecutarse
  uint32_t currentTime = millis();
  // Comprueba si han transcurrido más de 100 milisegundos desde la última vez que el estado del LED cambió
  if( (currentTime - previousTime) > 100){
    // Actualiza previousTime con el tiempo actual, para usarlo como referencia en la próxima comparación de tiempo.
    previousTime = currentTime;
    // Cambia el estado del LED. Si estaba encendido , lo apaga y viceversa.
    ledState = !ledState;
    // Establece el estado del LED al valor actual de ledState (encendido o apagado).
    digitalWrite(LED_BUILTIN, ledState);
  }
}
