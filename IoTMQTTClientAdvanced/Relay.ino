// Relay Module

  
//----------------------------------------------------------------------------------------------------
void RelayInit()
{
  pinMode(RELAYCH1PIN, OUTPUT);
  digitalWrite(RELAYCH1PIN, HIGH);
  pinMode(RELAYCH2PIN, OUTPUT);
  digitalWrite(RELAYCH2PIN, HIGH);
}

//----------------------------------------------------------------------------------------------------
void SetRelay(int Channel, bool Onstate)
{
  if(Channel==1)
  { 
    RelayCH1Value = Onstate;
    if(RelayCH1Value) digitalWrite(RELAYCH1PIN,LOW); else digitalWrite(RELAYCH1PIN,HIGH);
    Serial.print("Relay Chanel 1: ");
    Serial.println(RelayCH1Value);
  }
  if(Channel==2)
  { 
    RelayCH2Value = Onstate;
    if(RelayCH2Value) digitalWrite(RELAYCH2PIN,LOW); else digitalWrite(RELAYCH2PIN,HIGH);
    Serial.print("Relay Chanel 2: ");
    Serial.println(RelayCH2Value);
  }
}
