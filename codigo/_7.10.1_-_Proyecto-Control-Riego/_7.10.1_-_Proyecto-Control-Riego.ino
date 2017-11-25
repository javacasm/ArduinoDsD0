/*
Curso de Arduino
Control de riego

Descripcion
Sistema que en funcion de la humedad del suelo 
activa o desactiva un sistema de riego

Montaje

Sensor de humedad A0 -            A0
Potenciometro                     A1
Rele que enciendo la Bomba        10

by JAVacasM
*/
/* ==== Defines - Constantes ==== */
#define SERIAL_BAUD 9600    // Configuracion de conexion serie

#define PIN_HUMEDAD_SUELO A1 
#define PIN_POTENCIOMETRO A0

#define PIN_RELE          10

#define ESPERA            1000
/* ==== END Defines ==== */


/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(SERIAL_BAUD);
  pinMode(PIN_RELE,OUTPUT);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {

   int iHumedad=1023-analogRead(PIN_HUMEDAD_SUELO);
   int iPotenciometro=analogRead(PIN_POTENCIOMETRO);

   Serial.print("Potenciometro:");
   Serial.print(iPotenciometro);
   Serial.print(" Humedad:");
   Serial.println(iHumedad);
   
   if(iPotenciometro>iHumedad){
     enciendeRiego();
   }else{
     apagaRiego();
   }
   delay(ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */
void enciendeRiego(){
  digitalWrite(PIN_RELE,HIGH);
  Serial.println("Riego encendido");
}

void apagaRiego(){
  digitalWrite(PIN_RELE,LOW);
  Serial.println("Riego apagado");
}
/* ==== END Functions ==== */
