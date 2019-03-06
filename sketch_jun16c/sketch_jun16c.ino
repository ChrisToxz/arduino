/* Simple Serial ECHO script : Written by ScottC 03/07/2012 */

/* Use a variable called byteRead to temporarily store
   the data coming from the computer */
byte byteRead;
int serialData;

void setup() {                
// Turn the Serial Protocol ON
  Serial.begin(9600);
}

void loop() {
   /*  check if data has been sent from the computer: */
  if (Serial.available()) {
    serialData = Serial.read();
    switch(serialData){
      case 49:
      Serial.write("Doe start 1");
      break;
      default:
      Serial.write("Niks");
      break;
    }
  }
}
