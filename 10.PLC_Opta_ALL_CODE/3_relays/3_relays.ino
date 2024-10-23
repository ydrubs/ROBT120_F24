/**
  Getting Started with Opta™
  Name: Output_Relay_Opta
  Purpose: Test output relays of the Opta™.

  @author Arduino
*/

void setup() {
  // Initialize Relays outputs
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  // Initialize Opta LEDs
  pinMode(LED_D0, OUTPUT);
  pinMode(LED_D1, OUTPUT);
  pinMode(LED_D2, OUTPUT);
  pinMode(LED_D3, OUTPUT);
}

void loop() {
  // Closes and opens the contact of relay 1 and turns on/off led 1
  digitalWrite(D0, HIGH); // Sets the relay 1 on
  digitalWrite(LED_D0, HIGH);
  delay(1000);
  digitalWrite(D0, LOW); // Sets the relay 1 off
  digitalWrite(LED_D0, LOW);
  delay(1000);

  // Closes and opens the contact of relay 2 and turns on/off led 2
  digitalWrite(D1, HIGH); // Sets the relay 2 on
  digitalWrite(LED_D1, HIGH);
  delay(1000); 
  digitalWrite(D1, LOW); // Sets the relay 2 off
  digitalWrite(LED_D1, LOW);
  delay(1000);

  // Closes and opens the contact of relay 3 and turns on/off led 3
  digitalWrite(D2, HIGH); // Sets the relay 3 on
  digitalWrite(LED_D2, HIGH);
  delay(1000);
  digitalWrite(D2, LOW); // Sets the relay 3 off
  digitalWrite(LED_D2, LOW);
  delay(1000);  
  //  Closes and opens the contact of relay 4 and turns on/off led 4
  digitalWrite(D3, HIGH); // Sets the relay 4 on
  digitalWrite(LED_D3, HIGH);
  delay(1000);
  digitalWrite(D3, LOW); // Sets the relay 4 off
  digitalWrite(LED_D3, LOW);
  delay(1000);
}