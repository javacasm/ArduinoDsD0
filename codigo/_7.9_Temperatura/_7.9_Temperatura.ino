/*
Curso de Arduino

Medida de la temperatura usando un sensor LM35 conectado pin analógico A0

Conexiones

Potenciómetro:
  El terminal del extremo izquiero conectado a 5V
  El terminal del otro extremo conectado a GND
  El terminal central  conectado a A0

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_LM35   A0
#define TIEMPO_ESPERA       100 // 100 milisegundos = 0.1 segundo
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
  int iValorLM35=analogRead(PIN_LM35);

  // Convertimos a grados
  // usamos numeros decimales
  float fTemperatura=(5.0 * iValorLM35 * 100.0)/1024.0; // usamos constantes decimales
              // Para forzar la conversión con decimales

  Serial.print("Temperatura:");
  Serial.print(fTemperatura);
  Serial.println("C");


  delay(TIEMPO_ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
