#include <Wire.h>
#include "DFRobot_SHT20.h"
#include <BH1750.h>

BH1750 luxometro; 

// Ver forma de tomar los datos del sensor:
const byte luxMode = BH1750_CONTINUOUS_HIGH_RES_MODE; 
float tempC;
int pinLM25 = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("Prueba SHT20");
  sht20.initSHT20();
  luxometro.begin(luxMode);
  delay(100);
  sht20.checkSHT20;
}

void loop() {
  float humdedad = sht20.readHumidity();
  float temp_sust = sht20.readTemperature();
  uint16_t luz = luxometro.readLightLevel();
  tempC = analogRead(pinLM35);
  tempC = (5.0 * tempC * 100.0)/1024.0; // Ver esta ecuacion: https://programarfacil.com/blog/arduino-blog/leer-el-sensor-de-temperatura-lm35-en-arduino/
  
  // Ver si funcion este tipo de print: 
  Serial.print("Humedad: " + humedad + " %");     
  Serial.print("Temperatura sustrato: " + temp_sust + " °C");
  Serial.print("Luz: " + luz + " lx");
  Serial.print("Temperatura ambiente: " + tempC + " °C");
  delay(1000);

}
