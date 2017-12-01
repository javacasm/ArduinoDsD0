/*
Curso de Arduino

Controlando luces navideñas con reles
Luces controladas con 4 reles y musica navideña

Conexiones 
Zumbador a pin 5

4 Reles pines 8-11

Scores 2 by tomds
https://github.com/tomds/Arduino-Tunes/blob/master/arduino_tunes.pde

by JAVacasM

*/


/* ==== Defines - Constantes ==== */
#define PIN_ZUMBADOR 5

#define PIN_RELE1   11
#define PIN_RELE2   10
#define PIN_RELE3    9
#define PIN_RELE4    8

#define NUMERO_RELES 4   // Podiamos sustituirlo por  sizeof(iReles)/sizeof(int)
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
// Array de reles, podemos anadir mas reles
int iReles[]={PIN_RELE1, PIN_RELE2, PIN_RELE3,PIN_RELE4};

int iReleActivo=0;    // Guardamos el rele que esta activo

int tempo=300;        // Velocidad a la que la reproducimos

char nombreNotas[] = { 'c', 'd', 'e', 'f', 's', 'g', 'a', 'v', 'b', 'C', 'D', 'E' };
int tonoNotas[] = { 1915, 1700, 1519, 1432, 1352, 1275, 1136, 1073, 1014, 956, 852, 758 };   

// Guarda las notas de la cancion, un espacio es una pausa  
char notasCancion[] = "bbbbbbbDgab CCCCCbbbbbaabaDbbbbbbbDgab  CCCCCbbbbDDCag ";  // Jingle Bells
// Guarda la nuracion de cada nota
int duraciones[] = { 1,1,2,1,1,2,1,1,1,1,3,1,   1,1,2,1,1,1,1,1,1,1,1,1,1,2,2,1,1,2,1,1,2,1,1,2,1,3,1,1, 1,1,2,1,1,1,1,1,1,1,1,1,1,3,2};
/* ==== END Global Variables ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  // Hacemos un bucle sobre todos los reles (funcionaria si cambiamos el numero de reles)
  for(int i = 0; i<NUMERO_RELES; i++){ 
    pinMode(iReles[i],OUTPUT);      // Cada pin como salida
    digitalWrite(iReles[i],LOW);    // Lo apagamos
  }
  pinMode(PIN_ZUMBADOR,OUTPUT);  // Pin del zumbador como salida
}

/* ==== END Setup ==== */


/* ==== Loop - Codigo que se repite==== */
void loop() {
  for (int i = 0; i < sizeof(notasCancion); i++) {  // Bucle para recorrer todas las notas
    digitalWrite(iReles[iReleActivo],HIGH);   // Enciende el rele que toque
    if (notasCancion[i] == ' ') { // silencio
      delay(duraciones[i] * tempo); 
    } else {
      playNotaPorNombre(notasCancion[i], duraciones[i] * tempo);
    }

    delay(tempo / 2);      // pausa entre notas
    
    digitalWrite(iReles[iReleActivo],LOW);  // Apagamos el rele que toca

    iReleActivo=iReleActivo+1;      // Cambiamos a la siguiente tira
    if(iReleActivo==NUMERO_RELES)  {   
       iReleActivo=0; // Volvemos al primero 
    }
  }
}

void playNota(int tono, int duracion) { // Reproduce una nota de tono durante duracion
  for (long i = 0; i < duracion * 1000L; i += tono * 2) {  
    // Usamos long porque pueden ser numero muy grandes
    digitalWrite(PIN_ZUMBADOR, HIGH);
    delayMicroseconds(tono);
    digitalWrite(PIN_ZUMBADOR, LOW);
    delayMicroseconds(tono);
  }
}

void playNotaPorNombre(char nota, int duracion) {  // Busca la nota por su nombre y la reproduce 
  for (int i = 0; i<sizeof(nombreNotas); i++) { // busca la nota
    if (nombreNotas[i] == nota) {  // La ha encontrado
      playNota(tonoNotas[i], duracion);  // Optimizacion  break;  // Dejamos de buscar
    }
  }
}
/* ==== END Functions ==== */
