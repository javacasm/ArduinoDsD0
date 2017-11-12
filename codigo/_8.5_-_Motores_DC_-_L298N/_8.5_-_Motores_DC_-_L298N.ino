/*
Curso de Arduino

Control de motor con L298N

Conexiones 
EA(velocidad A)   9
IN1(direccion A)   8 
IN2(direccion A)   7

by JAVacasM
 */


/* ==== Includes - Librerias==== */
#include <L298N.h>
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define SPEEDPIN   9
#define IN1        8
#define IN2        7
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
L298N motor(SPEEDPIN, IN1, IN2);
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  motor.setSpeed(80);   // Velocidad a 80 (entre 0 y 255)
  motor.forward();      // Adelante
  delay( 1000 );        // espera 1 segundo
  motor.setSpeed(127);  // Media velocidad
  motor.backward( );    // Atras
  delay( 1000 );        // espera 1 segundo
  motor.stop();         // Paramos el motor
  delay( 1000 );  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
