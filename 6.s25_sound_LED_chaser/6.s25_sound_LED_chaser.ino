const int soundSensorPin = A0; // Analog pin connected to the sound sensor
const int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11}; // Digital pins connected to the LEDs

void setup() {
  pinMode(soundSensorPin, INPUT);
  for (int i = 0; i < 10; i++) {
    pinMode(ledPins[i], OUTPUT); // Set the LED pins as outputs
  }
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int soundValue = analogRead(soundSensorPin); // Read the analog input value
  
  for (int i = 0; i < 10; i++) {
    int lowerBound = 70 + (i * 100);
    int upperBound = lowerBound + 100;
    
    if (soundValue >= lowerBound && soundValue < upperBound) {
      for (int j = 0; j <= i; j++) {
        digitalWrite(ledPins[j], HIGH); // Turn on the LEDs up to the current index
      }
      for (int k = i + 1; k < 10; k++) {
        digitalWrite(ledPins[k], LOW); // Turn off the remaining LEDs
      }
    }
  }
  
}