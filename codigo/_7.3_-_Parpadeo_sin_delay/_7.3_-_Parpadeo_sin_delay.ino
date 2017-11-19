/*
Curso de Arduino

Parpadeo de led sin delay


Conexiones 
LEd conectado a pin 13  (Se puede usar el de la placa)

by JAVacasM
 */


/* ==== Includes - Librerias==== */

/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_LED 13
#define INTERVALO 1000  // intervalo de parpadeo
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
int estadoLed=LOW;   // Ultimo estado del led
long anteriorMillis = 0;     // almacena el momento del  ultimo cambio de estado
/* ==== END Global Variables ==== */

/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  pinMode(PIN_LED, OUTPUT);  
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
 unsigned long actualMillis = millis();
  if(actualMillis - anteriorMillis > INTERVALO) {
    anteriorMillis = actualMillis;   
    if (estadoLed == LOW) {
      estadoLed = HIGH;
    } else {
      estadoLed = LOW;
    }
    digitalWrite(PIN_LED, estadoLed);
  }

}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
