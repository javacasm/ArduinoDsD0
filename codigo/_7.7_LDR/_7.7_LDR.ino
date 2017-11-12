/*
Curso de Arduino

Lectura de valor de una resistencia LDR conectada a pin analógico A0

Conexiones

Resistencia LDR:
  Un terminal conectado a 5V
  Otro terminal conectado a la resistencia de 10k y conectado a A0
  El otro terminal de la resistencia conectado a GND
  (ninguno de los dos componentes tiene polaridad)

     ---- 5V
     |
    LDR
     |
     |--- A0
     |
Resistencia
     |
     ---- GND

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_LDR           A0
#define TIEMPO_ESPERA     1000 // 1000 milisegundos = 1 segundo
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
  int iValorLDR=analogRead(PIN_LDR);

  Serial.print("Valor LDR:");
  Serial.println(iValorLDR);

  delay(TIEMPO_ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
