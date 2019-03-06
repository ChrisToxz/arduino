#include "FastLED.h"



#define stripA_leds 300 
#define stripB_leds 66
CRGB ledsA[stripA_leds];
int hueA = 0;
int hueB = 0;


void setup() {
 Serial.begin(9600);
 FastLED.addLeds<NEOPIXEL, 39>(ledsA, stripA_leds);
 FastLED.setBrightness(100);
 FastLED.setTemperature(Candle);
 //startupLight();
 
}
 void loop(){
  fill_solid(ledsA, stripA_leds, CRGB::White);
  FastLED.show();
  delay(3000);
  fill_solid(ledsA, stripA_leds, CRGB::Blue);
  FastLED.show();
  delay(3000);
  
 }



