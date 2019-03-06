#include "FastLED.h"


int stripA = 0;
int stripB = 0;
#define stripA_leds 55  
#define stripB_leds 66
#define stripA_interval 5000
#define stripB_interval 5000
long stripApreviousMillis;
long stripBpreviousMillis;
CRGB ledsA[stripA_leds];
CRGB ledsB[stripB_leds];
int serialData;
int hueA = 0;
int hueB = 0;

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
      stripApreviousMillis = millis();
      if(hueA != 255){
        for(int i = hueA; i < 255; hueA = i++){
          for(int dot = 0; dot < stripA_leds; dot++){
            ledsA[dot] = CHSV(225,0,i);
          }
           FastLED.show();   
        }
     }
     break;
     case 50:
     Serial.write("Doe 1 stoppen");
     if(hueA != 0){
      for(int i = hueA; i >= 0; hueA = i--){
        for(int dot = 0; dot < stripA_leds; dot++){
            ledsA[dot] = CHSV(224,0,i);
          }
           FastLED.show();
      }
     }
     break;
     case 51:
     Serial.write("Doe start 2");
      stripB = 1;
      stripBpreviousMillis = millis();
      if(hueB != 255){
        for(int i = hueB; i < 255; hueB = i++){
          for(int dot = 0; dot < stripB_leds; dot++){
            ledsB[dot] = CHSV(225,0,i);
          }
           FastLED.show();   
        }
     }
     break;
     case 52:
      Serial.write("Doe stop 2");
      if(hueB != 255){
        for(int i = hueB; i < 255; hueB = i++){
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

