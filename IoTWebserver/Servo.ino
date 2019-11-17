// Servo Module


//----------------------------------------------------------------------------------------------------
void ServoInit()
{
#ifdef SERVO
  Servo_SG90.attach(SERVOPIN);
  Servo_SG90.write(ServoValue);
#endif
}


//----------------------------------------------------------------------------------------------------
void SetServo(int Direction)
{
#ifdef SERVO
  ServoValue = Direction;  
  Servo_SG90.write(ServoValue);
#endif
}


//----------------------------------------------------------------------------------------------------
String ServoString()
{
  #ifdef SERVO
    return(",\"SERVO\":1");
  #endif
  return("");
}
