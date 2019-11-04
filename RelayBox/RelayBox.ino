void setup() 
{
   digitalWrite(D1, HIGH);
   digitalWrite(D2, HIGH);
   digitalWrite(D3, HIGH);
   digitalWrite(D4, HIGH);
   pinMode(D1, OUTPUT);
   pinMode(D2, OUTPUT);
   pinMode(D3, OUTPUT);
   pinMode(D4, OUTPUT);

   for(int i=0; i<=1000; i++)
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
