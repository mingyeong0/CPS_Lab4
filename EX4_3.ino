// EX 4_3

const int FAN = 5;  // MOSFET gate connection (PWM pin)

void setup() {
  pinMode(FAN, OUTPUT);
  analogWrite(FAN, 0);     // start in OFF state
}

void loop() {
  // Turn fan ON (duty cycle 200/255)
  analogWrite(FAN, 200);
  delay(6000);             // 6 s ON

  // Turn fan OFF
  analogWrite(FAN, 0);
  digitalWrite(FAN, LOW);
  delay(10000);            // 10 s OFF
}

