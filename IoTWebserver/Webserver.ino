// Webserver Module

//----------------------------------------------------------------------------------------------------
void WebserverInit()
{
  // Setup fixed IP
  // IPAddress staticIP(192,168,1,250); //ESP static ip
  // IPAddress gateway(192,168,1,1);   //IP Address of your WiFi Router (Gateway)
  // IPAddress subnet(255,255,255,0);  //Subnet mask
  // IPAddress dns(192,168,1,1);  //DNS
  // WiFi.config(staticIP, gateway, subnet, dns);
  
  WiFi.begin(ssid, password);     //Connect to your WiFi router
  Serial.println("");

  while (WiFi.status() != WL_CONNECTED) 
  {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
 
  server.on("/", handleRoot);
  server.on("/readData",  handleReadData);  
  server.on("/SetRelay",  handleRelay);
  server.on("/SetRGBLed", handleRGBLed);
  server.on("/SetServo",  handleServo);

  server.begin();
  Serial.println("HTTP server started");

}

//----------------------------------------------------------------------------------------------------
void handleRoot() 
{
 String s = MAIN_page; //Read HTML contents
 server.send(200, "text/html", s); //Send web page
}

//----------------------------------------------------------------------------------------------------
void handleReadData() 
{
  String currentTime = timeClient.getFormattedTime();
  server.send(200, "application/json", "{" + 
    TimeString() +
    TempHumString() + 
    MotionString() + 
    SoilString() +
    LightString() +
    RelayString() +
    ServoString() +
    RGBLedString() +
  "}");
}

//----------------------------------------------------------------------------------------------------
void handleRelay() 
{
  String RelayChannel = server.arg("Channel"); 
  SetRelay(RelayChannel.toInt());
  server.send(200, "application/json", "{" + TimeString() + RelayString() + "}");
}

//----------------------------------------------------------------------------------------------------
void handleServo() 
{
  String ServoData = server.arg("ServoData"); 
  SetServo(ServoData.toInt());
  server.send(200, "text/plane", "");
}

//----------------------------------------------------------------------------------------------------
void handleRGBLed() 
{
  String RValue = server.arg("R");  
  String GValue = server.arg("G");  
  String BValue = server.arg("B"); 
  SetRGBLed(RValue.toInt(),GValue.toInt(),BValue.toInt()); 
  server.send(200, "text/plane", "");
}
