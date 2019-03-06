#include "FastLED.h"
#define leds 195
CRGB led[leds];
void setup() {
  Serial.begin(9600);
FastLED.addLeds<NEOPIXEL, 39>(led, leds);
 FastLED.setBrightness(10);
}
//105
void loop() {
  // put your main code here, to run repeatedly:
  

  for(int i = 0; i < leds; i++){
    led[i] = CRGB::White;
    FastLED.show();
  }
  fill_solid(led, leds, CRGB::Red);
  FastLED.show();

}
