/*
Curso de Arduino
Iluminacion gradual con LEDs

Descripcion
Controlaremos la intensidad de la ilumniacion con un potenciometro

Montaje

Potenciometro                     A0
Transistor Mosfet (de potencia)    9

by JAVacasM
*/

/* ==== Defines - Constantes ==== */
#define PIN_POTENCIOMETRO A0

#define PIN_PWM           9
/* ==== END Defines ==== */


/* ==== Setup - Configuracion ==== */
void setup() {
// Nada que configurar aqui
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iPotenciometro=analogRead(PIN_POTENCIOMETRO);
  int iValorBrillo=map(iPotenciometro,0,1023,0,255);
  // Convertimos el valor del potenciometro (0-1023)
  // a la escala de brillo (0-255)
  
  analogWrite(PIN_PWM, iValorBrillo);
    
    delay(30);
}

