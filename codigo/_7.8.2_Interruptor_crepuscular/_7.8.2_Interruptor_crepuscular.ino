/*
Curso de Arduino

Interruptor crepuscular

Conexiones
Potenciómetro:
  El terminal de un extremo conectado a 5V
  El terminal del otro extremo conectado a GND
  El terminal central  conectado a A1


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

LED conectado a  pin 7 

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_LDR            A0
#define PIN_POTENCIOMETRO  A1
#define PIN_LED             7

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
  pinMode(PIN_LED,OUTPUT);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iValorLDR=analogRead(PIN_LDR);
  int iValorPot=analogRead(PIN_POTENCIOMETRO);
  
  Serial.print("LDR:");
  Serial.print(iValorLDR);

  Serial.print(" Pot:");
  Serial.println(iValorPot);

  if(iValorPot<iValorLDR) {
    digitalWrite(PIN_LED,HIGH); // Encendemos la luz
    Serial.println("Encendemos la luz");
  } else {
    digitalWrite(PIN_LED,LOW); // Apagamos la luz
    Serial.println("Apagamos la luz");
  }

  delay(TIEMPO_ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
