/*
Curso de Arduino

Medida del voltaje conectado a pin analógico A0

Para modificar ese voltaje usaremos un potenciómetro

Conexiones

Potenciómetro:
  El terminal de un extremo conectado a 5V
  El terminal del otro extremo conectado a GND
  El terminal central  conectado a A0


by JAVacasM
 */


/* ==== Includes - Librerias==== */
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_POTENCIOMETRO   A0
#define TIEMPO_ESPERA       100 // 100 milisegundos = 0.1 segundo
/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(9600); // Activamos la comunicación serie con el PC
  // No es necesario hacer pinMode con los pines Analógicos
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  int iValorPotenciometro=analogRead(PIN_POTENCIOMETRO);

  // Convertimos a voltios
  // usamos numeros decimales
  float fVoltios=iValorPotenciometro/1023.0*5.0; // usamos constantes decimales
              // Para forzar la conversión con decimales

  Serial.print("Valor potenciometro:");
  Serial.print(iValorPotenciometro);
  Serial.print("equivale a ");
  Serial.print(fVoltios);
  Serial.println(" voltios")

  delay(TIEMPO_ESPERA);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
