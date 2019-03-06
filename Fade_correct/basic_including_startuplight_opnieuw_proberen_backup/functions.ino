// Startup
void startupLight(){
  int lasttime;
  int interval = 25;
  
  for(int dot = 0; dot < stripA_leds;){
    if(dot != stripA_leds){
      ledsA[dot] = CHSV(128, 255, 255);
     
      if(delay_without_delaying(lasttime, interval)){
         FastLED.show();
         lasttime = millis(); 
        dot++;                  
      }
    }
    
  }
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

boolean delay_without_delaying(unsigned long since, unsigned long time) {
  // return false if we're still "delaying", true if time ms has passed.
  // this should look a lot like "blink without delay"
  unsigned long currentmillis = millis();
  if (currentmillis - since >= time) {
    since = currentmillis;
    return true;
  }
  return false;
}


