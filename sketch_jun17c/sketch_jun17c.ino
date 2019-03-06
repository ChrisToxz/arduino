
int dipPins[] = {52,53,51};
int transAddress;
void setup()
{
 Serial.begin(9600);
 int i;
 for(i = 0; i<=3; i++){
   pinMode(dipPins[i], INPUT_PULLUP);      // set the digital pins (defined above) as input
  }
}

void loop() {

  int s1state = digitalRead(52);
 
  int s2state = digitalRead(53);

  int s3state = digitalRead(51);
    Serial.print(s1state, DEC);
  Serial.print(s2state, DEC);
  Serial.println(s3state, DEC);
delay(1000);

}


