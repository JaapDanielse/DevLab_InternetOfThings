// GPO DevLab Pir Sensor example

#define LEDPIN D4 //

void setup() 
{
  Serial.begin(115200); // Set baudrate
  Serial.println("\n\nHello IoT World!");  
  pinMode(LEDPIN, OUTPUT);
}

void loop() 
{
  digitalWrite(LEDPIN, LOW);  
  delay(200);
  digitalWrite(LEDPIN, HIGH);  
  delay(200);
  digitalWrite(LEDPIN, LOW);  
  delay(200);
  digitalWrite(LEDPIN, HIGH);  
  delay(1000);
}
