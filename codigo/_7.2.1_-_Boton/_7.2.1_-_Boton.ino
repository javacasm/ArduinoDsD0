/*
 * Curso de Arduino
 *
 * Parpadeo de led sin delay
 *
 * Conexiones
 * LED conectado a pin 13  (Se puede usar el de la placa)
 *
 * by JAVacasM
 *
 * revised by chute (2017/11/16)
 *
 */

/* ==== Defines - Constantes ==== */
#define PIN_BOTON   2
#define PIN_LED   13
/* ==== END Defines ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  pinMode(PIN_BOTON, INPUT);
  pinMode(PIN_LED,OUTPUT);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iEstadoBoton=digitalRead(PIN_BOTON);

  digitalWrite(PIN_LED,iEstadoBoton);

  delay(10);
}
/* ==== End Loop ==== */
