#include "FastLED.h"


int stripA = 0;
#define pin 8
int val = 0; 
int time = 0;
#define stripA_leds 55  
#define stripA_interval 5000
long stripApreviousMillis;
CRGB ledsA[stripA_leds];
int hueA = 0;

void setup() {
  // put your setup code here, to run once:
   pinMode(44, INPUT);     // declare sensor as input
  FastLED.addLeds<NEOPIXEL, 6>(ledsA, stripA_leds);
 fill_solid(ledsA, stripA_leds, CRGB::Black);
  FastLED.show();
  Serial.begin(9600);
}

void loop() {
  Serial.println(digitalRead(45));
  // put your main code here, to run repeatedly:
//  val = digitalRead(pin);  // read input value
//  if (val == HIGH) {
//    Serial.write('Detected');
//    Serial.println(time);
//   for(int dot = 0; dot < stripA_leds; dot++){
//            ledsA[dot] = CHSV(225,0,255);
//          }
//           FastLED.show();  
//           
//  }
}
