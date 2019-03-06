/*
** Example Arduino sketch for SainSmart I2C LCD2004 adapter for HD44780 LCD screens
** Readily found on eBay or http://www.sainsmart.com/ 
** The LCD2004 module appears to be identical to one marketed by YwRobot
**
** Address pins 0,1 & 2 are all permenantly tied high so the address is fixed at 0x27
**
** Written for and tested with Arduino 1.0
** This example uses F Malpartida's NewLiquidCrystal library. Obtain from:
** https://bitbucket.org/fmalpartida/new-liquidcrystal 
**
** Edward Comer
** LICENSE: GNU General Public License, version 3 (GPL-3.0)
**
** NOTE: TEsted on Arduino NANO whose I2C pins are A4==SDA, A5==SCL
*/
#include <Wire.h>
#include <LCD.h>
#include <LiquidCrystal_I2C.h>

#define I2C_ADDR    0x3F  // Define I2C Address where the PCF8574A is
#define BACKLIGHT_PIN     3


int n = 1;
int serialOld = 0;
int timeLCD;
long serialRead;
int LCDon;

LiquidCrystal_I2C  lcd(I2C_ADDR,2,1,0,4,5,6,7);

void setup()
{
  lcd.begin (16,2);
// Switch on the backlight
  lcd.setBacklightPin(BACKLIGHT_PIN,POSITIVE);
  lcd.setBacklight(HIGH);
  lcd.home ();                   // go home
  serialRead = analogRead(1);
}
  
void loop()
{
  lcd.setCursor ( 0, 0 );
  lcd.print("jaja");
//  if(delay_without_delaying(timeLCD, 2000) && LCDon == 1){
//     lcd.clear();
//     LCDon = 0;
//   }
  
  
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
