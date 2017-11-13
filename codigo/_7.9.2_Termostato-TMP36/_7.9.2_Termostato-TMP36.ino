/*
 Curso de Arduino
 
 Medida de temperatura con sensor TMP36
  Descripción

 Sensor TMP36 
 
 pin V del sensor conectado a 5V de Arduino
 pin central del sensor Vout a A0 de Arduino
 pin GND a GND de Arduino

 by JAVacasM
 */
 
/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_TMP36   A0       // Conectamos el pin central
#define PIN_LEDVERDE 6     // Led que representa la refrigeracion
#define PIN_POTENCIOMETRO A1
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(9600); // Configuramos la conexion con el PC
  pinMode(PIN_LEDVERDE,OUTPUT);  // Configuramos el LedVerdePin como salida
// No necesitamos configurar los pines analogicos
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int lectura = analogRead(PIN_TMP36); // Valor entre 0 y 1023
  
  float voltaje = lectura * 5.0 / 1024.0; // Voltaje entre 0 y 5V

  float temperatura = (voltaje - 0.5) * 100; // Temperatura en º Celsius

  int valorPotenciometro = analogRead(PIN_POTENCIOMETRO); // Valor entre 0 y 1023

  float voltajeUmbral = valorPotenciometro * 5.0 / 1024.0; // Voltaje entre 0 y 5V

  float temperaturaUmbral = (voltajeUmbral - 0.5) * 100; // Temperatura en º Celsius


  Serial.print("Temperatura:");  
  Serial.print(temperatura);  // Mostramos el valor de la temperatura 
  Serial.println("C");

  Serial.print("Temperatura Umbral:");  
  Serial.print(temperaturaUmbral);  // Mostramos el valor de la temperatura umbral
  Serial.println("C");


  if(temperatura>temperaturaUmbral) { // Si la temperatura supera los 30º 
    digitalWrite(PIN_LEDVERDE,HIGH);
    Serial.println("Activamos la refrigeracion");
  }else {
    digitalWrite(PIN_LEDVERDE,LOW);
    Serial.println("Apagamos la refrigeracion");
  }
  delay(500);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
