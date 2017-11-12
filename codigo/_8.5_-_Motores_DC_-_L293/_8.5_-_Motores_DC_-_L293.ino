/*
Curso de Arduino

Control de motor con L293

Conexiones 
EA(velocidad A)   3
IN1(direccion A)   4 
IN2(direccion A)   5

by JAVacasM
 */


/* ==== Includes - Librerias==== */
#include <L293.h>
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define SPEEDPIN  3
#define I1        4
#define I2        5
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
L293 motor( SPEEDPIN, I1, I2 );
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  motor.forward( 255 ); // Adelante a maxima velocidad
  delay( 1000 );        // espera 1 segundo
  motor.back( 127 );    // Atras a media velocidad
  delay( 1000 );        // espera 1 segundo
  motor.stop();         // Paramos el motor
  delay( 1000 );  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
