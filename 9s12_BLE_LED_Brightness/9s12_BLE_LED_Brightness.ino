/*
* ArduinoBlue-library example code to control the brightness of an LED using a slider.
*/

#include <SoftwareSerial.h>
#include <ArduinoBlue.h>

const unsigned long BAUD_RATE = 9600;

// The bluetooth tx and rx pins must be supported by software serial.
// Visit https://www.arduino.cc/en/Reference/SoftwareSerial for unsupported pins.
// Bluetooth TX -> Arduino D8
const int BLUETOOTH_TX = 8;
// Bluetooth RX -> Arduino D7
const int BLUETOOTH_RX = 7;

// LED (+) -> Arduino D9
const int LED_PIN = 9;

SoftwareSerial bluetooth(BLUETOOTH_TX, BLUETOOTH_RX);
ArduinoBlue phone(bluetooth); // pass reference of bluetooth object to ArduinoBlue constructor.

void setup() {
    // Start serial communications.
    // The baud rate must be the same for both serials.
    Serial.begin(BAUD_RATE);
    bluetooth.begin(BAUD_RATE);

    // delay just in case bluetooth module needs time to "get ready".
    delay(100);

    Serial.println("setup complete");

    // Declare LED pin as an output pin.
    pinMode(LED_PIN, OUTPUT);
}

void loop() {

  // Get slider ID and it's value
  int sliderId = phone.getSliderId();
  int sliderVal = phone.getSliderVal(); //range of 0 to 200

  if (sliderId == 0) {
    // Adjust LED brightness.
    int writeVal = map(sliderVal, 0, 200, 0, 255);
    analogWrite(LED_PIN, writeVal);
    Serial.print("ID: "); Serial.print(sliderId);
    Serial.print("\tWriteVal: "); Serial.print(writeVal);
    Serial.print("\tVal: "); Serial.println(sliderVal);
  }
}

//*****We can use any slider to send commands to a pin by sending commands whenever any slider gets touched
// The sliderId will not be -1 if a slider has been touched.
//   if (sliderId != -1) {
//     // Adjust LED brightness.
//     int writeVal = map(sliderVal, 0, 200, 0, 255);
//     analogWrite(LED_PIN, writeVal);
//     Serial.print("ID: "); Serial.print(sliderId);
//     Serial.print("\tWriteVal: "); Serial.print(writeVal);
//     Serial.print("\tVal: "); Serial.println(sliderVal);
//   }
// }
