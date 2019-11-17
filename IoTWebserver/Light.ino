// Light Module


#ifdef LIGHT
//----------------------------------------------------------------------------------------------------
void LightInit()
{
  pinMode(LIGHTPIN, INPUT); 
}


//----------------------------------------------------------------------------------------------------
void LightRead()
{
  static unsigned long LightTimer = 0;
  if (millis() < LightTimer) return;
  LightTimer = millis() + 1000;
  LightValue = analogRead(LIGHTPIN); // read sensor value
}
#endif


//----------------------------------------------------------------------------------------------------
String LightString()
{
  #ifdef LIGHT
    return(",\"LIGHT\":\"" + String(LightValue) + "\"");
  #endif

  return("");
}
