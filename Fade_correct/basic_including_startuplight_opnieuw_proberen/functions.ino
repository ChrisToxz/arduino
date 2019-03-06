// Startup
void startupLight(){
  int lasttime;
  int interval = 25;
  int waves = 5;

  for(int i = 0; i < waves;){
    fadeLightBy(ledsB, stripB_leds, 10);
    fill_solid(ledsA, stripA_leds, CRGB::White);
    FastLED.show();
    delay(1000);
  }
  
  
//  for(int dot = 0; dot < stripA_leds + 1 ;){
//    if(dot != stripA_leds){
//      ledsA[dot] = CHSV(255, 0, 255);     
//      if(delay_without_delaying(lasttime, interval)){
//         FastLED.show();
//         lasttime = millis(); 
//        dot++;                  
//      }
//    }else{
//      for(int dotb = 0; dotb < stripB_leds;){
//        ledsB[dotb] = CHSV(128, 255, 255);     
//        if(delay_without_delaying(lasttime, interval)){
//           FastLED.show();
//           lasttime = millis(); 
//          dotb++;                  
//        }
//      }
//    }
//  }
}

void startupDip(){
  int i;
 for(i = 0; i<=3; i++){
   pinMode(dipPins[i], INPUT_PULLUP);      // set the digital pins (defined above) as input
  }
  s1state = digitalRead(52);
 
  s2state = digitalRead(53);

  s3state = digitalRead(51);
  Serial.println('DIP Started');
}

//Clear all leads
void clearAll(){
  fill_solid(ledsA, stripA_leds, CRGB::Black);
  fill_solid(ledsB, stripB_leds, CRGB::Black);
  FastLED.show();
}

void checkTimer(){
  
  if(stripA == 1){
    if (delay_without_delaying(stripApreviousMillis, stripA_interval)) {
         Serial.write("Timer over A");
          stripA = 0;
         if(hueA != 0){
          for(int i = hueA; i >= 0; hueA = i--){
            for(int dot = 0; dot < stripA_leds; dot++){
                ledsA[dot] = CHSV(224,0,i);
              }
               FastLED.show();
            }
         }
      }
    }
    if(stripB == 1){
    if (delay_without_delaying(stripBpreviousMillis, stripB_interval)) {
         Serial.write("Timer over B");
          stripB = 0;
         if(hueB != 0){
          for(int i = hueB; i >= 0; hueB = i--){
            for(int dot = 0; dot < stripB_leds; dot++){
                ledsB[dot] = CHSV(224,0,i);
              }
               FastLED.show();
            }
         }
      }
    }
}





