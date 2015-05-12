void pingInit(){
  pingSetup();
  digitalWrite(PINGVCC_1, HIGH);
   digitalWrite(PINGVCC_2, HIGH);
  
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration_1, duration_2, inches_1, cm_1, inches_2, cm_2;
  
    // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:

  digitalWrite(PINGTRIG_1, LOW);
  delayMicroseconds(1);
  digitalWrite(PINGTRIG_1, HIGH);
  delayMicroseconds(2);
  digitalWrite(PINGTRIG_1, LOW);


  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (PINGECHO_1, INPUT);//attach pin 4 to Echo
  duration_1 = pulseIn(PINGECHO_1, HIGH);

  // convert the time into a distance
  inches_1 = microsecondsToInches(duration_1);
  cm_1 = microsecondsToCentimeters(duration_1);
 
//  Serial.print(inches_1);
//  Serial.print("in_1, ");
//  Serial.print(cm_1);
//  Serial.print("cm_1");
//  Serial.println();



  delay(10);
  

  digitalWrite(PINGTRIG_2, LOW);
  delayMicroseconds(1);
  digitalWrite(PINGTRIG_2, HIGH);
  delayMicroseconds(2);
  digitalWrite(PINGTRIG_2, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode (PINGECHO_2, INPUT);//attach pin 4 to Echo
  duration_2 = pulseIn(PINGECHO_2, HIGH);

  // convert the time into a distance
  inches_2 = microsecondsToInches(duration_2);
  cm_2 = microsecondsToCentimeters(duration_2);
 
//  Serial.print(inches_2);
//  Serial.print("in_2, ");
//  Serial.print(cm_2);
//  Serial.print("cm_2");
//  Serial.println();

  display.update();
  display.setCursor(0,0);
  display.setTextSize(1);
  display.println("Sensor Array");
  display.println();
  display.setTextSize(2);
  display.print(cm_1);
  display.print("cm_1");
  display.println();

  display.print(cm_2);
  display.print("cm_2");
  display.println();
  display.update();
  display.clear();
 
  delay(1);
  
  if(cm_1 && cm_2 < 50){
    warningInit();
    motor(1, BRAKE, 255);
    motor(2, BRAKE, 255); 
    delay(5);
    motor(1, BACKWARD, 255);
    motor(2, FORWARD, 255); 
  }
  else if(cm_1 < 60 && cm_2 > 0){
    motor(1, BRAKE, 255);
    motor(2, BRAKE, 255); 
    delay(5);
    motor(1, BACKWARD, 150);
    motor(2, FORWARD, 150); 
  }
  else if(cm_2 < 60 && cm_1 > 0){
    motor(1, BRAKE, 255);
    motor(2, BRAKE, 255); 
    delay(5);
  motor(1, FORWARD, 150);
  motor(2, BACKWARD, 150); 
  }
  else if(cm_1 && cm_2 > 50){
    motor(1, BRAKE, 255);
    motor(2, BRAKE, 255); 
    delay(5);
     motor(1, FORWARD, 155);
     motor(2, FORWARD, 155); 
     delay(5);
     dangerInit();
  }
//  if(cm_1 < 20){
//  motor(1, BACKWARD, 255);
//  motor(2, FORWARD, 255); 
//
//  }
//
//  else{
//        
//    motor(1, FORWARD, 255);
//    motor(2, FORWARD, 255); 
//    happyInit();
//    pirInit();
//  }

}
