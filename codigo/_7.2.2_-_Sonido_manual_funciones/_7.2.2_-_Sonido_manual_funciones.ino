/*
Curso de Arduino

Generando Sonido manualmente

Conexiones 
Zumbador a pin 5

by JAVacasM
 */

/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_ZUMBADOR 5
#define N 500
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */

/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  pinMode(PIN_ZUMBADOR,OUTPUT);
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int espera=1;
/*  for(int i=0;i<N/espera;i++){
    digitalWrite(PIN_ZUMBADOR,LOW);
    delay(espera);
    digitalWrite(PIN_ZUMBADOR,HIGH);
    delay(espera);
  }*/
  enciendeApaga(PIN_ZUMBADOR,espera,N);
  enciendeApaga(PIN_ZUMBADOR,espera*2,N*3);
  enciendeApaga(PIN_ZUMBADOR,5,N*2);
}

/* ==== End Loop ==== */

/* ==== Funciones ==== */
void enciendeApaga(int pin,int periodoNota,int duracion){
    for(int i=0;i<duracion/(2*periodoNota);i++){
      digitalWrite(pin,LOW);
      delay(periodoNota);
      digitalWrite(pin,HIGH);
      delay(periodoNota);
  }
}

/* ==== END Functions ==== */
