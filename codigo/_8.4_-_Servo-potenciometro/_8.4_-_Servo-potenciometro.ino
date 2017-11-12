/*
Curso de Arduino

Control de servo con potenciometro

Servo:
Cable rojo:            5V
Cable negro/marron:   GND
Cable blanco/naranja:   9

Potenciometro:
Un extremo:            5V
Otro extremo:         GND
Central:               A0

by JAVacasM
 */


/* ==== Includes - Librerias==== */
#include <Servo.h>
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_SERVO 9
#define PIN_POTENCIOMETRO A0

/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
Servo miServo;

/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  miServo.attach(PIN_SERVO);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {

  int iValorPot=analogRead(PIN_POTENCIOMETRO);    // Leemos el potenciometro
  int iPosicionServo=map(iValorPot,0,1023,0,179); // Convertimos el valor al rango del servo
  miServo.write(iPosicionServo);                  // Enviamos la posicion al servo
  delay(15);                                      // Esperamos para darle tiempo al servo a moverse
  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
