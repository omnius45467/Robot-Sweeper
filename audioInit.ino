void audioInit(){
  int incomingAudio;
//  const char incomingAudio;
  pinMode(incomingAudio, INPUT);
  incomingAudio = analogRead(A15);//read input from A0
  //do stuff with the variable "incomingAudio"

  Serial.print(incomingAudio);
  Serial.print(" audio");
  Serial.println();
  if(incomingAudio < 0){
//  warningInit();
  
  }
}
