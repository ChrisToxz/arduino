#include "FastLED.h"


int stripA = 0;
int stripB = 0;
#define stripA_leds 55  
#define stripB_leds 66
CRGB ledsA[stripA_leds];
CRGB ledsB[stripB_leds];
int hueA = 0;
int hueB = 0;


int FastLED_fade_counter = 0;

void setup() {
 Serial.begin(9600);
 FastLED.addLeds<NEOPIXEL, 6>(ledsA, stripA_leds);
 FastLED.addLeds<NEOPIXEL, 3>(ledsB, stripB_leds);
 FastLED.setBrightness(50);
 startupLight();
 
}
 void loop(){
  
 }

//      if(hueB != 255){
//        for(int i = hueB; i < 255; hueB = i++){
//          for(int dot = 0; dot < stripB_leds; dot++){
//            ledsB[dot] = CHSV(225,,i);
//          }
//           FastLED.show();   
//        }
            


