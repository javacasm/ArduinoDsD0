/*
Curso de Arduino

Descripcion del proyecto

Conexiones

Potenciometro en A0

PWM en 11

by JAVacasM
 */


/* ==== Includes - Librerias==== */

/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_POT A0
#define PIN_PWM 11
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
  int iPot=analogRead(PIN_POT);
  int pwm=map(iPot,0,1023,0,255);
  analogWrite(PIN_PWM,pwm);
  Serial.println(pwm);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
