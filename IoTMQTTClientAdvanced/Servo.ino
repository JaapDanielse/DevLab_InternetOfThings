// Servo Module


//----------------------------------------------------------------------------------------------------
void ServoInit()
{
  Servo_SG90.attach(SERVOPIN);
  Servo_SG90.write(ServoValue);
}


//----------------------------------------------------------------------------------------------------
void SetServo(int Direction)
{
  Serial.print("Servo: ");
  Serial.println(Direction);
  ServoValue = Direction;  
  Servo_SG90.write(ServoValue);
}
