void pingInit(){
  
  pinMode(PINGVCC, OUTPUT);
  pinMode(PINGTRIG, OUTPUT);
  pinMode(PINGECHO, INPUT);
  pinMode(PINGGND, OUTPUT);
  digitalWrite(PINGVCC, HIGH);
  
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration, inches, cm;
  
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(PINGTRIG, LOW);
  delayMicroseconds(1);
  digitalWrite(PINGTRIG, HIGH);
  delayMicroseconds(2);
  digitalWrite(PINGTRIG, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (PINGECHO, INPUT);//attach pin 4 to Echo
  duration = pulseIn(PINGECHO, HIGH);

  // convert the time into a distance
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
 
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  delay(1);
  
  if(cm>=30){
    
  // Suppose a DC motor is connected to M1_A(+) and M1_B(-)
  // Let it run full speed forward and half speed backward.
  // If 'BRAKE' or 'RELEASE' is used, the 'speed' parameter
  // is ignored.
  motor(1, BRAKE, 255);
  motor(2, BRAKE, 255); 

  long randNumber;
  randNumber = random(10, 29);
  delay(randNumber); 
  motor(1, FORWARD, 255);
  motor(2, FORWARD, 255);
  warningInit();
//  // Be friendly to the motor: stop it before reverse.
//  motor(1, RELEASE, 0);
//  motor(2, RELEASE, 0);
//  delay(5);
//  motor(1, BACKWARD, 255);
//  motor(2, BACKWARD, 255);
//  delay(200);
//  motor(1, RELEASE, 0);
//  motor(2, RELEASE, 0);
  }
  else if( cm <=20 && >= 10){
  motor(1, BRAKE, 255);
  motor(2, BRAKE, 255); 
  delay(50); 
  motor(1, BACKWARD, 255);
  motor(2, FORWARD, 255);
  delay(2);  
  warningInit();
//   motor(1, BRAKE, 255);
//  motor(2, BRAKE, 255); 
//  delay(5);
  
  }
  else if( cm <=10 ){
  motor(1, BRAKE, 255);
  motor(2, BRAKE, 255); 
  warningInit();
  motor(1, FORWARD, 180);
  motor(2, BACKWARD, 180);
//  warningInit();
//  motor(1, FORWARD, 180);
//  motor(2, BACKWARD, 180);
 
  delay(100);
  }
  else{
  motor(1, BRAKE, 255);
  motor(2, BRAKE, 255); 
  warningInit();
  }

}
