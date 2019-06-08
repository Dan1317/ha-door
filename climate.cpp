#include <Adafruit_Sensor.h>
#include <DHT.h>

#include "climate.h"


/*
 * For detailed usage, please refer to https://learn.adafruit.com/dht/overview
 */
// Uncomment the type of sensor in use:
//#define DHTTYPE    DHT11     // DHT 11
#define DHTTYPE    DHT22     // DHT 22 (AM2302)
//#define DHTTYPE    DHT21     // DHT 21 (AM2301)
const int DHT_DATA = 2;

DHT dht(DHT_DATA, DHTTYPE);

float lastHumidityReading = 0.00f;
float lastTemperatureReading = 0.00f;

float GetHumidity() {
  float humidity = dht.readHumidity();
  if (isnan(humidity)) {
    return lastHumidityReading;
  }
  lastHumidityReading = humidity;
  return humidity;
}

float GetTemperature() {
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float temperature = dht.readTemperature(true);
  if (isnan(temperature)) {
    return lastTemperatureReading;
  }
  lastTemperatureReading = temperature;
  return temperature;
}

float GetHeatIndex() {
  return dht.computeHeatIndex(lastTemperatureReading, lastHumidityReading);
}

