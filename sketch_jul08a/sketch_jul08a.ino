#include "FastLED.h"
#define leds 30
CRGB led[leds];
void setup() {
  Serial.begin(9600);
FastLED.addLeds<NEOPIXEL, 39>(led, leds);
}
//105
void loop() {
  Serial.println("hallo");
  fill_solid(led, leds, CRGB::Red);
 FastLED.show();
 delay(1000);
 fill_solid(led, leds, CRGB::Black);
  FastLED.show();
  delay(1000);
//  for(int i = 0; i < 255; i++){
//          for(int dot = 0; dot < leds; dot++){
//            led[dot] = CHSV(225,0,i);
//            Serial.println(dot);
//          }
//           FastLED.show();
//  }
//  delay(5000);
//  fill_solid(led, leds, CRGB::Black);
//  FastLED.show();
//  delay(1000);
//  Serial.println("test");
}
