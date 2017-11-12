/*
Curso de Arduino

Encendemos y apagamos un LED conectado al pin 13

Conexiones

LED:
  Terminal positivo (el más largo): pin digital 13
    (Si se usa otro pin hay que incluir una resistencia de al menos 220 Ohmios)
  Terminal negativo (más corto): GND

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_LED           13
#define TIEMPO_ESPERA     1000 // 1000 milisegundos = 1 segundo
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  pinMode(PIN_LED,OUTPUT);    // Configuramos el pin como salida
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  digitalWrite(PIN_LED,HIGH); // Activamos la salida (estado alto (5V))
  delay(TIEMPO_ESPERA);
  digitalWrite(PIN_LED,LOW); // Desactivamos la salida (estado bajo (0V))
  delay(TIEMPO_ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
