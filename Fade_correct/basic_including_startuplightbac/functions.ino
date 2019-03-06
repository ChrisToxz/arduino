// Startup
void startupLight(){
  int green = 128;
  for(int dot = 0; dot < stripA_leds + 1; dot++){
    if(dot != stripA_leds){
      ledsA[dot] = CRGB::Green;
      
      ledsA[dot] = CHSV(green, 255, 255);
      FastLED.show();
      delay(20);
      green--;                    
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
   
  if(millis() - StripApreviousMillis > stripA_interval){
     Serial.write("Timer over");
      stripA = 0;
     if(hue1 != 0){
      for(int i = hue1; i >= 0; hue1 = i--){
        for(int dot = 0; dot < stripA_leds; dot++){
            ledsA[dot] = CHSV(224,0,i);
          }
           FastLED.show();
      }
     }
    
  }
}
}

