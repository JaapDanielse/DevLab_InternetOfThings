// GPO DevLab Servo example

#include <Servo.h>

#define ServoMin 0 //
#define ServoMax 155 //

Servo Servo_SG90;

int  ServoValue=0;
bool ServoDirection = true;

void setup() 
{
  // D0=16, D1=5, D2=4, D3=0, D4=2, D5=14, D6=12, D7=13, D8=15
  Servo_SG90.attach(D5); // D4=2
  Servo_SG90.write(ServoValue);
  Serial.begin(115200); // Set baudrate
}

void loop() 
{
  
  if(ServoDirection) 
    Servo_SG90.write(ServoValue++);
  else
    Servo_SG90.write(ServoValue--);

  if(ServoValue==ServoMin || ServoValue==ServoMax) ServoDirection = !ServoDirection;
  
  delay(10); // Wait a bit
}
