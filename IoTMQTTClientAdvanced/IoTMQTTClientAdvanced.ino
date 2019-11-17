/*
  MQTTClientAdvanced (c)J.C. Daniëlse - November 2019

  Based on Adafruit MQTT Client Example and Viral Science implementation

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
  

  V1.0   JpD 17-11-2019
         Original version
*/

#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"
#include <DHTesp.h>
#include <Servo.h>

  
#define WLAN_SSID       "  ---ssid---  "             // Your SSID
#define WLAN_PASS       "  ---password---  "        // Your password

#define IO_SERVER      "io.adafruit.com"
#define IO_SERVERPORT  1883                   
#define IO_USERNAME    "  ---adafruit username--  "
#define IO_KEY         "  ---adafruit key---  "

const int RELAYCH1PIN = D1;
const int RELAYCH2PIN = D2;
bool RelayCH1Value = false;
bool RelayCH2Value = false;

const int SERVOPIN = D5;
int ServoValue = 90;
Servo Servo_SG90;
  
const int TEMPHUMPIN = D7;
float Humidity = 0.0;
float Temperature = 0.0;
DHTesp dht;


//WIFI CLIENT
WiFiClient client;

// MQTT Server 
Adafruit_MQTT_Client mqtt(&client, IO_SERVER, IO_SERVERPORT, IO_USERNAME, IO_KEY);
Adafruit_MQTT_Subscribe RelayChannel1 = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/Relay1");
Adafruit_MQTT_Subscribe RelayChannel2 = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/Relay2");
Adafruit_MQTT_Subscribe ServoChannel = Adafruit_MQTT_Subscribe(&mqtt, IO_USERNAME "/feeds/ServoSlider");
Adafruit_MQTT_Publish TempChannel = Adafruit_MQTT_Publish(&mqtt, IO_USERNAME "/feeds/Temperature");

Adafruit_MQTT_Subscribe *subscription;

//----------------------------------------------------------------------------------------------------
void setup() 
{
  Serial.begin(115200);
  RelayInit();
  TempHumInit();
  ServoInit();
  MQTTInit();
  mqtt.subscribe(&RelayChannel1);
  mqtt.subscribe(&RelayChannel2);
  mqtt.subscribe(&ServoChannel);
}

//----------------------------------------------------------------------------------------------------
void loop() 
{
  TempHumRead();
  MQTTConnect();

  while ((subscription = mqtt.readSubscription(5000))) // keep connection open 20 seconds after activity
  {
    if (subscription == &RelayChannel1) 
        SetRelay(1,!strcmp((char *)RelayChannel1.lastread, "ON"));
    if (subscription == &RelayChannel2) 
        SetRelay(2,!strcmp((char *)RelayChannel2.lastread, "ON"));
    if (subscription == &ServoChannel) 
        SetServo(atoi((char *)ServoChannel.lastread));
  }
  
  MQTTPublish(&TempChannel, (int)Temperature);
}
