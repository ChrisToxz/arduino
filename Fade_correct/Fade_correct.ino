#include <FastLED.h>


#define NUM_LEDS 55
#define DATA_PIN 6
#define Brightness 255

#define start_1 0
#define end_1 18
#define start_2 19
#define end_2 37
#define start_3 38
#define end_3 54


byte byteRead;
int serialData;
CRGB leds[NUM_LEDS];


  
uint8_t hue = 0;
int hue1 = 0;
void setup() { 
  Serial.begin(9600);
  
       FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
       FastLED.setBrightness(Brightness);
         for(int i = 0; i < NUM_LEDS; i++){
          leds[i] = CRGB::Black;
          FastLED.show();
        }
        FastLED.setTemperature(Candle);
   }

   void loop() {
    
   if (Serial.available()) {
    serialData = Serial.read();
    switch(serialData){
      case 49:
      Serial.write("Doe start 1");
      if(hue1 != 255){
        for(int i = hue1; i < 255; hue1 = i++){
          for(int dot = start_1; dot < end_1; dot++){
            leds[dot] = CHSV(225,0,i);
          }
           FastLED.show();   
        }
     }
     break;
     case 50:
     Serial.write("Doe 1 stoppen");
     if(hue1 != 0){
      for(int i = hue1; i >= 0; hue1 = i--){
        for(int dot = start_1; dot < end_1; dot++){
            leds[dot] = CHSV(224,0,i);
          }
           FastLED.show();
      }
     }
    }
     
   }
    
     
    
//    delay(10);
//    hue++;
//  
//
//  fill_solid(leds, NUM_LEDS, CHSV(hue, 255, 255));
//  
//  FastLED.show();
    
//        for(int dot = start_1; dot < end_1; dot++) { 
//            leds[dot] = CRGB::Blue;
//            FastLED.show();  
//            // clear this led for the next time around the loop
//            leds[dot] = CRGB::Black;
//            delay(75);
//        }
    }
