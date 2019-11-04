// GPO DevLab RGB Led example

#include <Adafruit_NeoPixel.h>

#define PIXELPIN D2 //
#define NUMPIXELS 1 //

Adafruit_NeoPixel pixels(NUMPIXELS, PIXELPIN, NEO_GRB + NEO_KHZ800);


void setup() 
{
  Serial.begin(115200); // Set baudrate
  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

}

void loop() 
{
  pixels.setPixelColor(0, pixels.Color(150, 0, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(500);
  pixels.setPixelColor(0, pixels.Color(0, 150, 0));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(500);
  pixels.setPixelColor(0, pixels.Color(0, 0, 150));
  pixels.show();   // Send the updated pixel colors to the hardware.
  delay(500);
}
