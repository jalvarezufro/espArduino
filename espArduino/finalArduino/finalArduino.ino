#define LED 8
int buzzer=12;
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
  pinMode(buzzer,OUTPUT);
  pinMode(LED, OUTPUT);
}
void loop()
{
boolean bul = true;
int val;
int valAux;
int turnOff;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);
delay(500);

if(val>400){
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  tone(buzzer,200);
  while(bul){
   if (Serial.available()) 
   { // If data is available to read,
     turnOff = Serial.read(); // read it and store it in val
     if(turnOff == 0){
      bul = false;
      noTone(buzzer);
      digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
   }
 }
  valAux=analogRead(0);//Read Gas value from analog 0
  Serial.println(valAux,DEC);
  delay(500);
  }

}
  }
