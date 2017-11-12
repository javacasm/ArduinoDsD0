/*
Curso de Arduino

Lectura de valor de potenciometro conectado a pin analógico A0

Conexiones

Potenciómetro:
  El terminal de un extremo conectado a 5V
  El terminal del otro extremo conectado a GND
  El terminal central  conectado a A0


by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_POTENCIOMETRO   A0
#define TIEMPO_ESPERA       1000 // 1000 milisegundos = 1 segundo
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(9600); // Activamos la comunicación serie con el PC
  // No es necesario hacer pinMode con los pines Analógicos
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iValorPotenciometro=analogRead(PIN_POTENCIOMETRO);

  Serial.print("Valor potenciometro:");
  Serial.println(iValorPotenciometro);

  delay(TIEMPO_ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
