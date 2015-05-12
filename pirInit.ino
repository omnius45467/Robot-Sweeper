int pirPin = 53;
int pirVcc = 51;

void pirInit(){
pinMode(pirPin, INPUT);
pinMode(pirVcc, OUTPUT);
digitalWrite(pirVcc, HIGH);
int pir = digitalRead(pirPin);
Serial.print("pir: ");
Serial.print(pir);
Serial.println();
if(pir > 0){
warningInit();
dangerInit();
motor(1, BACKWARD, 255);
motor(2, BACKWARD, 255);
delay(3.14*2/7);
}
}

