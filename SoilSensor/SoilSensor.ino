// GPO DevLab Soil Moisture Sensor example

int SoilSensValue = 0;

void setup() 
{
  Serial.begin(115200); // Set baudrate
}

void loop() 
{
   SoilSensValue = analogRead(A0); // read sensor value
   Serial.println("Soil sensor value:" + String(SoilSensValue)); // Show
   delay(1000); // wait a second
}
