#define pin_I1 A0
#define pin_I2 A1
#define pin_I3 A2
#define pin_I4 A3
#define pin_I5 A4
#define pin_I6 A5
#define pin_I7 A6
#define pin_I8 A7

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:

  Serial.print(digitalRead(pin_I1));
  Serial.print(",");
  Serial.print(digitalRead(pin_I2));
  Serial.print(",");
  Serial.print(digitalRead(pin_I3));
  Serial.print(",");
  Serial.print(digitalRead(pin_I4));
  Serial.print(",");
  Serial.print(digitalRead(pin_I5));
  Serial.print(",");
  Serial.print(digitalRead(pin_I6));
  Serial.print(",");
  Serial.print(digitalRead(pin_I7));
  Serial.print(",");
  Serial.println(digitalRead(pin_I8));

  delay(100);
}