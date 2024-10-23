#define pin_I1 A0
#define pin_I2 A1
#define pin_I3 A2
#define pin_I4 A3
#define pin_I5 A4
#define pin_I6 A5
#define pin_I7 A6
#define pin_I8 A7

int pins[] = { pin_I1, pin_I2, pin_I3, pin_I4, pin_I5, pin_I6, pin_I7, pin_I8 };

void setup() {
  // put your setup code here, to run once:

  Serial.begin(9600);
}

bool stateSwitch[] = { false, false, false, false, false, false, false, false };

void loop() {
  // put your main code here, to run repeatedly:

  for (int i = 0; i <= 7; i++) {
    if (stateSwitch[i] == 0) {
      if (digitalRead(pins[i]) == 1) {
        ON_function(i);
        stateSwitch[i] = 1;
      }
    } else {
      if (digitalRead(pins[i]) == 0) {
        OFF_function(i);
        stateSwitch[i] = 0;
      }
    }
  }
}

void ON_function(int n) {
  Serial.print("Switch ");
  Serial.print(n+1);
  Serial.println(" ON");
}

void OFF_function(int n) {
  Serial.print("Switch ");
  Serial.print(n+1);
  Serial.println(" OFF");
}