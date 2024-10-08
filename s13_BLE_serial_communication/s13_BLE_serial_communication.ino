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

}

void loop() {
//Write data from Serial to BLE
//Type something in the serial monitor and see the responce in a popup inside the ArduinoBlue app

  // Send string from serial command line to the phone. This will alert the user.
  if (Serial.available()) {
      Serial.write("send: ");
      String str = Serial.readString();
      phone.sendMessage(str); // phone.sendMessage(str) sends the text to the phone.
      Serial.print(str);
      Serial.write('\n');
  }

//Send data from ArduinoBlue app to serial

  // Returns the text data sent from the phone.
  // After it returns the latest data, empty string "" is sent in subsequent.
  // calls until text data is sent again.

  String str = phone.getText();
  if (str != "") {
      Serial.println(str);
  }

}