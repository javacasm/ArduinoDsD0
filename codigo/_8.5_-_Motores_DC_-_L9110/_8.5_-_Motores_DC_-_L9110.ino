/*
Curso de Arduino

Control de motor con L9110

Conexiones 

MOTOR B
B1A   10
B1B   11
A1A    5
A1B    6
(Todos PWM)

by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define B1A   10
#define B1B   11
#define A1A    5
#define A1B    6
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {  // Al usar PWM no necesitamos pinMode
}
/* ==== END Setup ==== */


/* ==== Loop - Codigo que se repite==== */
void loop() {

  adelante(127);
  delay(1000);
  adelante(255);
  delay(1000);
  parar();
  delay(1000);
  giro(127);
  delay(1000);
  atras(255);
  delay(1000);

}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

void adelante(int velocidad){
  analogWrite(A1A,velocidad);
  analogWrite(A1B,0);
  analogWrite(B1A,velocidad);
  analogWrite(B1B,0);
}

void atras(int velocidad){
  analogWrite(A1A,0);
  analogWrite(A1B,velocidad);
  analogWrite(B1A,0);
  analogWrite(B1B,velocidad);
}

void giro(int velocidad){
  analogWrite(A1A,0);
  analogWrite(A1B,velocidad);
  analogWrite(B1A,velocidad);
  analogWrite(B1B,0);  
}
void parar(){
  analogWrite(A1A,0);
  analogWrite(A1B,0);
  analogWrite(B1A,0);
  analogWrite(B1B,0);
}

/* ==== END Functions ==== */
