#define MAG_PIN 7


void setup() {
  pinMode(MAG_PIN, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  int value = digitalRead(MAG_PIN);
  Serial.println(value);
  delay(1000);
}
