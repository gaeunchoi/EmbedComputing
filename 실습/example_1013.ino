int val = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  val = analogRead(A3);
  Serial.print("Analog 3 input = ");
  Serial.println(val);
  delay(1000);

}
