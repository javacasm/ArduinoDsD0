/*
Curso de Arduino

Medimos la huedad del suelo con un sensor analogico

Conexiones

Pin positivo a 5V
Pin negativo a GND
Pin A0 a A0

by JAVacasM
 */


/* ==== Includes - Librerias==== */

/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_SENSOR_HUMEDAD A0
#define ESPERA 50
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
Serial.begin(9600);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iValorHumedad=analogRead(PIN_SENSOR_HUMEDAD);
  Serial.println(iValorHumedad);

  delay(ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
