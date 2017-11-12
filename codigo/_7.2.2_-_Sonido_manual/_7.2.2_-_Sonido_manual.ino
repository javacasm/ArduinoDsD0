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

for(int i=0;i<N/1;i++){
  enciendeApaga(PIN_ZUMBADOR,1);
}

for(int i=0;i<N/2;i++){
  enciendeApaga(PIN_ZUMBADOR,2);
}

for(int i=0;i<N/4;i++){
  enciendeApaga(PIN_ZUMBADOR,4);
}

for(int i=0;i<N/10;i++){
  enciendeApaga(PIN_ZUMBADOR,10);
}
  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

void enciendeApaga(int iPin,long lTiempoEspera){
  digitalWrite(iPin,LOW);
  delay(lTiempoEspera);
  digitalWrite(iPin,HIGH);
  delay(lTiempoEspera);
}

/* ==== END Functions ==== */
