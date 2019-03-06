
void clearAll(){
  hueA = 0;
  hueB = 0;
  fill_solid(ledsA, stripA_leds, CRGB::Black);
  fill_solid(ledsB, stripB_leds, CRGB::Black);
  FastLED.show();
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

