// Temperature and Humidity module


//----------------------------------------------------------------------------------------------------
void TempHumInit()
{
  dht.setup(TEMPHUMPIN, DHTesp::DHT22); // Connect DHT sensor to D7  
}


//----------------------------------------------------------------------------------------------------
void TempHumRead()
{
  static unsigned long TempHumTimer = millis() + dht.getMinimumSamplingPeriod();
  if (millis() < TempHumTimer) return;
    
  TempHumTimer = millis() + dht.getMinimumSamplingPeriod();
  Humidity = dht.getHumidity();
  Temperature = dht.getTemperature();
}
