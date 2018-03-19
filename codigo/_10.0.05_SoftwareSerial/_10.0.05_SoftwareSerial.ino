#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // Usara los pines 10 para RX y 11 para TX
void setup()
{
// Abre el puerto normal de comunicaciones:
Serial.begin(57600);
while (!Serial) {
; // espera a que el puerto esté disponible, sólo en Leonardo
}
Serial.println("hola!");

// establece la velocidad del puerto SoftwareSerial
mySerial.begin(4800);
mySerial.println("Hello, world?");
}

void loop()
{
if (mySerial.available()) //espera a tener datos disponibles para leer
Serial.write(mySerial.read()); //escribe por el serie normal lo que lee por el otro
if (Serial.available()) //espera hasta el serie tenga pendiente, escrito por nos
mySerial.write(Serial.read()); //lo envía por el softwareserie
}

