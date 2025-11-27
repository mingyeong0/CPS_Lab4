// EX 4_2_A

const int FAN = 5;          // pin PWM - D5 
const int OFF_TIME = 10000; // 10 s OFF → 15 s cycle
const int STEPS    = 5;     // increase every second for 5 s
const int START_PWM = 90;   // starting PWM threshold, adjust between 60~120
const int KICK_PWM  = 255;  // kickstart
const int KICK_TIME = 250;  // 200~300 ms recommended

void setup() {
  pinMode(FAN, OUTPUT);
  analogWrite(FAN, 0);
}

void loop() {
  analogWrite(FAN, 0);
  delay(OFF_TIME);  // 10 s off

  analogWrite(FAN, KICK_PWM); //Kickstart
  delay(KICK_TIME);

  
  for (int i = 0; i < STEPS; i++) {
    int pwm = START_PWM + i * ((255 - START_PWM) / (STEPS - 1));
    if (pwm > 255) pwm = 255;
    analogWrite(FAN, pwm);
    delay(1000); 
  } // 5 seconds ON: increase speed every second

  analogWrite(FAN, 0); // Turn OFF
}
