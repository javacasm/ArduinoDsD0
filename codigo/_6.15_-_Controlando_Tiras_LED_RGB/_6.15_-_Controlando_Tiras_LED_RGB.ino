/*
Curso de Arduino
Iluminacion gradual con LEDs

Descripcion
Controlaremos la intensidad de la ilumniacion con un potenciometro

Montaje

Potenciometro Verde               A0
Potencimetro Rojo                 A1
Potenciometro Azul                A2
Transistor Mosfet (de potencia) Azul     9
Transistor Mosfet (de potencia) Rojo     10
Transistor Mosfet (de potencia) Verde     11

by JAVacasM
*/

/* ==== Defines - Constantes ==== */
#define PIN_POT_G A0
#define PIN_POT_R A1
#define PIN_POT_B A2

#define PIN_PWM_G          11
#define PIN_PWM_R          10
#define PIN_PWM_B           9
/* ==== END Defines ==== */


/* ==== Setup - Configuracion ==== */
void setup() {
// Nada que configurar aqui
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iPotG=analogRead(PIN_POT_G);
  int iPotR=analogRead(PIN_POT_R);
  int iPotB=analogRead(PIN_POT_B);
  // Convertimos el valor del potenciometro (0-1023)
  // a la escala de brillo (0-255)
  
  int iBrilloG=map(iPotG,0,1023,0,255);
  int iBrilloR=map(iPotR,0,1023,0,255);
  int iBrilloB=map(iPotB,0,1023,0,255);
  
  analogWrite(PIN_PWM_G, iBrilloG);
  analogWrite(PIN_PWM_R, iBrilloR);
  analogWrite(PIN_PWM_B, iBrilloB);
  delay(30);   // Esperamos un tiempo a que se estabilice el brillo
}

