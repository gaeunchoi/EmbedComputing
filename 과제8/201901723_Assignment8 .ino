int analogPin = A3;
int val = 0;
void setup() {
  Serial.begin(9600);
}

void loop() {
  /*
  val = analogRead(A3);
  Serial.print("Analog 3 input = ");
  Serial.println(val);

  val = analogRead(A0);
  Serial.print("Analog 0 input = ");
  Serial.println(val);
  delay(1000);
  */
  val = analogRead(analogPin);
  Serial.print("Analog 3 input = ");
  Serial.println(val);
  Serial.print(val*0.0049);
  Serial.println("V");

  val = analogRead(A0);
  Serial.print("Analog 0 input = ");
  Serial.println(val);
  Serial.print(val * 0.0049);
  Serial.println("V");
  
  delay(1000);
}
