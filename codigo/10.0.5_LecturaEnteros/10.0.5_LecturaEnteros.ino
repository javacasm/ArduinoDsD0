const int redPin = 3, greenPin = 5, bluePin = 6;

void setup() {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);   pinMode(greenPin, OUTPUT);  pinMode(bluePin, OUTPUT); }

void loop() { 
  while (Serial.available() > 0) { //Si hay datos leemos 3 enteros
    int red = Serial.parseInt(), green = Serial.parseInt(), blue = Serial.parseInt(); 
    if (Serial.read() == '\n') {  // si hay fin de linea hemos terminado
      red = 255 - constrain(red, 0, 255);  // Ajustamos al rango 0-255
      green = 255 - constrain(green, 0, 255);
      blue = 255 - constrain(blue, 0, 255);
      analogWrite(redPin, red);  // Ajustamos el brillo de los 3 niveles
      analogWrite(greenPin, green);
      analogWrite(bluePin, blue);
      // Mostramos los datos en hexadecimal en pantalla
      Serial.print(red, HEX);       Serial.print(green, HEX);       Serial.println(blue, HEX);
    }
  }
}
