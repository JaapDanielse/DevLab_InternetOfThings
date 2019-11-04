// GPO DevLab Light Depedent Resistor example

int LightValue = 0;

void setup() 
{
  pinMode(D0, OUTPUT);
  digitalWrite(D0,LOW);
  Serial.begin(115200); // Set baudrate
}

void loop() 
{
   digitalWrite(D0,HIGH);
   LightValue = analogRead(A0); // read sensor value
   Serial.println("Soil sensor value:" + String(LightValue)); // Show
   digitalWrite(D0,LOW);
   delay(1000); // wait a second
}
