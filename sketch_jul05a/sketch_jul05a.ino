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
  for(int i = 0; i < 255; i++){
          for(int dot = 0; dot < stripA_leds; dot++){
            ledsA[dot] = CHSV(225,0,i);
          }
           FastLED.show();
           delay(100);
  }
  delay(5000);
  fill_solid(led, leds, CRGB::Black);
  FastLED.show();
  delay(1000);

}
