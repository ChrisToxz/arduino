#include "FastLED.h"


int stripA = 0;
int stripB = 0;
#define stripA_leds 55  
#define stripB_leds 66
#define sensorA 9
CRGB ledsA[stripA_leds];
CRGB ledsB[stripB_leds];
int hueA = 0;
int hueB = 0;


int FastLED_fade_counter = 0;

void setup() {
 // Rust startup
 delay(3000);
 //Start Serial
 Serial.begin(9600);
 // ledsA - stripA_leds
 FastLED.addLeds<NEOPIXEL, 6>(ledsA, stripA_leds);
 // ledsB - stripB_leds
 FastLED.addLeds<NEOPIXEL, 3>(ledsB, stripB_leds);
 FastLED.setBrightness(10);
 startupLight();
 clearAll();
 delay(2500);
}
 void loop(){
  Serial.println(digitalRead(sensorA));
  if(digitalRead(sensorA) == HIGH){
    fill_solid(ledsA, stripA_leds, CHSV(85, 255, 255));
  fill_solid(ledsB, stripB_leds, CHSV(85, 255, 255));
  FastLED.show();
  }else{
     clearAll();
  }
 }


            


