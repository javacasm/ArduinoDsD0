/*
Curso de Arduino


Descripcion
Controlaremos del color de una tira de leds RGB via puerto serie
Usaremos transistores mosfet para controlar la tira de leds

Montaje


Transistor Mosfet Azul     9
Transistor Mosfet Rojo    10
Transistor Mosfet Verde   11

Selector de colores
https://www.w3schools.com/colors/colors_picker.asp

by JAVacasM
*/

/* ==== Defines - Constantes ==== */
#define PIN_PWM_G          11
#define PIN_PWM_R          10
#define PIN_PWM_B           9
/* ==== END Defines ==== */


#define ERROR_CONVERSION -1

/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(9600); // Configuramos la conexion serie
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {

  if ( Serial.available() > 6 ) { // Al menos necesitamos 6 caracteres
    String sCadena="";
    while( Serial.available() > 0 ){  // Leemos todos los caracteres disponibles
      char c = char(Serial.read());
      if( ( c != '\n' ) && ( c != '\r' ) )  {//Los caracteres de fin de linea no los guardamos
        sCadena += c;
      }
    }
    Serial.print(sCadena.c_str()); // Enviamos lo que hemos leido
    Serial.print(" > ");
    
    // Cogemos los primeros 6 y los convertimos
    int iBrilloR = hexToByte( sCadena.substring(0 , 2).c_str()); // Los 2 primeros el rojo
    int iBrilloG = hexToByte( sCadena.substring(2 , 4).c_str()); // Los 2 siguientes el verde
    int iBrilloB = hexToByte( sCadena.substring(4 , 6).c_str()); // Los 2 ultimos el azul
    
    setColor(iBrilloR, iBrilloG, iBrilloB); // Establecemos los valores recibidos del pwm
  }

  delay(30);   // Esperamos un tiempo a que se estabilice el brillo
}
/* ==== END Loop ==== */

/* ==== Funciones =====*/
// Establecemos los valores de PWM y los enviamos via puerto serie
void setColor( int iBrilloR, int iBrilloG, int iBrilloB){
  Serial.print(iBrilloR); // Enviamos los valores de vuelta por el puerto serie
  Serial.print(",");
  Serial.print(iBrilloG);
  Serial.print(",");
  Serial.println(iBrilloB);
  
  analogWrite(PIN_PWM_G, iBrilloG); // Establecemos los valroes de PWM de los 3 colores
  analogWrite(PIN_PWM_R, iBrilloR);
  analogWrite(PIN_PWM_B, iBrilloB);
}

// Conversion de char a cifra hexadecimal
// Tabla ASCII  https://upload.wikimedia.org/wikipedia/commons/d/dd/ASCII-Table.svg
int charToDigit(char c){
  if ( ( c >= '0' ) && ( c <= '9') ) { // Si es un numero 0-9
    return      c - '0';
  } else if ( ( c >= 'A' ) && ( c <= 'F') ) { // Si es una letra A-F
    return 10 + c - 'A';
  } else if ( ( c >= 'a' ) && ( c <= 'f') ) { // Si es una letra a-f
    return 10 + c - 'a';
  }
  // Si llegamos aqui es que es otro tipo de caracter
  return ERROR_CONVERSION;
}

// Conversion de 2 caracteres a byte hexadecimal
int hexToByte(char cs[2]){
  int iFirstDigit = charToDigit( cs[0] );   // Primer digito
  int iSecondDigit = charToDigit( cs[1] );  // Segundo digito

  // Si hay algun error, lo damos todo por erroneo
  if ( ( iFirstDigit == ERROR_CONVERSION ) || ( iSecondDigit == ERROR_CONVERSION) )  
    return ERROR_CONVERSION;
    
  return iFirstDigit * 16 + iSecondDigit; //Convertimos los 2 digitos a su valor hexadecimal
}


/* ==== Funciones =====*/
