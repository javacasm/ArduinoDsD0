/*
Curso de Arduino

Control de Rele

Conexiones
Pin positivo del rele a 5V
Pin negativo del rele a GND
Pin de Señal (s)  a pin 11 de arduino

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_RELE 11
#define ESPERA 2000
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */

/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  pinMode(PIN_RELE,OUTPUT);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  digitalWrite(PIN_RELE,HIGH);
  delay(ESPERA);
  digitalWrite(PIN_RELE,LOW);
  delay(ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
