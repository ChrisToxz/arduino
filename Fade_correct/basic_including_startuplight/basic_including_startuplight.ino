#include "FastLED.h"


int stripA = 0;
int stripB = 0;
#define stripA_leds 55  
#define stripB_leds 66
#define stripA_interval 5000
long StripApreviousMillis;
CRGB ledsA[stripA_leds];
CRGB ledsB[stripB_leds];
int serialData;
int hue1 = 0;

void setup() {
 Serial.begin(9600);
 FastLED.addLeds<NEOPIXEL, 6>(ledsA, stripA_leds);
 FastLED.addLeds<NEOPIXEL, 3>(ledsB, stripB_leds);
 startupLight();
 clearAll();
 FastLED.setTemperature(Candle);
 
}
 void loop(){
  checkTimer();
if (Serial.available()) {
    serialData = Serial.read();
    switch(serialData){
      case 49:
      Serial.write("Doe start 1");
      stripA = 1;
      StripApreviousMillis = millis();
      if(hue1 != 255){
        for(int i = hue1; i < 255; hue1 = i++){
          for(int dot = 0; dot < stripA_leds; dot++){
            ledsA[dot] = CHSV(225,0,i);
          }
           FastLED.show();   
        }
     }
     break;
     case 50:
     Serial.write("Doe 1 stoppen");
     if(hue1 != 0){
      for(int i = hue1; i >= 0; hue1 = i--){
        for(int dot = 0; dot < stripA_leds; dot++){
            ledsA[dot] = CHSV(224,0,i);
          }
           FastLED.show();
      }
     }
     break;
     case 51:
     Serial.write("Doe start 2");
      if(hue1 != 255){
        for(int i = hue1; i < 255; hue1 = i++){
          for(int dot = 0; dot < stripB_leds; dot++){
            ledsB[dot] = CHSV(225,0,i);
          }
           FastLED.show();   
        }
     }
     break;
     case 52:
      Serial.write("Doe stop 2");
      if(hue1 != 255){
        for(int i = hue1; i < 255; hue1 = i++){
          for(int dot = 0; dot < stripB_leds; dot++){
            ledsB[dot] = CHSV(225,0,i);
          }
           FastLED.show();   
        }
     }
     break;
    }  
   }
 }

