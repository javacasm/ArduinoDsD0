/*
Curso de Arduino

Cambios en el nivel de brillo de un led con PWM

Conexiones:

LED: 
  patilla positiva a pin 6
  patilla negativa a GND


by JAVacasM
 */

/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_LED 6
#define ESPERA 20
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */

/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  
  for(int i=0;i<100;i++)  {  // Brillo creciente
    analogWrite(PIN_LED,i);
    delay(ESPERA);
  }

  for(int i=100;i>0;i--)  {    // Brillo decreciente
    analogWrite(PIN_LED,i);
    delay(ESPERA);
  }
  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */
/* ==== END Functions ==== */
