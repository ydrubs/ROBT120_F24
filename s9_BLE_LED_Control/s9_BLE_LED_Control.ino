/*
* Demo program for controling red, green, and blue LED.
*/

#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

const unsigned long BAUD_RATE = 9600;

const int LED1 = 13;
const int LED2 = 12;

// The bluetooth tx and rx pins must be supported by software serial.
// Visit https://www.arduino.cc/en/Reference/SoftwareSerial for unsupported pins.
// Bluetooth TX -> Arduino D8
// Bluetooth RX -> Arduino D7
const int BLUETOOTH_TX_PIN = 8;
const int BLUETOOTH_RX_PIN = 7;

SoftwareSerial bluetooth(BLUETOOTH_TX_PIN, BLUETOOTH_RX_PIN);
ArduinoBlue phone(bluetooth); // pass reference of bluetooth object to ArduinoBlue constructor.

int button;
bool LED1on;
bool LED2on;


void setup() {
  // Start serial communications.
  // The baud rate must be the same for both serials.
  Serial.begin(BAUD_RATE);
  bluetooth.begin(BAUD_RATE);

  // delay just in case bluetooth module needs time to "get ready".
  delay(100);

  // Declare LED pins as output pins
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  
  Serial.println("setup complete");
}

void loop() {
  button = phone.getButton();

  if (button == 0) {
    if (LED1on) {
      digitalWrite(LED1, LOW);
      LED1on = false;
    }
    else {
      digitalWrite(LED1, HIGH);
      LED1on = true;
    }

  }
  else if (button == 1) {
    if (LED2on) {
      digitalWrite(LED2, LOW);
      LED2on = false;
    }
    else {
      digitalWrite(LED2, HIGH);
      LED2on = true;
    }
  }

}
