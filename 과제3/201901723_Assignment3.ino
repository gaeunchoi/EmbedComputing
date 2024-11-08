int ledNo = 13;

void setup() {
  pinMode(ledNo, OUTPUT);
}

void loop() {
  int times = 500;
  digitalWrite(ledNo, HIGH);
  delay(times);
  digitalWrite(ledNo, LOW);
  delay(times);
}
