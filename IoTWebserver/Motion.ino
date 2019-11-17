// Motion Module


#ifdef MOTION
//----------------------------------------------------------------------------------------------------
void MotionInit()
{
  pinMode(MOTIONPIN, INPUT); 
}


//----------------------------------------------------------------------------------------------------
void MotionRead()
{
  MotionValue = digitalRead(MOTIONPIN); // save value
}
#endif


//----------------------------------------------------------------------------------------------------
String MotionString()
{
  #ifdef MOTION
    String MotionValueString;
    if ( MotionValue == 0) MotionValueString = "NONE";
    if ( MotionValue == 1) MotionValueString = "DETECTED !";
    return(",\"MOTION\":\""+ MotionValueString + "\"");
  #endif

  return("");
}
