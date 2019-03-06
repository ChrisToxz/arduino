#include <RTClib.h>
#include <Wire.h>

RTC_DS1307 rtc;

char buf1[20];

void setup() 
{
  Serial.begin(9600);
  Wire.begin();

  rtc.begin();
  //rtc.adjust(DateTime(F(__DATE__),F(__TIME__)));

}

void loop()
{
  DateTime now = rtc.now();

  buf1 = rtc.now.hour();
  
  Serial.print(F("Date/Time: "));
  Serial.println(buf1);

  delay(1000);
}
