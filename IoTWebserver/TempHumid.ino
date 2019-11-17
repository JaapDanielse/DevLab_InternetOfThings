// Temperature and Humidity module


#ifdef TEMPHUM
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
#endif


//----------------------------------------------------------------------------------------------------
String TempHumString()
{
  #ifdef TEMPHUM
    return(",\"TEMP\":\""+ String(Temperature) + "\",\"HUMID\":\"" + String(Humidity)+ "\"");
  #endif
  return("");
}
