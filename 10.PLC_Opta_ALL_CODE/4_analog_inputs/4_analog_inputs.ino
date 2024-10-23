	/**
	  Getting Started with Opta™
	  Name: Analog_Inputs_Opta
	  Purpose: Test analog pins A0, A1 and A2 as inputs on Opta™.
	 
	  @author Arduino
	*/
	 
	void setup() {
	   Serial.begin(9600);
	   // 65535 is the max value with 16 bits resolution set by analogReadResolution(16)
	   // 4095 is the max value with 12 bits resolution set by analogReadResolution(12)
	   analogReadResolution(12);
	}
	 
	void loop() {
	   // Read the input on analog input I1 corresponding to A0:
	   int sensorValueA0 = analogRead(A0);
	   float voltageA0 = sensorValueA0 * (3.0 / 4095.0)/ 0.3;
	 
	   // Print out the value you read from I1 to the max value for the analog inputs resolution:
	   Serial.print("I1 value: ");
	   Serial.print(sensorValueA0);
	   Serial.print(" corresponding to ");
	   Serial.print(voltageA0, 5); // Print the voltage as a float with 5 decimal digits
	   Serial.println("Volts");

	 
	   delay(1000);
	}