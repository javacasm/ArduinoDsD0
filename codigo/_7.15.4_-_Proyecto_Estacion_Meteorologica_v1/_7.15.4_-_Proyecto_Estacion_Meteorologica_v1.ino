/*
Curso de Arduino

Proyecto: Estacion meteorologica v1



Conexiones

Sensor de temperatura DHT22:
  El terminal del extremo izquiero conectado a 5V
  El terminal del otro extremo conectado a GND
  El terminal segundo conectado al pin digital 2
  (el tercer terminal no se conecta)


LCD I2C

  Vcc a 5V
  GND a GND
  SDA a SDA (A4)
  SCL a SCL (A5)


by JAVacasM
 */


/* ==== Includes - Librerias==== */
// SENSOR DHT22
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

// LCD I2C
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_DHT      2

//#define DHT_TIPO           DHT11     // DHT 11
#define DHT_TIPO           DHT22     // DHT 22 (AM2302)
//#define DHT_TIPO           DHT21     // DHT 21 (AM2301)


/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
// DHT22
DHT_Unified dht(PIN_DHT,DHT_TIPO);

long lTiempoEspera;  // el sensor nos dirá el tiempo mínimo

// LCD
LiquidCrystal_I2C lcd(0x27,16,2);

/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */

/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  // Serie
  Serial.begin(9600);

  // Sensor DHT22
  dht.begin();

  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  lTiempoEspera = sensor.min_delay / 1000;

  // LCD I2C
  lcd.init();                      // initialize the lcd 

  // Print a message to the LCD.
  lcd.backlight();
  
}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  // Sensor DHT22
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error leyendo temperatura!");
    lcd.setCursor(0,0);
    lcd.print("Error temperatura");
  }
  else {
    Serial.print("Temperatura:");
    Serial.print(event.temperature);
    Serial.print(" C ");
    lcd.setCursor(0,0);
    lcd.print("Temp:");
    lcd.print(event.temperature);
    lcd.print(" C ");
  }

 // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println(" Error leyendo humedad!");
    lcd.setCursor(0,1);
    lcd.print("Error Humedad");
  }
  else {

    Serial.print(" Humedad: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
    lcd.setCursor(0,1);
    lcd.print("Humedad: ");
    lcd.print(event.relative_humidity);
    lcd.print("%");
  }

  delay(lTiempoEspera);
  
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
