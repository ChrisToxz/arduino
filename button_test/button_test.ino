int serialData;
const int buttonPin = 10;   
int i;
int buttonState = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 pinMode(buttonPin, INPUT);
 Serial.write('Started');
}

void loop() {
     int sensorValue = digitalRead(buttonPin);
     

     if(sensorValue == HIGH){
      i++;
      delay(100);
     }
      Serial.println(i);

}
