/*
Curso de Arduino

Bucle que envia datos al PC


Conexiones - USB

by JAVacasM
 */


/* ==== Includes - Librerias==== */

/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */

/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(9600);  // Configurando el puerto Serie
  
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  //Serial.println("Bucle desde 100");
  // Definimos la variable local i
  for (int i=100;i>0;i=i-5) {  
    Serial.print(i);
    Serial.print(",");
    Serial.println(50);
  }

}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
