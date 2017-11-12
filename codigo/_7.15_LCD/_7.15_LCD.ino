
/*
Curso de Arduino

LED RGB Anodo comun

Conexiones

 * LCD RS a pin 12
 * LCD Enable  a pin 11
 * LCD D4  a pin 5
 * LCD D5  a pin 4
 * LCD D6  a pin 3
 * LCD D7  a pin 2
 * LCD R/W pin to ground
 * Potenciometro de 10K 
 * extremos a +5V y GND 
 * LCD pin 3 al cursos
 
 Library originally added 18 Apr 2008
 by David A. Mellis (http://www.arduino.cc/en/Tutorial/LiquidCrystal)
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe

 updated by JAVacasM
 
 
 */

/* ==== Includes - Librerias==== */
#include <LiquidCrystal.h>
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
// Inicializamos con nuestra conexion
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  
  lcd.begin(16, 2);   // Inicializamos
 
  lcd.print("Hola Arduino!"); // Imprimimos en la posicion inicial
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  lcd.setCursor(0, 1);   // Posicionamos el cursos en la segunda fila
  
  lcd.print(millis()/1000);  // Mostramos los segundos que han pasado desde el arranque
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
