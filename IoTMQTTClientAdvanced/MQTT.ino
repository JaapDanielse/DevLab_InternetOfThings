// MQTT Module

//----------------------------------------------------------------------------------------------------
void MQTTInit()
{
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());
 
}

//----------------------------------------------------------------------------------------------------
void MQTTConnect() 
{
  int8_t ret;

  if (mqtt.connected()) 
    return;

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  
  while ((ret = mqtt.connect()) != 0) {
    Serial.println(mqtt.connectErrorString(ret));
    Serial.println("Retrying MQTT connection in 5 seconds...");
    mqtt.disconnect();
    delay(5000); 
    retries--;
    if (retries == 0) {
      while (1);
    }
  }
  Serial.println("MQTT Connected!");
}


//----------------------------------------------------------------------------------------------------
void MQTTPublish(Adafruit_MQTT_Publish * PublishChannel, int Value)
{
  if (!PublishChannel->publish(Value)) 
    Serial.println(F("Publish Failed"));
}
