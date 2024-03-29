#include "FastLED.h"
#define leds 30
int temp;
CRGB led[leds];
void setup() {
  Serial.begin(9600);
FastLED.addLeds<NEOPIXEL, 40>(led, leds);
FastLED.setBrightness(40);
}
//1054

//All the predefined FastLED color temperatures:
#define TEMPERATURE_0 UncorrectedTemperature
#define TEMPERATURE_1 Candle
#define TEMPERATURE_2 Tungsten40W
#define TEMPERATURE_3 Tungsten100W
#define TEMPERATURE_4 Halogen
#define TEMPERATURE_5 CarbonArc
#define TEMPERATURE_6 HighNoonSun
#define TEMPERATURE_7 DirectSunlight
#define TEMPERATURE_8 OvercastSky
#define TEMPERATURE_9 ClearBlueSky
#define TEMPERATURE_10 WarmFluorescent
#define TEMPERATURE_11 StandardFluorescent
#define TEMPERATURE_12 CoolWhiteFluorescent
#define TEMPERATURE_13 FullSpectrumFluorescent
#define TEMPERATURE_14 GrowLightFluorescent
#define TEMPERATURE_15 BlackLightFluorescent
#define TEMPERATURE_16 MercuryVapor
#define TEMPERATURE_17 SodiumVapor
#define TEMPERATURE_18 MetalHalide
#define TEMPERATURE_19 HighPressureSodium
void loop() {
//  for(int i = 0; i < 255; i++){
//          for(int dot = 0; dot < leds; dot++){
//            led[dot] = CHSV(225,0,i);
//          }
//           FastLED.show();
//  }
//  delay(5000);
switch (temp) {
    case 0:
      FastLED.setTemperature( TEMPERATURE_0 );  break;
    case 1:
      FastLED.setTemperature( TEMPERATURE_1 );  break;
    case 2:
      FastLED.setTemperature( TEMPERATURE_2 );  break;
    case 3:
      FastLED.setTemperature( TEMPERATURE_3 );  break;
    case 4:
      FastLED.setTemperature( TEMPERATURE_4 );  break;
    case 5:
      FastLED.setTemperature( TEMPERATURE_5 );  break;
    case 6:
      FastLED.setTemperature( TEMPERATURE_6 );  break;
    case 7:
      FastLED.setTemperature( TEMPERATURE_7 );  break;
    case 8:
      FastLED.setTemperature( TEMPERATURE_8 );  break;
    case 9:
      FastLED.setTemperature( TEMPERATURE_9 );  break;
    case 10:
      FastLED.setTemperature( TEMPERATURE_10 );  break;
    case 11:
      FastLED.setTemperature( TEMPERATURE_11 );  break;
    case 12:
      FastLED.setTemperature( TEMPERATURE_12 );  break;
    case 13:
      FastLED.setTemperature( TEMPERATURE_13 );  break;
    case 14:
      FastLED.setTemperature( TEMPERATURE_14 );  break;
    case 15:
      FastLED.setTemperature( TEMPERATURE_15 );  break;
    case 16:
      FastLED.setTemperature( TEMPERATURE_16 );  break;
    case 17:
      FastLED.setTemperature( TEMPERATURE_17 );  break;
    case 18:
      FastLED.setTemperature( TEMPERATURE_18 );  break;
    case 19:
      FastLED.setTemperature( TEMPERATURE_19 );  break;
  }

  fill_solid(led, leds, CRGB::White);
  FastLED.show();
   temp++;
    if (temp == 20) { temp = 0; }  //reset
    Serial.print("Current temperature: "); Serial.println(temp);  //print temp # to serial monitor
delay(5000);
 fill_solid(led, leds, CRGB::Black);
  FastLED.show();
  delay(1000);

}
