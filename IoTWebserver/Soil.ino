// Soil Module


#ifdef SOIL
//----------------------------------------------------------------------------------------------------
void SoilInit()
{
  pinMode(SOILPIN, INPUT); 
}


//----------------------------------------------------------------------------------------------------
void SoilRead()
{
  static unsigned long SoilTimer = 0;
  if (millis() < SoilTimer) return;
  SoilTimer = millis() + 2000;
  SoilValue = analogRead(SOILPIN); // read sensor value
}
#endif


//----------------------------------------------------------------------------------------------------
String SoilString()
{
  #ifdef SOIL
    const int SOILDRY    =   0;
    const int SOILNORMAL = 100;
    const int SOILMOIST  = 200;
    const int SOILWET    = 300;
    const int SOILSOAKED = 400;
    
    String SoilValueString = "";
  
    if ( SoilValue >= SOILDRY && SoilValue < SOILNORMAL ) SoilValueString = "DRY";
    if ( SoilValue >= SOILNORMAL && SoilValue < SOILMOIST ) SoilValueString = "NORMAL";
    if ( SoilValue >= SOILMOIST && SoilValue < SOILWET ) SoilValueString = "MOIST";
    if ( SoilValue >= SOILWET && SoilValue < SOILSOAKED ) SoilValueString = "WET";
    if ( SoilValue >= SOILSOAKED ) SoilValueString = "SOAKED";
    
    return(",\"SOIL\":\""+ SoilValueString + " " + String(SoilValue) + "\"");
  #endif

  return("");
}
