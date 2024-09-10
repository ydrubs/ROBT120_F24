const int buzzer = 9; //buzzer to arduino pin 9


void setup(){
   
  pinMode(buzzer, OUTPUT); // Set buzzer - pin 9 as an output

}

void loop(){
 
  tone(buzzer, 1000); // Send 1KHz sound signal...
  delay(2500);         // ...for 1 sec
  noTone(buzzer);     // Stop sound...
  delay(250);         // ...for 1sec
  
}