// Relay Module

  
//----------------------------------------------------------------------------------------------------
void RelayInit()
{
#ifdef RELAY
  pinMode(RELAYCH1PIN, OUTPUT);
  digitalWrite(RELAYCH1PIN, HIGH);
  pinMode(RELAYCH2PIN, OUTPUT);
  digitalWrite(RELAYCH2PIN, HIGH);
  pinMode(RELAYCH3PIN, OUTPUT);
  digitalWrite(RELAYCH3PIN, HIGH);
  pinMode(RELAYCH4PIN, OUTPUT);  
  digitalWrite(RELAYCH4PIN, HIGH);
#endif
}

//----------------------------------------------------------------------------------------------------
void SetRelay(int Channel)
{
#ifdef RELAY
  if(Channel==1)
  { 
    RelayCH1Value = !RelayCH1Value;
    if(RelayCH1Value) digitalWrite(RELAYCH1PIN,LOW); else digitalWrite(RELAYCH1PIN,HIGH);
  }
  if(Channel==2)
  { 
    RelayCH2Value = !RelayCH2Value;
    if(RelayCH2Value) digitalWrite(RELAYCH2PIN,LOW); else digitalWrite(RELAYCH2PIN,HIGH);
  }
  if(Channel==3)
  { 
    RelayCH3Value = !RelayCH3Value;
    if(RelayCH3Value) digitalWrite(RELAYCH3PIN,LOW); else digitalWrite(RELAYCH3PIN,HIGH);
  }
  if(Channel==4)
  { 
    RelayCH4Value = !RelayCH4Value;
    if(RelayCH4Value) digitalWrite(RELAYCH4PIN,LOW); else digitalWrite(RELAYCH4PIN,HIGH);
  }
#endif
}


//----------------------------------------------------------------------------------------------------
String RelayString()
{
  #ifdef RELAY
    int CH1Value = (int) RelayCH1Value;
    int CH2Value = (int) RelayCH2Value;
    int CH3Value = (int) RelayCH3Value;
    int CH4Value = (int) RelayCH4Value;
  
    return(",\"RELAY\":{\"RCH1\":" + String(CH1Value) + 
                       ",\"RCH2\":" + String(CH2Value) + 
                       ",\"RCH3\":" + String(CH3Value) + 
                       ",\"RCH4\":" + String(CH4Value) + "}"); 
  #endif
  return("");
}
