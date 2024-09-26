int ledPin = 10;
int microphonePin = 3;
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(microphonePin, INPUT);
}

void loop() {
  state = digitalRead(microphonePin);

  if (state == HIGH) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }

  else {
    digitalWrite(ledPin, LOW);
  }
}