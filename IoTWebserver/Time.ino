// Time Module

#ifdef TIME
//----------------------------------------------------------------------------------------------------
void TimeInit()
{
  timeClient.begin();
  timeClient.update();
}


//----------------------------------------------------------------------------------------------------
void TimeRead()
{
  static bool TimeSync = false;

  if (!TimeSync && timeClient.getMinutes()==0)
  { 
    timeClient.update();
    Serial.println("TimeSync");
    TimeSync = true;
  }

  if (TimeSync && timeClient.getMinutes()!=0)
    TimeSync = false;
}
#endif


//----------------------------------------------------------------------------------------------------
String TimeString()
{
  #ifdef TIME
    return("\"TIME\":\""+ timeClient.getFormattedTime() + "\"");
  #endif
  
  return("\"IOT\":0");
}
