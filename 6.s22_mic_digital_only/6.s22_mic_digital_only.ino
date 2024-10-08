int ledPin = 10;
int microphonePin = 3;
int state = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(microphonePin, INPUT);
  Serial.begin(9600);
}

void loop() {
  state = digitalRead(microphonePin);
  Serial.println(state);

  if (state == LOW) {
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }

  else {
    digitalWrite(ledPin, LOW);
  }
}