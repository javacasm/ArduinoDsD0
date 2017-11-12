/*
Curso de Arduino

Medida de la temperatura y humedad usando un sensor DHT22 conectado pin digital 2

Conexiones

Potenciómetro:
  El terminal del extremo izquiero conectado a 5V
  El terminal del otro extremo conectado a GND
  El terminal segundo conectado al pin digital 2
  (el tercer terminal no se conecta)

by JAVacasM
 */


/* ==== Includes - Librerias==== */
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
/* ====  END Includes ==== */

/* ==== Defines - Constantes ==== */
#define PIN_DHT      2

//#define DHT_TIPO           DHT11     // DHT 11
#define DHT_TIPO           DHT22     // DHT 22 (AM2302)
//#define DHT_TIPO           DHT21     // DHT 21 (AM2301)

/* ==== END Defines ==== */

/* ==== Variables Globales ==== */
DHT_Unified dht(PIN_DHT,DHT_TIPO);

long lTiempoEspera;  // el sensor nos dirá el tiempo mínimo
/* ==== END Global Variables ==== */


/* ==== Funciones a usar - Prototipos ==== */
/* ==== END Prototipos ==== */

/* ==== Setup - Configuracion ==== */
void setup() {
  Serial.begin(9600); // Activamos la comunicación serie con el PC


  dht.begin();   // Incializamos la comunciación con el sensor

  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  // Mostramos los datos del sensor referentes a temperatura
  Serial.println("------------------------------------");
  Serial.println("Temperatura");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Valor:    "); Serial.print(sensor.max_value); Serial.println(" C");
  Serial.print  ("Min Valor:    "); Serial.print(sensor.min_value); Serial.println(" C");
  Serial.print  ("Resolucion:   "); Serial.print(sensor.resolution); Serial.println(" C");
  Serial.println("------------------------------------");
  
  // Mostramos los datos del sensor referentes a humedad
  
  dht.humidity().getSensor(&sensor);
  
  Serial.println("------------------------------------");
  Serial.println("Humedad");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Valor:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Valor:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolucion:   "); Serial.print(sensor.resolution); Serial.println("%");
  Serial.println("------------------------------------");
  
  // Establecemos el tiempo de espera en funcion de lo que nos da el sensor
  
  lTiempoEspera = sensor.min_delay / 1000;

  Serial.print("Esperaremos: ");
  Serial.print(lTiempoEspera);
  Serial.println(" ms");

}
/* ==== END Setup ==== */

/* ==== Loop - Codigo que se repite==== */
void loop() {
  sensors_event_t event;
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error leyendo temperatura!");
  }
  else {
    Serial.print("Temperatura:");
    Serial.print(event.temperature);
    Serial.println(" C");
  }
  // Get humidity event and print its value.
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error leyendo humedad!");
  }
  else {
    Serial.print("Humedad: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }

  delay(lTiempoEspera);
}
/* ==== End Loop ==== */

/* ==== Funciones ==== */

/* ==== END Functions ==== */
