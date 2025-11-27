// EX 4_4

const int CTRL = 9; // PC817 LED control pin

void setup() {
  pinMode(CTRL, OUTPUT);
  digitalWrite(CTRL, LOW); 
}

void loop() {
  digitalWrite(CTRL, HIGH); // Fan ON (PC817 LED ON)
  delay(3000);              // 3 s
  digitalWrite(CTRL, LOW);  // Fan OFF
  delay(10000);             // 10 s
}


