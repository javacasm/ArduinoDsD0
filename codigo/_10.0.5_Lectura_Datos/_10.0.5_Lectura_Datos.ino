void setup() {
   Serial.begin(9600);     // abrimos el puerto a  9600 bps
}

void loop() {
    if (Serial.available() > 0) {  // hay caracteres pendientes de recibir

            char caracterRecibido = Serial.read();

            Serial.print("He recibido el caracter: ");
            Serial.print(caracterRecibido);   // Imprimimos el caracter
            Serial.print(" con codigo ascii:");
            Serial.println(int(caracterRecibido)); // Imprimimos su codigo ascii
    }
}
