// RGBLed Module

//----------------------------------------------------------------------------------------------------
void RGBLedInit()
{
#ifdef RGBLED
  pixels.begin();
  pixels.setPixelColor(0, pixels.Color(LedRValue, LedGValue, LedBValue));
#endif
}


//----------------------------------------------------------------------------------------------------
void SetRGBLed(byte RValue, byte GValue, byte BValue)
{
#ifdef RGBLED
  LedRValue = RValue;
  LedGValue = GValue;
  LedBValue = BValue;
  pixels.setPixelColor(0, pixels.Color(LedRValue, LedGValue, LedBValue));
  pixels.show();
#endif
}

//----------------------------------------------------------------------------------------------------
String RGBLedString()
{
  #ifdef RGBLED
    return(",\"RGBLED\":1");
  #endif

  return("");
}
