// GPO DevLab Pir Sensor example

int PirValue = 0;

void setup() 
{
  pinMode(D2, INPUT); // Set D2 pin as input
  Serial.begin(115200); // Set baudrate
}

void loop() 
{
  if(PirValue != digitalRead(D2)) // if new sensor value (1 = motion, 0 = still)
  {
    PirValue = digitalRead(D2); // save value
    Serial.println("New Value: " + String(PirValue)); // Show 
  }
  delay(100); // Wait a bit
}
