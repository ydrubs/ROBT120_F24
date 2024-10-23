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

bool stateSwitch = false;

void loop() {
  // put your main code here, to run repeatedly:
  
  if (stateSwitch == 0) {
    if (digitalRead(pin_I1) == 1) {
      ON_function();
      stateSwitch = 1;
    }
  } else {
    if (digitalRead(pin_I1) == 0) {
      OFF_function();
      stateSwitch = 0;
    }
  }

}

void ON_function() {
  Serial.println("Switch 1 ON");
}

void OFF_function() {
  Serial.println("Switch 1 OFF");
}