/*
  IoTWebserver (c)J.C. Daniëlse - November 2019
  Local Webserver IoT
  
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
  

  V1.0   JpD 16-11-2019
         Original version
*/


// Defines
//----------------------------------------------------------------------------------------------------
 #define TIME 
 #define TEMPHUM 
 //#define SOIL 
 //#define LIGHT
 //#define MOTION 
 #define RELAY
 #define SERVO
 #define RGBLED 


// Includes
//----------------------------------------------------------------------------------------------------
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include "index.h" //Our HTML webpage contents with javascripts

#ifdef TIME
  #include <NTPClient.h>
  #include <WiFiUdp.h>
#endif

#ifdef TEMPHUM
  #include <DHTesp.h>
#endif

#ifdef SERVO
  #include <Servo.h>
#endif

#ifdef RGBLED
  #include <Adafruit_NeoPixel.h>
#endif


// declarations
//----------------------------------------------------------------------------------------------------
const char* ssid = "  ---ssid--  ";
const char* password = "  ---password---  ";

ESP8266WebServer server(80); //Server on port 80

#ifdef TIME
  const long utcOffsetInSeconds = 3600;
  WiFiUDP ntpUDP;
  NTPClient timeClient(ntpUDP, "pool.ntp.org", utcOffsetInSeconds);
#endif

#ifdef TEMPHUM
  const int TEMPHUMPIN = D7;
  float Humidity = 0.0;
  float Temperature = 0.0;
  DHTesp dht;
#endif

#ifdef SOIL
  const int SOILPIN = A0;
  int SoilValue = 0;
#endif

#ifdef LIGHT
  const int LIGHTPIN = A0;
  int LightValue = 0;
#endif

#ifdef MOTION
  const int MOTIONPIN = D0;
  int MotionValue = 0;
#endif

#ifdef RELAY
  const int RELAYCH1PIN = D1;
  const int RELAYCH2PIN = D2;
  const int RELAYCH3PIN = D3;
  const int RELAYCH4PIN = D4;
  bool RelayCH1Value = false;
  bool RelayCH2Value = false;
  bool RelayCH3Value = false;
  bool RelayCH4Value = false;
#endif

#ifdef SERVO
  const int SERVOPIN = D5;
  int ServoValue = 90;
  Servo Servo_SG90;
#endif

#ifdef RGBLED
  const int RGBLEDPIN = D6;
  const int NUMPIXELS = 1;
  byte LedRValue = 0;
  byte LedGValue = 0;
  byte LedBValue = 0;
  Adafruit_NeoPixel pixels(NUMPIXELS, RGBLEDPIN, NEO_GRB + NEO_KHZ800);
#endif


//----------------------------------------------------------------------------------------------------
void setup(void)
{
  Serial.begin(115200);
  WebserverInit();

#ifdef TIME
  TimeInit();
#endif
#ifdef TEMPHUM
  TempHumInit();
#endif
#ifdef SOIL
  SoilInit();
#endif
#ifdef LIGHT
  LightInit();
#endif
#ifdef MOTION
  MotionInit();
#endif
#ifdef RELAY
  RelayInit();
#endif
#ifdef SERVO
  ServoInit();
#endif
#ifdef RGBLED
  RGBLedInit(); 
#endif
}


//----------------------------------------------------------------------------------------------------
void loop(void)
{
  server.handleClient();
#ifdef TIME
  TimeRead();
#endif
#ifdef TEMPHUM
  TempHumRead();
#endif
#ifdef SOIL
  SoilRead();
#endif
#ifdef LIGHT
  LightRead();
#endif
#ifdef MOTION
  MotionRead();
#endif
}
