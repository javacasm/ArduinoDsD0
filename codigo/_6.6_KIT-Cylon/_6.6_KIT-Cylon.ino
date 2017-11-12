/*
Curso de Arduino

Scanner Larson o KIT o Cylon
Encendemos y apagamos 5 leds conectado a los pines 8,9,10,11,12

Conexiones

LED:
  Terminal positivo (el más largo) conectado a los pines 8,9,10,11,12
  Terminal negativo (más corto): conectados a una resistencias de 220 
  Ohmios
      conectada a GND

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PRIMER_LED           8
#define ULTIMO_LED           12
#define TIEMPO_ESPERA     1000 // 1000 milisegundos = 1 segundo
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  for(int i=PRIMER_LED;i<=ULTIMO_LED;i++){  // Iteramos por todos los pines
      pinMode(i,OUTPUT);    // Configuramos el pin como salida
  }

}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  // Vamos por orden creciente de pines
  for(int i=PRIMER_LED;i<=ULTIMO_LED;i++){  // incrementamos a cada paso
    digitalWrite(i,HIGH); // Encendemos el led i
    delay(TIEMPO_ESPERA);
    digitalWrite(i,LOW); // Apagamos el led i, antes de pasar al siguiente
  }
  // Vamos en orden decreciente de pines
  for(int i=ULTIMO_LED;i>=PRIMER_LED;i--){  // decrementamos a cada paso
    digitalWrite(i,HIGH); // Encendemos el led i
    delay(TIEMPO_ESPERA);
    digitalWrite(i,LOW); // Apagamos el led i, antes de pasar al siguiente
  }

}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
