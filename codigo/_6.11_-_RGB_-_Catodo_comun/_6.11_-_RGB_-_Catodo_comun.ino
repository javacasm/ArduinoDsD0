/*
Curso de Arduino

LED RGB Catodo comun

Conexiones

LED RGB

pin Rojo  11
pin Verde 10
pin Azul   9
pin comun a GND
by JAVacasM
 */


/* ==== Includes - Librerias==== */

/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_ROJO  11
#define PIN_VERDE 10
#define PIN_AZUL   9

#define ESPERA 1000
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */

/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() { // Configuramos los pines como salidas
  pinMode(PIN_ROJO,OUTPUT);
  pinMode(PIN_VERDE,OUTPUT);
  pinMode(PIN_AZUL,OUTPUT);
  
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  
  // Veremos rojo
  digitalWrite(PIN_VERDE, LOW);   // Apagamos el verde
  digitalWrite(PIN_AZUL,  LOW);   // Apagamos el azul
  digitalWrite(PIN_ROJO, HIGH);   // Encendemos el rojo

  delay(ESPERA);

  // Veremos azul
  digitalWrite(PIN_VERDE, LOW);   // Apagamos el verde
  digitalWrite(PIN_AZUL, HIGH);   // Encendemos el azul
  digitalWrite(PIN_ROJO,  LOW);   // Apagamos el rojo

  delay(ESPERA);

    // Veremos verde
  digitalWrite(PIN_VERDE, HIGH);  // Encendemos el verde
  digitalWrite(PIN_AZUL,  LOW);   // Apagamos el azul
  digitalWrite(PIN_ROJO,  LOW);   // Apagamos el rojo

  delay(ESPERA);

  // Veremos morado: azul+rojo
  digitalWrite(PIN_VERDE, LOW);   // Apagamos el verde
  digitalWrite(PIN_AZUL, HIGH);   // Encendemos el azul
  digitalWrite(PIN_ROJO, HIGH);   // Encendemos el rojo

  delay(ESPERA);

  // Veremos cyan: verde+azul
  digitalWrite(PIN_VERDE, HIGH);  // Encendemos el verde
  digitalWrite(PIN_AZUL,  HIGH);  // Encendemos el azul
  digitalWrite(PIN_ROJO,   LOW);  // Apagamos el rojo

  delay(ESPERA);

  // Veremos amarillo: verde y rojo
  digitalWrite(PIN_VERDE, HIGH);  // Encendemos el verde
  digitalWrite(PIN_AZUL,   LOW);  // Apagamos el azul
  digitalWrite(PIN_ROJO,  HIGH);  // Encendemos el rojo

  delay(ESPERA);
  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */
/* ==== END Functions ==== */
