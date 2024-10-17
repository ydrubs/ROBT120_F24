/**
  Getting Started with Opta™
  Name: LED_Blink_Opta
  Purpose: Blink STATUS LEDs on Opta™.

  @author Arduino

  NOTE: If there is a read error consult the documentation here: https://forum.arduino.cc/t/opta-unable-to-upload-programs-error-exit-status-74/1193410/4
*/

void setup() {
  pinMode(LED_D0, OUTPUT);
  pinMode(LED_D1, OUTPUT);
  pinMode(LED_D2, OUTPUT);
  pinMode(LED_D3, OUTPUT);
  pinMode(LED_RESET, OUTPUT);
  pinMode(LED_USER, OUTPUT);
}

void loop() {
  digitalWrite(LED_D0, HIGH);
  delay(100);
  digitalWrite(LED_D0, LOW);
  delay(100);

  digitalWrite(LED_D1, HIGH);
  delay(100);
  digitalWrite(LED_D1, LOW);
  delay(100);

  digitalWrite(LED_D2, HIGH);
  delay(100);
  digitalWrite(LED_D2, LOW);
  delay(100);

  digitalWrite(LED_D3, HIGH);
  delay(100);
  digitalWrite(LED_D3, LOW);
  delay(500);

  digitalWrite(LED_RESET, HIGH);
  delay(100);
  digitalWrite(LED_RESET, LOW);
  delay(500);

  digitalWrite(LED_USER, HIGH);
  delay(100);
  digitalWrite(LED_USER, LOW);
  delay(500);
}