void startupLight(){

  long start = millis();
  for (int count = 0; count < 3; count++) {
    for (hueA = 180; hueA < 255; hueA++) {
      for (int dot = 0; dot < stripA_leds; dot++) {
        ledsA[dot] = CHSV(21, 255, hueA); // Can be any colour.

      }

      for (int dot = 0; dot < stripB_leds; dot++) {
        ledsB[dot] = CHSV(21, 255, hueA); // Can be any colour.

      }
      FastLED.show();
    }
    delay(100);
    for (hueA = 255; hueA > 178; hueA--) {
      for (int dot = 0; dot < stripA_leds; dot++) {
        ledsA[dot] = CHSV(21, 255, hueA); // Can be any colour.

      }
      for (int dotB = 0; dotB < stripB_leds; dotB++) {
        ledsB[dotB] = CHSV(21, 255, hueA); // Can be any colour.

      }

      FastLED.show();
    }
  }
  fill_solid(ledsA, stripA_leds, CRGB::Black);
  fill_solid(ledsB, stripB_leds, CRGB::Black);
  FastLED.show();
  delay(250);
  // groen  
  for (int count = 0; count < 3; count++) {
    for (hueA = 180; hueA < 255; hueA++) {
      for (int dot = 0; dot < stripA_leds; dot++) {
        ledsA[dot] = CHSV(85, 255, hueA); // Can be any colour.

      }

      for (int dot = 0; dot < stripB_leds; dot++) {
        ledsB[dot] = CHSV(85, 255, hueA); // Can be any colour.

      }
      FastLED.show();
    }
    delay(10);
    for (hueA = 255; hueA > 178; hueA--) {
      for (int dot = 0; dot < stripA_leds; dot++) {
        ledsA[dot] = CHSV(85, 255, hueA); // Can be any colour.

      }
      for (int dotB = 0; dotB < stripB_leds; dotB++) {
        ledsB[dotB] = CHSV(85, 255, hueA); // Can be any colour.

      }

      FastLED.show();
    }
  }
  fill_solid(ledsA, stripA_leds, CHSV(85, 255, 255));
  fill_solid(ledsB, stripB_leds, CHSV(85, 255, 255));
  FastLED.show();
  delay(1000);
  fill_solid(ledsA, stripA_leds, CRGB::Black);
  fill_solid(ledsB, stripB_leds, CRGB::Black);
  FastLED.show();
  delay(5000);
}

boolean  delay_without_delaying(unsigned long since, unsigned long time) {
  // return false if we're still "delaying", true if time ms has passed.
  // this should look a lot like "blink without delay"
  unsigned long currentmillis = millis();
  if (currentmillis - since >= time) {
    since = currentmillis;
    return true;
  }
  return false;
}

