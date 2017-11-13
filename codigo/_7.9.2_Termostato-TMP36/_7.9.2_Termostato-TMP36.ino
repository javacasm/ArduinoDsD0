/*
 Medida de temperatura con sensor TMP36
 JA. Vacas

 Descripción

 Sensor TMP36 
 pin V del sensor conectado a 5V de Arduino
 pin central del sensor Vout a A0 de Arduino
 pin GND a GND de Arduino
 
 */

// constantes que no cambian
// se usan para establecer los pines

const int TMP36Pin = A0;     // Conectamos el pin central
const int LedVerdePin=6;     // Led que representa la refrigeracion
const int PotenciometroPin=A1;

// variables globales que cambian
float temperatura = 0;         // variable para almacenar la temperatura medida
float temperaturaUmbral=0;     // Almacenamos la temperatura umbral
// Configuración
void setup() {
  Serial.begin(9600); // Configuramos la conexion con el PC
  pinMode(LedVerdePin,OUTPUT);  // Configuramos el LedVerdePin como salida
// No necesitamos configurar los pines analogicos
}

// Bucle que se repite
void loop() {
  int lectura = analogRead(TMP36Pin); // Valor entre 0 y 1023
  
  float voltaje = lectura * 5.0 / 1024.0; // Voltaje entre 0 y 5V

  temperatura = (voltaje - 0.5) * 100; // Temperatura en º Celsius

  int valorPotenciometro = analogRead(PotenciometroPin); // Valor entre 0 y 1023

  float voltajeUmbral = valorPotenciometro * 5.0 / 1024.0; // Voltaje entre 0 y 5V

  temperaturaUmbral = (voltajeUmbral - 0.5) * 100; // Temperatura en º Celsius


  Serial.print("Temperatura:");  
  Serial.print(temperatura);  // Mostramos el valor de la temperatura 
  Serial.println("C");

  Serial.print("Temperatura Umbral:");  
  Serial.print(temperaturaUmbral);  // Mostramos el valor de la temperatura umbral
  Serial.println("C");


  if(temperatura>temperaturaUmbral) { // Si la temperatura supera los 30º 
    digitalWrite(LedVerdePin,HIGH);
    Serial.println("Activamos la refrigeracion");
  }else {
    digitalWrite(LedVerdePin,LOW);
    Serial.println("Apagamos la refrigeracion");
  }
  delay(500);
}
