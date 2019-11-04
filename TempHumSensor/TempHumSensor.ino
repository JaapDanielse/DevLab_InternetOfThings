#include "DHTesp.h"

DHTesp dht;

void setup()
{
  Serial.begin(115200);
  dht.setup(D7, DHTesp::DHT22); // Connect DHT sensor to D7
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  float Humidity = dht.getHumidity();
  float Temperature = dht.getTemperature();

  Serial.print(dht.getStatusString());
  Serial.print(" Humidity: ");
  Serial.print(Humidity, 1);
  Serial.print("% Temperature: ");
  Serial.print(Temperature, 1);
  Serial.println("°C");
  delay(2000);
}
