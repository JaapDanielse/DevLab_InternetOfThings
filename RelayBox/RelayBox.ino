void setup() 
{
   pinMode(D1, OUTPUT);
   digitalWrite(D1, HIGH);
   pinMode(D2, OUTPUT);
   digitalWrite(D2, HIGH);
   pinMode(D3, OUTPUT);
   digitalWrite(D3, HIGH);
   pinMode(D4, OUTPUT);
   digitalWrite(D4, HIGH);

   for(int i=0; i<=3; i++)
   {
     digitalWrite(D1, LOW);
     delay(500);
     digitalWrite(D1, HIGH);
     delay(500);
     digitalWrite(D2, LOW);
     delay(500);
     digitalWrite(D2, HIGH);
     delay(500);
     digitalWrite(D3, LOW);
     delay(500);
     digitalWrite(D3, HIGH);
     delay(500);
     digitalWrite(D4, LOW);
     delay(500);
     digitalWrite(D4, HIGH);
     delay(500);
   }
}

void loop() 
{
   
}
