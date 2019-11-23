// GPO DevLab Pir Sensor example

int PirValue = 0;

void setup() 
{
  pinMode(D0, INPUT); // Set D0 pin as input
  Serial.begin(115200); // Set baudrate
}

void loop() 
{
  static  int i=0;
  if(PirValue != digitalRead(D0)) // if new sensor value (1 = motion, 0 = still)
  {
    PirValue = digitalRead(D0); // save value
    Serial.print(i++); // Show 
    Serial.println(" New Value: " + String(PirValue)); // Show 
  }
  delay(100); // Wait a bit
}
