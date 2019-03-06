#include "FastLED.h"
#define strip1 55  
#define strip2 66

CRGB ledsA[strip1];
CRGB ledsB[strip2];

void startupLight(){
  for(int dot = 0; dot < strip1 + 1; dot++){
    if(dot != strip1){
      ledsA[dot] = CRGB::Blue;
      FastLED.show();
      delay(50);
      Serial.write(dot);
    }else{
     for(int dot = 0; dot < strip2 + 1; dot++)
     {
      if(dot != strip2){
        ledsB[dot] = CRGB::Blue;
        FastLED.show();
        delay(50);
        }else{
          delay(500);
          clearAll();
          delay(500);
          fill_solid(ledsA, strip1, CRGB::Green);
          fill_solid(ledsB, strip2, CRGB::Green);
          FastLED.show();
          delay(1000);
          clearAll();
        }
      }
    }
  }
}

void clearAll(){
  fill_solid(ledsA, strip1, CRGB::Black);
  fill_solid(ledsB, strip2, CRGB::Black);
  FastLED.show();
}
void setup() {
 Serial.begin(9600);
 FastLED.addLeds<NEOPIXEL, 6>(ledsA, strip1);
 FastLED.addLeds<NEOPIXEL, 3>(ledsB, strip2);
 startupLight();
 FastLED.setTemperature(Candle);
 
}
 void loop(){
  
  FastLED.show();
 }

