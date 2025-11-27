// EX 4_2_B

const int FAN = 5;   // D5
const int POT = A0;
const int OFF_TIME = 10000; // 10 s OFF
const int ON_TIME  = 5000;  // 5 s ON

void hardOff() {
  analogWrite(FAN, 0);
  digitalWrite(FAN, LOW);   // completely OFF
}

void setup() {
  pinMode(FAN, OUTPUT);
  pinMode(POT, INPUT);
  hardOff();
}

void loop() {
  hardOff();
  delay(OFF_TIME);  // 10 s OFF

  analogWrite(FAN, 255);
  delay(250);  //Kickstart

  // 5 s: real-time speed control using potentiometer
  unsigned long t0 = millis();
  while (millis() - t0 < ON_TIME) {
    int pot = analogRead(POT);          // read 0 ~ 1023
    int pwm = map(pot, 0, 1023, 0, 255);// map to 0 ~ 255
    if (pwm > 0 && pwm < 80) pwm = 80;  // starting threshold adjustment
    analogWrite(FAN, pwm);
    delay(20);
  }

  hardOff();
}
