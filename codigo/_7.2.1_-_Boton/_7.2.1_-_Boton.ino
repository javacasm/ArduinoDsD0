
#define PIN_BOTON   2
#define PIN_LED   13

void setup() {
  pinMode(PIN_BOTON, INPUT);
  pinMode(PIN_LED,OUTPUT);
}


void loop() {
  int iEstadoBoton=digitalRead(PIN_BOTON);

  digitalWrite(PIN_LED,iEstadoBoton);

  delay(10);
}
